#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
#define INCERMENT 10
typedef int ElemType;
//typedef ElemType List[SIZE]; 
typedef ElemType* SqList; //Ȼ�����һ��SIZE���ȵ��ڴ棬������ָ�����ʽ���в����� �Ҿ���������á�
//���Ա����Ӿ��Ƕ��˸�int length��������0.0 mmp 

//������Sequence Listȥ����struct��� ����malloc���ڴ滹�ǰ���ElemType���з���ġ� 
 
int InitList(SqList *S) {
	*S=(ElemType*)malloc(sizeof(ElemType)*SIZE); //�ٴ����꣬malloc���������һ���ڴ棬����һ��ָ�룬���Ա���Ҫ��ָ�����ͽ��ա�
	//������õ���S���Ǿ��Ǹ�һ������ָ�����ռ䣬��ֱ��Ц�����Խ�������Ҫ��ȷ�� 
	if (!S) return -1;//�����ָ��һ���յ�λ�ã���ɾ�� 
	printf("hello world!\n");
	return 0;
}
//�ȴ������������Ϥָ�������//���ע��C�����е�����������Ϊָ����д��ݵġ� 
int Insert(SqList *S,int pos,ElemType e){
	*(*S+pos)=e;
	return 0;
}

int ListTraverse(SqList S){
//	ElemType *pos=S;//������ָ����߲��� ,��ΪS����һ��ͷָ�룬�ڴ�����ֵ����ʱ�������⡣ 
	if(!S) {
		printf("An empty List\n");
	}        // S�϶�����ָ��ģ�����ָ��Ķ������ǿյģ�ֻ��������Ϊָ��ĵط��Ѿ���Ԫ�ظ������� 
	while (S){
		printf("%d",*S);
		S++;
	}
}

int main() {
	SqList S; //S�Լ�����һ��ָ�����͡� Ҳ����ElemType*�����͡� 
	InitList(&S);//S��ֵ����ָ���ֵ��Ҳ����һ��16���Ƶ�ַ��������ʾ��10���ƾ���70���� 
//	ElemType * pos =S; //pos��ָ��ָ���ָ�� ��Ҳ����һ������ָ�롣��ɾ���� pos���Ƕ���ָ�룡���� ������ָ�붨����
//						//pos����һ��һ��ָ�� 
//	printf("%x",*pos);//��ַ�� ����˵��û�з����ַ�� %x 16����  
	
	printf("After Inserttion!\n");
	ListTraverse(S);
}

//���ַ���λԪ�أ�����Ԫ�أ�ɾ��Ԫ�ء������ض�Ԫ�ص�λ�á�
 

