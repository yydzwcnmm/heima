#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>
#include"Cir.h"

int main()
{

    Point p1;
    p1.setPointXY(10,10);
    Circle c1;
    c1.setCP(10,20);
    c1.setR(5);
    c1.isrela(p1);
    system("pause");
    return EXIT_SUCCESS;
}
