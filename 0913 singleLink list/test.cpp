#include<stdio.h> 
int main(){
	int *p;
	int *q;
	int number[10]={1,2,3,4,5,6,7,8,9,0};
	p=number;
	printf("p: %d\n",*p);
	
	while (p!=&number[10]){
		q=p;
		p=p+1;
		printf("p: %d\n",*p);
		printf("q: %d\n",*q);
		printf("\n");
	}

}
