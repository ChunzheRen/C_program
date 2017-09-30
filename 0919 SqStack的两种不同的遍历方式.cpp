int StackTraverse(SqStack *S){
	while(((*S)->top-(*S)->base )==0){
		printf("nothing to traverse , an empty Stack!\n");
		return -1;
	}
	ElemType *pt = (*S)->base;
	for(int i=0;i<((*S)->top-(*S)->base);i++){
		printf("%d__",*pt);
		pt ++;
	}
	printf("\n");
	free(pt);
	return 0;
}
//第一种方式最大的问题在于没有一个合适处理pt
明明可以直接进行遍历，为何非要用 
int StackTraverse(SqStack S){
	while (S->base != S->top){
		printf("%d__",*(S->base));
		S->base++;
	}
	printf("\n");
	return 0;
}
