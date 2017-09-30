#include<iostream>
using namespace std;
class A 
{      
public:
     void Func(void){ cout <<"Func of class A"<< endl; }
};


void Test(void)
{
    A *p;
   {
      A a;
      p = &a; // 注意 a 的生命期 ，只在这个程序块中（花括号里面的两行），而不是整个test函数
      
   }
     p->Func();  // p是“野指针”//此处是p对于Func()的调用。 
}


int main(){
	Test() ;
	return 0;
}
//一切正常啊。。。 
