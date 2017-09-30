#include<stdio.h>
#define SIZE 10
int main(){
	char words[SIZE];
	puts("Enter string:(press an empty line to quit)");
	while(fgets(words,SIZE,stdin))!=NULL && words[0]!='\n'){
		fputs(words,stdout);
	}
	puts("Done");
	return 0;
}
