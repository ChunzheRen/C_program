//2017��9��18��19:59:35 //
//û�н��Stack  input�����⣬�ͺ����Ρ� 
#include <stdlib.h> 
#include <stdio.h>
#define SIZE 5
#define INCREMENT 2
typedef int ElemType;
typedef struct Stack{
	ElemType *top;
	ElemType *base;
	int size;
}Stack,*SqStack;

int InitStack(SqStack *S){
	*S =(SqStack)malloc(sizeof(struct Stack));
	if (!*S) return -1;
	(*S)->base= (ElemType*)malloc(sizeof(ElemType)*SIZE);
	if(!(*S)->base) return -1;
	(*S)->top=(*S)->base;
	(*S)->size = SIZE;
	return 0;
}
int DestroyStack(SqStack *S){
	if(!*S) {
		printf("Already destroyed!\n");
		return -1;
	}
	(*S)->top =NULL;
	(*S)->base =NULL;
	free((*S)->base);
	free(*S);
	printf("Successfully destroyed!\n");
	return 0;
}


//int StackTraverse(SqStack *S){
//	while(((*S)->top-(*S)->base )==0){
//		printf("nothing to traverse , an empty Stack!\n");
//		return -1;
//	}
//	ElemType *pt = (*S)->base;
//	for(int i=0;i<((*S)->top-(*S)->base);i++){
//		printf("%d__",*pt);
//		pt ++;
//	}
//	printf("\n");
//	free(pt);
//	return 0;
//}
int StackTraverse(SqStack S){
	while (S->base != S->top){
		printf("%d__",*(S->base));
		S->base++;
	}
	printf("\n");
	return 0;
}



int Push1(SqStack *S,ElemType e){
	if (((*S)->top-(*S)->base)>=(*S)->size){
		ElemType* newSqList =(ElemType*)realloc((*S)->base,sizeof(ElemType)*(SIZE+INCREMENT));
		if (!*newSqList) return -1;
		(*S)->base=newSqList;
		(*S)->top =(*S)->base+(*S)->size;
		(*S)->size+=INCREMENT;
	}///��ʵ����������realloc�����е�û�ס������� 
//	*((*S)->top) =e;
//	(*S)->top++;
	
	*(*S)->top++=e;//�� 

//	*++(*S)->top=e;//Ӧ������++�ˣ�error 
	
	return 0;
}
int Push(SqStack*S,ElemType e){
	if ((((*S)->base)-((*S)->top))>(*S)->size) {
		(*S)->base = (ElemType*)realloc((*S)->base,(sizeof(ElemType)*(SIZE+INCREMENT)));
		//�ڴ�λ�÷����˱仯��ָ��Ҫ�������·��䡣 
		(*S)->top= (*S)->base +(*S)->size;
		(*S)->size +=INCREMENT;
	}
	*((*S)->top)++ =e;
	return 0;
}
ElemType Pop (SqStack *S){
	ElemType e;
	e=*((*S)->top)--;
	(*S)->top =(*S)->top--;
	return e ;
}
int main(){
	SqStack Sa;
	InitStack(&Sa);
	ElemType *e =(ElemType*)malloc(sizeof(ElemType));
	while (scanf("%d",e)){
//		Push1(&Sa,*e);
		Push(&Sa,*e);
		printf("you have entered : %d\n",*e);
	}
	free(e);
	//���ָ��ӵ�ַ��Ӧ����û�б����ȥ�ɡ�
	//������ͬ�Ķ�����Ӧ����ָ���ƶ�λ�ó�������ɡ� 
	//�����ʱStackTraverse�����⡣������ 
	StackTraverse(Sa);
	DestroyStack(&Sa);
	return 0;
}

//����Ӧ���ǲ��뵽��ͬһ��λ�ã����Ե���������ʧ�ܣ������λ�õ�һ�����ã��Ժ�Ķ���һ��λ���ˡ� 
