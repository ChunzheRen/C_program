//栈和队列，是操作受到限制的线性表，stack栈是仅仅在表尾进行插入或者删除的线性表（链表或者顺序表），表透视bottom，表卫视top。//后进先出，last in first out
//除了在stack top进行增删，还包括了初始化 判断空 取top元素
//顺序栈 SqStack
//非空栈的栈顶指针始终指向有元素的下一个位置上。 

//总体而言，stack是一个线性表，仅仅是插入方式的差别。 
#include<stdio.h>
#include <stdlib.h>
#define SIZE 5
#define INCREMENT 1
typedef int ElemType;
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
int StackEmpty(SqStack S){
	if(S->base =S->top) printf("Empty!\n");
	else printf("Not Empty!\n");
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
}//未知 

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
	//*--((*S)->top)
	return e;
}
//改进版，直接用SqStack会影响最终的数值。 
int StackTraverse(SqStack S){
	ElemType* pt =(ElemType*)malloc(sizeof(ElemType));
	pt=(S)->base;
	while (pt!=(S->top)){
		printf("%d__",*pt);
		pt++;
	}
	printf("\n");
	return 0;
}
int main(){
	SqStack Sa;
	InitStack(&Sa);
	
	ElemType *e=(ElemType*)malloc(sizeof(ElemType));
	while (scanf("%d",e)){
		printf("you have entered : %d.\n",*e);
		Push(&Sa,*e);
	}
	free(e);
	StackTraverse(Sa);
	StackTraverse(Sa);
	return 0;
}

//2017年9月17日22:16:57
//是不是可以用链表来写这个stack
//还有就是关于top指针的操作，（*S）->top -(*S)->base = Stack中的元素数目。因为top指向的是最后一个元素的后面。 指针的运算。 
//关于Destroy的操作，为什么没办法释放内存？？？unable to free  
//代码中没有对S自己分配内存啊，但是就能运行。。。。。很迷。。 
//如何检验指针的指向的空间是不是被释放了，还是说单纯的改变了指向？？？
//类似的都是，clear就是把内存里面的东西清空，但是destroy是完全的归还内存
//clear的操作就是单纯的top=base 
//元素的长度就是  S.top-S.base操作。
//S.top-1就是最上面的元素。 

///StackTraverse没法做两次是神魔鬼啊。。。。。 
///你改变了base的指向？？但是是副本传递参数啊。。。 
//难道说SqStack就是一次指针，其实也是可以改变对象的，
//而SqStack不仅仅是为了改变对象，更多的是为了改变内存地址？？？

//不是很懂二次指针， 

