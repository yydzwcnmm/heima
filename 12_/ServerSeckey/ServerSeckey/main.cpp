#include <cstdio>
#include"SerOP.h"
int main()
{
	SerOP op("server.json");
	op.startServer();
    printf("hello from ServerSeckey!\n");
    return 0;
}