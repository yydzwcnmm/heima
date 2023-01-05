#pragma once
#include <map>
#include "TcpServer.h"
#include "Message.pb.h"
class SerOP
{
public:
	SerOP(string json);
	~SerOP();
	//启动服务器
	void startServer();
	//线程工作函数
	static void* working(void* arg);
	void seckeyAgree(RequestMsg* reqMsg);
private:
	unsigned short my_port;
	string my_serverID; //当前服务器ID
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

