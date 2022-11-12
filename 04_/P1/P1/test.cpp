#include<iostream>
#include"Persion.pb.h"


//using namespace std;

using std::cout;
using std::endl;
using std::string;
 int main()
 {
   //创建PERSION 对象
    Persion p;
    p.set_id(1001);

    p.add_name(); //申请一块内存
    p.set_name(0,"gg bao"); //申请内存中，0号位置，加入名字
    p.add_name(); //申请一块内存
    p.set_name(1,"xiaom"); //申请内存中，1号位置，加入名字
    p.add_name(); //申请一块内存
    p.set_name(2,"djj"); //申请内存中，1号位置，加入名字
   //p.set_name("lufei");
    p.set_sex("man");
    p.set_age(17);

   //将PERSION对象-》字符串
   string output;
   p.SerializeToString(&output);
   cout<<"序列化后的数据： "<<output<<endl;
   //数据传输
   //接受数据 ——》解码 -》 原始数据

   Persion pp;
   pp.ParseFromString(output);
   //解析后数据在pp
   cout<<"id "<<pp.id()<<endl;
   //cout<<"name "<<pp.name()<<endl;
   cout<<"name0 =  "<<pp.name(0)<<endl;
   cout<<"name1 =  "<<pp.name(1)<<endl;
   cout<<"name2 =  "<<pp.name(2)<<endl;
   cout<<"sex  "<<pp.sex()<<endl;
   cout<<"age  "<<pp.age()<<endl;

 }
