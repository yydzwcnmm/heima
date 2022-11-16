#pragma once
#include "Codec.h"
#include "Message.pb.h"
#include <iostream>
using namespace std;
struct RequestInfo
{
	int cmd;
	string clientID;
	string serverID;
	string sign;
	string data;
};


class RequestCodec : public Codec
{
public:
    friend class Codec;

    //空对象
    RequestCodec();
    //构造对象 用于解码
    RequestCodec(string encStr);
    //构造对象 用于编码
    RequestCodec(RequestInfo *info);
    //解码使用
    void initMessage(string encStr);
    //编码使用
    void initMessage(RequestInfo *info);
    //序列化 返回字符串
    string encodeMsg();
    //反序列化函数 返回类或结构体 返回值方便强行转化
	void* decodeMsg();

	~RequestCodec();

private:
    string m_encStr;
	RequestMsg m_msg;

};

