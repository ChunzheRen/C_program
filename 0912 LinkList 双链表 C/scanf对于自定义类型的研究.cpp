//研究scanf对于自定义类型的研究。
//自定义类型用指针系列 ，指针必须分配内存系列。
 
#include <stdio.h> 
#include <stdlib.h>
//typedef int ElemType;
//int main(){
//	ElemType *e;
//	scanf("%p",&e);
//	printf("%d",e);
//	printf("%d",(*	e));
//	return 0;
//}

//第二个printf没有分配空间？？？？ 

//程序能编译，但是运行出错 
//输入10 （11） 
//第一次打印16 （17） 【线性+6】 
//第二次打印直接出错 （还是出错） 

 typedef int ElemType;
 int main() {
 	ElemType e;
 	ElemType *pt=&e;
 	//怀疑问题是没有分配一个空间  
	 //必须使用malloc分配一个内存空间 //我自己尝试使用赋值方法。
	 //差别就是指向的内存空间是不是一个被命名符标识的空间。  	 
//	还有一种方式是使用malloc free 组合 解决上述问题，然后问题的解决办法其实本质上就是分配匿名变量。
 	printf("%d",e);
// 	scanf("%p",&pt);  这个解法是错的。 
 	//最新的资料是%p 与 &p得到的是一个二重指针，也就是指针的指针 
 	scanf ("%d",pt); 
 	printf("%d",*pt);
	return 0;
 }
// 可以使用C11的泛型编程技术，或者使用sprintf先转化为字符串，之后自行输出 。 
//解决办法 ，宏+条件编译  自定义输出函数  使用面向对象的语言 ，或者自定义运算符的重载操作。 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

