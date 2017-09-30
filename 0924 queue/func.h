///链表型队列 不循环  
#include <stdio.h> 
#include <stdlib.h>
#include <typeinfo.h>
#include <string.h>

typedef int ElemType;
typedef struct Node{
	ElemType data;
	struct Node *next;
}Node,*QNode;
typedef struct Queue{
	struct Node *head;
	struct Node *tail;
}Queue,*SqQueue;
