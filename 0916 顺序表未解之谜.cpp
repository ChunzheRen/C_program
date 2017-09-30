//所以其实用二次指针还是一次指针声明一个顺序表的初始化都是可以的。 
#include <stdio.h>
#include <stdlib.h>
#define LISTSIZE 10
typedef int ElemType;
typedef struct List{
	ElemType *elem;
	int length;
	int listsize;  
}List,*Sqlist;

int InitList(Sqlist *L){ 
	(*L) =(Sqlist)malloc(sizeof(Sqlist)); 
	(*L)->elem=(ElemType*)malloc(sizeof(ElemType)*LISTSIZE);
	if (!(*L)->elem)  return -1;
	(*L)->length=0;
	(*L)->listsize=LISTSIZE;
}
int main(){
	Sqlist La=NULL; //最好先分配空间，否则会很危险。 
	InitList(&La);
}

// A linked list is a list that has no nodes and it can
// be initialised when it is defined: List *La = NULL;
//然后不需要用初始化函数，直接进行NULL就行了！？ 
