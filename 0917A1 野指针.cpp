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
      p = &a; // ע�� a �������� ��ֻ�����������У���������������У�������������test����
      
   }
     p->Func();  // p�ǡ�Ұָ�롱//�˴���p����Func()�ĵ��á� 
}


int main(){
	Test() ;
	return 0;
}
//һ�������������� 
