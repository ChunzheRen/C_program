///һԪ����ʽ
//������ʵ�� 
#include <stdlib.h> 
#include <stdio.h>
#include <typeinfo.h>
typedef int ElemType ;
typedef struct LNode{
	ElemType coefficient;
	ElemType index;
	struct LNode* next; 
}LNode,*LinkList;

//LinkList��һ��ָ�����ʽ����LinkList*�Ƕ���ָ�����ʽ�� 
int InitList(LinkList *L){
	//L�������֮�󷵻ص���һ��һ��ָ�롣 
	//*L Ӧ�÷������ LinkLIst���͵Ķ����� 
	(*L)=(LinkList)malloc(sizeof(struct LNode)); 
	(*L)->index =0;
	(*L)->coefficent=0; //������¼�ܹ���ϵ���Ķ��١�
	return 0; 
}
//�����ض�λ�õ�ϵ����ָ�� 
int GetElem(LinkList *L,int pos){
}
int LocateElem(LinkList *L,int e){
}
int Display(LinkList L){
}
LinkList Multiply(LinkList La,LinkList Lb){
}
LinkList Plus(LinkList La,LinkList Lb){
}
LinkList Substract(LinkList La,LinkList Lb){
}
int InsertElem(LinkList *L){
}
int CreateList(LinkList *L){
}
//��Ҫ���̣��Ա�ָ���Ĵ�С���Լ���Ӧ�Ĳ�����
//��ȻҲ���԰�����һ��La��Ϊ�����޸ĵĶ��� 



