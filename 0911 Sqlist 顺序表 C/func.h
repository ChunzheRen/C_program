#define LISTSIZE 100
#define LISTINCREMENT 10
typedef struct Sqlist {
	ElemType *elem;
	int length;
	int listsize;
}Sqlist;
