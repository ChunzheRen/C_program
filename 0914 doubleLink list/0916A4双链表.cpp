//双链表 
#include <stdio.h>
#include <stdlib.h>
#define LISTSIZE 100
typedef int ElemType;
typedef struct LNode{
	LNode *head;
	LNode *next;
	ElemType data;
}LNode,*LinkList;

int InitList(LinkList *L){
	(*L) =(LinkList)malloc(sizeof(struct LNode)*LISTSIZE);//相当于是给一个节点分配了空间。
	(*L)->head=(*L);
	(*L)->next =(*L);
	(*L)->data =0;
	return 0;
}

int DestroyList(LinkList *L){
	
}

int ClearList(LinkList *L){
	
}

//其实insert是要考虑空间是不是够用的 
int InsertPos(LinkList *L){
	
}

int InsertList(LinkList L,ElemType e,int pos){
	while
}

int GetElem(LinkList L){
	
}

int LocateElem(LinkList L){
	
}

int Display(LinkList L){
	int cts=0;
	LinkList pt =(LinkList)malloc(sizeof(struct LNode));
	pt = L->next;
	while(cts<L->data){
		printf("%d__",pt->data);
		pt=pt->next;
		cts++;
	}
	free(pt);
	printf("\nthat is all.\n");
	return 0;
}

int main(){
	LinkList La;
	InitList(&La);
	ElemType *pt;
	while (scanf("%d",pt)){
		InsertList(&La,*pt);
	}
	printf("starting display list.\n");
	Display(La);
	return 0;
}
