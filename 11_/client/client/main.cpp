#include <cstdio>
#include<iostream>
#include<string>
#include "ClientOP.h"


int usage()
{
	int nSe1 = -1;
	printf("\n ************************************* \n");
	printf("\n        1 密钥协商 \n");
	printf("\n        2 密钥校验 \n");
	printf("\n        3 密钥注销 \n");
	printf("\n        4 密钥查看 \n");
	printf("\n        0 退出系统 \n");
	printf("\n ************************************* \n");
	scanf("%d", &nSe1);
	while (getchar() != '\n')
	{

	}
	return nSe1;
}

int main()
{
    printf("hello from client!\n");
	//创建客户端操作对象
	ClientOP op;


	while (1)
	{
		int sel = usage();
		switch (sel)
		{
		case1:
			//密钥协商
			op.seckeyAgree();
			break;
		case2:
			//密钥检查
			op.seckeyCheck();
			break;
		case3:
			//密钥注销
			op.seckeyZhuXiao();
			break;
	
		default:
			break;
		}
	}
    return 0;
}

