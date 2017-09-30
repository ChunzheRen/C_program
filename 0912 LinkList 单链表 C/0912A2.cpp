#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>>

typedef int ElemType ;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

int InitList(LinkList*L){
	(*L) =(LNode*)malloc(sizeof(struct LNode));
	(*L) =(LinkList)malloc(sizeof(strcut LNode));
	
}

