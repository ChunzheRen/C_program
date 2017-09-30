//������ Ŀ�꣺��ʱ�õ�������д��˫������������⡣ 
//�����Ĺ��ܣ�����ɾ�����ҷ�ת 
//2017��9��12��20:31:44 
//����ʵ��˫����ͷ����¼������ 
///Arthur: Justin.ShaoHui.ChunZhe.Ren 
///IDE ��Dev C++ 5.11 
//Tips������Ҫ�ı�ԭ������ĺ���������ֵ���ݾͺ��� 
//˫��������ڵ���������Ʋ����� �������ǰ�������ѧ�õ�����͹��ˡ� 
#include <stdlib.h> 
#include <stdio.h>
typedef int ElemType ;
typedef struct LNode{
	ElemType data;
	struct LNode* next; 
}LNode,*LinkList; 
//�漰��һ��������������ĸı䣬��Ҫ��ʹ�ö���ָ�� LinkList* �� 
int InitList(LinkList *L) {
	//��ʼ����ʵ�ʾ����� malloc����new���пռ�ķ��� 
	(*L)=(LinkList)malloc(sizeof(LinkList));
	//һ��Ҫע�����ߵĲ�����һ���ԡ� 
	if (!L) return -1;
	//return �����þ��Ƿ��������� 
	(*L)->data= 0;
	(*L)->next =NULL;
//	(*L)->prev =NULL;
	printf("successfully initialized.\n");
	return 0;
}
 
//��ʼ������ͷָ���Լ�ͷ��㣬˫�����ͷβ�ڵ㶼�ǿյġ� 
//�����漰����Щ�����б�ģ�������Ҫ����LinkList�ġ�
 
int HeadInsert(LinkList *L,ElemType e){
	//����Ķ�����ɶ ��Ȼ�����ȴ����ڵ���˵��ġ�
	LinkList p = (LinkList)malloc(sizeof(LinkList));
	(p)->data =e;
	(p)->next =(*L)->next;
//	p->prev = (*L);
	(*L)->next = p;
	free(p);
	return 0;
}
//} 
//int TailInsert()
//int InsertElem()  



int DisplayList(LinkList L){
	//���ȴ�������ָ�룬�Լ�����û��Ҫ����prevָ��
	LinkList p=(LinkList)malloc(sizeof(LinkList));  //������ָ�� ,����ElemType�����ʱ���Ҫʹ��*�ˡ� 
	p = L->next;//pָ����ǵ�һ������Ԫ�� 
	int cts= 1; //������ 
	//����������ListEmpty���������ģ����Ǻ�������ListEmptyû�취�����scope�����ð��� 
	if (! p) {
		return -1;//�����ж�p 
	}
	else {
		printf("output the list\n");
		while(p->next){ //����ָ�벻�����һ��Ԫ�أ�����һ�ַ�������p=L->prev; 
			printf("the %d element is:%d\n",cts,p->data);
			p+=1;	//����ָ��������һ����Ԫ 
		}
		printf("%d",p->next->data);
	}
	printf("that is all\n");
	return 0;
} 
ElemType LocateElem(LinkList L,int pos){
	LinkList p=(LinkList )malloc(sizeof(LinkList));
	p = L->next;
	int cts=1;
	for (;cts<pos;cts++){
		if (p)
			p =  p->next;
		else {
			printf("error.\n");
			return -1;
		}
	}
	ElemType e = p->data; 
	return e;
}
//int NextElem()
//int PrevElem()

int ListEmpty(LinkList L){
	if (!(L->next)){
	 	printf("Empty!\n") ;
		return -1;} 
	else {
		printf("Not Empty!\n");
		return 0;}
}

//int ClearList()
//int DestroyList()
//int TransverList()

int main(){
	LinkList La;
	InitList (&La);
//	ElemType e[10] = {10,11,12,13,14,15,16,17,18,19};
	ListEmpty (La);
	//�Ժ����ʵ�ָ�������Ҫ��Ԫ�ش�С��������Ĳ��� 
	ElemType *pt= (ElemType*) malloc(sizeof(ElemType));
	
//	printf("input a int(press 'q' to quit)\n"); 
//	while ((scanf("%d",pt))) //pt�������ָ�룬���Բ���Ҫ����ĵ�ַ����� 
//		printf("you have entered:%d\n",*pt);
//		HeadInsert(&La,*pt);

	ElemType e[5] ={1,2,3,4,5};
	for (int i=0;i<5;i++){
		HeadInsert(&La,e[i]);
	}
	
	free(pt);
	printf("everything ok.\n");
	ListEmpty(La);
//	DisplayList(La);
	

	LinkList pointer =(LinkList) malloc(sizeof(LinkList));
	pointer = La->next;
	printf("%d\n",pointer->data);
	pointer= pointer->next;
	printf ("%d\n",pointer->data);
	

	return 0;
}

//ע�⺯���Ķ��壬һ�����ǲ����һ��&listƽ���޹ʵĸ���һ��������Ϊ�����ģ�
//һ��Ļ���Ҫ��һ��������ֵ���ݵķ�ʽ���ݲ�������C��������&La���ݲ�����һ����׼���á� 

//2017��9��13��17:17:12 
//������ʾ���ǲ�������Ԫ�ء����Ǿ������һ��������Ӧ������û���ȥ�� 
//׼��дһ��Ѱ���ض�λ��Ԫ�صĺ������������ҵ���������û�в��ȥ

//2017��9��13��17:21:27
//����һ���������������˿��û������˫����ĸо��� 

//2017��9��13��17:29:51
//���⻹�Ǵ�����InsertElem�������⡣ �������˫����Ĳ�������ż�������⡣��˫�������������� 
//�����ԭ������Ϊ��һ��Ԫ���ǿյģ�Ҳ����HeadInsert�����⡣ 

//2017��9��13��20:41:56
//����˫������Ϊѧϰ���еĵ������ʵ�֡�
//��Ϊ�������е�����Ľӿ�ʵ�ֲ�����
//��Ϊ��д�ع����е����� 
