#include<stdio.h>
void Exchg2(int *px, int *py)
{
//int * 在定义中的变量是声明指针用的。
//然后在表达式中的*是用来解除引用的，解除引用获得对应的d地址，也就是间接引用符号。 
   int tmp = *px;
   *px = *py;
   *py = tmp;
   printf("*px = %d, *py = %d.\n", *px, *py);
}

int main()
{
   int a = 4;int b = 6;
   Exchg2(int* px= &a,int *py = &b);
   //实际的参数输入是需要用地址调用符号 （取地址符号），声明的指针要输入一个地址 int *pointer= & number；或者 pointer =&number ； 
   printf("a = %d, b = %d.\n", a, b);
   return(0);
}

void Exchg3(int &x, int &y)
{
   int tmp = x;
   x = y;
   y = tmp;
   printf("x = %d,y = %d\n", x, y);
}
main()
{
   int a = 4;
   int b = 6;
   Exchg3(a, b);
   printf("a = %d, b = %d\n", a, b);
   return(0);
}
//按照一个实际的引用来传递，按照地址传递 ，按照数值传递。

//要实际考虑到storage duration && scope 以及 linkage
