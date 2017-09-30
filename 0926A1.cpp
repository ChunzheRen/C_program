#include<stdio.h> 
#include<stdlib.h>
typedef int ElemType;
typedef struct Node{
	struct Node *next;
	struct Node *prev;
	ElemType data; 
}LNode;

typedef struct List{
	struct Node* prev; 
	struct Node* next; 
	int size;
}LinkList; 

int InitList(LinkList *L) {
	L = (LinkList*)malloc(sizeof(struct List));
	if(!L) return -1;
	L->next = L->prev =NULL;
	L->size=0;   //没有头结点 
	printf("maybe initialized.\n");
	return 0;
}
int main(){
	LinkList LA;
	InitList(&LA);
	printf("%d\n",LA.size);
	}
