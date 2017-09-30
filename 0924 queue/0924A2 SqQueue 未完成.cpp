//链表型队列 不循环 头插入 尾巴输出 头结点
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
//FIFO队列 

int InitQueue(SqQueue Q){
	(*Q).head=(*Q).tail =(QNode)malloc(sizeof(struct Node));
	//这句话不仅仅把Q的head和tail分配了空间，而且让tail和head指向了同一个位置。 
	if(!(*Q).head) {
		printf("unable to initialized.\n");
		return -1;	
	}
	((*Q).head)=NULL;//刚才仅仅是创建了一个空的结点，以后才是说分配了一个指向。 
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
	//对于单链表还是需要从头开始找最后一个节点的，要是双链表就好了。 
//	struct Node *prev=(struct Node*) malloc(sizeof(struct Node));
	struct Node *pt=((*Q).head);//首先，按照这种插入方法，头结点以后是有东西的。 
	struct Node *prev ;
	//这个判断条件是最烦人的. 
	while (pt->next){   
	
	
		//////////////////////////////////////////////////////////////////////////////////////////// 
		prev = pt;//prev指向pt刚才的地方。 ///你用pt和prev 和 pt*和prev*的差别就在在于一个是对象，解除引用之后产生的是一个地址，也就是说&pt=address of pointer，而*pt=the address pt pointed to。
//		将*pt 赋给*prev  毫无逻辑可言//pay special attention！ 
 
 
 		///////////////////////////////////////////////////////
		pt=pt->next;//mmp，这个是链表。别总他妈的用pt++; 
		
		
		
		
	}//最后输出的时候pt指向的是最后一个有数据的结点？不，是尾结点，是没有数据的结点。//所以，可能还是要用cts进行判断。 
	
	ElemType e =(*pt).data;
	((*Q).tail)=prev;//////////////////还是这种赋值的毛病。 
	(*prev).next =NULL; //删除结点 
	
	free(pt);//单纯的是一个删除结点的操作。  的确是删除了结点 
	printf("Pop:%d\n",e);
	return e;
}

int QueueEmpty(SqQueue Q){
	if ((*Q).head==(*Q).tail) return 1;
	else return 0;
}
//这个队列默认是头插入，所以就很尴尬。。。。traverse的顺序是反的。。。。 
//注意：由于是头插入，所以尾结点其实是没有数据的。NO DATA. 
int QueueTraverse(SqQueue Q){
	if (QueueEmpty(Q)){
		printf("Empty One\n");
		exit(-1);
	}
	struct Node*pt =(struct Node*)malloc (sizeof(struct Node));
	pt=(*Q).head;
	while(pt){
		printf("%d__",(*pt).data);
		pt=pt->next;//就是说不是pt++因为你在表中的顺序不是连续的，所以说要用next进行赋值。 
	}
	printf("\n");
	return 0;
}
//涉及到指针，最烦人的就是这个类型不对应，尤其是指针的类型不对应。。 

//不断调用Pop来进行删除 ,并且进行free 
int DestroyQueue(SqQueue Q){
	while ((Q->head)!=(Q->tail)){
		printf("here\n");
		Pop(Q);//这里面的pop是从tail释放啊。
		printf("here\n");
//		pt=pt->next;//一定要注意是指向next这种方式啊！ 
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
	
	//Q->tail->data根本就没有东西，所有的乱码都是因为指向了空指针. 
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
	
	
	
	//pop()循环的bug？ 
//	printf("below i will destroy the list.\n");
//	DestroyQueue(&Q);
//	
	
	
	
	
	free(e);
	free(pt);
	return 0;
}


//2017年9月25日08:45:13
//还是解决不了pop的问题
 
