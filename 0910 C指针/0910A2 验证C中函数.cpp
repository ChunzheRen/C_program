//验证 基于数组的顺序线性表里面的 函数的&和*的cpp文件。 
#include<stdio.h> 
#include <stdlib.h>
#define LISTSIZE 10
//对于struct（SQLIST作为标识符）的一个Alias ，也叫Sqlist. 
typedef struct Sqlist{
	int * Elem ;
	int length;
}Sqlist;

int InitList(Sqlist &L,int number=10,int number2=10){
	int* pointer =(int *)malloc(sizeof(int)*LISTSIZE);
	if(!pointer) return -1;
	(*(L).Elem) = *pointer;
	(L).length= number2;
	return 0;
}
//mmp *L是一个实际对象，(*L).Elem 又变成了一个指针。所以说number必须要用地址引用符号 
//但是InitList的本质问题在于，对于ElemList的初始化是要分配空间的？ 
 
//*L->length 和 *(L->length)的差别？？？ 

int IsEmpty(Sqlist &L){
	if(L.length>0){	
		printf("%d",L.length);
	}
	return 0;
}
int main(){
	Sqlist L;
	//最初的初始化是创建一个指向Sqlist的指针，
	//问题就是指针没有指向任何的实例对象。
	//严重问题就是关于引用和指针在函数中的情况。
	
//	(*L).elem 与 *(L.elem )的差别????? 
	InitList(L,10,10);
	IsEmpty(L);
	return 0;
}

//函数定义如果是指针，那么传入的参数就应该是参数地址。 &val;
//函数定义如果是参数，点用哪个的时候直接传入参数。     val;






