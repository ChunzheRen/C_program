//线性表  List实现方式  
#include<stdio.h>
#include <stdlib.h>
#include <typeinfo.h>
#define LISTSIZE 1000
#define LISTINCREMENT 10
//对于链表的基本操作就是要熟悉指针的移动以及数组的控制 
typedef int ElemType;
typedef struct A{
	ElemType *elem;
	int length;
	int listsize; //sizeof(ElemType)为单位进行操作。 
}List,*Sqlist;

int InitList (List*L){
	(*L).elem = (ElemType*)malloc (sizeof(ElemType)*LISTSIZE);
	if (!((*L)->elem)) return -1;
	(*L).length =0;
	(*L).listsize =LISTSIZE;
	return 0;
}
int DestroyList(List *L){
	if ((*L)->elem) free (*L)->elem;//因为顺序表里面就是一个内存加上一些修饰的东西构成一个struct。
//	然后 ，基本上你负责处理这个数组的内存就够了。 
	(*L)->length =0;
	(*L)->listsize =0;
	return 0 ;
}
