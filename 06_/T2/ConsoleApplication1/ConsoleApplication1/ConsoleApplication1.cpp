// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
#include <iostream>
#include "Request.h"
#include "Response.h"
#include "Codec.h"

string enCode(Codec* c1)
{
    return c1->encodeMsg();
}

void* decode(Codec* c2){

    return c2->decodeMsg();

}

int main()
{
    cout << "Hello World!\n";
	RequestInfo info = { 9,"onepice","ggbao","djj","rbq" };
    RequestCodec send(&info);
    // 数据编码
  
    
    //
    string output;
    //output = send.encodeMsg();
    output = enCode(&send);

    // 解码
    RequestCodec resv(output);
    //RequestMsg* t =  (RequestMsg* )resv.decodeMsg();
    RequestMsg* t =  (RequestMsg* )decode(&resv);

    cout << "cmdtype: " << t->cmdtype()
		<< ", clinetID: " << t->clientid()
		<< ", serverID: " << t->serverid()
		<< ", sign: " << t->sign()
		<< ", data: " << t->data() << endl;
	
// ++++++++++++++++++++++++++++++++++++++++++++++++++

    RespondInfo infosv = { 66,99,"adw","dww","xgp"};
    RespondCodec sendsv(&infosv);
    // 数据编码
  
    
    //
    
    //output = send.encodeMsg();
    output = enCode(&sendsv);

    // 解码
    RespondCodec resv2(output);
    //RequestMsg* t =  (RequestMsg* )resv.decodeMsg();
    RespondMsg* r2 =  (RespondMsg* )decode(&resv2);

   cout << "status: " << r2->status()
		<< ", seckeyID: " << r2->seckeyid()
		<< ", clinetID: " << r2->clientid()
		<< ", serverID: " << r2->serverid()
		<< ", data: " << r2->data() << endl;




}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
