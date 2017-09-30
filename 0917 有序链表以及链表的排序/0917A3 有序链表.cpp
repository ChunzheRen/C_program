//��������嵽ǰ�漴��.��Ҫע��ľ��ǲ�����ͷ����β�������⴦��.
//��������Ĳ�������һ��Ķ��ǵ�ǰλ�õĲ��룬����Ҳ������ͷ���������β����������

//�����Ͻ�����4�������ѡ�� 

#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

int InitList(LinkList*L){
	(*L)=(LinkList)malloc(sizeof(struct LNode));
	if (!(*L))  return -1;
	(*L)->next =NULL;
	(*L)->data =0;
}
//һ����������� 
int Insert(LinkList *L,ElemType e){
	LinkList node =(LinkList)malloc(sizeof(struct LNode));
	node->data =e;
	
	LinkList pt =(LinkList)malloc(sizeof(struct LNode));
	pt=(*L)->next; //ptָ����ǵ�һ��λ�� 
	
	LinkList prev =(LinkList)malloc(sizeof(struct LNode));
	
	if (!(pt)){
		(*L)->next = node;
		(*L)->data+=1;
		free(pt);
		return 0;
	}
	//����һ��ͷָ��
	if (((*L)->next->data)>(node->data)){
		node->next = pt;
		(*L)->next =node;
		(*L)->data+=1;
		free(pt);
		return 0;
	}
	
	while(pt && ((pt->data)<(node->data))){
		prev =pt;
		pt=pt->next;
	}
	
	if(!pt){//����������λ�� 
		prev->next =node;
		node->next =NULL;
	}
	else {//��������������� 
		node->next =prev->next;
		prev->next =node;
	}
	(*L)->data+=1;
	free(pt);
	return 0;
}

int Display(LinkList L){
	LinkList pt =(LinkList)malloc(sizeof(struct LNode));
	pt =(L)->next;
	while (pt){
		printf("%d__",pt->data);
		pt=pt->next;	
	}
	free(pt);
	printf("\n");
	return 0;
}

int ListTraverse(LinkList L){
	LinkList pt=(LinkList)malloc(sizeof(struct LNode));
	pt=L->next;
	while(pt){
		printf("%d",pt->data);
		pt = pt->next;
	}
	return 0;
}

int main(){
	LinkList La=NULL;
	InitList(&La);
	ElemType *e=(ElemType*)malloc(sizeof(ElemType));
	while (scanf("%d",e)){
		Insert(&La,*e);
		Display(La);
	}
	free(e);
	Display(La);
	return 0;
}
//�����˴�ӡ��������⡣���� 
