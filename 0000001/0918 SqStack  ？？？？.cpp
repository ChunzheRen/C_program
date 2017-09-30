//2017年9月18日19:59:35 //
//没有解决Stack  input的问题，就很尴尬。 
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
	}///其实对于上述的realloc还是有点没谱。。。。 
//	*((*S)->top) =e;
//	(*S)->top++;
	
	*(*S)->top++=e;//： 

//	*++(*S)->top=e;//应该是先++了，error 
	
	return 0;
}
int Push(SqStack*S,ElemType e){
	if ((((*S)->base)-((*S)->top))>(*S)->size) {
		(*S)->base = (ElemType*)realloc((*S)->base,(sizeof(ElemType)*(SIZE+INCREMENT)));
		//内存位置发生了变化，指针要进行重新分配。 
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
	//出现复杂地址，应该是没有保存进去吧。
	//出现相同的东西，应该是指针移动位置出现问题吧。 
	//最后发现时StackTraverse的问题。。。。 
	StackTraverse(Sa);
	DestroyStack(&Sa);
	return 0;
}

//问题应该是插入到了同一个位置，所以导致了最后的失败，插入的位置第一个还好，以后的都在一个位置了。 
