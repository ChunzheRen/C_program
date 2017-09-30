#include "SqStack.h"
#include "SqStack.cpp"
typedef char ElemType;
//可不可以实现数值和操作符的类型的分离？但是输入都是要输入字符串啊 
//数字之间进行ascii的比较实质上是比较ascii对应的数值情况。 
ElemType Precede(ElemType a,ElemType b){
	switch(a){//下面的case都是a可能出现的情况。 
		case '+' :
		case '-' :
			if (b=='+'||b=='-'||b==')'||b=='#') return'>';
			else if(b=='*'||b=='/'||b=='(') return '<';
		case '*':
		case '/':
			if (b=='(') return '<';
			else return '>';
		case '(':
			if (b=='+'||b=='-'||b=='*'||b=='/'||b=='(') return '<';
			else if(b=')') return '=';
			else exit(-1);
		case ')':
			if (b=='+'||b=='-'||b=='*'||b=='/') return '>';
			else if (b==')'||b=='#') return '>';
			else exit(-1);
		case '#':
			if (b=='+'||b=='-'||b=='*'||b=='/'||b=='(') return '<';
			else if (b=='#') return '=';
			else exit(-1);	
	}
}

int In(ElemType c ){
	switch(c){
		case '+':
		case '-':
		case '*':
		case '/':
		case '(':
		case ')':
		case '#':
			return 1;
		default:
			return 0;
	}
}

ElemType  calculate(ElemType a,ElemType theta,ElemType b){
	ElemType c;
	a=a-48;
	b=b-48;
	switch(theta){
		case'+':
			c=a+b+48;
		case '-':
			c=a-b+48;
		case '*':
			c=a*b+48;
		case '/':
			c=a/b+48;
	}
	return c;
}

ElemType func(){
	SqStack operate;
	SqStack number;
	InitStack(&operate);
	InitStack(&number);
	ElemType a,b,theta,c,x;
	
	Push(&operate,'#');
	StackTraverse(operate);
	printf("#A\n");
//	x比你的c运算优先级高的话，就先进去 
	while((c=getchar())!='\0'){
		printf("here\n");
		x=*--operate->top;
		printf("%c\n",x);
		if(In(c)){
		switch(x,c){
			case '<':
				Push(&operate,c);
				printf("case<\n");
				c=getchar();//防止\n，正式程序必须删除。getchar会读取\n 
				continue;
			case '>':
				a=Pop(&number);
				b=Pop(&number);
				theta =c;
				c=calculate(a,theta,b);
				Push(&number,c);
				printf("case>\n");
				c=getchar();
				continue;
			case '=':
				Pop(&operate);
				printf("case=\n");
				c=getchar();
				continue;
			}
		}
		else if(!In(c)){
			Push(&number,c);//进去的都是字符形式的数字. 
			StackTraverse(number);
			continue;
			}
		else {
			printf("\nERROR\n");
			return 0;
		}
	}
	return c;
}



///getchar会不会读取缓冲区里面的\n??? 
//int main(){
//	ElemType c,x;
//	while(c=getchar!='\0'){
//		x=func();
//	}
//	printf("%c",x);
//	return 0;
//}
//感觉原来的程序的push有问题,但push的问题出在一个对于char的处理上面。 

