//D->B
//��̬���� ����ָ��malloc 
#include<stdio.h>
#include<malloc.h>
#define SIZE 200
int D2B(int Dnumber){
	int DBnumber=Dnumber;
	//��̬���� 
	int *Bnumber;//C����û�ж�̬����ĸ��� 
	Bnumber = (int*)malloc(sizeof(int)*SIZE);
	if (!Bnumber) return -1;
	int cts=0;
	while((Dnumber>1)){
//		*Bnumber++=Dnumber%2;//������ 
		Bnumber[cts] =Dnumber%2; 
		Dnumber/=2;
		cts+=1;//��̬�����ж���һ������Ԫ��   
		//�����Ƕ���wpt�Ĳ���,Ҳ����malloc��realloc���� 
	}
	Bnumber[cts]=Dnumber;
//	*Bnumber++=Dnumber;
	printf("D: %d\nB: ",DBnumber);
	while(cts>=0) {
		printf("%d",Bnumber[cts]);
		cts--;
	}
	free(Bnumber);
	return 0; 
}
int main(){
	printf("D->B:\n");
	int number ;
	scanf("%d",&number);
	D2B(number);
}
