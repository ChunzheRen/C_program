#include "SqStack.h"
#include "SqStack.cpp"
typedef char ElemType;//把表达式当做字符拆解 
//就是将优先级表进行实际的操作： 
ElemType Precede(ElemType t1,ElemType t2){
	ElemType f;
	switch (t2){
		case '+':
		case '-':
			if (t1=='('||t1=='#')
				f='<';
			else 
				f='>';
				break;
		case '*':
		case '/':
			if (t1=='*'||t1=='/'||t1==')')
				f='>';
			else 
				f='<';
				break;
		case '(':
			if (t1==')')
				return -1;
			else 
				f='<';
		case ')':
			switch(t1)
			{
				case '(':
					f='=';
				case '#':
					return -1;
				default:
					f='>';
				
			}
			break;
		case '#':
			switch(t1){
				case '#':
					f='=';
					break;
				case '(':
					return -1;
				default:
					f='=';
			}
		}
		return f;
}

//判断输入的是不是运算符 
int In(ElemType c) {
	switch(c){
		case'+':
		case'-':
		case'*':
		case'/':
		case'(':
		case')':
		case'#':
			return 1;
		default:
			return 0;
	}
}
//定义两个运算符和运算符号之间的运算，然后输出结果：
ElemType Operate(ElemType a,ElemType b,ElemType theta){
	ElemType c;
	a=a-48;
	b=b-48;
	switch(theta){
		case '+':
			c=a+b-48;
		case '-':
			c=a-b+48;
		case'*':
			c=a*b+48;
		case '/':
			c=a/b+48;
	}
	return c;
}
//注意返回的东西是一个类似表达式拆解之后的东西，也就是一个char 
ElemType Calculate(){
	SqStack operate;
	SqStack operand;
	ElemType a,b,c,x,theta;
	InitStack(&operate);
	Push (&operate,'#');
	InitStack(&operand);
	
//	只有C是新输入的，c和x进行比较，然后a b theta进行运算发	
//	x是operate的top。 
//	c是输入的运算符号或者是运算数 ,是t2，而x是t1. 
	
	c=getchar();
	x= *(operate->top);
	while(c!='#'||x!='#'){
		if(In(c)) {
			switch(Precede(x,c))
			{
				case '<':Push(&operate,c);
						c=getchar();
						break;
				case '=':
						x=Pop(&operate);
						c=getchar();
						break;
				case '>':
						x=Pop(&operate);
						a=Pop(&operand);
						b=Pop(&operand);
						Push(&operand,Operate(a,b,theta));
						break;
			} 
		}
	}
	
}



int main(){
	
}
