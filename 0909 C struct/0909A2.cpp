#include<stdio.h> 
typedef struct Student{
	int a = 1;	
};
Student stu1;

//Student�ǽṹ�ı�ʶ�������ǽṹ�ı����� 

struct Student{
	int a =1;
};
struct Student stu1;

typedef struct
{
int num;
int age;
}aaa,bbb,ccc;
===========//�ȼ��� 
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
//����ԭ�������������C++����������ĸ���ģ�Ȼ��structҲ��һ������public��class��
 
 struct Student
{
int a;
}stu1;//stu1��һ������
typedef struct Student2
{
int a;
}stu2;//stu2��һ���ṹ������

stu1.a=10;
stu2 student2; student2.a=10;



// C/C++ ͨ�ã� 
// struct _x1 { ...}x1; �� typedef struct _x2{ ...} x2; ��ʲô��ͬ��
//��ʵ, ǰ���Ƕ�������_x1��_x1�Ķ���ʵ��x1, �����Ƕ�������_x2��_x2�������x2 ,
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
