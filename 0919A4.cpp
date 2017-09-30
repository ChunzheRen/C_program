#include <stdio.h>
#include <stdlib.h>
//int main(){
//	int a[10] ={1,2,3,4,5,6,7,8,9,10};
//	int *pt = &a[2];
//	printf("%d\n",pt[0]);
//	printf("%d\n",(pt[1]));
//	printf("%d\n",*(pt+2));
//	printf("%d\n",(2[a]));  //意思就是 *(2+a[0]) 
//	return 0;	
//}
//数组的数值会被声明为一个常量，也就是会被分配一个固定大小的空间，但是呢，你的指针是不会被分配指向的大小的，所以，使用指针更加灵活，尤其是可以指针运算，但是相对来说是不可以进行数组运算的
//函数传递的都是按照数值进行传递，即使是指针，在最终也是传递一个指针的拷贝，看上去好像是进行了地址的传递
//所以，传递一个non const的指针其实并不安全，最好还是传递一个const 指针，如果你不希望被修改的情况下 





//void strcpy(char *buffer ,char*const string ) {
//	while ((*buffer++==*string++ )!='\0') {
//		continue ;
//	}
//}
//const一般修饰的是左边，然后你用的是char *const string 也就是一个指向char的const指针，是专门防止你修改的，或者说这个指针只能指向固定的位置。
//而const char *pt 可以指向字符串常量是可以修改指向的位置的，应该也是能进行替换的。 
void strcpy(char *buffer,char * string) {
	while ((*buffer ++==*string ++)!='\0'){
		continue;
	}
}
//	char *buffer ="buffer"; //绝逼不对，因为你一个non const指向的是一个const的字符串常量，你觉得可能对吗？
//	其实你的char *本身就是C语言对于数组的独特的规定。

//int strlen(char *str){
//	int len =0;
//	char ch=*str;
//	while(ch){
//		ch=*(str++);
//		printf("%c\n",ch);
//		len++;
//	}
//	return len;
//}
//int main(){
//	char pt[] ="12345";
//	int num = strlen(pt);
//	printf("%d\n",num);
//}


//
//char str[] = "This is the end";
//char input[100];
//
//printf("%s\n", str);
//printf("%c\n", *str);
//
//scanf("%99s", input);



//%s will get all the values until it gets NULL i.e. '\0'.

int main(){
	char *pt ="hello\0world";
	printf("%s",pt);
	printf("\n");
	char *pt1="const stirng";
	while (*pt1){
//		printf("%c",*(pt1));
//		printf("%s",*(pt1));错误的类型会导致输出失败。 
		pt1++;
	}
}

//strcpy的功能就是进行字符串的拷贝，以及自动的添加\0在后面。 



For both *printf and *scanf, %s expects the corresponding argument to be of type char *, 
and for scanf, it had better point to a writable buffer (i.e., not a string literal).
//对于 *scanf 和 *printf 来说，%s都希望遇见的是char*类型 ，然后对于scanf，最好就是指向一个可以修改的变量类型，最好不要是字符串常量。
char *str_constant = "I point to a string literal";  //字符串常量 
char str_buf[] = "I am an array of char initialized with a string literal"; //字符串，可变长度。 

printf("string literal = %s\n", "I am a string literal");  //可迭代的字符串对象 
printf("str_constant = %s\n", str_constant);				//字符串常量    就是指针指向的 
printf("str_buf = %s\n", str_buf);
//printf的%s 可以用char *的""  ，或者是char pt[]的"" 或者是 "" ,总之还是非常的广泛。 
scanf("%55s", str_buf);
//scanf的%s 最好用可迭代的[] 数组类型 ，而不要用字符串。
//scanf一旦涉及到了%s,八成是对于数组的修改，所以就是没有好事，所以就尽量用可迭代对象作为输入的接受者。也就是字符串数组、

//单论字符串， 
//然后就是喜闻乐见的scanf溢出事件，gets也一样，不如用fgets和fputs
//与printf不一样的是，可以进行 输出大小环境的限制。
//用scanf会在第一个空白的位置停下俩。 
 


 
