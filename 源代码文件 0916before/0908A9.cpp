#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
int main(){
	int LengthString,number;
	char* buffer;
	
	printf("input the length of the string");
	scanf("%d",&LengthString);
	//意思是返回一个char指针。 
	buffer = (char*) malloc(100);
	//意思是100 byte
	if (!buffer) {
		return -1;
	} 
	
	for (int number=0;number<LengthString;number++)
		buffer[n]=rand()%26+'a' ;
	buffer[i]='\0';
	printf("生成的随机字符串是：%s\n",buffer); 
	free (buffer) ;
	
	return 0;
	
}

#define SIZE 1000
int main(){
	int ListSize ,number;
	char *buffer;
	
	buffer =(char*) malloc(SIZE);
	if (!buffer){
		return -1;
	}
	
	for (int number=0;number<ListSize;number++)
		buffer[n]=rand() %26+'a';
	buffer[i]='\0';
	printf("随机生成的字符串是：%s\n",buffer);
	free(buffer) ;
	
	
	return 0;
}
