#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#include<string>

class Maker
{

public:
    void Iint()
    {
        name = "顶针";
        age = 20;

    }

    void setName(string Name)
    {
        name = Name;
    }

    string getN()
    {
        return name;
    }

   
      void setA(int Age)
    {
        if(Age<100&&Age>0)
        {
            age = Age;
        }
        else{
            printf("age input err");
        }
    }
    
    int getA()
    {
        return age;
    }

    void prit()
    {
        cout<<"name"<<name<<endl;
        cout<<"age"<<age<<endl;

    }

private:
    string name;
    int age;

};

int main()
{
    //printf("ok\n");
    Maker d;
    d.Iint();
    d.prit();
    d.setA(99);
    d.setName("dzz");
    d.prit();


    system("pause");
    return EXIT_SUCCESS;
    
}