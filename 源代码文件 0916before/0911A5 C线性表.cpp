#include<stdio.h> 
#include<stdlib.h>

#define LISTSIZE 100
#define LISTINCREMENT 10

typedef int ElemType;
struct List{
	ElemType *elem;
	int length;
	int listsize;
}List,*Sqlist;//����List �����Ǹ�����һ������ �����Ժ���struct���� 
//int InitList() 
int main(){
	struct List *La;
	La =(struct List*)malloc(100);
	if(La){
		printf("initialized successfully");
	}
	return 0;
}
