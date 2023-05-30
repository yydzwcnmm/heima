#include<iostream>
#include<occi.h>
using namespace std;
using namespace oracle::occi;

int main()
{
	Environment* env = Environment::createEnvironment();
	//��������
	Connection* conn = env->createConnection("SCOTT","123456",);

	Statement* st = conn->createStatement();
	string sql = "slect * from dept";
	//ֻ���ñ�û�в�ѯ
	st->setSQL(sql);

	ResultSet* result = st->executeQuery;
	while (result->next())
	{
		cout << "no :" << result->getInt(1) << ","
			<< "name:" << result->getString(2) << ","
			<< "location:" << result->getString(3) << endl;

	}
	st->closeResultSet(result);

	//����
	sql = "insert into dept values(33,'GG BAO','gg')";
	st->setSQL(sql);
	int ret = st->executeUpdate();
	cout << "insert ret = " << ret << endl;



	//���ٶ���
	conn->terminateStatement(st);
	env->terminateConnection(conn);
	//�ͷŻ�������
	Environment::terminateEnvironment(env);
	return 0;
}