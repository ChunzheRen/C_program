//�ַ����Լ�������һ������������˫�������������ַ�������˵������Ϊchar *�ı�����
//const char*string���������û�������ַ�����һ��Ҫ��һ�����顣 
#include <stdio.h>
int puts(const char*string){
	int count =0;
	while(*string){
		putchar(*string++);
		count++;
	}
	putchar('\n');
	return count;
}



