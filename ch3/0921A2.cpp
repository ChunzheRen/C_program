//3.4 
//��дһ������char��stack�ṹ
//֮�����3.4�㷨
#include "SqStack.h"
#include "SqStack.cpp"
#define SIZE 100
//���Զ�̬���飿�� �Ҿ�����ָ����аɣ� 
int func(){
	SqStack Sa;
	InitStack(&Sa);
	ElemType ch;
	//ʵ��ȫ�����룬������ 
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

//push������������#��@���ַ�
//pop��������ȡ����#����@�ģ�#-ɾ��һ�� @clear stack 

///���ǹ�������Ĳ�������PC�еĲ�����˵һ��һ��char���ж��롣
//ch = getchar() Ȼ�󼸸���־�ǣ�\n��\0

//��scanf�ı��ʲ�����˵��scanf��Ϊ����ĳ���������ж��룬����getchar�ǽ��ж�ȡ�� 




 
