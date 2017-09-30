#include <iostream>
#include <malloc.h>
#define LIST_SIZE 100
#define LIST_INCREMENT 10

typedef int BASICELEM;
typedef struct {
	BASICELEM *elem;
	int length;
	int listsize;
}Sqlist;

int InitList(Sqlist &L) {
	L.elem = (BASICELEM* )malloc((LIST_SIZE) * sizeof(BASICELEM));
	if (!L.elem) {
		return -1;
	}
	L.length = 0;
	L.listsize = LIST_SIZE;
	return 0;
}
int LocateElem(Sqlist &L,BASICELEM elem ) {
	int position = -1;
	for (int i = 0; i < L.length; i++) {
		if (L.elem[i] == elem) {
			position = i;
		}
	}
	return position;
}








int main() {
	return 0;
}
