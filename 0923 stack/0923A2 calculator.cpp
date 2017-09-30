#include "SqStack.h"
#include "SqStack.cpp"
typedef char ElemType;//�ѱ��ʽ�����ַ���� 
//���ǽ����ȼ������ʵ�ʵĲ����� 
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

//�ж�������ǲ�������� 
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
//����������������������֮������㣬Ȼ����������
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
//ע�ⷵ�صĶ�����һ�����Ʊ��ʽ���֮��Ķ�����Ҳ����һ��char 
ElemType Calculate(){
	SqStack operate;
	SqStack operand;
	ElemType a,b,c,x,theta;
	InitStack(&operate);
	Push (&operate,'#');
	InitStack(&operand);
	
//	ֻ��C��������ģ�c��x���бȽϣ�Ȼ��a b theta�������㷢	
//	x��operate��top�� 
//	c�������������Ż����������� ,��t2����x��t1. 
	
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
