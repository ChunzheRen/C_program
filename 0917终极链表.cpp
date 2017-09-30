//终极链表 ，把ElemType里阿米尼的东西换成一个顺序表。 

//有序双链表 ——就是数值的排序情况 
//有序链表:存储有序数据的链表结构为有序链表.
//有了以前链表的基础.写起来就很简单了.无非是从first循环链结点,一直找到一个大于当前链结点关键字的那个链结点.将追加的
//这个链结点插到前面即可.需要注意的就是插入在头部和尾部的特殊处理.
 //存储的元素是无所谓的，因为不涉及核心的指针的改变情况 
 
 //指向头尾节点的，用来存储一次多项式的双链表。
 //有序双链表的插入也要求有顺序这个就很烦了。 
#include <stdio.h> 
#include <stdlib.h> 
typedef int ElemType;
typedef struct Node{
	struct Node *next;
	struct Node *prev;
	ElemType data; //???data其实也可以是一个数组，不过为了简化就不分配空间了。把data当做一个常量。 
}Node,*LNode;
//一般的LinkList直接指向节点，现在进行了修改，先指向一个结点的struct。 
typedef struct List{
	struct Node* head; 
	LNode tail;//指向的是Node类型 
	ElemType size;
}List,*LinkList; //LinkList指向的是一个链表。 
//然后就是定义了一个指向头尾节点的表。其实这个就够了。
//linklist是对于结点进行间接控制的表。
 
int InitList(LinkList *L) {
	(*L) =(LinkList)malloc(sizeof(struct List));
	if(!*L) return -1;
	
	(*L)->head =(LNode)malloc(sizeof(struct Node)); 
	if(!(*L)->head) return -1;
	
	(*L)->tail =(LNode)malloc(sizeof(struct Node));
	if(!(*L)->tail) return -1;
	
	(*L)->size =0;
	printf("maybe initialized.\n");
	return 0;
}
//这个表的头结点不同于其余元素结点。 
//在第一个数据元素前面插入。 
int InsertHead(LinkList *L,ElemType e){
	LNode pt=(LNode) malloc(sizeof(struct Node));
	if ((*L)->size ==0) {
		(*L)->head = pt;
		(*L)->tail = pt;
		pt->next =pt;
		pt->prev =pt;
		pt->data =e;
	}
	else{
		pt->data =e;
		pt->next=(*L)->head;
		pt->prev=(*L)->tail;
		(*L)->tail->next =pt;
		(*L)->head->prev =pt;
		(*L)->head =pt;
	}
	(*L)->size++;
	return 0;
}

int DisplayList(LinkList L){
	
}

int main(){
	LinkList La =NULL;
	InitList(&La);
	
}

