//使用顺序表的循环队列
// 使用GB 书上的线性表，而不是你自己的线性表。
//准备以后有时间尝试一下自己的线性表。 

//我一直在思考，链表建立循环队列的话，用双向链表，其实是逻辑循环的，需要的是两个节点，头节点和尾结点。
//其实一个节点也可以。头结点就是一个指向下一个，一个指向最后。
//尾巴节点完全可以装东西，然后就是指向前一个节点和头结点。
 

但是你队空和队满的情况 都是说front=rear
解决方法：一个是用另外一个布尔变量区分；
一个是用 队满的时候：
(rear+1)%n=front,删除元素，移动front，
rear指向想插入的位置，插入元素，移动rear，
count计算queue中的元素个数。 
一开始front和rear都是0； 
Q->rear =(Q->rear+1)%QueueSize;
也就是循环意义下面的插入，

插入 rear 6->7(1)
删除 front 6->7(1) 
用 (rear+1)%SIZE或者(front+1) %SIZE就是差别。 

取对头元素 
if(QueueEmpty(Q)) return -1;
return *(Q->base+Q->front)就是头结点的位置。
 











#include <stdio.h> 
#include <stdlib.h>
#define SIZE 5;
#define INCREMENT 2;

typedef int ElemType;

typedef struct Queue{
	ElemType *base;//一个数组。。。实现的是动态分配内存 
	int front;//书上是front和rear。。。感觉差别好大。	
	int rear;//尾巴指针，一般指向对尾巴的下一个元素  
}Queue,*SqQueue;
//纯正的线性表使用size和length来进行操作的。 
//要不要给SqQueue进行空间的分配？？？ 
int InitQueue(SqQueue *Q){
	ElemType *base= malloc(sizeof(ElemType)*SIZE);
	if (!(*Q)->base) return -1;
	Q.front =Q.rear =0;//感觉可以用size来替换啊 
	return 0;
}
 
int DestroyQueue(SqQueue *Q) {
	if((*Q).base)
		free((*Q).base);
	(*Q).base =NULL;//不知道有啥用啊。。。 
	(*Q).front=(*Q).rear =0;
	return OK;
}
int ClearQueue(SqQueue *Q){
	(*Q).front =(*Q).rear=0;
	return OK;
	//线性表的clear一直就是不释放空间，重新进行覆盖书写罢了。 
}
//链表的clearlist
//int ClearQueueLinkList(SqQueue *Q) {
//	QNode p,q;
//	(*Q).rear =(*Q).front;//这个位置无所谓//回归空表的节奏 
//	p=(*Q).front->next;//将第一个数据元素，（最后一个push进来的） 
//	(*Q).front->next=NULL;//变成了一个空表，和咸鱼有啥区别。 
//	while(p) {
//		q=p;
//		p=p->next;  //p就是下一个元素。。。 
//		free(q);   //p作为工作指针，q作为下一个指针 
//	}
//	return OK; 
//}保留链表。保留头指针尾指针，但是free所有剩余结点。
 
int QueueEmpty(SqQueue Q){
	if(Q.front==Q.rear) return 1;
	else return 0;
}






int QueueLength(SqQueue *Q){
	return(Q.rear-Q.front+SIZE)%SIZE;
}//不知道有啥区别？？？why！！！//一直不理解这个算法 
//相当于取了余数，3-4+6除以6 是5个 。
//rear一直指向的是最后插入的结点的后一个
//所以rear的后面就是 head的时候其实还有一个空的。
//为了避免负值，最好的方法就是这样了吧 
ElemType GetHead(SqQueue Q){
	if(Q.front==Q.rear) return 0;
	(*e)=*(Q.base+Q.front);//也就是数组的初始点加上数组的最终点 
}///一定要注意是连续内存假象循环的形式，或者说计算机立马其实就是循环的内存。。 
int EnQueue(SqQueue *Q,ElemType e) {
	///首先考虑的是空间是不是足够的。
	if(((*Q).rear+1)%SIZE==(*Q).front) return -1;
	//然后就不管了？？？？不是可以扩展空间吗？？？
	//循环队列没办法扩展空间？？？
	(*Q).base[(*Q).rear]=e;
	(*Q).rear=((*Q).rear+1)%SIZE;
	return 0;
}
int QueueTraverse()


 
int main(){
	
	return 0;
}
