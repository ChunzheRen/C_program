#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <typeinfo.h>
#define SIZE 5
#define INCREMENT 1
typedef char ElemType;
typedef struct Stack{
	ElemType *base;
	ElemType *top;
	int size;
}Stack,*SqStack;
