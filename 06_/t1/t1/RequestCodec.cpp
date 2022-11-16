#include <iostream>
#include "RequestCodec.h"


RequestCodec::RequestCodec()
{

}

RequestCodec::RequestCodec(string encStr)
{	
	//保存解码字符串
	initMessage(encStr);
}

RequestCodec::RequestCodec(RequestInfo * info)
{	
	//编码
	initMessage(info);
}

void RequestCodec::initMessage(string encStr)
{
	//保存解码字符串
	m_encStr = encStr;
}

void RequestCodec::initMessage(RequestInfo * info)
{	
	//编码 写入数据
	m_msg.set_cmdtype(info->cmd);
	m_msg.set_clientid(info->clientID);
	m_msg.set_serverid(info->serverID);
	m_msg.set_sign(info->sign);
	m_msg.set_data(info->data);
}

string RequestCodec::encodeMsg()
{
	
	string output;
	m_msg.SerializeToString(&output);
	return output;
	
}

void * RequestCodec::decodeMsg()
{
	m_msg.ParseFromString(m_encStr);
	return &m_msg;
}

RequestCodec::~RequestCodec()
{

}

