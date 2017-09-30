typedef char ElemType;
typedef struct Stack{
	ElemType *top;
	ElemType *base;
	int size =90;
}Stack,*SqStack;
int StackTraverse(SqStack S){
	while (S-base==S->top){
		return -1;
	}
	ElemType *pt=S->top;
	while (S->top!=S->base){
		printf("%c\n",*pt);
		S->top--;
	}
	return 0;
}
int Pop(SqStack *S){
	S->
}
