//�������Ӧ�ò��� 
#include<stdio.h> 
#include<stdlib.h>
#include<malloc.h>
#include <typeinfo.h>
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;
//����һ��int���ڱ���״̬ 
int InitList(LinkList *L){//����һ����㣬��Ϊͷ��㡣��ʵ���ǲ���һ��ͷ��㡣 
	L = (LinkList*)malloc(sizeof(struct LNode)); 
	if(!*L)  return -1;//������ռ� 
	(*L)->next=NULL;
	(*L)->data =0;
	printf("successfully initialized.\n");
	return 0; 
}
LinkList MergeList(LinkList *La,LinkList *Lb){
	LinkList pt = (LinkList)malloc(sizeof(struct LNode));
	LinkList pa=(*La)->next;
	LinkList pb=(*Lb)->next;
	LinkList newL;
	InitList(&newL);
	InitList(&newL);
	free(pt);
	return newL;
}
int DisplayList(LinkList L){
	LinkList p =L->next;
	int cts =1;
	while(p && cts<L->data){
		printf("%d--",cts,p->data);
		p= p->next;
		cts++; 
	}
	printf("that is all.\n");
	return 0;
}
int main(){
	LinkList L;
	InitList(&L);
	DisplayList(L);
	return 0;
}

//Ӧ�û���������� 
 









