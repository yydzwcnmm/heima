#include "SerOP.h"
#include "TcpSocket.h"
#include "RequestFactory.h"
#include "RequestCodec.h"
#include "RespondCodec.h"
#include "RespondFactory.h"
#include "RsaCrypto.h"
#include <string>
#include <iostream>
#include <fstream>
//#include <json/json.h>
//#include <unistd.h>
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
	RequestMsg* req = (RequestMsg*)c->decodeMsg();
	//反序列化数据存入REQ

	switch (req->cmdtype())
	{
	case 1:
		//密钥协商!!!!!!!
		pmeigeduixiang->seckeyAgree(req);
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
	return NULL;
	delete c;
	delete fac;
	//tcp处理
}


void SerOP::seckeyAgree(RequestMsg* reqMsg)
{
	
	//对签名进行校验
	//公钥数据写入磁盘
	ofstream ofs("public.pem");
	ofs<<reqMsg->data();
	//创建非对称加密对象
	RsaCrypto rsa("public.pem",false);
	bool b1 =rsa.rsaVerify();
	if (b1 == false) {
		cout << "签名校验失败" << endl;
	}
	else {
		 
	}

}