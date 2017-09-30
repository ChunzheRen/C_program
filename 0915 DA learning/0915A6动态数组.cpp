//动态数组 
//C语言没有动态数组，需要realloc 和free 
//动态数组的空间来自于heap 

//核心就是指针 malloc和free 

//然后希望你尝试一下任意类型的动态数组
//typedef int ElemType 
#include <stdio.h>
#include <stdlib.h> 
int main(){
	int arrlen;
	int *arraypt;
	int cur_e;
	printf("输入数组长度:\n");
	scanf ("%d",&arrlen);
	//处理数组. 
	arraypt=(int*)malloc(arrlen*sizeof(int));
	if (!arraypt) return -1;
	//i++应该是在最后才执行 
	printf("enter a number(input 'q' to quit).\n");
	
	int i =0;
	while ((scanf("%d",&arraypt[i])) && i<arrlen-1){
		printf("enter a number(input 'q' to quit).\n");
		i++;
	}//数组可以不加&，但是数组元素必须加上& 
	
	printf("output.\n");
	int cts1=0;
	while(cts1<i){
		printf("%d_",arraypt[cts1]);
		cts1++;
	}
	
	free(arraypt);
	return 0;
}
