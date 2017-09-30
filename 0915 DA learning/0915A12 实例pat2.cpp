//核心就是字符串的字符的读取以及字符转化为一个字符串的过程。，。。
//但是感觉好难啊。
//而且学会了性价比很低 
#include<stdio.h>
#include<ctype.h>
voidint_to_string(intn){
	switch(n){
	case0:
		printf("%s","ling");
		break;
	case1:
		printf("%s","yi");
		break;
	case2:
		printf("%s","er");
		break;
	case3:
		printf("%s","san");
		break;
	case4:
		printf("%s","si");
		break;
	case5:
		printf("%s","wu");
		break;
	case6:
		printf("%s","liu");
		break;
	case7:
		printf("%s","qi");
		break;
	case8:
		printf("%s","ba");
		break;
	case9:
		printf("%s","jiu");
		break;
	default:
		break;
	}
}
//用switch可以暴力拆解，将字符转变为数字。 
voidstring_output(intnum){
	if(num/10){
		string_output(num/10);
		if((num/10)!=0){
			printf("");
		}
		int_to_string(num%10);
	}else{
		int_to_string(num);
	}
}
intget_Input_Sum(){
	charch;
	intsum=0;
	while((ch=getchar())!='\n'){
		if(isdigit(ch)){
			sum+=ch-0x30;
		}
	}
	returnsum;
}
voidint_to_reverse(intnum){
	if(num<0){
		num=-num;
		int_to_string(-1);
		printf("");
		string_output(num);
	}elseif(num==0){
		int_to_string(0);
	}else{
		string_output(num);
	}
}
intmain(){
	
	int_to_reverse(get_Input_Sum());
	return0;
}


//两种不同的思路 ，上面的那个我是在是看不懂。。。。。 
#include<stdio.h>
int char_processor(char ch){
	int number;
	switch(ch){
	case '0':
		number=0;
		printf("%s","ling");
		break;
	case '1':
		number=1;
		printf("%s","yi");
		break;
	case '2':
		number=2;
		printf("%s","er");
		break;
	case '3':
		number=3;
		printf("%s","san");
		break;
	case '4':
		number=4;
		printf("%s","si");
		break;
	case '5':
		number=5;
		printf("%s","wu");
		break;
	case '6':
		number=6;
		printf("%s","liu");
		break;
	case '7':
		number=7;
		printf("%s","qi");
		break;
	case '8':
		number =8;
		printf("%s","ba");
		break;
	case '9':
		number =9;
		printf("%s","jiu");
		break;
	default:
		break;
	}
}
int main(){
	char ch;
	int sum=0;
	ch=getchar();
	int number=0;
	while((ch!='\n')&&(ch!=EOF)){
		number = char_processor(ch);
		sum=number+sum;
		printf("\nsum: %d",sum);
		ch=getchar();
		printf(" ");
	}
	
	printf("\n");
	printf("sum: %d",sum);
	return 0;
}
