#include<stdio.h> 
#include <stdlib.h>
#define SIZE 10 

//妄想用二次指针进行操作。 然后验证二次指针是不是会对数组造成改变。 
int Traverse2(int **array){
	while((**array)!='\0'){//但是我就始终想不出来到底判断条件是啥。 字符串的末尾倒是\0 
		printf("*array: %d\n",*array);
		printf("**array: %d\n",**array);
		(*array)++;//array++ 是二次指针移动位置，是很危险的。 一开始二次指针指向的是一次指针，然后我让一次指针进行++,应该没错啊。 
		printf("after moving.\n");
		printf("*array: %d\n",*array);//一个很愚蠢的问题就是运算优先级的问题 ，也就是*和++ 
		printf("**array: %d\n",**array);
		printf("ok!\n");
	}//在第一次遍历之后 
	printf("terminated\n");
	return 0;//字符串由于末尾是自动加上了\0，所以直接判断就好。 
}

int Traverse1(int*pt) {
	printf("\nStarting Traversing.\n");
	while((*pt)){
		printf("ok!\n");
		printf("%d",*pt);
		pt++; 
	} 
	printf("i am here.\n");
}

int main(){
	int *array;
	array =(int*) malloc (sizeof(int)*SIZE);  //	int array[SIZE];
	int* pt=array;//pt指向array，修改pt来修改array的值。 
	
	while ((scanf("%d",pt))){		
//		array[cts]=*pt;//array = pt 的意思是让array指向pt，所以必须用*array 
//		*array=*pt;array++;//因为是实际的操作，所以array每次的移动都是指向了一个新的位置，所以说同样大小的指针空间和数组空间并不一样。
		pt++;
	}//赋值操作没有问题 
	printf("用一次指针开始遍历\n");
	Traverse1(array);
	printf("一次指针遍历之后\n"); 
	printf("%d\n",*array);
	
	printf("用二次指针开始遍历\n");
	Traverse2(&array);//一般的数组后面都是\0结尾，直接判断指针解除引用之后是不是\0就好了。
	printf("在二重指针操作之后。\n");
	printf("%d",*array);
	
	return 0 ;
}
//技术验证，关于数组和指针的互换，之后验证二重指针对于函数传递参数的影响。 







//int Traverse1(int*pt) {
//	printf("\nStarting Traversing.\n");
//	while((*pt)){
//		printf("ok!\n");
//		printf("%d",*pt);
//		pt++; 
//	} 
//	printf("i am here.\n");
//}

//int main(){
//	int *array;
//	array =(int*) malloc (sizeof(int)*SIZE);  //	int array[SIZE];
//	int* pt=array;//pt指向array，修改pt来修改array的值。 
//	
//	while ((scanf("%d",pt))){		
////		array[cts]=*pt;//array = pt 的意思是让array指向pt，所以必须用*array 
////		*array=*pt;array++;//因为是实际的操作，所以array每次的移动都是指向了一个新的位置，所以说同样大小的指针空间和数组空间并不一样。
//		pt++;
//	}
//	Traverse(array);//一般的数组后面都是\0结尾，直接判断指针解除引用之后是不是\0就好了。
////	free(array);//一个不是malloc的东西没办法用malloc释放。 动态内存专用 
////	&array是int (*)[10]类型 
//	return 0 ;
//}
////技术验证，关于数组和指针的互换，之后验证二重指针对于函数传递参数的影响。 
