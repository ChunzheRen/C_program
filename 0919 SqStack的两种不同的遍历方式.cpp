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
//��һ�ַ�ʽ������������û��һ�����ʴ���pt
��������ֱ�ӽ��б�����Ϊ�η�Ҫ�� 
int StackTraverse(SqStack S){
	while (S->base != S->top){
		printf("%d__",*(S->base));
		S->base++;
	}
	printf("\n");
	return 0;
}
