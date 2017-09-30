//线性表1型
//2017年9月16日20:03:23
//基本实现了基本的功能，但是没能处理好类似于*LinkList的问题。 
#include <stdio.h>
#include <stdlib.h>

#define LISTSIZE 1000
#define LISTINCREMENT 10
typedef int ElemType;
typedef struct List{
	ElemType *elem;
	int length;
	int listsize;  
}List; //*Sqlist;

//MALLOC返回的是一个指向void的指针，然后把这个指针指向的空间赋值给另外一个指针
//所以，一个有空间的void指针，赋值给一个没有空间的指针。 

//2017年9月16日19:39:23 
//int InitList(List L){
//	L.elem =(ElemType*)malloc(LISTSIZE*sizeof(ElemType));
//	//保持左右类型一致。 
//	if(!(L.elem)) return -1;
//	L.length =0;
//	L.listsize =LISTSIZE;
//	return 0;
//}//不涉及L的空间的改变，不是真正的分配空间。不要使用 

//只要不是二重指针就不用-> 
int InitList(List *L){
	(*L).elem =(ElemType*)malloc(LISTSIZE*sizeof(ElemType));
	//保持左右类型一致。 
	if(!((*L).elem)) return -1;
	(*L).length =0;
	(*L).listsize =LISTSIZE;
	return 0;
}

int Display(List L) {
	int cts= 0;
	while(cts<L.length){
		printf("%d__",*(L.elem+cts));
		cts++;
	}
	printf("\nthat is all.\n");
	return 0;
}

int InsertTail(List *L,ElemType e){
	if (((*L).length)>((*L).listsize)){
		ElemType *p=(ElemType*)realloc((*L).elem,(LISTSIZE+LISTINCREMENT)*sizeof(ElemType));
		(*L).elem =p;
	}
	//涉及到空间的重新分配。
	*((*L).length+(*L).elem) = e;
	(*L).length+=1;
	
}

int main(){
	struct List Lb;
	InitList(&Lb);
	ElemType *pt =(ElemType*)malloc(sizeof(ElemType));
	while(scanf("%d",pt)){
		InsertTail(&Lb,*pt);
	}
	Display(Lb);
//	printf("length : %d\n",Lb.length);
//	ElemType *pt=(ElemType*)malloc(sizeof(int));
//	printf("input a number (q to quit..)\n") ;
//	while(scanf("%d",pt)){
//		InsertTail(&Lb,*pt);
//	}
//	printf("length : %d\n",(*Lb).length);
//	DisplayList(Lb);
	return 0;
}
