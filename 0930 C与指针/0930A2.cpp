#include<stdio.h> 
#include <stdlib.h>
#define SIZE 10 

//�����ö���ָ����в����� Ȼ����֤����ָ���ǲ��ǻ��������ɸı䡣 
int Traverse2(int **array){
	while((**array)!='\0'){//�����Ҿ�ʼ���벻���������ж�������ɶ�� �ַ�����ĩβ����\0 
		printf("*array: %d\n",*array);
		printf("**array: %d\n",**array);
		(*array)++;//array++ �Ƕ���ָ���ƶ�λ�ã��Ǻ�Σ�յġ� һ��ʼ����ָ��ָ�����һ��ָ�룬Ȼ������һ��ָ�����++,Ӧ��û���� 
		printf("after moving.\n");
		printf("*array: %d\n",*array);//һ�����޴�����������������ȼ������� ��Ҳ����*��++ 
		printf("**array: %d\n",**array);
		printf("ok!\n");
	}//�ڵ�һ�α���֮�� 
	printf("terminated\n");
	return 0;//�ַ�������ĩβ���Զ�������\0������ֱ���жϾͺá� 
}

int Traverse1(int*pt) {
	printf("\nStarting Traversing.\n");
	while((*pt)){
		printf("ok!\n");
		printf("%d",*pt);
		pt++; 
	} 
	printf("i am here.\n");
}

int main(){
	int *array;
	array =(int*) malloc (sizeof(int)*SIZE);  //	int array[SIZE];
	int* pt=array;//ptָ��array���޸�pt���޸�array��ֵ�� 
	
	while ((scanf("%d",pt))){		
//		array[cts]=*pt;//array = pt ����˼����arrayָ��pt�����Ա�����*array 
//		*array=*pt;array++;//��Ϊ��ʵ�ʵĲ���������arrayÿ�ε��ƶ�����ָ����һ���µ�λ�ã�����˵ͬ����С��ָ��ռ������ռ䲢��һ����
		pt++;
	}//��ֵ����û������ 
	printf("��һ��ָ�뿪ʼ����\n");
	Traverse1(array);
	printf("һ��ָ�����֮��\n"); 
	printf("%d\n",*array);
	
	printf("�ö���ָ�뿪ʼ����\n");
	Traverse2(&array);//һ���������涼��\0��β��ֱ���ж�ָ��������֮���ǲ���\0�ͺ��ˡ�
	printf("�ڶ���ָ�����֮��\n");
	printf("%d",*array);
	
	return 0 ;
}
//������֤�����������ָ��Ļ�����֮����֤����ָ����ں������ݲ�����Ӱ�졣 







//int Traverse1(int*pt) {
//	printf("\nStarting Traversing.\n");
//	while((*pt)){
//		printf("ok!\n");
//		printf("%d",*pt);
//		pt++; 
//	} 
//	printf("i am here.\n");
//}

//int main(){
//	int *array;
//	array =(int*) malloc (sizeof(int)*SIZE);  //	int array[SIZE];
//	int* pt=array;//ptָ��array���޸�pt���޸�array��ֵ�� 
//	
//	while ((scanf("%d",pt))){		
////		array[cts]=*pt;//array = pt ����˼����arrayָ��pt�����Ա�����*array 
////		*array=*pt;array++;//��Ϊ��ʵ�ʵĲ���������arrayÿ�ε��ƶ�����ָ����һ���µ�λ�ã�����˵ͬ����С��ָ��ռ������ռ䲢��һ����
//		pt++;
//	}
//	Traverse(array);//һ���������涼��\0��β��ֱ���ж�ָ��������֮���ǲ���\0�ͺ��ˡ�
////	free(array);//һ������malloc�Ķ���û�취��malloc�ͷš� ��̬�ڴ�ר�� 
////	&array��int (*)[10]���� 
//	return 0 ;
//}
////������֤�����������ָ��Ļ�����֮����֤����ָ����ں������ݲ�����Ӱ�졣 
