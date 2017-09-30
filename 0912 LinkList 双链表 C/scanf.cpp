#include <stdio.h> 
#include <stdlib.h>
typedef int ElemType;
int main(){
//	ElemType e ; //第一种解法 
	ElemType *p = (ElemType *) malloc(sizeof(ElemType));//分配一个匿名的空间，注意free 
	printf("input a number\n");
	scanf("%d",p); //由于scanf 的另外一个参数是提供地址，所以我们需要的是地址&val 或者 直接pointer
//	而用 %p 和 &pointer已经牵扯到了二重指针 
	printf("%d",*p) ;
	//然后就是封装或循环  
	free(p) ;
	return 0;
}
