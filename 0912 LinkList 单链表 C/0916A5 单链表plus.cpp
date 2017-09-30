//另外一种链表，但是仅仅是单链表plus 
//这个是由节点的情况决定的。 
#include <stdio.h>
#include <stdlib.h>
#define LISTSIZE 100

typedef struct LNode{
	ElemType data;
	struct LNode *next;
}*Link,*Position; 
typedef struct{
	Link head,next;
	int len;
}LinkList;//分别指向头尾节点的LinkList 

