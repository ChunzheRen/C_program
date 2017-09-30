//用于检验Sqlist和*sqlist 
#include <stdio.h>
#include <stdlib.h>
#define LISTSIZE 100
typedef int ElemType;
typedef struct Sqlist {
	ElemType *elem;
	int length;
	int listsize;
}Sqlist,*Sqlist2;

int InitList(Sqlist *L) {
	(*L).elem = (ElemType *)malloc(LISTSIZE * sizeof(ElemType));
	if ((*L).elem) return -1;
	(*L).length = 0;
	(*L).listsize = LISTSIZE;
	return 0;
}

int main(){
	Sqlist L;
	InitList(&L);
	if (&L) printf("success");
	return 0;
}
