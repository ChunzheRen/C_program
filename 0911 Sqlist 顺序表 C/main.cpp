#include <stdio.h>
#include <stdlib.h>
#include <typeinfo.h>
typedef int ElemType;
#include "func.h"
#include "func.cpp"

int main(){
	Sqlist La; 
//	Sqlist Lb;
	int e;
	ElemType E;
	 
	InitList (&La);
	if(!La.elem) printf("successfully initialized\n");
	ListEmpty(&La);
	
	ListLength(&La);
	//Ϊ�ε�ǰ�������һ��47�������Ҿ���Ӧ����400�������������� 
	
	for (int i=0;i<10;i++){
		//��һ����ʵ��һ������EOF��ֹͣ�ĳ��� 
		printf("input a number:\n");
		scanf ("%d",&e);
		E =ElemType(e);
		InsertElem(&La,i,E);
	}
	//Ϊɶ��������֮���GG,Ӧ���Ǵ洢�ռ�����⡣ 
	for (int i =0;i<10;i++) {
		ElemType E =*((La).elem +i);
		int e =  int(E);
		printf("the %d elem is:%d\n",i,e);
	}
	ListLength(&La);
	printf("congratulations\n");
	return 0;
	//���Ա��transverse���ܡ� 
}

