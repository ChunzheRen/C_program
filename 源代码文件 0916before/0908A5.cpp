#include<stdio.h>
#include<string.h>
void fit(char *,unsigned int);
int main(){
	char message[]="i love python very much! and i love zhangxiaoxiao very much as well,so maybe i am a fucking ";
	puts (message);
	
	fit(message,9);
	puts (message);
	
	puts("lets look some more")
	puts(message+5);
	
	return 0;
}
void fit(char *string,unsigned int size){
	if (strlen(string)>size)
		string[size]='\0';
}
//�ַ�������һ��������һ��λ�õĶϵ磬�����ʹ�����������ַ�������ͣ�͡� 
