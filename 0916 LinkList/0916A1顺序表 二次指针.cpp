//���Ա� *Sqlist ʵ�ַ�ʽ 
//��Ҫ������Ҫ��->������. ���о���malloc����ռ䷽��Ĳ�ͬ
//�о����������������Դ���ڿռ��������⣬ 
#include <stdio.h>
#include <stdlib.h>
#include <typeinfo.h>
#define LISTSIZE 1000
#define LISTINCREMENT 10
//��������Ļ�����������Ҫ��Ϥָ����ƶ��Լ�����Ŀ��� 
typedef int ElemType;
typedef struct List{
	ElemType *elem;
	int length;
	int listsize; //sizeof(ElemType)Ϊ��λ���в����� 
}List,*Sqlist;
//List �� Sqlist�����Ƕ��󣬶�����Ҫʵ�����Ĳ����� 
//size���������ж������С�ģ�Ȼ��length���������ж�����ĳ��ȵġ� 
//�����L�Ľ�����һ����ַ�� 
//���Ա�ʾһ���������ڴ棬ֻ��������������������length��listsize 
int InitList(Sqlist *L){
	(*L)->elem = (ElemType*)malloc(sizeof(int)*LISTSIZE);
	//����ռ�һ��Ҫ�û�������,��Ҫ��Sqlsit 
	//Ȼ����ڣ�malloc�ķ�����һ��void*���͡�Ҳ����ָ�����͡�����Sqlist�Լ�����ָ�룬���Բ�����˵�� 
	//�������Ա���ȷ�ķ�ʽ�Ǹ�elem����ռ䣬�����Ǹ�Sqlist����ռ䡣 
	if(!(*L)->elem) return -1;
	(*L)->elem =0;
	(*L)->length =0;
	(*L)->listsize =LISTSIZE;
	return 0;
}

int DestroyList(Sqlist *L){
	if((*L)->elem)    free((*L)->elem);
//	(*L)->elem =NULL;��ʵ�ǲ���Ҫ�� 
	(*L)->length =0;
	(*L)->listsize =0;
	return 0;
}
//��ʵ�ǲ��õ����ڴ��л���Ԫ�صģ���Ϊ���鱾����ǿ��޸ġ�
//Ȼ����ǵ����ѱ�ĵ�ַ�����Ǹ�length�Ϳ����ˡ�
//��destroy���ڱ��ʲ�� 
int ClearList(Sqlist *L){
	(*L)->length =0;
	return 0;
}

//β�˲���Ԫ��  
int InsertTail(Sqlist *L,ElemType e){
	printf("#B\n");
	ElemType *p = (*L)->elem+(*L)->length;
	*p = e;
	printf("#c\n");
	(*L)->length=(*L)->length+1;
	return 1;
}

int DisplayList(Sqlist L){
	if (L->length==0) {
		printf("an empty list.\n");
		return -1;	
	}
	int cts=0;
	for (;cts<L->length;cts++){
		printf("%d_",L->elem+cts);
	}
	printf("that is all.\n");
	return 0;
}
int main(){
	Sqlist Lb;
	InitList(&Lb);
//	printf("length : %d\n",(*Lb).length);
//	ElemType *pt=(ElemType*)malloc(sizeof(int));
//	;//ָ����Ҫ������ռ�ġ� 
//	printf("input a number (q to quit..)\n") ;
//	while(scanf("%d",pt)){
//		InsertTail(&Lb,*pt);
//	}
//	printf("length : %d\n",(*Lb).length);
//	DisplayList(Lb);
	return 0;
}

