//D->B
//动态数组 就是指针malloc 
#include<stdio.h>
#include<malloc.h>
#define SIZE 200
int D2B(int Dnumber){
	int DBnumber=Dnumber;
	//动态数组 
	int *Bnumber;//C语言没有动态数组的概念 
	Bnumber = (int*)malloc(sizeof(int)*SIZE);
	if (!Bnumber) return -1;
	int cts=0;
	while((Dnumber>1)){
//		*Bnumber++=Dnumber%2;//不可以 
		Bnumber[cts] =Dnumber%2; 
		Dnumber/=2;
		cts+=1;//动态数组中多了一个数据元素   
		//下面是对于wpt的操作,也就是malloc和realloc数组 
	}
	Bnumber[cts]=Dnumber;
//	*Bnumber++=Dnumber;
	printf("D: %d\nB: ",DBnumber);
	while(cts>=0) {
		printf("%d",Bnumber[cts]);
		cts--;
	}
	free(Bnumber);
	return 0; 
}
int main(){
	printf("D->B:\n");
	int number ;
	scanf("%d",&number);
	D2B(number);
}
