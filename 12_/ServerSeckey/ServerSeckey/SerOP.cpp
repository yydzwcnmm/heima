#include "SerOP.h"
#include"TcpServer.h"
#include<string>
#include<iostream>
#include"RequestCodec.h"
#include"RequestFactory.h"
#include"RespondFactory.h"
#include"TcpSocket.h"
SerOP::SerOP(string json)
{
	// ����json�ļ�, ���ļ� -> Value ROOT
	ifstream ifs(json);
	Reader r;
	Value root;
	//������ŵ�ROOT��
	r.parse(ifs, root);
	// ��root�еļ�ֵ��valueֵȡ��
	my_port = root["Port"].asInt();
	my_serverID = root["ServerID"].asString();
	cout << my_serverID << ", �˿�:" << my_port << endl;
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
		cout << "�ȴ��ͻ�������" << endl;
		//�ȴ��ͻ�������
		arg.tcp = m_server->acceptConn();
		if (arg.tcp == NULL) {
			continue;
		}
		//�������߳�
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

	//���ܿͻ�������
	string msg = tcp->recvMsg(); 
	//�����࣬������������,�����л�
	CodecFactory* fac = new RequestFactory(msg);
	Codec* c = fac->createCodec();
	RequestMsg* req = (RequestMsg*)c->decodeMsg();
	//�����л����ݴ���REQ

	switch (req->cmdtype())
	{
	case 1:
		//��ԿЭ��!!!!!!!
		pmeigeduixiang->seckeyAgree();
		break;
	case 2:
		//��ԿУ��
		break;
	case 3:
		//��Կע��
		break;
	default:
		break;
	}
	return NULL;
	delete c;
	delete fac;
	//tcp����
}

void SerOP::seckeyAgree()
{

}
