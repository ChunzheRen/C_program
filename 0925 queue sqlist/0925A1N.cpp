	//���ǽ���������� 
	#include<stdio.h>
    #include <stdlib.h>
    #include <typeinfo.h>
    #define SIZE 5  
    typedef int ElemType;
    typedef struct Queue{
    	int front;
	    int rear;
    	ElemType *base;
    }Queue,*SqQueue;
    
    //��ʼ���ģ��װһ��ָ�� 
    int InitQueue(SqQueue*Q){
	    (*Q)->front=0;
		(*Q)->rear=0;
    	(*Q)->base =(ElemType*)malloc(SIZE*sizeof(ElemType));
    	if (!(*Q)->base) return -1;
    	printf("perhaps initialized successfully.\n");
    	return 0;
    }
    	int  QueueTraverse(SqQueue *Q){
		if (((*Q)->rear)%SIZE==((*Q)->front)%SIZE){
			printf("An Empty List.\n");
			printf("\n");
			return -1;
		}
		
		ElemType *pt=(*Q)->base+(*Q)->front;//e��ָ�룬ָ����ʼλ��
		while(pt!=(*Q)->base+(*Q)->rear){
			printf("%d__",*pt);
			pt++;
		}
		printf("\n");
		return 0;
	}
	
    //Ҫ��һ���ѭ���ж��ǲ��ǿյģ�����Ҫһ��Ԫ��ʼ���Ǳ��ճ����ġ����еĿ����ڴ���Զ��SIZE-1 
    int Push(SqQueue *Q,ElemType e){
    	QueueTraverse(Q);
    	if(((*Q)->rear+1)%SIZE==((*Q)->front)){
    		printf("it is full currently.Unable to Insert.\n");
    		return -1;
    	}
    	*((*Q)->base+(*Q)->rear)=e;
    	(*Q)->rear=((*Q)->rear+1)%SIZE;
    	return 0;
    }
    
    int Pop(SqQueue *Q){
    	if ((((*Q)->rear)%SIZE)==(((*Q)->front)%SIZE)){
    		printf("Don`t Need Pop.\n");
    		return -1;
		}
		int e;
    	e=*((*Q)->base+(*Q)->front);
    	(*Q)->front=((*Q)->front+1)%SIZE;
    	printf("Pop:%d\n",e);
    	//����destroy֮�⣬������Ҫ�κε�free������ 
    	return 0;
    }

//Ҳ���Ǳ����ǵĽ��������
//ÿһ�ζ��ǰ�βָ���λ�ú�ͷָ���λ�ý��и����ǱȽ���ֵġ� 

    int main(){
    	SqQueue SQ;
    	InitQueue(&SQ);
    	printf("time to input some certain elements to the Queue.\n");
    	
		ElemType *e=(SQ->base+SQ->front); 
		QueueTraverse(&SQ);
		while(scanf("%d",e)){
			Push(&SQ,*e);
			printf("you just entered :%d\n",*e);
			QueueTraverse(&SQ);
		}
		QueueTraverse(&SQ);
    	return 0;
    }

//(*Q).base +(*Q).rear is int*
//*((*Q).base +(*Q).rear) is int 
//ʹ�ö���ָ���ʹ��һ��ָ��֮��Ĳ���Ǻܴ�ġ����Ƕ��Ƕ��ڵ�ַ�Ĳ��� ��Ȼ��һ���->��* .�� ���ġ�
//�����ָ���Ƚ������ ��֮���ٽ���->������ʵ����һ��ָ��ֱ�ӽ���-> 

//����˵�����б�Ҫ��base��0����Ϊ6%6��0 
