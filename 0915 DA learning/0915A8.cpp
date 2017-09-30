#include<stdio.h> 
#include<stdlib.h>


int count1bit(unsigned int value){
	int cts=0;
	for (cts=0;value!=0;value=value>>1){
		if (value%2 !=0){
			cts+=1;
		}
	}
	return cts;
}
int main(){
	printf("%d",count1bit(100));
	return 0;
}


#include <stdio.h> 
int main(){
	unsigned int number=1000;
	int location=2;
	//也就是把指定的位数，也就是第三位设置为1
	number = number | 1<<location;
	numebr |=(1<<location) ;
	
	number =number & ~(1<<location); //把指定的位置设置为0
	numebr &~(1<<location) ;
	
	//赋值运算符的顺序是从右到左
	
	while((ch=getchar())!=EOF ) // 会受到位置的影响 、
//	sizeof() 是一个单目运算符号lk 
}
