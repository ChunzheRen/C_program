#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
int main (){
	int e =1;
	ElemType E;
	E =ElemType(e);
	//�˴���Ҫ���������жϡ�
	if (typeid(ElemType)==typeid(E)) printf("E is ElemType");
	//Ȼ��Typeid��ʹ����Ҫʹ��ElemType����ǿ������ת���������жϡ� 
	//Ȼ������ָ��ľ��ǻ����ϵĲ�����������������������ҪListTransver������ 
	for (int i=) 
	return 0;
} 
