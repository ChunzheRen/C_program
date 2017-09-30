#include "SqStack.h"
#include "SqStack.cpp"
#define SIZE 100
int check(){
	SqStack Sa;
	InitStack(&Sa);
	ElemType string1 [SIZE];//匹配括号最好用字符串以及\0。 //ch可以指向一个字符串常量或者指向一个字符数组。 
	//用scanf就是没办法处理空格。 
	fgets(string1,SIZE,stdin);
		ElemType *ch=string1;
		//读取进来的东西存储之后是\n\0 
		while((*ch)!='\n'){
			if(!isalnum(*ch)){
				Push(&Sa,*ch);
				}
			ch++;
			}
	ElemType *ch1=Sa->base;
	while(*ch1!='\0'){
		printf("%c",*ch1);
		ch1++;
	}//读取()还是有问题。。。 
	return 0;
}//解决ch读取无限循环的方法就是了解你的fgets读取之后的操作。 

int main(){
	check();
	return 0;
}

//虽然这个gets函数是一次读取一个字符，但是实际上即使你连续的输入，gets也是读取一个字符。 

// gets(ch);
// p=ch;
// while(*p) {
// p++; 
//也就是虽然是整个的读取，但是后续的处理是一个个的，也就是利用了指针是数组的第一个元素这个特性。
	 

//fgets函数就是加上了一个\0,然后保留从缓冲区读取的\n.
//gets函数删除\n  

//更进一步的算法就是将输出的东西与输入的东西进行对比 

//2017年9月21日18:57:45
 
//比较完善的算法：
//根据你的输入，判断你的输出，首先，只有括号会被放进来，当你输入的是左括号的时候，使用的是亚栈操作，
//当你输入的是右括号的时候，采取的措施是输出pop，并且根据逻辑判断，是不是匹配的。
//push的条件——唯一——左括号
//pop条件——右括号并且进行比较 
