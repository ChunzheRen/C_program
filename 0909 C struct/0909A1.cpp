#include <stdio.h>
//typedef struct Student{
//	int a =1 ;	
//};
//int main(){
//	Student stu1;
//	printf("%d:\n",stu1.a);
//	return 0;
//}
//
//typedef struct structname{
//	int a=1;
//}aliasesforstudent;
////aliasesforstudent����һ��struct�ı���== mmp 
//int main(){
//	structname stu1;
//	aliasesforstudent stu2;
//	
//	printf("%d",stu1.a);
//	printf("\n");
//	printf("%d",stu2.a);
//	return 0;
//}
//
//struct structname{
//	int a =1;
//};
//int main(){
//	struct structname stu1;
//	printf("%d",stu1);
//	return 0;
//}
//
//
//struct structname{
//	int a =1;
//}aliasforstruct;
//
//int main(){
//	struct structname stu1;
////	struct aliasforstruct stu2;
//	printf("%d",stu1.a);
//	printf("\n");
////	printf("%d",stu2);
//	printf("%d",aliasforstruct.a);
//	return 0;
//}
////aliasforstruct����һ��ʵ�����αؾ��᣿ 


struct structname{
	int a =111;
}aliasforstruct,*anothername;
//��ʶ���������ֲ�ͬ��struct��Ȼ��������־������ֲ�ͬ�ı�����
//���� �н��������ǲ���ȫһ���� 
struct structname stu1;
//anothername ��һ��ָ��ṹstructname��ʶ�� ��ָ�� ��Ȼ���Լ�Ҳ��һ����ʵ�����Ķ��� �� 
 
int main(){
	printf("%d",stu1.a);
	printf("\n");
	printf("%d",anothername->a);
	return 0;
}

//2017��9��11��20:15:05 
//����typedef ����һ������ʡ��struct �Ĺؼ���  


























