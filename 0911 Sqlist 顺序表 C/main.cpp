#include <stdio.h>
#include <stdlib.h>
#include <typeinfo.h>
typedef int ElemType;
#include "func.h"
#include "func.cpp"

int main(){
	Sqlist La; 
//	Sqlist Lb;
	int e;
	ElemType E;
	 
	InitList (&La);
	if(!La.elem) printf("successfully initialized\n");
	ListEmpty(&La);
	
	ListLength(&La);
	//为何当前输出的是一个47？？？我觉得应该是400啊。。。。。。 
	
	for (int i=0;i<10;i++){
		//下一步是实现一个输入EOF才停止的程序。 
		printf("input a number:\n");
		scanf ("%d",&e);
		E =ElemType(e);
		InsertElem(&La,i,E);
	}
	//为啥运行三次之后就GG,应该是存储空间的问题。 
	for (int i =0;i<10;i++) {
		ElemType E =*((La).elem +i);
		int e =  int(E);
		printf("the %d elem is:%d\n",i,e);
	}
	ListLength(&La);
	printf("congratulations\n");
	return 0;
	//线性表的transverse功能。 
}

