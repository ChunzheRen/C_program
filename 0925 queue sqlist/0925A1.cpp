//һ��ʧ�ܵ����Ա����ǻ��ǿ�����ǿ���á� 
//���Ա� ʵ�ֶ��� ʹ��������Ϊָ�룬�����Ǵ�����ָ�����
#include<stdio.h >
#include <stdlib.h>
#include <math.h> 
#define SIZE 5  
int SIZE =5;
//#define INCREMENT 2//���ϵ���˼��ѭ�������ǲ����Խ��������ݻ��ģ���������һ���ƶ�ͷָ��βָ�������� 
//typedef int int ;
typedef struct Queue{
	int front;
	int rear;//int���Ӿ���ָ��ĺ��壬��elemtype����Ϊchar 
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
	//�ж����ˣ���ͷָ���һҲ�ǿ��Եġ� 
	if(((*Q).rear+1)%SIZE==((*Q).front)){
		printf("it is full currently.Unable to Insert.\n");
		return 0;//�Ժ�����ݲ����ġ� 
	}
	//βָ��һֱ��ָ��հ׵Ĳ���λ�á� 
	//�����ָ�븳ֵ����Ҫֱ����ָ�����ģ�Ҳ���ǰ�Ŀ��ĵ�ֵַ����ָ����Ϊָ���ֵ�� 
	*(((*Q).base+(*Q).rear)%  SIZE)=e;
	(*Q).rear=((*Q).base+(*Q).rear+1)%(int)SIZE;//��Ϊ���������ڴ����Կ���++�����������߼�ѭ���� 
	return 0;
} //��ֵ���ƶ�βָ��. 

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
