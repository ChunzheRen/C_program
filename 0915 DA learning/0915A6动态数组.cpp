//��̬���� 
//C����û�ж�̬���飬��Ҫrealloc ��free 
//��̬����Ŀռ�������heap 

//���ľ���ָ�� malloc��free 

//Ȼ��ϣ���㳢��һ���������͵Ķ�̬����
//typedef int ElemType 
#include <stdio.h>
#include <stdlib.h> 
int main(){
	int arrlen;
	int *arraypt;
	int cur_e;
	printf("�������鳤��:\n");
	scanf ("%d",&arrlen);
	//��������. 
	arraypt=(int*)malloc(arrlen*sizeof(int));
	if (!arraypt) return -1;
	//i++Ӧ����������ִ�� 
	printf("enter a number(input 'q' to quit).\n");
	
	int i =0;
	while ((scanf("%d",&arraypt[i])) && i<arrlen-1){
		printf("enter a number(input 'q' to quit).\n");
		i++;
	}//������Բ���&����������Ԫ�ر������& 
	
	printf("output.\n");
	int cts1=0;
	while(cts1<i){
		printf("%d_",arraypt[cts1]);
		cts1++;
	}
	
	free(arraypt);
	return 0;
}
