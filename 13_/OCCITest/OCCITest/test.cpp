#include<iostream>
#include<occi.h>
using namespace std;
using namespace oracle::occi;

int main()
{
	Environment* env = Environment::createEnvironment();
	//��������
	Connection* conn = env->createConnection("SCOTT","123456",);

	//���ٶ���
	env->terminateConnection(conn);
	//�ͷŻ�������
	Environment::terminateEnvironment(env);
	return 0;
}