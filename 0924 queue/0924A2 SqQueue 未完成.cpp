//�����Ͷ��� ��ѭ�� ͷ���� β����� ͷ���
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
	QNode head;
	QNode tail;
}Queue,*SqQueue;
//FIFO���� 

int InitQueue(SqQueue Q){
	(*Q).head=(*Q).tail =(QNode)malloc(sizeof(struct Node));
	//��仰��������Q��head��tail�����˿ռ䣬������tail��headָ����ͬһ��λ�á� 
	if(!(*Q).head) {
		printf("unable to initialized.\n");
		return -1;	
	}
	((*Q).head)=NULL;//�ղŽ����Ǵ�����һ���յĽ�㣬�Ժ����˵������һ��ָ�� 
	printf("maybe successfully initialized.\n");
	return 0;
}

int Push(SqQueue Q,ElemType e) {
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
	(*newNode).data =e;
	(*newNode).next=((*Q).head);
	((*Q).head) = (newNode);
	return 0;
}

ElemType Pop(SqQueue Q){
	if(Q->head==Q->tail) {
		printf("nothing to pop");
		return 0;
	}
	//���ڵ���������Ҫ��ͷ��ʼ�����һ���ڵ�ģ�Ҫ��˫����ͺ��ˡ� 
//	struct Node *prev=(struct Node*) malloc(sizeof(struct Node));
	struct Node *pt=((*Q).head);//���ȣ��������ֲ��뷽����ͷ����Ժ����ж����ġ� 
	struct Node *prev ;
	//����ж���������˵�. 
	while (pt->next){   
	
	
		//////////////////////////////////////////////////////////////////////////////////////////// 
		prev = pt;//prevָ��pt�ղŵĵط��� ///����pt��prev �� pt*��prev*�Ĳ���������һ���Ƕ��󣬽������֮���������һ����ַ��Ҳ����˵&pt=address of pointer����*pt=the address pt pointed to��
//		��*pt ����*prev  �����߼�����//pay special attention�� 
 
 
 		///////////////////////////////////////////////////////
		pt=pt->next;//mmp����������������������pt++; 
		
		
		
		
	}//��������ʱ��ptָ��������һ�������ݵĽ�㣿������β��㣬��û�����ݵĽ�㡣//���ԣ����ܻ���Ҫ��cts�����жϡ� 
	
	ElemType e =(*pt).data;
	((*Q).tail)=prev;//////////////////�������ָ�ֵ��ë���� 
	(*prev).next =NULL; //ɾ����� 
	
	free(pt);//��������һ��ɾ�����Ĳ�����  ��ȷ��ɾ���˽�� 
	printf("Pop:%d\n",e);
	return e;
}

int QueueEmpty(SqQueue Q){
	if ((*Q).head==(*Q).tail) return 1;
	else return 0;
}
//�������Ĭ����ͷ���룬���Ծͺ����Ρ�������traverse��˳���Ƿ��ġ������� 
//ע�⣺������ͷ���룬����β�����ʵ��û�����ݵġ�NO DATA. 
int QueueTraverse(SqQueue Q){
	if (QueueEmpty(Q)){
		printf("Empty One\n");
		exit(-1);
	}
	struct Node*pt =(struct Node*)malloc (sizeof(struct Node));
	pt=(*Q).head;
	while(pt){
		printf("%d__",(*pt).data);
		pt=pt->next;//����˵����pt++��Ϊ���ڱ��е�˳���������ģ�����˵Ҫ��next���и�ֵ�� 
	}
	printf("\n");
	return 0;
}
//�漰��ָ�룬��˵ľ���������Ͳ���Ӧ��������ָ������Ͳ���Ӧ���� 

//���ϵ���Pop������ɾ�� ,���ҽ���free 
int DestroyQueue(SqQueue Q){
	while ((Q->head)!=(Q->tail)){
		printf("here\n");
		Pop(Q);//�������pop�Ǵ�tail�ͷŰ���
		printf("here\n");
//		pt=pt->next;//һ��Ҫע����ָ��next���ַ�ʽ���� 
	}
	free(Q);
}
int ClearQueue(Queue *Q){
	
}
int main(){
	Queue Q;
	InitQueue(&Q);
	struct Node*pt =(struct Node*)malloc(sizeof(struct Node));
	ElemType *e=(ElemType*)malloc(sizeof(ElemType));
	printf("ready to push.\n");
	while(scanf("%d",e)){
		Push(&Q,*e);
		printf("you have pushed :%d\n",*e);
	}
	if(QueueEmpty(&Q)){
		printf("An Empty List.\n");
	}
	QueueTraverse(&Q);
	QueueTraverse(&Q);
	QueueTraverse(&Q);
	QueueTraverse(&Q);
	QueueTraverse(&Q);
	
	//Q->tail->data������û�ж��������е����붼����Ϊָ���˿�ָ��. 
//	struct Node* pt1= Q.head;
//	while(pt1->next!=Q.tail){
//		Pop(&Q);	
//		QueueTraverse(&Q);
//		pt1= pt1->next;
//	}


//		
//	Pop(&Q);	
//	QueueTraverse(&Q);
//	Pop(&Q);	
//	QueueTraverse(&Q);
//	Pop(&Q);	
//	QueueTraverse(&Q);
//	Pop(&Q);	
//	QueueTraverse(&Q);
//	Pop(&Q);	
//	QueueTraverse(&Q);
	
	
	
	//pop()ѭ����bug�� 
//	printf("below i will destroy the list.\n");
//	DestroyQueue(&Q);
//	
	
	
	
	
	free(e);
	free(pt);
	return 0;
}


//2017��9��25��08:45:13
//���ǽ������pop������
 
