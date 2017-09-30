#include <stdio.h>
#include <stdlib.h>
int func1(int a ,int b){
	return a+b;
}
int func2(){
	int a, b;
	scanf("%d",&a);
	scanf("%d",&b);
	int sum = func1(a,b);
	printf("%d\n",sum);
	return 0;
}
int main(){
	func2();
	return 0;
}
