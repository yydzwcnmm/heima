#include <cstdio>
#include<iostream>
#include<string>
#include "ClientOP.h"


int usage()
{
	int nSe1 = -1;
	printf("\n ************************************* \n");
	printf("\n        1 ��ԿЭ�� \n");
	printf("\n        2 ��ԿУ�� \n");
	printf("\n        3 ��Կע�� \n");
	printf("\n        4 ��Կ�鿴 \n");
	printf("\n        0 �˳�ϵͳ \n");
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
	//�����ͻ��˲�������
	ClientOP op;


	while (1)
	{
		int sel = usage();
		switch (sel)
		{
		case1:
			//��ԿЭ��
			op.seckeyAgree();
			break;
		case2:
			//��Կ���
			op.seckeyCheck();
			break;
		case3:
			//��Կע��
			op.seckeyZhuXiao();
			break;
	
		default:
			break;
		}
	}
    return 0;
}

