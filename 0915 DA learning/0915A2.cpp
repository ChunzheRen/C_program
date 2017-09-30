#include <stdio.h> 
#include <stdlib.h>
#define MAX_COLS 20
#define MAX_INPUT 1000
int read_column_numbers(int columns[],int max){
	int num=0;
	
	//一步一的填充数组 num就是计数器的作用 ,然后如果你的输入的数组元素到了EOF（0）就自动的停止了。 
	while(num<max && scanf("%d",&columns[num])==1 && columns[num]>=0){
		num++;
		}
		//然后还要确定你的标号是偶数个.
		if(num%2!=0) return -1;
		
		int ch;
		while(ch!=getchar()!=EOF && ch!='\n'){
			continue;
		}
		return num;
	}
void rearrange(char *output,char *const input,int n_columns,int const columns[]){
	int cts=0;//辅助 
	int output_col = 0;//辅助 
	int len =strlen(input); //读入的数组的长度。 常量 
	
	for (;cts<n_columns;cts+=2) {
		int nchars =columns[col+1] -columns[col] +1;
	}
	//就是去读行号，然后根据目标的行号进行选择和输出。 
}
int main(void){	
	int columns[MAX_COLS];	//需要处理的列数 。 
	char input[MAX_INPUT];	//容纳输入行的数组 。 
	char output[MAX_INPUT];//容纳输出行的数组，也就是rearrange操作的结果。 
	int n_columns=read_column_numbers(columns,MAX_COLS);//进行处理的列标号。 
	//注意啊，这个数组可不是按照数值进行传递，而是传递地址。 
	while (gets(input)!=NULL) {
		printf("input is:%s\n",input);
		rearrange(input,output,n_columns,columns);//也就是对于用数组编号进行选择性的output
		printf("the rearraged one is:%s \n",output);
	}
	return 0;
}
