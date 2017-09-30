//2017年9月11日21:50:20
///author ：Justin.Shaohui.Chunzhe.Ren 
#include <stdio.h>
#include <stdlib.h>
#include <typeinfo.h>
#define LISTSIZE 100
#define LISTINCREMENT 10
//新的体会，一个elem就是第一个元素的位置，这个元素类似于数组的0号元素 
typedef int ElemType;
typedef struct Sqlist {
	ElemType *elem;
	int length;
	int listsize;
}Sqlist;
//用Sqlist结尾与*Sqlist 结尾有很大差别。后者直接是一个对象实例了？？？？ 
//函数要不要用二重指针？？？？ 
int InitList(Sqlist *L) {
	(*L).elem = (ElemType *)malloc(LISTSIZE * sizeof(ElemType));
	if ((*L).elem) return -1;
	(*L).length = 0;
	(*L).listsize = LISTSIZE;
	return 0;
}
int DestroyList(Sqlist *L) {
	if (!(*L).elem) free((*L).elem);
	//这个free与我们的初始化的方式有很大的关系 
//	(*L).elem = (ElemType*) malloc(size);________free((*L).elem);
	//释放完毕空间之后 
	(*L).elem =NULL;
	(*L).length =0;
	(*L).listsize = 0;
	return 0; 
}
 //clearlist  和destroylist的差别？？？ ——要学习 InsertList。
//destroylist销毁头结点中首结点指针指向的线性存储空间
//clearlist  单纯修改逻辑关系值 
int ClearList(Sqlist *L){
	(*L).length =0;
	return 0;
}

//这些不涉及列表加工，单纯输出列表属性的东西不必要指针。 
//一个 用于输出当前列表是否为空的情况，但是可以和输出长度合并。
 
int ListEmpty(Sqlist *L){
	if ((*L).length ==0) {
		printf("it`s empty now\n"); 
		return 1;
	}
	else {
		printf("it`s not empty\n"); 
		return 0;
	}
}

int ListLength(Sqlist *L){
	printf("list length : %d",(*L).length); 
	return (*L).length;
} 

ElemType GetElem(Sqlist *L,int pos ){
	if ( pos<1 || pos>((*L).length))
		printf("input erroe");
		return -1;
	ElemType e;
	e = *((*L).elem+pos-1);
	return e;
}

int LocateElem (Sqlist *L,ElemType e){
	int cts;
	for (cts=0;cts<=(*L).length-1;cts++){
		if (*((*L).elem+cts) == e) return cts+1;
	}
	return -1;
}
//问题就是pos的数值确定的问题。？？？？？？ 
//现在看来最大的问题就是顺序表的第一个元素到底是啥的问题。 
int InsertElem(Sqlist *L,int pos,ElemType e){
	//初始化部分 
	ElemType *newbase,*p,*q;
	//首先判断是不是可行的。。。。。。
	if (pos<1 || pos>(*L).length+1) return -1;
	//判断是不是需要增加空间
	if ((*L).length>(*L).listsize) {
		newbase = (ElemType *)realloc((*L).elem,sizeof(ElemType)*((*L).listsize+LISTINCREMENT));
		if (!newbase) return -1;
		(*L).elem = newbase;
		(*L).listsize+=LISTINCREMENT;
	}
	q=(*L).elem +pos-1; ///新的感想，指针加减法不是单纯的加减法，而是根据存储空间进行加减法 
	//然后为啥要用这个地址我还是不知道 
	for(p =(*L).elem+(*L).length-1;p>=q;p--) 
		*(p+1)=*p;
	*q =e;
	(*L).length +=1;
	return 0;
}
ElemType DeleteElem(Sqlist *L,int pos){
	ElemType e= -1 ;
	if (pos<1||pos>(*L).length +1) return -1;
	ElemType *p ,*q;//要被删除的对象是p ，工作指针q
	p=(*L).elem + pos -1; //整个程序对于pos的定义我个人是定义为第pos个有效数据元素，也就是数组的[pos-1] 
	e = *p;
	q =(*L).elem+ (*L).length-1;
	for (q;q>=p;p--){
		*(p-1)=*p;
	}
	(*L).length -=1;
	return e;
}
//int main() {
//	Sqlist La;
//	int length;
//	ElemType e [10]={1,2,3,4,5,6,7,8,9,10};
////	一开始创建的是Sqlist *La 但是似乎是由于没有分配空间？ 
////	后来用的是Sqlist *La = NULL 但是指向的是空的位置 最后也不行 
//	InitList(&La);
//	
//	if ((La).elem)//一定要注意是判断La的地址是不是一个空的。 
//	//可以用&La 或者La.x进行判断。问题来了，判断的是不是一个内存地址的内容。 
//		printf("ok ,successfully initialized\n");
//	
//	ListEmpty(&La);
//	printf("%d",La.listsize);
//	printf("\n");
//	
//	ClearList(&La);
//	ListEmpty(&La);
//	DestroyList(&La);
//	ListEmpty(&La);
//
//	ElemType *p,*q;
//	for (int pos=0;pos<10;pos++) {
//		p = (La).elem +pos-1;
//		for(q = (La).elem+(La).length -1;q>p;q--){
//			*(q+1)=*q;
//		}
//		p=&e[pos];
//		(La).length +=1;
//	}
//	printf("i am here\n");
//	
//	for (int i=0;i<10;i++){
//		printf("the %d element is: %d\n",(i+1),((La).elem+i));
//	}
//	
//	printf("congratulations\n");
//	return 0;
//}


///然后下面就是Merge等等二次操作 

