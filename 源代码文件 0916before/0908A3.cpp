#include<stdio.h> 
void put1(const char*string){
	while(*string !='\0')
		putchar(*string++);
}
//string���ͱ����Ͼ���һ��ָ�룬����pointer�ļӼ����Ͷ��ڽ�����ָ��ļӼ�����ȫ��һ����
 
 int i =0;
 while (string[i]!='\0'){
 	putchar(string[i++]);
 }
 
 while(*string)
// ���ַ����ǿհ׵�ʱ�򣬻����һ��false�����ǵ�����ַ�����һ���ǿհ׵�ʱ�򣬾ͻ����true 
