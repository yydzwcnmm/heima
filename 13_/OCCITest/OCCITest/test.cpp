#include<iostream>
#include<occi.h>
using namespace std;
using namespace oracle::occi;

int main()
{
	Environment* env = Environment::createEnvironment();
	//创建对象
	Connection* conn = env->createConnection("SCOTT","123456",);

	//销毁对象
	env->terminateConnection(conn);
	//释放环境对象
	Environment::terminateEnvironment(env);
	return 0;
}