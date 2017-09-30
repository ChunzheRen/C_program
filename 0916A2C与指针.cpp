//学习C与指针 
int *p=NULL;
//一个指针不指向任何的数据，是一个宏定义 
#define NULL (void*)0
//(void*)是一种强制性类型转换。 

#include <stdio.h>
int main(){
	int *p =NULL;
	printf("%d\n",p);
	return 0;
}
//NULL使得p指向地址0，所以相对安全。
//NUL 代表\0， EOF也就是字符的结束位置，是ASCII的0号元素。
//void* 指针，单纯的是定义一个指针变量，但是却不说明是保存什么类型的数据。

//递归与迭代的差别：
//递归的常用例子是求阶乘，
//http://blog.csdn.net/shuimanting520/article/details/51360137
 
