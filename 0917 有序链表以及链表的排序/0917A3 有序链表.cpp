//这个链结点插到前面即可.需要注意的就是插入在头部和尾部的特殊处理.
//就是链表的插入问题一般的都是当前位置的插入，但是也存在则头结点插入或者尾结点插入的情况

//总体上讲就是4个情况的选择。 

#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

int InitList(LinkList*L){
	(*L)=(LinkList)malloc(sizeof(struct LNode));
	if (!(*L))  return -1;
	(*L)->next =NULL;
	(*L)->data =0;
}
//一共四种情况。 
int Insert(LinkList *L,ElemType e){
	LinkList node =(LinkList)malloc(sizeof(struct LNode));
	node->data =e;
	
	LinkList pt =(LinkList)malloc(sizeof(struct LNode));
	pt=(*L)->next; //pt指向的是第一个位置 
	
	LinkList prev =(LinkList)malloc(sizeof(struct LNode));
	
	if (!(pt)){
		(*L)->next = node;
		(*L)->data+=1;
		free(pt);
		return 0;
	}
	//处理一下头指针
	if (((*L)->next->data)>(node->data)){
		node->next = pt;
		(*L)->next =node;
		(*L)->data+=1;
		free(pt);
		return 0;
	}
	
	while(pt && ((pt->data)<(node->data))){
		prev =pt;
		pt=pt->next;
	}
	
	if(!pt){//到达了最后的位置 
		prev->next =node;
		node->next =NULL;
	}
	else {//这个是最常见的情况。 
		node->next =prev->next;
		prev->next =node;
	}
	(*L)->data+=1;
	free(pt);
	return 0;
}

int Display(LinkList L){
	LinkList pt =(LinkList)malloc(sizeof(struct LNode));
	pt =(L)->next;
	while (pt){
		printf("%d__",pt->data);
		pt=pt->next;	
	}
	free(pt);
	printf("\n");
	return 0;
}

int ListTraverse(LinkList L){
	LinkList pt=(LinkList)malloc(sizeof(struct LNode));
	pt=L->next;
	while(pt){
		printf("%d",pt->data);
		pt = pt->next;
	}
	return 0;
}

int main(){
	LinkList La=NULL;
	InitList(&La);
	ElemType *e=(ElemType*)malloc(sizeof(ElemType));
	while (scanf("%d",e)){
		Insert(&La,*e);
		Display(La);
	}
	free(e);
	Display(La);
	return 0;
}
//遇到了打印错误的问题。。。 
