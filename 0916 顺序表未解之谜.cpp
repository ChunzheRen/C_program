//������ʵ�ö���ָ�뻹��һ��ָ������һ��˳���ĳ�ʼ�����ǿ��Եġ� 
#include <stdio.h>
#include <stdlib.h>
#define LISTSIZE 10
typedef int ElemType;
typedef struct List{
	ElemType *elem;
	int length;
	int listsize;  
}List,*Sqlist;

int InitList(Sqlist *L){ 
	(*L) =(Sqlist)malloc(sizeof(Sqlist)); 
	(*L)->elem=(ElemType*)malloc(sizeof(ElemType)*LISTSIZE);
	if (!(*L)->elem)  return -1;
	(*L)->length=0;
	(*L)->listsize=LISTSIZE;
}
int main(){
	Sqlist La=NULL; //����ȷ���ռ䣬������Σ�ա� 
	InitList(&La);
}

// A linked list is a list that has no nodes and it can
// be initialised when it is defined: List *La = NULL;
//Ȼ����Ҫ�ó�ʼ��������ֱ�ӽ���NULL�����ˣ��� 
