//��֤ ���������˳�����Ա������ ������&��*��cpp�ļ��� 
#include<stdio.h> 
#include <stdlib.h>
#define LISTSIZE 10
//����struct��SQLIST��Ϊ��ʶ������һ��Alias ��Ҳ��Sqlist. 
typedef struct Sqlist{
	int * Elem ;
	int length;
}Sqlist;

int InitList(Sqlist &L,int number=10,int number2=10){
	int* pointer =(int *)malloc(sizeof(int)*LISTSIZE);
	if(!pointer) return -1;
	(*(L).Elem) = *pointer;
	(L).length= number2;
	return 0;
}
//mmp *L��һ��ʵ�ʶ���(*L).Elem �ֱ����һ��ָ�롣����˵number����Ҫ�õ�ַ���÷��� 
//����InitList�ı����������ڣ�����ElemList�ĳ�ʼ����Ҫ����ռ�ģ� 
 
//*L->length �� *(L->length)�Ĳ�𣿣��� 

int IsEmpty(Sqlist &L){
	if(L.length>0){	
		printf("%d",L.length);
	}
	return 0;
}
int main(){
	Sqlist L;
	//����ĳ�ʼ���Ǵ���һ��ָ��Sqlist��ָ�룬
	//�������ָ��û��ָ���κε�ʵ������
	//����������ǹ������ú�ָ���ں����е������
	
//	(*L).elem �� *(L.elem )�Ĳ��????? 
	InitList(L,10,10);
	IsEmpty(L);
	return 0;
}

//�������������ָ�룬��ô����Ĳ�����Ӧ���ǲ�����ַ�� &val;
//������������ǲ����������ĸ���ʱ��ֱ�Ӵ��������     val;






