//ջ�Ͷ��У��ǲ����ܵ����Ƶ����Ա�stackջ�ǽ����ڱ�β���в������ɾ�������Ա��������˳�������͸��bottom��������top��//����ȳ���last in first out
//������stack top������ɾ���������˳�ʼ�� �жϿ� ȡtopԪ��
//˳��ջ SqStack
//�ǿ�ջ��ջ��ָ��ʼ��ָ����Ԫ�ص���һ��λ���ϡ� 

//������ԣ�stack��һ�����Ա������ǲ��뷽ʽ�Ĳ�� 
#include<stdio.h>
#include <stdlib.h>
#define SIZE 5
#define INCREMENT 1
typedef int ElemType;
typedef struct Stack{
	ElemType *base;
	ElemType *top;
	int size;
}Stack,*SqStack;
int InitStack(SqStack *S){
	//�������ˣ�����SqStackû�б�����һ���ռ䡣
	*S = (SqStack)malloc(sizeof(struct Stack));
	if(!*S) return -1;
	
//	S= (*SqStack) malloc(sizeof(struct Stack)); Ҳ�ܳɹ����룬���Ǹо��Ͳ��ԣ�����ԭ���Ǹ����� 
	(*S)->base =(ElemType*)malloc(sizeof(ElemType)*SIZE);
	if (!((*S)->base)) return -1;
	
	(*S)->top =(*S)->base;
	(*S)->size = SIZE;
	printf("Maybe successfully initialized.\n");
	return 0;
}
//һ���Ƕ���S�Լ��ռ�ķ����Լ�free������
//һ���Ƕ��������˳���Ĺ���ָ������Ͳ��� ˳������һ�����飬����˵���ǿ�����ָ��������ִ�б���Traverse������ 

int ClearStack(SqStack *S){
	(*S)->top=(*S)->base;
//	*(*S)->base =0;
	return 0;
}

int DestroyStack(SqStack *S){
//	if ((*S)->base) free((*S)->base);
///�����ĸı�����ͷ��ڴ��ǲ��Եġ� 
	(*S)->base = NULL;
	(*S)->top =NULL;
//	free(*S); //�е�Σ�� S���ڴ� 
	printf("the stack is destroyed.\n");
	return 0;
}
int StackEmpty(SqStack S){
	if(S->base =S->top) printf("Empty!\n");
	else printf("Not Empty!\n");
	return 0;
}
//����base��λ����1. //�������Ա���˵���ҵ�һ��Ԫ����O(n)�� 
ElemType GetTop(SqStack S,int pos){
	return *(S->base+pos);//return *(S->top-1);
}//��Ҫ��������ſ���֪�����յĽ�� //�������gettop������getposition. 

int LocateElem(SqStack S,ElemType e){
	ElemType *pt =(ElemType*)malloc(sizeof(ElemType));
	pt = S->base;
	int pos = 0;
	while(pt != (S->top)){
		if (e==*pt)	return pos;
		pt++;
		pos++;
	}
	free(pt);
	return 0;
}//δ֪ 

int Push(SqStack *S,ElemType e){
	if (((*S)->top-(*S)->base)>=(*S)->size){
		ElemType* newSqList =(ElemType*)realloc((*S)->base,sizeof(ElemType)*(SIZE+INCREMENT));
		if (!*newSqList) return -1;
		(*S)->base=newSqList;
		(*S)->top =(*S)->base+(*S)->size;
		(*S)->size+=INCREMENT;
	}///��ʵ����������realloc�����е�û�ס������� 
//	*((*S)->top) =e;
//	(*S)->top++;
	
	*(*S)->top++=e;//�� 

//	*++(*S)->top=e;//Ӧ������++�ˣ�error 
	
	return 0;
}
//ע��topָ��ָ��������һ������Ԫ�ص���һ���� 
ElemType Pop(SqStack *S){
	ElemType e =*((*S)->top-1);
	(*S)->top= (*S)->top-1;
	//*--((*S)->top)
	return e;
}
//�Ľ��棬ֱ����SqStack��Ӱ�����յ���ֵ�� 
int StackTraverse(SqStack S){
	ElemType* pt =(ElemType*)malloc(sizeof(ElemType));
	pt=(S)->base;
	while (pt!=(S->top)){
		printf("%d__",*pt);
		pt++;
	}
	printf("\n");
	return 0;
}
int main(){
	SqStack Sa;
	InitStack(&Sa);
	
	ElemType *e=(ElemType*)malloc(sizeof(ElemType));
	while (scanf("%d",e)){
		printf("you have entered : %d.\n",*e);
		Push(&Sa,*e);
	}
	free(e);
	StackTraverse(Sa);
	StackTraverse(Sa);
	return 0;
}

//2017��9��17��22:16:57
//�ǲ��ǿ�����������д���stack
//���о��ǹ���topָ��Ĳ�������*S��->top -(*S)->base = Stack�е�Ԫ����Ŀ����Ϊtopָ��������һ��Ԫ�صĺ��档 ָ������㡣 
//����Destroy�Ĳ�����Ϊʲôû�취�ͷ��ڴ棿����unable to free  
//������û�ж�S�Լ������ڴ氡�����Ǿ������С������������ԡ��� 
//��μ���ָ���ָ��Ŀռ��ǲ��Ǳ��ͷ��ˣ�����˵�����ĸı���ָ�򣿣���
//���ƵĶ��ǣ�clear���ǰ��ڴ�����Ķ�����գ�����destroy����ȫ�Ĺ黹�ڴ�
//clear�Ĳ������ǵ�����top=base 
//Ԫ�صĳ��Ⱦ���  S.top-S.base������
//S.top-1�����������Ԫ�ء� 

///StackTraverseû������������ħ������������ 
///��ı���base��ָ�򣿣������Ǹ������ݲ����������� 
//�ѵ�˵SqStack����һ��ָ�룬��ʵҲ�ǿ��Ըı����ģ�
//��SqStack��������Ϊ�˸ı���󣬸������Ϊ�˸ı��ڴ��ַ������

//���Ǻܶ�����ָ�룬 

