#pragma once
#include"TcpServer.h"
#include<map>
class SerOP
{
public:
	SerOP(string json);
	~SerOP();
	//����������
	void startServer();
	//�̹߳�������
	static void* working(void* arg);
	void seckeyAgree();
private:
	unsigned short my_port;
	string my_serverID; //��ǰ������ID
	TcpServer *m_server = NULL;
	//map<pthread_t, TcpSocket>m_list;
	//TcpSocket* tcp;

	struct parameter
	{
		TcpSocket* tcp;
		SerOP* a;
	};
	struct parameter arg;
};

