#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <typeinfo.h>
#define SIZE 5
#define INCREMENT 1
typedef char ElemType;
typedef struct Stack{
	ElemType *base;
	ElemType *top;
	int size;
}Stack,*SqStack;

int InitStack(SqStack *S){
	//老朋友了，就是SqStack没有被分配一个空间。
	*S = (SqStack)malloc(sizeof(struct Stack));
	if(!*S) return -1;
	
//	S= (*SqStack) malloc(sizeof(struct Stack)); 也能成功编译，但是感觉就不对，不是原本是副本。 
	(*S)->base =(ElemType*)malloc(sizeof(ElemType)*SIZE);
	if (!((*S)->base)) return -1;
	
	(*S)->top =(*S)->base;
	(*S)->size = SIZE;
	printf("Maybe successfully initialized.\n");
	return 0;
}
//一个是对于S自己空间的分配以及free操作。
//一个是对于链表和顺序表的工作指针的理解和操作 顺序表就是一个数组，所以说就是可以用指针运算来执行遍历Traverse操作。 

int ClearStack(SqStack *S){
	(*S)->top=(*S)->base;
//	*(*S)->base =0;
	return 0;
}

int DestroyStack(SqStack *S){
//	if ((*S)->base) free((*S)->base);
///单纯的改变而不释放内存是不对的。 
	(*S)->base = NULL;
	(*S)->top =NULL;
//	free(*S); //有点危险 S无内存 
	printf("the stack is destroyed.\n");
	return 0;
}
//定义base的位置是1. //对于线性表来说，找到一个元素是O(n)。 
ElemType GetTop(SqStack S,int pos){
	return *(S->base+pos);//return *(S->top-1);
}//还要继续试验才可以知道最终的结果 //这个不是gettop，而是getposition. 

int LocateElem(SqStack S,ElemType e){
	ElemType *pt =(ElemType*)malloc(sizeof(ElemType));
	pt = S->base;
	int pos = 0;
	while(pt != (S->top)){
		if (e==*pt)	return pos;
		pt++;
		pos++;
	}
	free(pt);
	return 0;
} 

int Push(SqStack *S,ElemType e){
	if (((*S)->top-(*S)->base)>=(*S)->size){
		ElemType* newSqList =(ElemType*)realloc((*S)->base,sizeof(ElemType)*(SIZE+INCREMENT));
		if (!*newSqList) return -1;
		(*S)->base=newSqList;
		(*S)->top =(*S)->base+(*S)->size;
		(*S)->size+=INCREMENT;
	}///其实对于上述的realloc还是有点没谱。。。。 
//	*((*S)->top) =e;
//	(*S)->top++;
	
	*(*S)->top++=e;//： 

//	*++(*S)->top=e;//应该是先++了，error 
	
	return 0;
}
//注意top指针指向的是最后一个数据元素的下一个。 
ElemType Pop(SqStack *S){
	ElemType e =*((*S)->top-1);
	(*S)->top= (*S)->top-1;
	printf("%d",e);
	return e;
}
//从第一个元素开始遍历，也就是从base开始向上到top。 
int StackTraverse(SqStack S){
	while (S->base != S->top){
		printf("%d__",int(*(S->base)));
		S->base++;
	}
	printf("\n");
	return 0;
}
//使用强制新类型转化实现变量的重新使用。 
int StackEmpty(SqStack S){
	if (S->base==S->top){
//		printf("An empty Stack\n");
		return 0;
	}
	else{
//		printf("Not empty\n");
		return 1;
	}
}
int func(){
	SqStack Sa;
	InitStack(&Sa);
	ElemType ch;
	//实现全部输入，多次输出 
	while(ch=getchar()!=EOF){
		while (ch!= EOF && ch!= '\n'){
			switch(ch){
				case '#':Pop(&Sa) ;
				case '@':ClearStack(&Sa);
				default:
					Push(&Sa,ch) ;
			}
			printf("\n#A\n");
			while(Sa->base!=Sa->top){
				ElemType ch = Pop(&Sa);
				printf("%c\n",ch);
				printf("#B\n");
			}
			ClearStack(&Sa);
		}
	}
	return 0;
}
int main() {
	func();
	return 0;
}
