	//还是解决不了问题 
	//深入学习C语言之后，在解决问题 
	#include<stdio.h>
    #include <stdlib.h>
    #include <typeinfo.h>
    #define SIZE 5  
    typedef int ElemType;
    typedef struct Queue{
    	int front;
	    int rear;
    	ElemType *base;
    }SqQueue;
    
    //开始大规模换装一重指针 
    int InitQueue(SqQueue*Q){
	    (*Q).front=(*Q).rear=0;
    	(*Q).base=(ElemType*)malloc(SIZE*sizeof(ElemType));
    	if (!(*Q).base) return -1;
    	printf("perhaps initialized successfully.\n");
    	return 0;
    }
    	int  QueueTraverse(SqQueue Q){
		if ((Q.rear)%SIZE==(Q.front)%SIZE){
			printf("An Empty List.\n");
			printf("\n");
			return -1;
		}
		
		ElemType *pt=Q.base+Q.front;//e是指针，指向起始位置
		while(pt!=Q.base+Q.rear){
			printf("%d__",*pt);
			pt++;
		}
		printf("\n");
		return 0;
	}
	
    //要用一般的循环判断是不是空的，就需要一个元素始终是被空出来的。队列的可用内存永远是SIZE-1 
    int Push(SqQueue *Q,ElemType e){
    	if(((*Q).rear+1)%SIZE==((*Q).front)){
    		printf("it is full currently.Unable to Insert.\n");
    		return -1;
    	}
    	*((*Q).base+(*Q).rear)=e;
    	(*Q).rear=((*Q).rear+1)%SIZE;
    	return 0;
    }
    
    int Pop(SqQueue *Q){
    	if ((((*Q).rear)%SIZE)==(((*Q).front)%SIZE)){
    		printf("Don`t Need Pop.\n");
    		return -1;
		}
		int e;
    	e=*((*Q).base+(*Q).front);
    	(*Q).front=((*Q).front+1)%SIZE;
    	printf("Pop:%d\n",e);
    	//除了destroy之外，都不需要任何的free操作。 
    	return 0;
    }

//也就是被覆盖的结果，但是
//每一次都是把尾指针的位置和头指针的位置进行覆盖是比较奇怪的。 

int DestroyQueue(SqQueue*Q){
	free(Q->base);
	Q->front=Q->rear=0;
	return 0;
}
int ClearQueue(SqQueue*Q){
	Q->front=Q->rear=0;
	return 0;
}
int GetHead(SqQueue Q){
	if(Q.front==Q.rear){
		printf("An empty list.\n");
		return 0;
	}
	ElemType e;
	e=Q.base[Q.front];
	return e;
}
    int main(){
    	SqQueue SQ;
    	InitQueue(&SQ);
    	printf("time to input some certain elements to the Queue.\n");
    	
		ElemType *e=(ElemType*)malloc(sizeof(ElemType)); 
		QueueTraverse(SQ);
		while(scanf("%d",e)){
			Push(&SQ,*e);
			printf("you just entered :%d\n",*e);
			QueueTraverse(SQ);
		}
		while(SQ.front!=SQ.rear){
			Pop(&SQ);
		}
		QueueTraverse(SQ);
    	return 0;
    }

//(*Q).base +(*Q).rear is int*
//*((*Q).base +(*Q).rear) is int 
//使用二重指针和使用一重指针之间的差别还是很大的。但是都是对于地址的操作 ，然后一般的->和* .是 差不多的。
//你二重指针先解除引用 ，之后再进行->操作其实就是一重指针直接进行-> 

//所以说还是有必要让base是0，因为6%6是0 
