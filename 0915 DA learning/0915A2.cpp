#include <stdio.h> 
#include <stdlib.h>
#define MAX_COLS 20
#define MAX_INPUT 1000
int read_column_numbers(int columns[],int max){
	int num=0;
	
	//һ��һ��������� num���Ǽ����������� ,Ȼ�����������������Ԫ�ص���EOF��0�����Զ���ֹͣ�ˡ� 
	while(num<max && scanf("%d",&columns[num])==1 && columns[num]>=0){
		num++;
		}
		//Ȼ��Ҫȷ����ı����ż����.
		if(num%2!=0) return -1;
		
		int ch;
		while(ch!=getchar()!=EOF && ch!='\n'){
			continue;
		}
		return num;
	}
void rearrange(char *output,char *const input,int n_columns,int const columns[]){
	int cts=0;//���� 
	int output_col = 0;//���� 
	int len =strlen(input); //���������ĳ��ȡ� ���� 
	
	for (;cts<n_columns;cts+=2) {
		int nchars =columns[col+1] -columns[col] +1;
	}
	//����ȥ���кţ�Ȼ�����Ŀ����кŽ���ѡ�������� 
}
int main(void){	
	int columns[MAX_COLS];	//��Ҫ��������� �� 
	char input[MAX_INPUT];	//���������е����� �� 
	char output[MAX_INPUT];//��������е����飬Ҳ����rearrange�����Ľ���� 
	int n_columns=read_column_numbers(columns,MAX_COLS);//���д�����б�š� 
	//ע�Ⱑ���������ɲ��ǰ�����ֵ���д��ݣ����Ǵ��ݵ�ַ�� 
	while (gets(input)!=NULL) {
		printf("input is:%s\n",input);
		rearrange(input,output,n_columns,columns);//Ҳ���Ƕ����������Ž���ѡ���Ե�output
		printf("the rearraged one is:%s \n",output);
	}
	return 0;
}
