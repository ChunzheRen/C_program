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
////aliasesforstudent就是一个struct的别名== mmp 
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
////aliasforstruct就是一个实例，何必纠结？ 


struct structname{
	int a =111;
}aliasforstruct,*anothername;
//标识符就是区分不同的struct，然后变量名字就是区分不同的变量，
//二者 有交集，但是不完全一样。 
struct structname stu1;
//anothername 是一个指向结构structname标识符 的指针 。然后自己也是一个被实例化的对象 。 
 
int main(){
	printf("%d",stu1.a);
	printf("\n");
	printf("%d",anothername->a);
	return 0;
}

//2017年9月11日20:15:05 
//发现typedef 就是一个可以省略struct 的关键字  


























