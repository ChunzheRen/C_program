//˫���� 
//2017��9��14��16:39:25
 
#include<stdio.h> 
#include<stdlib.h>
#include <typeinfo.h>
typedef int ElemType;
typedef struct DNode {  //����˫����������
    ElemType data;  //������
    struct DNode *prev, *next;  //ǰ���ͺ��ָ��
}DNode, *DLinklist;

int InitList(DLinklist *L){
	*L= (DLinklist )malloc(sizeof(struct DNode));
	if(!(*L)) return -1;
	(*L)->data = 0;
	(*L)->next = NULL;
	(*L)->prev = NULL;
	printf("successfully initialized.\n");
	return 0;
}

int HeadInsert(DLinklist *L,ElemType e){
	DLinklist p = (DLinklist) malloc(sizeof(struct DNode));
	DLinklist q = (DLinklist) malloc(sizeof(struct DNode));
	q = (*L)->next;
	
	p->data=e;
	p->next = q;
	p->prev =(*L);
	
	(*L)->next =p;
	(*L)->data+=1;
	return 0;
}
int DisplayList(DLinklist *L){
	if(!(*L)->next) {
		printf("Empty List.\n");
		return -1;
	}
	DLinklist p = (DLinklist) malloc(sizeof(struct DNode));
	//�������û��ȥ��ָ��ָ��һ��λ�á�
	p = (*L) ->next;
	int cts =1;
	while(cts<((*L)->data+1)) {
		printf("%d--",cts,p->data);
		p = p->next;
		cts++;
	}
	free(p);
	printf("");
	printf("that`s all.\n");
	//���Ծ���û�н��пռ���ͷţ�Ȼ��IDE��ȥ���� 
	return 0;
}
ElemType LocateElem(DLinklist *L,int pos){
	DLinklist p =(DLinklist)malloc(sizeof(struct DNode));
	p= (*L)->next; 
	int cts=1;//��������ָ���Ǳ����
	ElemType e;
	while (cts<(*L)->data) {
		p= p->next;
		cts ++;	
	}
	e= p->data;	
	free(p);
	printf("the elem is %d",ElemType(e));
	return e;
}
int GetElem(){
	DLinklist p =(DLinklist)malloc(sizeof(struct DNode));
	
	free(p);
	return 0;
}
int DeleteElem(DLinklist *L,int pos){
	DLinklist p =(DLinklist)malloc(sizeof(struct DNode));
	free(p);
}
int main(){
	DLinklist La;
	InitList(&La);
	
	//��һ�����ǵ����ǲ�����Ҫ��malloc�����Ǹо������ķ���һ���������а��� 
	printf("input an int(input 'q' to quit).\n");
	int ct=1;
	//scanf���صĶ�����һ����������ʶ����  �����״̬ 
	ElemType e;
	ElemType *p=&e;
	while (scanf("%d",p)){
		
		printf("Elem No.%d : %d\n",ct,e);
		HeadInsert(&La,*p);
		ct+=1;
	}
	free(p);
	
//	LocateElem(&La,2);
	//���������� 
//	DisplayList(&La);
	DLinklist p=(DLinklist) malloc (sizeof(struct DNode));
	p=(*L)->data;
	return 0;
}
