//���Ա�  Listʵ�ַ�ʽ  
#include<stdio.h>
#include <stdlib.h>
#include <typeinfo.h>
#define LISTSIZE 1000
#define LISTINCREMENT 10
//��������Ļ�����������Ҫ��Ϥָ����ƶ��Լ�����Ŀ��� 
typedef int ElemType;
typedef struct A{
	ElemType *elem;
	int length;
	int listsize; //sizeof(ElemType)Ϊ��λ���в����� 
}List,*Sqlist;

int InitList (List*L){
	(*L).elem = (ElemType*)malloc (sizeof(ElemType)*LISTSIZE);
	if (!((*L)->elem)) return -1;
	(*L).length =0;
	(*L).listsize =LISTSIZE;
	return 0;
}
int DestroyList(List *L){
	if ((*L)->elem) free (*L)->elem;//��Ϊ˳����������һ���ڴ����һЩ���εĶ�������һ��struct��
//	Ȼ�� ���������㸺�������������ڴ�͹��ˡ� 
	(*L)->length =0;
	(*L)->listsize =0;
	return 0 ;
}
