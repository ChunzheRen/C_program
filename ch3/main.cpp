#include "SqStack.h"
#include "SqStack.cpp"

//10���Ƶ���8���� //����3.2.1 
//���ڽ��ƵĲ�������Ҫ������/��%���У�%���Ҫ����Ķ�����/���Ҫ����Ķ����� 
int Conversion() {
	SqStack Sa;
	InitStack(&Sa);
	ElemType *number =(ElemType*)malloc(sizeof(ElemType));
	printf("input a number [D]");
	scanf("%d",number);
	
	while(*number){
		Push(&Sa,(*number)%8);
		*number/=8;
	}
	number =Sa->top;
	while(StackEmpty(Sa)){
		Pop(&Sa);
		number--;
	}
	printf("\n");
	return 0;
}
//�Ҿ��øı�һ��ELEMTypeû�����Ⱑ�� 

int main(){
	SqStack Sa;
	InitStack(&Sa);
	ElemType *f=(ElemType*)malloc(sizeof(ElemType));
	printf("#a\n");
	while (scanf("%f",f)){
		printf("you entered %f\n",*f);
		Push(&Sa,*f);
	}
	printf("%f",*(Sa->base));
	StackTraverse(Sa);//������Ϊ��ı�����������Ҫ%d������ģ�Ӧ���ǲ�ƥ�䣬���Ǿ��������ÿ��������Ƚ���ǰ������ת�� 
}
//��֤��ͬ���͵ı仯���. 



