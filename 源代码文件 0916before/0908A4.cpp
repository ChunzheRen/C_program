//字符串自己可以是一个数组名，用双括号括起来的字符串或者说是声明为char *的变量。
//const char*string可以提醒用户，你的字符串不一定要是一个数组。 
#include <stdio.h>
int puts(const char*string){
	int count =0;
	while(*string){
		putchar(*string++);
		count++;
	}
	putchar('\n');
	return count;
}



