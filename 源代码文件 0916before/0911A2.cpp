//—ßœ∞malloc   “ª∫≈À≥–Ú±Ì 
#include<stdio.h> 
#include<stdlib.h>

struct List{
	int *elem;
}List,*L;

int main(){
	struct List *La;
	La =(struct List*)malloc(100);
	if(La){
		printf("initialized successfully");
	}
	return 0;
}
