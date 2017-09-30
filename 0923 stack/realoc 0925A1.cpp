#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <typeinfo.h>
#define SIZE 2
#define INCREMENT 1
typedef int ElemType;
typedef struct Stack{
	ElemType *base;
	ElemType *top;
	int size;
}Stack,SqStack;

int InitStack(SqStack *S){
	//�������ˣ�����SqStackû�б�����һ���ռ䡣
	S = (SqStack*)malloc(sizeof(struct Stack));
	if(!S) return -1;
	
//	S= (*SqStack) malloc(sizeof(struct Stack)); Ҳ�ܳɹ����룬���Ǹо��Ͳ��ԣ�����ԭ���Ǹ����� 
	(S)->base =(ElemType*)malloc(sizeof(ElemType)*SIZE);
	if (!((S)->base)) return -1;
	
	(S)->top =(S)->base;
	(S)->size = SIZE;
	printf("Maybe successfully initialized.\n");
	return 0;
}
//һ���Ƕ���S�Լ��ռ�ķ����Լ�free������
//һ���Ƕ��������˳���Ĺ���ָ������Ͳ��� ˳������һ�����飬����˵���ǿ�����ָ��������ִ�б���Traverse������ 

int ClearStack(SqStack *S){
	(S)->top=(S)->base;
//	*(*S)->base =0;
	return 0;
}

int DestroyStack(SqStack *S){
//	if ((*S)->base) free((*S)->base);
///�����ĸı�����ͷ��ڴ��ǲ��Եġ� 
	(S)->base = NULL;
	(S)->top =NULL;
//	free(*S); //�е�Σ�� S���ڴ� 
	printf("the stack is destroyed.\n");
	return 0;
}
//����base��λ����1. //�������Ա���˵���ҵ�һ��Ԫ����O(n)�� 
ElemType GetTop(SqStack S,int pos){
	return *(S.base+pos);//return *(S->top-1);
}//��Ҫ��������ſ���֪�����յĽ�� //�������gettop������getposition. 

int LocateElem(SqStack S,ElemType e){
	ElemType *pt =(ElemType*)malloc(sizeof(ElemType));
	pt = S.base;
	int pos = 0;
	while(pt != (S.top)){
		if (e==*pt)	return pos;
		pt++;
		pos++;
	}
	free(pt);
	return 0;
} 

int Push(SqStack **S,ElemType e){
	printf("#A\n");
	if (((*S)->top-(*S)->base)>=(*S)->size){
		ElemType* newSqList =(ElemType*)realloc((*S)->base,sizeof(ElemType)*(SIZE+INCREMENT));
		
		
		
		if (!*newSqList) return -1;
		(*S)->base=newSqList;
		(*S)->top =(*S)->base+(*S)->size;
		(*S)->size+=INCREMENT;
	}///��ʵ����������realloc�����е�û�ס������� 
//	*((*S)->top) =e;
//	(*S)->top++;
	printf("#A\n");
	(*S)->top =&e;
	(*S)->top =(*S)->top+1;
//	*((*S)->top++)=e;

//	*++(*S)->top=e;//Ӧ������++�ˣ�error 
	
	return 0;
}
//ע��topָ��ָ��������һ������Ԫ�ص���һ���� 
ElemType Pop(SqStack *S){
	ElemType e =*((S)->top-1);
	(S)->top= (S)->top-1;
	printf("%d",e);
	return e;
}
//�ӵ�һ��Ԫ�ؿ�ʼ������Ҳ���Ǵ�base��ʼ���ϵ�top�� 
int StackTraverse(SqStack S){
	if (!(S.base)){
		printf("Empty Stack!\n");
		return -1;
	}
	while (S.base != S.top){
		printf("%d__",S.base);
		S.base++;
	}
	printf("\n");
	return 0;
}
//ʹ��ǿ��������ת��ʵ�ֱ���������ʹ�á� 
int StackEmpty(SqStack S){
	if (S.base==S.top){
//		printf("An empty Stack\n");
		return 0;
	}
	else{
//		printf("Not empty\n");
		return 1;
	}
}
int main(){
	SqStack S;
	InitStack(&S);
	StackTraverse(S);
	ElemType e=10;
	SqStack *S1=&S;
//	[Warning] overflow in implicit constant conversion [-Woverflow]e=1024;
	Push(&S1,e);
	StackTraverse(S);
}
