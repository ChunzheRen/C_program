#include<stdio.h> 
#define SIZE 10
int main(){
	char words[SIZE];
	int i=0;
	puts("enter a string");
	while (fgets(words,SIZE,stdin)!=NULL&&words[0]!='\n'){
//		while(words[i]!='\n'&&words[i]!='\0'){
//			i++;
//		}
//		if (words[i]=='\n'){
//			words[i]='\0';
//		}
//		else{
//			while (getchar()!='\0'){
//				continue;
//			}
//			#�ӻ������м�����ȡ��ֱ����ֹ�� 
//		}
//		puts(words);
		fputs(words,stdout);
	}
	puts("DONE");
	return 0;
}
