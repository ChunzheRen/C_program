/* main2-7.c ����bo2-7.cpp�������� */
#include "../ch1/c1.h"

#include "c2-6.h"
#include "bo2-7.c"
void main()
{
	polynomial p, q;
	int m;
	printf("�������һ��һԪ����ʽ�ķ�����ĸ�����");
	scanf("%d", &m);
	CreatPolyn(&p, m);
	printf("������ڶ���һԪ����ʽ�ķ�����ĸ�����");
	scanf("%d", &m);
	CreatPolyn(&q, m);
	AddPolyn(&p, &q);
	printf("����һԪ����ʽ��ӵĽ����\n");
	PrintPolyn(p);
	printf("�����������һԪ����ʽ�ķ�����ĸ�����");
	scanf("%d", &m);
	CreatPolyn(&q, m);
	AddPolyn1(&p, &q);
	printf("����һԪ����ʽ��ӵĽ��(��һ�ַ���)��\n");
	PrintPolyn(p);
	printf("��������ĸ�һԪ����ʽ�ķ�����ĸ�����");
	scanf("%d", &m);
	CreatPolyn(&q, m);
	SubtractPolyn(&p, &q);
	printf("����һԪ����ʽ����Ľ����\n");
	PrintPolyn(p);
	printf("����������һԪ����ʽ�ķ�����ĸ�����");
	scanf("%d", &m);
	CreatPolyn(&q, m);
	MultiplyPolyn(&p, &q);
	printf("����һԪ����ʽ��˵Ľ����\n");
	PrintPolyn(p);
	DestroyPolyn(&p);
}