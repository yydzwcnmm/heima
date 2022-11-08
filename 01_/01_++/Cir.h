#pragma once
#include "Point.h"
#include <math.h>
#include<iostream>
using namespace std;
class Circle
{
private:
    int R;
    Point c;
    

public:
    void setR(int r);
    void setCP(Point &cp);
    void setCP(int x,int y);
    int getR();
    Point getCpoint();
    void pd(Point &poi);
    void isrela(Point &a1);
};

void Circle::setR(int r)
{
    R= r;
}

void Circle::setCP(Point &cp)
{
    int x1,y1;
    x1=cp.getPX();
    y1= cp.getPY();
    c.setPointXY(x1,y1);

}

void Circle::setCP(int x,int y)
{
    c.setPointXY(x,y);

}

int Circle::getR()
{
    return R;
}

Point Circle::getCpoint()
{
    return c;
}

//比较圆和点

void Circle::isrela(Point &a1)
{
    double distance = pow((a1.getPX()-c.getPX()),2) + pow((a1.getPY()-c.getPY()),2);

    double pfR = pow(R,2);
    if(distance>pfR){
        cout<<"点在圆外"<<endl;
    }
    if(distance<pfR)
    {
        /* code */
        cout<<"inside"<<endl;
    }
     if(distance==pfR)
    {
        /* code */
        cout<<"on"<<endl;
    }
    
    
}
