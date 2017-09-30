//3.4 
//先写一个关于char的stack结构
//之后进行3.4算法
#include "SqStack.h"
#include "SqStack.cpp"
#define SIZE 100
//尝试动态数组？？ 我觉得用指针就行吧？ 
int func(){
	SqStack Sa;
	InitStack(&Sa);
	ElemType ch;
	//实现全部输入，多次输出 
	while(ch=getchar()!=EOF){
		while (ch!= EOF && ch!= '\n'){
			switch(ch){
				case '#':Pop(&Sa) ;
				case '@':ClearStack(&Sa);
				default:
					Push(&Sa,ch) ;
			}
			StackTraverse(Sa);
			ClearStack(&Sa);
		}
	}
	return 0;
}
int main() {
	func();
	return 0;
}

//push操作——除了#和@的字符
//pop操作——取决于#或者@的，#-删除一个 @clear stack 

///还是关于输入的操作，在PC中的操作是说一个一个char进行读入。
//ch = getchar() 然后几个标志是：\n和\0

//和scanf的本质差别就是说：scanf是为了向某个东西进行读入，但是getchar是进行读取。 




 
