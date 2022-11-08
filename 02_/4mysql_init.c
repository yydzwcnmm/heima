#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<unistd.h>
#include<mysql/mysql.h>


#define HOST "192.168.6.145"
#define USER "root"
#define PWD "123456"
#define DB "scott"
#define SIZE 128

int shoe_result(MYSQL_RES *res)
{
    int f_nums = 0;
    int i = 0;
    int g =0;
    MYSQL_ROW row =NULL;
    MYSQL_FIELD *field = NULL;

    printf("row : %lu \n",mysql_num_rows(res));

    //获取字段的个数
    printf("nums = %u\n",mysql_num_fields(res));
    //字段个数
    f_nums=mysql_num_fields(res);
    field = mysql_fetch_fields(res);

    printf("--------------\n");
    //表头信息
    for( g=0 ;g<f_nums;g++){
        printf("%15s  ",field[g].name);
    }
    printf("\n");
    printf("--------------\n");

    while (1)
    {
        row = mysql_fetch_row(res);
        if(NULL==row){
            break;
        }

        for(i=0;i<f_nums;i++)
        {
            printf("%15s  ",row[i]);
        }
        printf("\n");
        
    }
    mysql_free_result(res);
    return 0;
}

int main(void)
{
    int ret = -1;
    char buf[SIZE];
    MYSQL *mysql = NULL;
    //结果集
    MYSQL_RES *res =NULL;

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
        else{printf("connect ok\n");}

  
//获取结果集
     shoe_result(res);
    //清屏
    system("clear");
    while (1)
    {

     #if 0
        /*标准屏幕输出 不带缓冲区*/
    write(STDOUT_FILENO,"mysql > ",strlen("mysql > "));

    //获取输入
    memset(buf,0,SIZE);
    read(STDIN_FILENO,buf,SIZE);
    if((strncasecmp(buf,"quit",4)==0) || (strncasecmp(buf,"exit",4) == 0)){
        printf("BB\n");
        break;
    }

    if('\n'==buf[strlen(buf)-1])
        buf[strlen(buf)-1] = '\0';
    
    if ('\0'==buf[0])
    {
        continue;
    }

    ret = mysql_query(mysql,buf);
    if(0!=ret){
        printf(" fail %s \n",mysql_error(mysql));
        continue;
    }
    
    res = mysql_store_result(mysql);
    if(NULL == res){
        printf("获取结果集 fail %s\n",mysql_error(mysql));
    }
    
    
   
    if(0==mysql_field_count(mysql)){
        //printf(" %ld row change \n",(long)mysql_affected_row(mysql));
    }
    else{
        //shoe_result(res);
    }
    
    #endif
    }
  

    //断开数据库
    mysql_close(mysql);
    return 0;


}

