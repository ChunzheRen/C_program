//ʹ��˳����ѭ������
// ʹ��GB ���ϵ����Ա����������Լ������Ա�
//׼���Ժ���ʱ�䳢��һ���Լ������Ա� 

//��һֱ��˼����������ѭ�����еĻ�����˫��������ʵ���߼�ѭ���ģ���Ҫ���������ڵ㣬ͷ�ڵ��β��㡣
//��ʵһ���ڵ�Ҳ���ԡ�ͷ������һ��ָ����һ����һ��ָ�����
//β�ͽڵ���ȫ����װ������Ȼ�����ָ��ǰһ���ڵ��ͷ��㡣
 

������ӿպͶ�������� ����˵front=rear
���������һ����������һ�������������֣�
һ������ ������ʱ��
(rear+1)%n=front,ɾ��Ԫ�أ��ƶ�front��
rearָ��������λ�ã�����Ԫ�أ��ƶ�rear��
count����queue�е�Ԫ�ظ����� 
һ��ʼfront��rear����0�� 
Q->rear =(Q->rear+1)%QueueSize;
Ҳ����ѭ����������Ĳ��룬

���� rear 6->7(1)
ɾ�� front 6->7(1) 
�� (rear+1)%SIZE����(front+1) %SIZE���ǲ�� 

ȡ��ͷԪ�� 
if(QueueEmpty(Q)) return -1;
return *(Q->base+Q->front)����ͷ����λ�á�
 











#include <stdio.h> 
#include <stdlib.h>
#define SIZE 5;
#define INCREMENT 2;

typedef int ElemType;

typedef struct Queue{
	ElemType *base;//һ�����顣����ʵ�ֵ��Ƕ�̬�����ڴ� 
	int front;//������front��rear�������о����ô�	
	int rear;//β��ָ�룬һ��ָ���β�͵���һ��Ԫ��  
}Queue,*SqQueue;
//���������Ա�ʹ��size��length�����в����ġ� 
//Ҫ��Ҫ��SqQueue���пռ�ķ��䣿���� 
int InitQueue(SqQueue *Q){
	ElemType *base= malloc(sizeof(ElemType)*SIZE);
	if (!(*Q)->base) return -1;
	Q.front =Q.rear =0;//�о�������size���滻�� 
	return 0;
}
 
int DestroyQueue(SqQueue *Q) {
	if((*Q).base)
		free((*Q).base);
	(*Q).base =NULL;//��֪����ɶ�ð������� 
	(*Q).front=(*Q).rear =0;
	return OK;
}
int ClearQueue(SqQueue *Q){
	(*Q).front =(*Q).rear=0;
	return OK;
	//���Ա��clearһֱ���ǲ��ͷſռ䣬���½��и�����д���ˡ� 
}
//�����clearlist
//int ClearQueueLinkList(SqQueue *Q) {
//	QNode p,q;
//	(*Q).rear =(*Q).front;//���λ������ν//�ع�ձ�Ľ��� 
//	p=(*Q).front->next;//����һ������Ԫ�أ������һ��push�����ģ� 
//	(*Q).front->next=NULL;//�����һ���ձ���������ɶ���� 
//	while(p) {
//		q=p;
//		p=p->next;  //p������һ��Ԫ�ء����� 
//		free(q);   //p��Ϊ����ָ�룬q��Ϊ��һ��ָ�� 
//	}
//	return OK; 
//}������������ͷָ��βָ�룬����free����ʣ���㡣
 
int QueueEmpty(SqQueue Q){
	if(Q.front==Q.rear) return 1;
	else return 0;
}






int QueueLength(SqQueue *Q){
	return(Q.rear-Q.front+SIZE)%SIZE;
}//��֪����ɶ���𣿣���why������//һֱ���������㷨 
//�൱��ȡ��������3-4+6����6 ��5�� ��
//rearһֱָ�����������Ľ��ĺ�һ��
//����rear�ĺ������ head��ʱ����ʵ����һ���յġ�
//Ϊ�˱��⸺ֵ����õķ������������˰� 
ElemType GetHead(SqQueue Q){
	if(Q.front==Q.rear) return 0;
	(*e)=*(Q.base+Q.front);//Ҳ��������ĳ�ʼ�������������յ� 
}///һ��Ҫע���������ڴ����ѭ������ʽ������˵�����������ʵ����ѭ�����ڴ档�� 
int EnQueue(SqQueue *Q,ElemType e) {
	///���ȿ��ǵ��ǿռ��ǲ����㹻�ġ�
	if(((*Q).rear+1)%SIZE==(*Q).front) return -1;
	//Ȼ��Ͳ����ˣ����������ǿ�����չ�ռ��𣿣���
	//ѭ������û�취��չ�ռ䣿����
	(*Q).base[(*Q).rear]=e;
	(*Q).rear=((*Q).rear+1)%SIZE;
	return 0;
}
int QueueTraverse()


 
int main(){
	
	return 0;
}
