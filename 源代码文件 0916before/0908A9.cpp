#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
int main(){
	int LengthString,number;
	char* buffer;
	
	printf("input the length of the string");
	scanf("%d",&LengthString);
	//��˼�Ƿ���һ��charָ�롣 
	buffer = (char*) malloc(100);
	//��˼��100 byte
	if (!buffer) {
		return -1;
	} 
	
	for (int number=0;number<LengthString;number++)
		buffer[n]=rand()%26+'a' ;
	buffer[i]='\0';
	printf("���ɵ�����ַ����ǣ�%s\n",buffer); 
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
	printf("������ɵ��ַ����ǣ�%s\n",buffer);
	free(buffer) ;
	
	
	return 0;
}
