#include<stdio.h> 
#include<stdlib.h>


int count1bit(unsigned int value){
	int cts=0;
	for (cts=0;value!=0;value=value>>1){
		if (value%2 !=0){
			cts+=1;
		}
	}
	return cts;
}
int main(){
	printf("%d",count1bit(100));
	return 0;
}


#include <stdio.h> 
int main(){
	unsigned int number=1000;
	int location=2;
	//Ҳ���ǰ�ָ����λ����Ҳ���ǵ���λ����Ϊ1
	number = number | 1<<location;
	numebr |=(1<<location) ;
	
	number =number & ~(1<<location); //��ָ����λ������Ϊ0
	numebr &~(1<<location) ;
	
	//��ֵ�������˳���Ǵ��ҵ���
	
	while((ch=getchar())!=EOF ) // ���ܵ�λ�õ�Ӱ�� ��
//	sizeof() ��һ����Ŀ�������lk 
}
