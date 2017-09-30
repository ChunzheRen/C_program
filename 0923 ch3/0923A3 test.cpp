#include "SqStack.h"
#include "SqStack.cpp"
typedef char ElemType;
//�ɲ�����ʵ����ֵ�Ͳ����������͵ķ��룿�������붼��Ҫ�����ַ����� 
//����֮�����ascii�ıȽ�ʵ�����ǱȽ�ascii��Ӧ����ֵ����� 
ElemType Precede(ElemType a,ElemType b){
	switch(a){//�����case����a���ܳ��ֵ������ 
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
//	x�����c�������ȼ��ߵĻ������Ƚ�ȥ 
	while((c=getchar())!='\0'){
		printf("here\n");
		x=*--operate->top;
		printf("%c\n",x);
		if(In(c)){
		switch(x,c){
			case '<':
				Push(&operate,c);
				printf("case<\n");
				c=getchar();//��ֹ\n����ʽ�������ɾ����getchar���ȡ\n 
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
			Push(&number,c);//��ȥ�Ķ����ַ���ʽ������. 
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



///getchar�᲻���ȡ�����������\n??? 
//int main(){
//	ElemType c,x;
//	while(c=getchar!='\0'){
//		x=func();
//	}
//	printf("%c",x);
//	return 0;
//}
//�о�ԭ���ĳ����push������,��push���������һ������char�Ĵ������档 

