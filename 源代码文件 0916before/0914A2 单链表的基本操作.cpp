//单链表的应用操作 
#include<stdio.h> 
#include<stdlib.h>
#include<malloc.h>
#include <typeinfo.h>
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;
//返回一个int用于表明状态 
int InitList(LinkList *L){//创建一个结点，作为头结点。其实就是插入一个头结点。 
	L = (LinkList*)malloc(sizeof(struct LNode)); 
	if(!*L)  return -1;//不给你空间 
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

//应该还是有问题吧 
 









