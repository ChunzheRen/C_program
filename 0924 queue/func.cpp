//FIFO���� //������ ���� ��ѭ�� 
 
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
//��ָ�����QNode�ռ�Ӧ���ǲ��Եİѡ� 
int InitQueue(SqQueue* Q){
	(*Q)=(SqQueue)malloc(sizeof(struct Queue));
	QNode newNode=(QNode)malloc(sizeof(struct Node));
	(*Q)->front=(*Q)->rear =newNode;
	newNode->next=NULL;
	//NULL������ɶ���Ҳ�֪����������֪�����ǿ϶���һ���̶��Ŀռ䣬Ȼ��Ҳ���ǿյ� �� 
	if(!(*Q)->front) return -1;
	(*Q)->data=0;
	//�ղŽ����Ǵ�����һ���յĽ�㣬�Ժ����˵������һ��ָ�� 
	return 0;
}//???һֱû�и�����������ָ��NULL����˼���ڣ��� 

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
//��destroy����������Լ������ǲ����ͷ���ͷ��� 



int Pop(SqQueue *Q){
	ElemType e;
	//���ڵ���������Ҫ��ͷ��ʼ�����һ���ڵ�ģ�Ҫ��˫����ͺ��ˡ� 
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
	
	//ptָ��������Ҫ�ͷŵĽ�㡣 
	e =(*pt).data;
	(*Q)->rear=prev;
	(*prev).next =NULL;
	printf("pop %d\n",e);
	
	(*Q)->data--;
	free(pt);//ǿ���ͷŽ�㡣 
	free(prev);
	return e;
}

//�������Ĭ����ͷ���룬���Ծͺ����Ρ�������traverse��˳���Ƿ��ġ������� 
//��Ӧ��ͷ�߲��push��Ӧ���Ǵ�β��pop�� 
int DestroyQueue1(SqQueue *Q){
	while((*Q)->front){
		(*Q)->rear=(*Q)->front->next;
		free((*Q)->front);
		(*Q)->front=(*Q)->rear;//���ʱ���Ѿ������ٵ���Q rear�������ˣ��������Ǹ�ָ����ѡ� 
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
}//���Ǻͷ���һ��ȣ�����ȷ��free�ˡ� 


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
//	}����֤����һ�㣺����˵NULLָ���ȷ�Ǵ��ڵġ�

//	DestroyQueue2(&SQ);
//	QNode pt=(SQ)->rear;
//	printf("#A\n");
//	if (!(pt)){
//		printf("ok!\n");
//	}

//Destroy��SQ��ϳ�ֵ������������free�������ж�󡣡���
//free֮�������б�ĺ�����û���� 

	free(e);
	return 0;
	
}


