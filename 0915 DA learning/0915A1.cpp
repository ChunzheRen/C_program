//�еı����-1��β��ʾ����EOFile 
//ע���ļ�����������Ż��з��Լ��ļ��������� 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXCOLS 20
#define MAXINPUT 1000

int ColumnNumber(int column[], int max){
	int num = 0 ;
	
	//�ж�������һ����û�ж������һ��Ԫ�أ�һ���Ƕ�ȡһ�ж�˳����һ���Ƕ�ȡ��colume����-1 EOF  �������� 
	//��ȡ�б�ţ���ȡ�Ķ���С��0��ֹͣ�� //scanf�Ķ�ȡ�����int��Ϊ״̬��־���ġ� //����������һ�������������
	while((num<max) && (scanf("%d",&column[num])) ==1 && (column[num]>=0)){
		num+=1;
	}
	if (num%2!=0){
		printf("û�ж�ȡż���Ե��ж���\n");
		return -1 ; 
	}
	//�����������泬��20λ��Ҫ��char��Ҳ���Ǽ������ַ��Ķ�ȡȻ�����continue������ֱ�������ַ�����EOF������û���κζ����ˣ��� 
	int ch; 
	while ((ch= getchar())!=EOF && ch!='\n'){
		continue;    
	} 
	return num;
}
//������������ʣ���C�����б��봫�ݵ�ַ��Ӧ���Ǵ�����ֵ��ʽ��ʱ��ᱻ��Ϊ��Ч�� 
//���ԣ�ϣ����������Ϊ����������ָ����Ϊ��ʽ����������������������ڱ��޸ĵķ��� ��char *pt
//����Ϊ�˷�ֹ���鱻�޸ģ�������Ҫ�ľ�����char *const pt; const���ε�һ������ߣ�Ҳ����һ��ָ�볣�������ı��ַ��
//�����const char* pt����Ҫ������������Ҳ��һ��const���ε�ʵ�ʲ��������Ӧ�þ��м���ľ����ԡ� 
void rearrange(char*output,char const *input,int n_columns,int const columns[]){
	
}
//���鱻����һ��ָ�룬��C�����������ô��ݵķ�ʽ���ݵ�ַ��
//���������������Ҫ����һ��&�����Ǽ�����scanf���������е�ĳһ���ض�Ԫ�ص�ʱ�򣬾���Ҫ������&string[]; 
//gets ȥ��\n������NUL puts����\n��NUL����������������
//fgets ����\n��fputsҲ��ɾ��\n��Ҳ���Ƕ����ַ����ڲ������ݲ������� 
int main(){
	int n_columns;
	int columns(MAXCOLS);
	char input(MAXINPUT);
	char output(MAXINPUT);
	
	n_columns =ColumnNumber(columns,MAXCOLS);
	while (gets(input)!=NULL){
		printf("original inputs:%s\n,input");
		rearrange(output,input,n_columns,columns);
		printf("rearranged line: %s\n",output);
	}
	return  0;
}
//ע�⣺������������ѭ��ִ�����֮���ִ�еģ���������ִ��֮����ѭ����

//strcpy��strncpy�����ַ����ĸ��Ǹ��Ʋ�����Ȼ��һ��ľ��ǰѵڶ����ַ������ǵ�һ���ַ����������һ���ַ������������ַ�������
//Ȼ��strcat�Ǹ��Ʋ��������������ɲ�����ʹ���ַ���������Ϊ��Щ��׼IO�����Ĳ������� 



 
