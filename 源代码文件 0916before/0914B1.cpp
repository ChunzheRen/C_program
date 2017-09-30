#include <stdio.h> 
int func(){
	int result ;
	int *pointer;
	pointer =&result;
	scanf("%d",pointer);
	int steps =0;
	while (result!=1){
		if (result%2==0){
			result= result/2;
		}
		else{
			result= (result*3+1)/2;
		}
		steps+=1;
	}
	return steps;
}
int main(){
	int result =func();
	printf("%d",result);
	return 0;
}
// 注意scanf自己本身就是读取一个地址作为参数，然后返回一个int表示输入输出的情况，所以说就是1表示成功，2表示失败之类的。 
