#include <stdio.h> 
#include <stdlib.h>
typedef int ElemType;
int main(){
//	ElemType e ; //��һ�ֽⷨ 
	ElemType *p = (ElemType *) malloc(sizeof(ElemType));//����һ�������Ŀռ䣬ע��free 
	printf("input a number\n");
	scanf("%d",p); //����scanf ������һ���������ṩ��ַ������������Ҫ���ǵ�ַ&val ���� ֱ��pointer
//	���� %p �� &pointer�Ѿ�ǣ�����˶���ָ�� 
	printf("%d",*p) ;
	//Ȼ����Ƿ�װ��ѭ��  
	free(p) ;
	return 0;
}
