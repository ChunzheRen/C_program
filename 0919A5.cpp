#include <stdio.h> 
#include <stdlib.h>
//int main(){
//	char *pt ="hello" ;//一个连续的内存 
////	char pt[]="hello";//数组类型的内存 
//	*(pt+1)='m';
//	printf("%s",pt);
//	
////	int vector[10],*pt = vector;
//	int matrix[2][3]={{1,2,3},{4,5,6}};
//	int (*pt2)[3] =matrix;
//	printf("%d",(*pt2)[1]);
//}
//不要吧多维数组想象为一个矩阵，而是要判断为数组的嵌套。
//多元数组的存储是按照最右边的变化作为行主要顺序。00-01-02-03-04-10-11-12-13-14这种存储方式
 
int main() {
	int matrix[10]={1,2,3,4,5,6,7,8,9,10};
	int *pt=matrix;
	printf("%d\n",*pt);
	printf("%d\n",*++pt);
	printf("%d\n",*pt++);
	printf("%d\n",*++pt);
}
++ 和* 由于是从右向左，所以先计算右边的，后计算左边的，但是也要考虑结合的情况。 
