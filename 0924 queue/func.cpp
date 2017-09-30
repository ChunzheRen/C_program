//FIFO队列 //链表型 队列 不循环 
 
#include <stdio.h> 
#include <stdlib.h>
#include <typeinfo.h>
#include <string.h>

typedef int ElemType;
typedef struct Node{
	ElemType data;
	struct Node *next;
}Node,*QNode;
typedef struct Queue{
	QNode front;
	QNode rear;
	int data;
}Queue,*SqQueue;
//给指针分配QNode空间应该是不对的把。 
int InitQueue(SqQueue* Q){
	(*Q)=(SqQueue)malloc(sizeof(struct Queue));
	QNode newNode=(QNode)malloc(sizeof(struct Node));
	(*Q)->front=(*Q)->rear =newNode;
	newNode->next=NULL;
	//NULL到底是啥，我不知道，但是我知道的是肯定是一个固定的空间，然后也不是空的 。 
	if(!(*Q)->front) return -1;
	(*Q)->data=0;
	//刚才仅仅是创建了一个空的结点，以后才是说分配了一个指向。 
	return 0;
}//???一直没有搞清楚到底这个指向NULL的意思所在？？ 

int QueueEmpty(SqQueue Q){
	if ((*Q).front==(*Q).rear) return 1;
	else return 0;
}

int PushHead(SqQueue *Q,ElemType e) {
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
	(*newNode).data =e;
	(*newNode).next=(*Q)->front;
	(*Q)->front = (newNode);
	(*Q)->data++;
	return 0;
}

int PushTail(SqQueue *Q,ElemType e){
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
	(*newNode).data =e;
	(*newNode).next=NULL;
	(*Q)->rear = (newNode);
	(*Q)->data++;
	return 0;
}

int QueueTraverse(SqQueue Q){
	if (QueueEmpty(Q)) {
		printf("Empty Queue\n");
		return -1 ;
	}
	
	QNode pt =(QNode)malloc(sizeof(struct Node));
	pt =(*Q).front;
	while((*pt).next) {
		printf("%d__",(*pt).data);
		pt=pt->next;
	}
	return 0;
}


//int ClearQueue(Queue *Q);
//和destroy的区别就是自己到底是不是释放了头结点 



int Pop(SqQueue *Q){
	ElemType e;
	//对于单链表还是需要从头开始找最后一个节点的，要是双链表就好了。 
	QNode prev=(QNode) malloc(sizeof(struct Node));
//	QNode pt=(QNode) malloc(sizeof(struct Node));
	QNode pt =(*Q)->front;
	
	if ((*Q)->data==1){
		(*Q)->front=(*Q)->rear;
		free(pt);
		free(prev);
		printf("Pop :%d\n",(*pt).data);
		(*Q)->data--;
		return 0;
	}
	
	int cts=1;
	while (cts<((*Q)->data)){
		*prev = *pt;
		pt=(*pt).next;
		cts++;
	}
	
	//pt指向了我们要释放的结点。 
	e =(*pt).data;
	(*Q)->rear=prev;
	(*prev).next =NULL;
	printf("pop %d\n",e);
	
	(*Q)->data--;
	free(pt);//强行释放结点。 
	free(prev);
	return e;
}

//这个队列默认是头插入，所以就很尴尬。。。。traverse的顺序是反的。。。。 
//对应着头边插的push，应该是从尾巴pop。 
int DestroyQueue1(SqQueue *Q){
	while((*Q)->front){
		(*Q)->rear=(*Q)->front->next;
		free((*Q)->front);
		(*Q)->front=(*Q)->rear;//这个时候已经不用再担心Q rear的问题了，反正就是个指针而已。 
	}
	printf("Queue destroyed.\n");
	free(Q);
	return 0; 
}

int DestroyQueue2(SqQueue *SQ){
 	int i=0;
 	int total =(*SQ)->data ;
 	while(i<total){
 		Pop(SQ);
 		printf("length:%d\n",(*SQ)->data);
 		i++;
	}
	free(SQ);
	printf("Queue destroyed.\n");
}//但是和方案一相比，不能确保free了。 


int main(){
	SqQueue SQ;
	InitQueue(&SQ);
	QueueTraverse(SQ);
	ElemType *e=(ElemType*)malloc(sizeof(ElemType));
	
	while(scanf("%d",e)){
		PushHead(&SQ,*e);
		printf("you have entered: %d\n",(*e));
	}
	printf("#A\n");
	QueueTraverse(SQ);
//	if (!(*SQ).rear->next){
//		printf("it is NULL\n");
//	}初步证明了一点：就是说NULL指针的确是存在的。

//	DestroyQueue2(&SQ);
//	QNode pt=(SQ)->rear;
//	printf("#A\n");
//	if (!(pt)){
//		printf("ok!\n");
//	}

//Destroy和SQ结合充分的体现了你这个free的威力有多大。。。
//free之后，整个列表的函数都没有了 

	free(e);
	return 0;
	
}


