#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
#define INCERMENT 10
typedef int ElemType;
//typedef ElemType List[SIZE]; 
typedef ElemType* SqList; //然后分配一个SIZE长度的内存，并且用指针的形式进行操作。 我觉得这个更好。
//线性表：老子就是多了个int length。。。。0.0 mmp 

//不就是Sequence List去掉了struct了嘛。 但是malloc的内存还是按照ElemType进行分配的。 
 
int InitList(SqList *S) {
	*S=(ElemType*)malloc(sizeof(ElemType)*SIZE); //再次重申，malloc是随机分配一个内存，返回一个指针，所以必须要用指针类型接收。
	//如果你用的是S，那就是给一个二级指针分配空间，简直搞笑。所以接收类型要明确。 
	if (!S) return -1;//如果还指向一个空的位置，就删除 
	printf("hello world!\n");
	return 0;
}
//先从无序的做起，熟悉指针操作。//务必注意C语言中的数组名是作为指针进行传递的。 
int Insert(SqList *S,int pos,ElemType e){
	*(*S+pos)=e;
	return 0;
}

int ListTraverse(SqList S){
//	ElemType *pos=S;//可以用指针或者不用 ,因为S就是一个头指针，在传递数值副本时可以随意。 
	if(!S) {
		printf("An empty List\n");
	}        // S肯定是有指向的，而且指向的东西不是空的，只不过是因为指向的地方已经被元素给覆盖了 
	while (S){
		printf("%d",*S);
		S++;
	}
}

int main() {
	SqList S; //S自己就是一个指针类型。 也就是ElemType*的类型。 
	InitList(&S);//S的值就是指针的值，也就是一个16进制地址，但是显示成10进制就是70多万。 
//	ElemType * pos =S; //pos是指向指针的指针 ，也就是一个二重指针。【删除】 pos不是二重指针！！！ 基本的指针定义概念。
//						//pos就是一个一级指针 
//	printf("%x",*pos);//地址。 或者说是没有分配地址。 %x 16进制  
	
	printf("After Inserttion!\n");
	ListTraverse(S);
}

//二分法定位元素，插入元素，删除元素。返回特定元素的位置。
 

