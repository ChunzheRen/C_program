//双链表 
//2017年9月14日16:39:25
 
#include<stdio.h> 
#include<stdlib.h>
#include <typeinfo.h>
typedef int ElemType;
typedef struct DNode {  //定义双链表结点类型
    ElemType data;  //数据域
    struct DNode *prev, *next;  //前驱和后继指针
}DNode, *DLinklist;

int InitList(DLinklist *L){
	*L= (DLinklist )malloc(sizeof(struct DNode));
	if(!(*L)) return -1;
	(*L)->data = 0;
	(*L)->next = NULL;
	(*L)->prev = NULL;
	printf("successfully initialized.\n");
	return 0;
}

int HeadInsert(DLinklist *L,ElemType e){
	DLinklist p = (DLinklist) malloc(sizeof(struct DNode));
	DLinklist q = (DLinklist) malloc(sizeof(struct DNode));
	q = (*L)->next;
	
	p->data=e;
	p->next = q;
	p->prev =(*L);
	
	(*L)->next =p;
	(*L)->data+=1;
	return 0;
}
int DisplayList(DLinklist *L){
	if(!(*L)->next) {
		printf("Empty List.\n");
		return -1;
	}
	DLinklist p = (DLinklist) malloc(sizeof(struct DNode));
	//问题就是没有去讲指针指向一个位置。
	p = (*L) ->next;
	int cts =1;
	while(cts<((*L)->data+1)) {
		printf("%d--",cts,p->data);
		p = p->next;
		cts++;
	}
	free(p);
	printf("");
	printf("that`s all.\n");
	//所以就是没有进行空间的释放，然后IDE就去报错。 
	return 0;
}
ElemType LocateElem(DLinklist *L,int pos){
	DLinklist p =(DLinklist)malloc(sizeof(struct DNode));
	p= (*L)->next; 
	int cts=1;//计数器和指针是必须的
	ElemType e;
	while (cts<(*L)->data) {
		p= p->next;
		cts ++;	
	}
	e= p->data;	
	free(p);
	printf("the elem is %d",ElemType(e));
	return e;
}
int GetElem(){
	DLinklist p =(DLinklist)malloc(sizeof(struct DNode));
	
	free(p);
	return 0;
}
int DeleteElem(DLinklist *L,int pos){
	DLinklist p =(DLinklist)malloc(sizeof(struct DNode));
	free(p);
}
int main(){
	DLinklist La;
	InitList(&La);
	
	//第一个就是到底是不是需要用malloc，但是感觉单纯的分配一个变量就行啊。 
	printf("input an int(input 'q' to quit).\n");
	int ct=1;
	//scanf返回的东西是一个整数，标识的是  输入的状态 
	ElemType e;
	ElemType *p=&e;
	while (scanf("%d",p)){
		
		printf("Elem No.%d : %d\n",ct,e);
		HeadInsert(&La,*p);
		ct+=1;
	}
	free(p);
	
//	LocateElem(&La,2);
	//问题在下面 
//	DisplayList(&La);
	DLinklist p=(DLinklist) malloc (sizeof(struct DNode));
	p=(*L)->data;
	return 0;
}
