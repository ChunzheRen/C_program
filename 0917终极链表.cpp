//�ռ����� ����ElemType�ﰢ����Ķ�������һ��˳��� 

//����˫���� ����������ֵ��������� 
//��������:�洢�������ݵ�����ṹΪ��������.
//������ǰ����Ļ���.д�����ͺܼ���.�޷��Ǵ�firstѭ�������,һֱ�ҵ�һ�����ڵ�ǰ�����ؼ��ֵ��Ǹ������.��׷�ӵ�
//��������嵽ǰ�漴��.��Ҫע��ľ��ǲ�����ͷ����β�������⴦��.
 //�洢��Ԫ��������ν�ģ���Ϊ���漰���ĵ�ָ��ĸı���� 
 
 //ָ��ͷβ�ڵ�ģ������洢һ�ζ���ʽ��˫����
 //����˫����Ĳ���ҲҪ����˳������ͺܷ��ˡ� 
#include <stdio.h> 
#include <stdlib.h> 
typedef int ElemType;
typedef struct Node{
	struct Node *next;
	struct Node *prev;
	ElemType data; //???data��ʵҲ������һ�����飬����Ϊ�˼򻯾Ͳ�����ռ��ˡ���data����һ�������� 
}Node,*LNode;
//һ���LinkListֱ��ָ��ڵ㣬���ڽ������޸ģ���ָ��һ������struct�� 
typedef struct List{
	struct Node* head; 
	LNode tail;//ָ�����Node���� 
	ElemType size;
}List,*LinkList; //LinkListָ�����һ������ 
//Ȼ����Ƕ�����һ��ָ��ͷβ�ڵ�ı���ʵ����͹��ˡ�
//linklist�Ƕ��ڽ����м�ӿ��Ƶı�
 
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
//������ͷ��㲻ͬ������Ԫ�ؽ�㡣 
//�ڵ�һ������Ԫ��ǰ����롣 
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

