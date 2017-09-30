#include<stdio.h> 
typedef struct Student{
	int a = 1;	
};
Student stu1;

//Student是结构的标识符而不是结构的变量名 

struct Student{
	int a =1;
};
struct Student stu1;

typedef struct
{
int num;
int age;
}aaa,bbb,ccc;
===========//等价于 
typedef struct
{
int num;
int age;
}aaa;
typedef aaa bbb;
typedef aaa ccc;



#include<iostream>

struct Student{
	int a =1;
};
Student student;
//本质原因就是面向对象的C++语言是有类的概念的，然后struct也是一个对象public的class。
 
 struct Student
{
int a;
}stu1;//stu1是一个变量
typedef struct Student2
{
int a;
}stu2;//stu2是一个结构体类型

stu1.a=10;
stu2 student2; student2.a=10;



// C/C++ 通用： 
// struct _x1 { ...}x1; 和 typedef struct _x2{ ...} x2; 有什么不同？
//其实, 前者是定义了类_x1和_x1的对象实例x1, 后者是定义了类_x2和_x2的类别名x2 ,
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
