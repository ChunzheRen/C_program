//Iteration
#include <stdio.h> 
#include <stdlib.h>
int printstring(int number){
	int result =number/10;
	if (result!=0){
		printstring(result);
	}
	putchar(number%10+'\0');
	
}
int main(){
	printstring(1024);
}
