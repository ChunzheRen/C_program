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
	
	
	///������������ǰд�Ķ������������������һ��struct��Ȼ���ڲ�Ҳ��һ��LNode�� 
	for (int i=0;i<n;i++){
		p=(struct LNode *)malloc(sizeof(struct LNode));  //Ϊ����ָ�����ռ䡣 
        scanf("%d",&p->elem);  
        tail->next=p;  
        p->next=NULL;  //����β�͵ĺ��棬Ȼ��β��ָ��ͬ����ָ�� 
        tail=p;  
	}
	return head;
}

LinkList Compare(LinkList *L) {
	LinkList p,q;
	///Ҫ����ָ��һ������Ҫ���ͷ���һ���ռ䡣 
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
//forѭ��Ƕ�ף��ı����ݣ����ı�ָ��
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
//whileѭ�����ı����ݣ����ı�ָ��
//���Ի��������������ǻ������ݵĽ��������ǻ��ڽ��Ľ�����
 //����һ��Ҫ�й���ָ�� 

LinkList Compare2(LinkList *L){
	
}





int main() {
	LinkList La;
	La= InitList(10);
	return 0;
}
