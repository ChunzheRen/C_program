//一个失败的线性表，但是还是可以勉强用用。 
//线性表 实现队列 使用数字作为指针，而不是纯正的指针对象
#include<stdio.h >
#include <stdlib.h>
#include <math.h> 
#define SIZE 5  
int SIZE =5;
//#define INCREMENT 2//网上的意思是循环队列是不可以进行扩大容积的，单纯就是一个移动头指针尾指针的情况。 
//typedef int int ;
typedef struct Queue{
	int front;
	int rear;//int更加具有指针的含义，而elemtype可能为char 
	int  *base;
}Queue,SqQueue;

int InitQueue(SqQueue*Q){
	(*Q).front=(*Q).rear = 0;
	(*Q).base =(int *)malloc(SIZE*sizeof(int ));
	if (!(*Q).base) return -1;
	printf("perhaps initialized successfully.\n");
	return 0;
}

int Push(SqQueue *Q,int  e){
	//判断满了，用头指针减一也是可以的。 
	if(((*Q).rear+1)%SIZE==((*Q).front)){
		printf("it is full currently.Unable to Insert.\n");
		return 0;//以后会扩容操作的。 
	}
	//尾指针一直是指向空白的插入位置。 
	//纯粹的指针赋值是需要直接用指针对象的，也就是把目标的地址值赋给指针作为指针的值。 
	*(((*Q).base+(*Q).rear)%  SIZE)=e;
	(*Q).rear=((*Q).base+(*Q).rear+1)%(int)SIZE;//因为是连续的内存所以可以++？？？但是逻辑循环。 
	return 0;
} //赋值，移动尾指针. 

int Pop(SqQueue *Q){
	int  e;
	e=(*Q).base[(*Q).front];
	(*Q).front=((*Q).base+(*Q).front-1)%(int)SIZE;
	return 0;
}

int QueueTraverse(SqQueue Q){
	int i=(Q).front;
	int j=(Q).rear;
	if(i==j) {
		printf("an Empty Queue.\n");
		return -1;
	}
	int  e;
	while(i!=j){
		e=(Q).base[i];
		printf("%d_",e);
		i=(i+1)%(int)SIZE;	
	}
	printf("\n");
	return 0;
}
int main(){
	SqQueue SQ;
	InitQueue(&SQ);
	QueueTraverse(SQ);
	Push(&SQ,1);
	Push(&SQ,2);
	Push(&SQ,3);
	QueueTraverse(SQ);
	Pop(&SQ);
	Pop(&SQ);
	Pop(&SQ);
	QueueTraverse(SQ);
	return 0;
}
