//����һ���������ǽ����ǵ�����plus 
//������ɽڵ����������ġ� 
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
}LinkList;//�ֱ�ָ��ͷβ�ڵ��LinkList 

