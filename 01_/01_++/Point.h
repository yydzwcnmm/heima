#pragma once
class Point
{

public:
    void setPointXY( int x,int y);
    int getPX();
    int getPY();

private:
    int pX;
    int pY;

};

void Point::setPointXY(int x,int y)
{
    pX = x;
    pY = y;

}

int Point::getPX()
{
    return pX;
}

int Point::getPY()
{
    return pY;
}


