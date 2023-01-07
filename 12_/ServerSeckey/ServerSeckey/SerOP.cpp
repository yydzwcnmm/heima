#include "SerOP.h"
#include "TcpSocket.h"
#include "RequestFactory.h"
#include "RequestCodec.h"
#include "RespondCodec.h"
#include "RespondFactory.h"
#include "RsaCrypto.h"
#include"forwards.h"
#include"reader.h"
#include <string>
#include <iostream>
#include <fstream>
#include <json/json.h>
#include <unistd.h>
#include "Hash.h"
using namespace std;
//using namespace Json;

	SerOP::SerOP(string json)
{
	// 解析json文件, 读文件 -> Value ROOT
	ifstream ifs(json);
	Reader r;
	Value root;
	//解析后放到ROOT中
	r.parse(ifs, root);
	// 将root中的键值对value值取出
	my_port = root["Port"].asInt();
	my_serverID = root["ServerID"].asString();
	cout << my_serverID << ", 端口:" << my_port << endl;
}

SerOP::~SerOP()
{
	if (m_server) {
	  delete m_server;
	}
	
}


string SerOP::seckeyAgree(RequestMsg* reqMsg)
{

	//对签名进行校验
	//公钥数据写入磁盘
	RespondInfo info;
	ofstream ofs("public.pem");
	ofs << reqMsg->data();
	//创建非对称加密对象
	RsaCrypto rsa("public.pem", false);
	bool b1 = rsa.rsaVerify();
	if (b1 == false) {
		cout << "签名校验失败" << endl;
		info.status = false;
	}
	else {
		//生产随机字符串
		string key = getRandKey(Len16);
		//通过公钥加密非对称加密密钥
		string seckey = rsa.rsaPubKeyEncrypt(key);
		//初始化回复数据
	
		info.clientID = reqMsg->clientid();
		info.data = seckey;
		info.seckeyID = 12; // 需要数据库
		info.serverID = my_serverID;
		info.status = true;
		 
	}
	//序列化
	CodecFactory* fac = new RespondFactory();
	Codec* c = fac->createCodec();
	string encMsg = c->encodeMsg();
	return encMsg;
}

//包含 0-9 A-Z a-z 特殊字符
string SerOP::getRandKey(KeyLen Len)
{
	int flag = 0;
	string randStr = string();
	char *cs = "!@#$%^&*()_+~<>?";
	for (int i = 0;i<Len;++i)
	{
		flag = rand() % 4;
		switch (flag)
		{
		case 0:
			randStr.append(1,'a'+rand()%26);
			break;
		case 1:
			randStr.append(1, 'A' + rand() % 26);
			break;
		case 2:
			randStr.append(1, '0' + rand() % 10);
			break;
		case 3:
			randStr.append(1, cs[rand()%16]);
			break;
		default:
			break;
		}
	}
	return randStr;
}

void SerOP::startServer()
{
	TcpServer *m_server = new TcpServer;
	m_server->setListen(my_port);
	while (1)
	{
		cout << "等待客户端连接" << endl;
		//等待客户端连接
		arg.tcp = m_server->acceptConn();
		if (arg.tcp == NULL) {
			continue;
		}
		//创建子线程
		pthread_t tid; 
		//!!!!!!
		pthread_create(&tid,NULL,working,& (arg));
		//m_list.insert(make_pair(tid,tcp));
	}

}


void * SerOP::working(void* arg)
{
	//TcpSocket* tcp = (TcpSocket*)arg;
	struct parameter* argworking;
	argworking = (struct parameter *) arg;
	TcpSocket* tcp = argworking->tcp;
	SerOP* pmeigeduixiang = argworking->a;

	//接受客户端数据
	string msg = tcp->recvMsg(); 
	//工厂类，生产编解码对象,反序列化
	CodecFactory* fac = new RequestFactory(msg);
	Codec* c = fac->createCodec();
	//反序列化数据存入REQ
	RequestMsg* req = (RequestMsg*)c->decodeMsg();
	
	string data;

	switch (req->cmdtype())
	{
	case 1:
		//密钥协商!!!!!!!
		data = pmeigeduixiang->seckeyAgree(req);
		break;
	case 2:
		//密钥校验
		break;
	case 3:
		//密钥注销
		break;
	default:
		break;
	}
	//密钥协商结果发送
	tcp->sendMsg(data);
	tcp->disConnect();
	delete tcp;
	return NULL;
	delete c;
	delete fac;
	//tcp处理
}

