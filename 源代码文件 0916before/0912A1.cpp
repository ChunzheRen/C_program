#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
int main (){
	int e =1;
	ElemType E;
	E =ElemType(e);
	//此处需要数据类型判断。
	if (typeid(ElemType)==typeid(E)) printf("E is ElemType");
	//然后Typeid的使用需要使用ElemType进行强制类型转化和类型判断。 
	//然后下面指向的就是基本上的插入操作和输出操作，并且需要ListTransver操作。 
	for (int i=) 
	return 0;
} 
