//���Ա�1��
//2017��9��16��20:03:23
//����ʵ���˻����Ĺ��ܣ�����û�ܴ����������*LinkList�����⡣ 
#include <stdio.h>
#include <stdlib.h>

#define LISTSIZE 1000
#define LISTINCREMENT 10
typedef int ElemType;
typedef struct List{
	ElemType *elem;
	int length;
	int listsize;  
}List; //*Sqlist;

//MALLOC���ص���һ��ָ��void��ָ�룬Ȼ������ָ��ָ��Ŀռ丳ֵ������һ��ָ��
//���ԣ�һ���пռ��voidָ�룬��ֵ��һ��û�пռ��ָ�롣 

//2017��9��16��19:39:23 
//int InitList(List L){
//	L.elem =(ElemType*)malloc(LISTSIZE*sizeof(ElemType));
//	//������������һ�¡� 
//	if(!(L.elem)) return -1;
//	L.length =0;
//	L.listsize =LISTSIZE;
//	return 0;
//}//���漰L�Ŀռ�ĸı䣬���������ķ���ռ䡣��Ҫʹ�� 

//ֻҪ���Ƕ���ָ��Ͳ���-> 
int InitList(List *L){
	(*L).elem =(ElemType*)malloc(LISTSIZE*sizeof(ElemType));
	//������������һ�¡� 
	if(!((*L).elem)) return -1;
	(*L).length =0;
	(*L).listsize =LISTSIZE;
	return 0;
}

int Display(List L) {
	int cts= 0;
	while(cts<L.length){
		printf("%d__",*(L.elem+cts));
		cts++;
	}
	printf("\nthat is all.\n");
	return 0;
}

int InsertTail(List *L,ElemType e){
	if (((*L).length)>((*L).listsize)){
		ElemType *p=(ElemType*)realloc((*L).elem,(LISTSIZE+LISTINCREMENT)*sizeof(ElemType));
		(*L).elem =p;
	}
	//�漰���ռ�����·��䡣
	*((*L).length+(*L).elem) = e;
	(*L).length+=1;
	
}

int main(){
	struct List Lb;
	InitList(&Lb);
	ElemType *pt =(ElemType*)malloc(sizeof(ElemType));
	while(scanf("%d",pt)){
		InsertTail(&Lb,*pt);
	}
	Display(Lb);
//	printf("length : %d\n",Lb.length);
//	ElemType *pt=(ElemType*)malloc(sizeof(int));
//	printf("input a number (q to quit..)\n") ;
//	while(scanf("%d",pt)){
//		InsertTail(&Lb,*pt);
//	}
//	printf("length : %d\n",(*Lb).length);
//	DisplayList(Lb);
	return 0;
}
