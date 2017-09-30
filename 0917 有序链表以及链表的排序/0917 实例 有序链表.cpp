//test
#include <stdlib.h>
#include <stdio.h>
typedef int ElemType;
typedef struct LNode{
	ElemType elem;
	struct LNode* next;
}LNode,*LinkList; 

LinkList InitList(int n){
	struct LNode *head,*tail,*p;
	head = (struct LNode*)malloc(sizeof(struct LNode));
	head->next = NULL;
	tail =head;
	
	
	///类似于我们以前写的东西，反正就是外层是一个struct，然后内层也是一串LNode。 
	for (int i=0;i<n;i++){
		p=(struct LNode *)malloc(sizeof(struct LNode));  //为工作指针分配空间。 
        scanf("%d",&p->elem);  
        tail->next=p;  
        p->next=NULL;  //插在尾巴的后面，然后被尾巴指针同样的指向。 
        tail=p;  
	}
	return head;
}

LinkList Compare(LinkList *L) {
	LinkList p,q;
	///要不就指向一个对象，要不就分配一个空间。 
	for (p=L->head->next;!p;p=p->next){
		for (q=p->next;!q;q=q->next){
			if (p->data>q->data){
				int t = p->data;
				p->data=q->data;
				q->data=t;
			}
		}
	}
}
//for循环嵌套，改变内容，不改变指向。
struct LNode  *p,*q;
p=(*L)->head->next;
while(p){
	q=p->next;
	while(q){
		if(p->data>q->data){
			int t;
			t=p->datal
			p->data =q->data;
			q->data =t;
		}
		q=q->next;
	}
	p=p->next;
}
//while循环，改变内容，不改变指向。
//所以基本的链表排序都是基于数据的交换而不是基于结点的交换。
 //链表一定要有工作指针 

LinkList Compare2(LinkList *L){
	
}





int main() {
	LinkList La;
	La= InitList(10);
	return 0;
}
