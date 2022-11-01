#include <stdio.h>
#include <string.h>
#include<stdlib.h>

#include<mysql/mysql.h>

#define HOST "192.168.6.145"
#define USER "root"
#define PWD "123456"
#define DB "scott"
#define SIZE 128



int main(void)
{
    int ret = -1;
    char buf[SIZE];
    MYSQL *mysql = NULL;
    mysql = mysql_init(NULL);
    if(NULL == mysql){
        printf("mysql init err\n");
    }
    printf("mysql init ok\n");
    
    mysql = mysql_real_connect(mysql,HOST,USER,PWD,DB,0,NULL,0);
    if (NULL==mysql)
    {
        printf("connect fail %s \n",mysql_error(mysql));
    }
        printf("connect ok\n");

#if 0

    //执行INSERT 表中插入一个对象
    memset(buf,0,SIZE); 
    strcpy(buf,"insert into dept values (1,'1name','1loc')");
    ret = mysql_query(mysql,buf);
    if(0!=ret){
        printf("insert fail\n");
    }else{
    printf("insert ok\n");
    }
#endif
    memset(buf,0,SIZE);
    strcpy(buf,"delete from dept where deptno = 1");
    ret = mysql_query(mysql,buf);
    if(0!=ret){
        printf("delect fail %s \n",mysql_error(mysql));
    }else{
    printf("delect ok\n");
    }

    //断开数据库
    mysql_close(mysql);
    return 0;

}

