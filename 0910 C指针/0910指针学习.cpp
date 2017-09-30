//#指针作为函数参数时候，函数的使用。
//其实函数的参数传递方式又很多，指针传递，数值传递以及引用传递。
//我觉得在函数形式参数中，用&val表示的是地址，也就是要求你输入一个地址。

//用指针做参数和用引用传递参数的差别

//创建一个数组，把指针赋给它，看有没有变化。
//创建的这个数组？？和别的之间的关系？？ 
#include <stdio.h> 
typedef int ElemType;
typedef struct List{
	ElemType* elem;
	int length;
}List;
int array[10]=[1,2,3,4,5,6,7,8,9,10];
int GetElem (int [10]*array,int &e,){
	e= GetElem 
}
int main(){
}

//函数的参数有多种传递参数的方式，包括了引用以及参数以及按值。
//但是差别呢？
指针作为函数的参数  Sqlist *L
在函数的定义里面 ： (*L).length = number ; 

main中函数的参数： 
&pos是**ppointer的级别 
但是pos是*pointer的级别 

//int *ptr =&num;
//void func(int **foo);
//void func2(int *foo);
//int main(){
//	int *pointer =NULL;
//	void func(&pointer);
//	void func2(pointer);} 

以下是头指针与头结点的关系：


//定义结点的结构体
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;
//LinkList是一个指向struct LNode的指针， 
则定义LinkList L;时，L为链表的头指针。
L=(LinkList) malloc (sizeof(LNode)); //创建一个结点
此处返回给L的是一个指针，并且赋给了头指针。
L->next=null; //这里说明我创建了一个头结点，即同时运用了头指针和头结点。

struct A{
	
}B,*L; 
int main(){
	struct B List;
	List = (struct B) malloc(100);
	return 0;
}


val=(val_type)malloc(size) 
