#include "SqStack.h"
#include "SqStack.cpp"

//10进制导入8进制 //程序3.2.1 
//对于进制的操作，主要是依靠/和%进行，%获得要输出的东西，/获得要输入的东西。 
int Conversion() {
	SqStack Sa;
	InitStack(&Sa);
	ElemType *number =(ElemType*)malloc(sizeof(ElemType));
	printf("input a number [D]");
	scanf("%d",number);
	
	while(*number){
		Push(&Sa,(*number)%8);
		*number/=8;
	}
	number =Sa->top;
	while(StackEmpty(Sa)){
		Pop(&Sa);
		number--;
	}
	printf("\n");
	return 0;
}
//我觉得改变一个ELEMType没有问题啊。 

int main(){
	SqStack Sa;
	InitStack(&Sa);
	ElemType *f=(ElemType*)malloc(sizeof(ElemType));
	printf("#a\n");
	while (scanf("%f",f)){
		printf("you entered %f\n",*f);
		Push(&Sa,*f);
	}
	printf("%f",*(Sa->base));
	StackTraverse(Sa);//就是因为你的遍历操作是需要%d的输出的，应该是不匹配，除非就是你对于每个输出首先进行前置类型转化 
}
//验证不同类型的变化情况. 



