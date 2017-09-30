#include<stdio.h> 
char * s_gets(char *st,int n ){
	char *ret_val;
	int i =0;
//这上面的东西有啥用处吗 
	ret_val =fgets(st,n,stdin);
//	#如果的确受到了东西就进入循环，否则输出一个NULL 
	if (ret_val){
		while(st[i]!='\n'&&st[i]!='\0') {
			i++;
		}
		if(st[i]='\n')
			st[i]='\0';//相当于结束字符串 
		else:
			while (getchar()!='\n')
			continue;
//	#抛弃其余的输入 
	}
	return ret_val;
}
//#输入一个变量，然后就是输出指定长度的字符串。 
//这个是用来替换前面的gets函数的，然后一是可以抛弃多余的输入，但是不合适的输入就是直接返回-1结束程序 
