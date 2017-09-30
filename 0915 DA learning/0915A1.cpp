//列的编号用-1结尾表示的是EOFile 
//注意文件的输入存在着换行符以及文件结束符。 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXCOLS 20
#define MAXINPUT 1000

int ColumnNumber(int column[], int max){
	int num = 0 ;
	
	//判断条件：一个是没有读到最后一个元素，一个是读取一切都顺利，一个是读取的colume不是-1 EOF  ？？？？ 
	//读取列表号，读取的东西小于0就停止。 //scanf的读取是输出int作为状态标志符的。 //行数被当做一个数组进行输入
	while((num<max) && (scanf("%d",&column[num])) ==1 && (column[num]>=0)){
		num+=1;
	}
	if (num%2!=0){
		printf("没有读取偶数对的列对数\n");
		return -1 ; 
	}
	//处理缓冲区里面超过20位需要的char，也就是继续逐字符的读取然后进行continue操作。直到换行字符或者EOF（里面没有任何东西了）。 
	int ch; 
	while ((ch= getchar())!=EOF && ch!='\n'){
		continue;    
	} 
	return num;
}
//由于数组的性质，在C语言中必须传递地址，应该是传递数值方式的时候会被认为无效。 
//所以，希望数数组作为参数必须用指针作为形式参数，这个后果就是数组存在被修改的风险 。char *pt
//所以为了防止数组被修改，我们需要的就是用char *const pt; const修饰的一般是左边，也就是一个指针常量，不改变地址。
//如果是const char* pt，就要求你的输入必须也是一个const修饰的实际参数，这个应用具有极大的局限性。 
void rearrange(char*output,char const *input,int n_columns,int const columns[]){
	
}
//数组被看做一个指针，在C语言中用引用传递的方式传递地址。
//数组参数本身并不需要增加一个&，但是假如用scanf处理数组中的某一个特定元素的时候，就需要我们用&string[]; 
//gets 去掉\n并加上NUL puts加上\n（NUL被保留？？？？）
//fgets 保留\n，fputs也不删除\n，也就是对于字符串内部的内容不做处理 
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
//注意：调增部分是在循环执行完毕之后的执行的，并不是先执行之后再循环。

//strcpy和strncpy负责字符串的覆盖复制操作，然后一般的就是把第二个字符串覆盖第一个字符串，因而第一个字符串不可以是字符常量。
//然后strcat是复制操作。？？？？可不可以使用字符串数组作为这些标准IO函数的参数？？ 



 
