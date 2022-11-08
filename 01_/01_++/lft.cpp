#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#include<string>

class Cube
{

public:
    void init()
    {
        mL = 0;
        mW = 0;
        mH = 0;

    }

    void selLWH(int l,int w,int h )
    {
        mL = l;
        mW = w;
        mH = h;
    }

    int getL()
    {
        return mL;
    }
     int getH()
    {
        return mH;
    }
     int getW()
    {
        return mW;
    }
    
    int getS()
    {
        return 2*mL*mH+2*mL*mW+2*mW*mH;
    }
    int getV()
    {
        return mL*mH*mW;

    }
    bool compC(Cube &cube)
    {
        if (getL()==cube.getL() && getW()==cube.getW() &&getH()==cube.getH() )
        {
            /* code */
            return true;
        }else{
            return false;
        }
        
    }

private:
    int mL;
    int mW;
    int mH;
    
};



int main()
{
    //printf("ok\n");
    

    Cube c1,c2;
    c1.init();
    c2.init();
    c1.selLWH(1,1,1);
    c2.selLWH(1,1,2);
    if (c1.compC(c2))
    {
        cout<<"eq"<<endl;

    }else{
        cout<<"not eq"<<endl;
    }
    


    system("pause");
    return EXIT_SUCCESS;
    
}