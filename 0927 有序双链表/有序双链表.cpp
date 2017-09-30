//比较成熟的有序双链表了！ 
//有待完善的功能，删除双链表，可以采用遍历的方式删除。 
#include<stdio.h> 
#include<stdlib.h>
typedef int ElemType;
typedef struct Node{
	struct Node *next;
	struct Node *prev;
	ElemType data; 
}LNode;
//不是队列，是有序的双链表。。。。。 
typedef struct List{
	struct Node* head; 
	struct Node* tail; 
	int size=0;
}LinkList; 
//有多个类似于LNode的struct，但是仅仅有一个LinkList的struct。 
int InitList(LinkList *L) {
	L = (LinkList*)malloc(sizeof(struct List));
	if(!L) return -1;
	L->head = L->tail =NULL;
	L->size=0;   //没有头结点 
	printf("maybe initialized.\n");
	return 0;
}
///就是要重新创建一个节点列表 

int ListTraverse(LinkList L){
	if (L.size==0){
		printf("An Empty List.\n");
		return 0;
	}
	LNode *pt =(LNode*)malloc(sizeof(struct Node));
	pt=L.head;
	int cts=0;
	do{
		printf("%d__",pt->data);
		pt=pt->next;
		cts++;
	}while(cts<L.size);
	printf("\n");
	return 0;//一大困惑就是，如果使用了pt=pt->next，会出现指针越界的情况。所以使用计数器的方法。 
}

int Insert(LinkList *L,ElemType e) {
	printf("before insertion.\n");
	ListTraverse(*L);
	LNode *newNode=(LNode*)malloc(sizeof(LNode));
	newNode->data=e;
	
	if(L->size==0){
		newNode->prev=newNode;
		newNode->next=newNode;
		L->head=newNode;
		L->tail=newNode;
		L->size++;
		return 0;
	}
	//直接插入 1 和 2 两个点。 
	
	if (L->head->data>=e){
		newNode->prev=L->tail; 
		newNode->next=L->head;
		L->head->prev=newNode;
		L->tail->next=newNode;
		L->head=newNode;
		L->size++;
		return 0;
	}
	else{	
		
		LNode*pt =(LNode*)malloc(sizeof(LNode));
		LNode*prev_pt=(LNode*)malloc(sizeof(LNode));
		pt=L->head; 
		prev_pt=pt;//还要处理一个问题就是在最后插入。 
		
		while(pt->next!=L->tail){//pt->next应对6 8 9问题  //如果没办法用指针判断，直接用计数器。 
			if (pt->data<e) {        //应对8 01 12 问题 
				prev_pt=pt;  
				pt=pt->next;	
			}	//1 3 4 --2 
			else{//属于8 10 12 问题：直接在pt的前面，prev的后面插入。 
				printf("#BB\n");
				newNode->next=pt;  
				newNode->prev=prev_pt;
				pt->prev = newNode;
				prev_pt->next = newNode;
				L->size++;
				printf("After insertion.\n");
				ListTraverse(*L);
				return 0;
			}
		}
		// 以上就是判断了最后只有pt 和 pt->next 
		//8 10 12 ---9 保证至少有一个还在。 就是在prev的后面和pt的前面。 
		//6 8----9  此时pt指向的是8，然后然后还是应该在pt的后面。 
		if(L->tail->data<e){ //如果是3 5 那么就直接插入。 
			printf("#CC\n");
			newNode->prev=L->tail;
			newNode->next=L->head;
			L->tail->next=newNode;
			L->head->prev=newNode;
			L->tail=newNode;
			L->size++;
			printf("After insertion.\n");
			ListTraverse(*L);
			return 0;
		}
		
		else if(pt->data>e){ // 1 3 4  -----2 
			printf("#DD\n");
			newNode->next=pt;
			newNode->prev=pt->prev;
			pt->prev->next =newNode;
			pt->prev=newNode;
			L->size++;
			printf("After insertion.\n");
			ListTraverse(*L);
			return 0;
		}
		
		else{//如果是 5 3  
			printf("#EE\n");
			printf("before insertion.\n");
			ListTraverse(*L);
			newNode->next =L->tail;
			newNode->prev =L->tail->prev;
			L->tail->prev->next =newNode;
			L->tail->prev=newNode; //一定要注意插入的顺序。也就是说你的插入情况一定要和真实情况相对应。 
			L->size++;
			printf("After insertion.\n");
			ListTraverse(*L);
			return 0; 
		}
		
		printf("data:%d\n",L->tail->prev->data);
		printf("##FF\n");
		L->size++;
		free(pt);
		free(prev_pt);
		printf("After insertion.\n");
		ListTraverse(*L);
		return 0;
	}
	printf("After insertion.\n");
	ListTraverse(*L);
	return 0;
}

int DestroyList(LinkList*L) {
	LNode *pt=L->tail;
	while(pt!=L->head){
		pt=pt->prev;
	}//主要就是让一个指针指向尾结点，然后逐个遍历删除的感觉。 
}
int main(){
	LinkList LA;
	InitList(&LA);
	ElemType *e=(ElemType*)malloc(sizeof(ElemType));
	while(scanf("%d",e)){
		Insert(&LA,*e);	
		printf("you just entered:%d\n",*e);
	}
	free(e);
	printf("the whole list after insertion.\n");
	ListTraverse(LA);
//	printf("#A\n");
//	printf("%d\n",LA.head->data);
//	printf("%d\n",LA.head->next->data);
//	printf("%d\n",LA.head->next->next->data);
	return 0;
	} 
//	插入大量的1之后就会有混乱，说明上面的插入是存在问题的。	
//  有序双链表最大的问题就是会出现对于不同的循环的插入问题，着重表现在：没有结点的情况 头结点前面插入 尾结点后面插入 相等的时候插入 
