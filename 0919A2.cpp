#include<stdio.h>
#include <stdlib.h>
typedef int ElemType;

typedef struct Stack
{
    struct Stack *next;
    ElemType data;
} Stack,*LinkStack;

int InitStack(LinkStack *S) {
    *S = (LinkStack)malloc(sizeof(struct Stack));
    if(!*S) return -1;
    (*S)->next=NULL;
    (*S)->data =0;
    printf("Maybe successfully initialized.\n");
    return 0;
}

Solution1:  //available
void DestroyStack(LinkStack *S) {
    while(*S){
        LinkStack pt=(*S);
        (*S)=(*S)->next;
        printf("#a\n");
        DestroyStack(S);
    }
    printf("LinkStack Destroyed!");
}
