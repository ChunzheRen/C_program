///一元多项式
//单链表实现 
#include <stdlib.h> 
#include <stdio.h>
#include <typeinfo.h>
typedef int ElemType ;
typedef struct LNode{
	ElemType coefficient;
	ElemType index;
	struct LNode* next; 
}LNode,*LinkList;

//LinkList是一次指针的形式，而LinkList*是二次指针的形式。 
int InitList(LinkList *L){
	//L解除引用之后返回的是一个一次指针。 
	//*L 应该分配的是 LinkLIst类型的东西。 
	(*L)=(LinkList)malloc(sizeof(struct LNode)); 
	(*L)->index =0;
	(*L)->coefficent=0; //用来记录总共的系数的多少。
	return 0; 
}
//返回特定位置的系数和指数 
int GetElem(LinkList *L,int pos){
}
int LocateElem(LinkList *L,int e){
}
int Display(LinkList L){
}
LinkList Multiply(LinkList La,LinkList Lb){
}
LinkList Plus(LinkList La,LinkList Lb){
}
LinkList Substract(LinkList La,LinkList Lb){
}
int InsertElem(LinkList *L){
}
int CreateList(LinkList *L){
}
//主要过程：对比指数的大小，以及对应的操作。
//当然也可以把其中一个La作为参数修改的对象。 



