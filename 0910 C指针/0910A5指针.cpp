#include<stdio.h>
void Exchg2(int *px, int *py)
{
//int * �ڶ����еı���������ָ���õġ�
//Ȼ���ڱ��ʽ�е�*������������õģ�������û�ö�Ӧ��d��ַ��Ҳ���Ǽ�����÷��š� 
   int tmp = *px;
   *px = *py;
   *py = tmp;
   printf("*px = %d, *py = %d.\n", *px, *py);
}

int main()
{
   int a = 4;int b = 6;
   Exchg2(int* px= &a,int *py = &b);
   //ʵ�ʵĲ�����������Ҫ�õ�ַ���÷��� ��ȡ��ַ���ţ���������ָ��Ҫ����һ����ַ int *pointer= & number������ pointer =&number �� 
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
//����һ��ʵ�ʵ����������ݣ����յ�ַ���� ��������ֵ���ݡ�

//Ҫʵ�ʿ��ǵ�storage duration && scope �Լ� linkage
