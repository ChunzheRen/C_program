//有了以前链表的基础.写起来就很简单了.无非是从first循环链结点,一直找到一个大于当前链结点关键字的那个链结点.将追加的
//这个链结点插到前面即可.需要注意的就是插入在头部和尾部的特殊处理.
//存储的元素是无所谓的，因为不涉及核心的指针的改变情况 
//带有头尾节点 当前工作结点的 循环 有序双链表。 
//有序双链表就是一个按照元素的位置选择插入位置的情况。 

//就是不用头结点，而是每一个节点都是元素结点，但是，一直是有头指针和尾巴指针的。同时，结点之间是有相互的双向连接的。 
#include <stdio.h> 
#include <stdlib.h> 
typedef int ElemType;
typedef struct Node{
	struct Node *next;
	struct Node *prev;
	ElemType data; //???data其实也可以是一个数组，不过为了简化就不分配空间了。把data当做一个常量。 
}LNode;

//一般的LinkList直接指向节点，现在进行了修改，先指向一个结点的struct。 
//全面换装一次指针 
typedef struct List{
	struct Node* prev; 
	struct Node* next; //指向的是Node类型 用LNode也可以。  LNode next 
	int size;//简化操作 
}LinkList; //LinkList指向的是一个链表。 
//然后就是定义了一个指向头尾节点的表。其实这个就够了。
//linklist是对于结点进行间接控制的表。
int InitList(LinkList *L) {
	L = (LinkList*)malloc(sizeof(struct List));
	if(!L) return -1;
//	L->next=L->prev = (LNode*)malloc(sizeof(struct Node)); 
//	if(!L->prev) return -1;//我的想法就是先插入一个点，作为头结点，一开始都指向真个 
	L->next = L->prev =NULL;
	L->size=0;   //没有头结点 
	printf("maybe initialized.\n");
	return 0;
}//2017年9月26日11:35:45
//最后的结论就是，根据你的malloc一个二重的结构，我觉得还是要先初始化一个头结点才好。 
//一个是没有结点的时候，一个是有一个或者多个结点的时候，结点的插入是有顺序的，根据你的元素的大小。 
int Insert(LinkList *L,ElemType e){
	
	LNode *newNode=(LNode*) malloc(sizeof(struct Node));
	newNode -> data =e;
	printf("#B\n");
	if (L->size==0) {//也就是用都指向NULL的时候进行的操作。但是我有点怀疑。 
		printf("#C\n");
		(L)->next =(L)->prev = newNode;   //是struct Node* 也就是LNode*类型，  
		newNode->next =newNode;
		newNode->prev =newNode;
		L->size++; 
		return 0;
	}
	printf("#B\n");
	LNode *pts=(LNode*)malloc(sizeof(struct Node)); //先分配工作指针 
	pts=(L)->prev;
	printf("#A\n");
	if(pts->data>=e){
		newNode->next=L->prev;
		newNode->prev=L->next;
		L->prev=newNode;
		L->next=newNode;
		L->prev=newNode;
		L->size++;
		return 0;
	}
	printf("#B\n");
	if(L->size>=3){//就是已经有一个或者多个结点的时候。 
		
		L->prev =pts; 	//等价于*(L->prev).data
		while(pts->data<newNode->data){
			pts=pts->next;
		}//11
		newNode->next=pts->prev;//8 9 
		newNode->prev=pts->prev->prev;//8 7
		pts->prev->prev->next=newNode;//7 8
		pts->prev->prev=newNode;//
		L->size++; 
	}
	else if(L->size==1){
		if(L->prev->data>e){   //就是你的数据比你的插入的第一个节点还小，直接插入，不过跟前面有冲突。 
			L->next=L->prev;
			newNode->next=L->prev;
			newNode->prev=L->prev;
			L->prev->next=newNode;
			L->prev->prev=newNode;
			L->prev=newNode;
			L->size++; 
		}
		else{
			L->prev=L->next;
			newNode->next =L->prev;
			newNode->prev =L->next;
			L->prev->next =newNode;
			L->prev->prev =newNode;
			L->next=newNode;
			L->size++; 
		}
	}
	
	else if (L->size==2){
		if(pts->data<e)	{
			if (pts->next->data<e){
				pts->next->next=newNode;
				pts->prev=newNode;
				newNode->next =pts;
				newNode->prev = pts->next;
				L->next=newNode;
			}//最后 
			else {    //(pts->next->dta)
				newNode->next=pts->next;
				newNode->prev=pts;
				pts->next->prev=newNode;
				pts->next =newNode;
		}//中间 
	}
	
	free(pts);
	return 0;
	}
}

int ListTraverse(LinkList L){
	if(L.size==0){
		printf("an enpty list.\n");
		return -1;
	}
	
	int cts=0;
	printf("here is the list.\n");
	LNode *pt =(L).prev;
	while(cts<L.size){
		printf("%d__",pt->data);
		pt=pt->next;
		cts++;
	}
	return 0;
}

int main(){
	LinkList LA;
	InitList(&LA);
	printf("%d\n",LA.size);
	
//	ElemType *e=(ElemType*)malloc(sizeof(ElemType));
//	while(scanf("%d",e)){
//		Insert(&LA,*e);
//		printf("you have just input: %d.\n",*e);
//	}
//	ListTraverse(LA);
	return 0;
}



//int InsertPos(LinkList *L,int pos,ElemType e){
//	LNode pt = (LNode)malloc(sizeof(struct Node));
//	LNode elem=(LNode)malloc(sizeof(struct Node));
//	if (pos==1){
//		InsertHead(L,e);
//	}
//	else{
//		pt = (*L)->head;
//		int cts=1;
//		while(cts<pos){
//			pt=pt->next;
//			cts++;
//		}
//		//pt指向的是要被后移的结点
//		elem->next=pt->next;
//		elem->prev =pt->prev; 
//		pt->next->prev =elem;
//		pt->prev->next =elem; 
//		elem->data =e;	
//	}
//	(*L)->size++;
//	free(pt);
//}
//这个表的头结点不同于其余元素结点。 
//实现的是有顺序的插入 



//int Insert(LinkList *L,ElemType e){
//	LNode pt=(LNode) malloc(sizeof(struct Node));
//	pt->data =e;
//	if ((*L)->size ==0) {
//		(*L)->head = pt;
//		(*L)->tail = pt;
//		pt->next =pt;
//		pt->prev =pt;
//	}
//}
//	
//	
//	
//	else{
//		//实现有序的插入 ,大的在后面，小的在前面。 
//		LNode pt1=(LNode) malloc(sizeof(struct Node));
//		pt1 =(*L)->head;
//		int cts=1;
//		while ((pt1!=(*L)->head)&&(pt->data>pt1->data)){
//			pt1=pt1->next;
//			cts++;
//			continue;	
//		}
//		//就是一直进行遍历，找到终止的情况。
//		//如果一上来就失败了，就插到1号位置就好了。 
//		InsertPos(L,cts,e);
//		//还要涉及到L的head和tail的位置，真的是有点烦啊。。。。。
//		//应该改的是InsertPos函数。 
//		free(pt1);
//	}
//	(*L)->size++;
//	return 0;
//}
