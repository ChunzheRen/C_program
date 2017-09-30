#include<stdio.h> 
void put1(const char*string){
	while(*string !='\0')
		putchar(*string++);
}
//string类型本质上就是一个指针，对于pointer的加减法和对于解引用指针的加减法完全不一样。
 
 int i =0;
 while (string[i]!='\0'){
 	putchar(string[i++]);
 }
 
 while(*string)
// 当字符串是空白的时候，会输出一个false，但是当你的字符串是一个非空白的时候，就会输出true 
