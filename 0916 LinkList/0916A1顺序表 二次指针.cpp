//线性表 *Sqlist 实现方式 
//主要就是需要用->而不是. 还有就是malloc分配空间方面的不同
//感觉程序的问题大多数是源自于空间分配的问题， 
#include <stdio.h>
#include <stdlib.h>
#include <typeinfo.h>
#define LISTSIZE 1000
#define LISTINCREMENT 10
//对于链表的基本操作就是要熟悉指针的移动以及数组的控制 
typedef int ElemType;
typedef struct List{
	ElemType *elem;
	int length;
	int listsize; //sizeof(ElemType)为单位进行操作。 
}List,*Sqlist;
//List 和 Sqlist都不是对象，而是需要实例化的操作。 
//size就是用来判断总体大小的，然后length就是用来判断总体的长度的。 
//分配给L的仅仅是一个地址。 
//线性表示一块连续的内存，只不过额外有两个区域是length和listsize 
int InitList(Sqlist *L){
	(*L)->elem = (ElemType*)malloc(sizeof(int)*LISTSIZE);
	//分配空间一定要用基本类型,不要用Sqlsit 
	//然后关于，malloc的返回是一个void*类型。也就是指针类型。由于Sqlist自己就是指针，所以不用再说。 
	//对于线性表，正确的方式是给elem分配空间，而不是给Sqlist分配空间。 
	if(!(*L)->elem) return -1;
	(*L)->elem =0;
	(*L)->length =0;
	(*L)->listsize =LISTSIZE;
	return 0;
}

int DestroyList(Sqlist *L){
	if((*L)->elem)    free((*L)->elem);
//	(*L)->elem =NULL;其实是不重要的 
	(*L)->length =0;
	(*L)->listsize =0;
	return 0;
}
//其实是不用担心内存中还有元素的，因为数组本身就是可修改。
//然后就是单纯把表的地址换成那个length就可以了。
//与destroy存在本质差别 
int ClearList(Sqlist *L){
	(*L)->length =0;
	return 0;
}

//尾端插入元素  
int InsertTail(Sqlist *L,ElemType e){
	printf("#B\n");
	ElemType *p = (*L)->elem+(*L)->length;
	*p = e;
	printf("#c\n");
	(*L)->length=(*L)->length+1;
	return 1;
}

int DisplayList(Sqlist L){
	if (L->length==0) {
		printf("an empty list.\n");
		return -1;	
	}
	int cts=0;
	for (;cts<L->length;cts++){
		printf("%d_",L->elem+cts);
	}
	printf("that is all.\n");
	return 0;
}
int main(){
	Sqlist Lb;
	InitList(&Lb);
//	printf("length : %d\n",(*Lb).length);
//	ElemType *pt=(ElemType*)malloc(sizeof(int));
//	;//指针需要被分配空间的。 
//	printf("input a number (q to quit..)\n") ;
//	while(scanf("%d",pt)){
//		InsertTail(&Lb,*pt);
//	}
//	printf("length : %d\n",(*Lb).length);
//	DisplayList(Lb);
	return 0;
}

