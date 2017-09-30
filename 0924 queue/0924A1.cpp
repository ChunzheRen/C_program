#include "func.h"
#include "func.cpp"

int main(){
	Queue Q;
	InitQueue(&Q);
	struct Node*pt =(struct Node*)malloc(sizeof(struct Node));
	ElemType *e=(ElemType*)malloc(sizeof(ElemType));
	while(scanf("%d",e)){
		Push(&Q,*e);
		printf("you have pushed :%d\n",*e);
	}
	QueueTraverse(&Q);
	free(e);
	free(pt);
	return 0;
}
