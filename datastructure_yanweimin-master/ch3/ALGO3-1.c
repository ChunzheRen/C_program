/* algo3-1.c �����㷨3.1�ĳ��� */
typedef int SElemType; /* ����ջԪ������Ϊ���� */
#include "../ch1/c1.h"
#include "c3-1.h" /* ����˳��ջ */
#include "bo3-1.c" /* ����˳��ջ�Ļ������� */

void conversion() /* �㷨3.1 */
{ /* �������������һ���Ǹ�ʮ������������ӡ��������ֵ�İ˽����� */
	SqStack s;
	unsigned n; /* �Ǹ����� */
	SElemType e;
	InitStack(&s); /* ��ʼ��ջ */
	printf("n(>=0)=");
	scanf("%u", &n); /* ����Ǹ�ʮ��������n */
	while (n) /* ��n������0 */
	{
		Push(&s, n % 8); /* ��ջn����8������(8���Ƶĵ�λ) */
		n = n / 8;
	}
	while (!StackEmpty(s)) /* ��ջ���� */
	{
		Pop(&s, &e); /* ����ջ��Ԫ���Ҹ�ֵ��e */
		printf("%d", e); /* ���e */
	}
	printf("\n");
}

void main()
{
	conversion();
}