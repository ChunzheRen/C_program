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
// ע��scanf�Լ�������Ƕ�ȡһ����ַ��Ϊ������Ȼ�󷵻�һ��int��ʾ������������������˵����1��ʾ�ɹ���2��ʾʧ��֮��ġ� 
