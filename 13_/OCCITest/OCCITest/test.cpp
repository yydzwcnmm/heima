#include<iostream>
#include<occi.h>
using namespace std;
using namespace oracle::occi;

int main()
{
	Environment* env = Environment::createEnvironment();
	//创建对象
	Connection* conn = env->createConnection("SCOTT","123456",);

	Statement* st = conn->createStatement();
	string sql = "slect * from dept";
	//只设置表，没有查询
	st->setSQL(sql);

	ResultSet* result = st->executeQuery;
	while (result->next())
	{
		cout << "no :" << result->getInt(1) << ","
			<< "name:" << result->getString(2) << ","
			<< "location:" << result->getString(3) << endl;

	}
	st->closeResultSet(result);

	//插入
	sql = "insert into dept values(33,'GG BAO','gg')";
	st->setSQL(sql);
	int ret = st->executeUpdate();
	cout << "insert ret = " << ret << endl;



	//销毁对象
	conn->terminateStatement(st);
	env->terminateConnection(conn);
	//释放环境对象
	Environment::terminateEnvironment(env);
	return 0;
}