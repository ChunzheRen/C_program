#include <stdio.h> 
#include <stdlib.h>
//int main(){
//	char *pt ="hello" ;//һ���������ڴ� 
////	char pt[]="hello";//�������͵��ڴ� 
//	*(pt+1)='m';
//	printf("%s",pt);
//	
////	int vector[10],*pt = vector;
//	int matrix[2][3]={{1,2,3},{4,5,6}};
//	int (*pt2)[3] =matrix;
//	printf("%d",(*pt2)[1]);
//}
//��Ҫ�ɶ�ά��������Ϊһ�����󣬶���Ҫ�ж�Ϊ�����Ƕ�ס�
//��Ԫ����Ĵ洢�ǰ������ұߵı仯��Ϊ����Ҫ˳��00-01-02-03-04-10-11-12-13-14���ִ洢��ʽ
 
int main() {
	int matrix[10]={1,2,3,4,5,6,7,8,9,10};
	int *pt=matrix;
	printf("%d\n",*pt);
	printf("%d\n",*++pt);
	printf("%d\n",*pt++);
	printf("%d\n",*++pt);
}
++ ��* �����Ǵ������������ȼ����ұߵģ��������ߵģ�����ҲҪ���ǽ�ϵ������ 
