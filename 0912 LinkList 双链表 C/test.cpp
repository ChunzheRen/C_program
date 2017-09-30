//单链表 目标：暂时用单链表来写，双链表存在着问题。 
//基本的功能：插入删除查找反转 
//2017年9月12日20:31:44 
//尝试实现双链表头结点记录链表长度 
///Arthur: Justin.ShaoHui.ChunZhe.Ren 
///IDE ：Dev C++ 5.11 
//Tips：不需要改变原来链表的函数就用数值传递就好了 
//双链表相对于单链表的优势不明显 ？？还是安安心心学好单链表就够了。 
#include <stdlib.h> 
#include <stdio.h>
typedef int ElemType ;
typedef struct LNode{
	ElemType data;
	struct LNode* next; 
}LNode,*LinkList; 
//涉及到一个对于链表自身的改变，就要求使用二重指针 LinkList* 【 
int InitList(LinkList *L) {
	//初始化的实质就是用 malloc或者new进行空间的分配 
	(*L)=(LinkList)malloc(sizeof(LinkList));
	//一定要注意两边的参数的一致性。 
	if (!L) return -1;
	//return 的作用就是返回主函数 
	(*L)->data= 0;
	(*L)->next =NULL;
//	(*L)->prev =NULL;
	printf("successfully initialized.\n");
	return 0;
}
 
//初始化的是头指针以及头结点，双链表的头尾节点都是空的。 
//所有涉及到这些操作列表的，都是需要加上LinkList的。
 
int HeadInsert(LinkList *L,ElemType e){
	//插入的东西是啥 ，然后首先创建节点再说别的。
	LinkList p = (LinkList)malloc(sizeof(LinkList));
	(p)->data =e;
	(p)->next =(*L)->next;
//	p->prev = (*L);
	(*L)->next = p;
	free(p);
	return 0;
}
//} 
//int TailInsert()
//int InsertElem()  



int DisplayList(LinkList L){
	//首先创建工作指针，自己觉得没必要考虑prev指针
	LinkList p=(LinkList)malloc(sizeof(LinkList));  //本质是指针 ,而用ElemType对象的时候就要使用*了。 
	p = L->next;//p指向的是第一个数据元素 
	int cts= 1; //计数器 
	//本来是想用ListEmpty来解决问题的，但是后来发现ListEmpty没办法在这个scope中引用啊。 
	if (! p) {
		return -1;//或者判定p 
	}
	else {
		printf("output the list\n");
		while(p->next){ //工作指针不是最后一个元素，另外一种方法：用p=L->prev; 
			printf("the %d element is:%d\n",cts,p->data);
			p+=1;	//工作指针移向下一个单元 
		}
		printf("%d",p->next->data);
	}
	printf("that is all\n");
	return 0;
} 
ElemType LocateElem(LinkList L,int pos){
	LinkList p=(LinkList )malloc(sizeof(LinkList));
	p = L->next;
	int cts=1;
	for (;cts<pos;cts++){
		if (p)
			p =  p->next;
		else {
			printf("error.\n");
			return -1;
		}
	}
	ElemType e = p->data; 
	return e;
}
//int NextElem()
//int PrevElem()

int ListEmpty(LinkList L){
	if (!(L->next)){
	 	printf("Empty!\n") ;
		return -1;} 
	else {
		printf("Not Empty!\n");
		return 0;}
}

//int ClearList()
//int DestroyList()
//int TransverList()

int main(){
	LinkList La;
	InitList (&La);
//	ElemType e[10] = {10,11,12,13,14,15,16,17,18,19};
	ListEmpty (La);
	//以后可以实现根据你需要的元素大小进行输入的操作 
	ElemType *pt= (ElemType*) malloc(sizeof(ElemType));
	
//	printf("input a int(press 'q' to quit)\n"); 
//	while ((scanf("%d",pt))) //pt本身就是指针，所以不需要额外的地址运算符 
//		printf("you have entered:%d\n",*pt);
//		HeadInsert(&La,*pt);

	ElemType e[5] ={1,2,3,4,5};
	for (int i=0;i<5;i++){
		HeadInsert(&La,e[i]);
	}
	
	free(pt);
	printf("everything ok.\n");
	ListEmpty(La);
//	DisplayList(La);
	

	LinkList pointer =(LinkList) malloc(sizeof(LinkList));
	pointer = La->next;
	printf("%d\n",pointer->data);
	pointer= pointer->next;
	printf ("%d\n",pointer->data);
	

	return 0;
}

//注意函数的定义，一般我是不会把一个&list平白无故的赋给一个函数作为参数的，
//一般的还是要用一个按照数值传递的方式传递参数。而C语言中用&La传递参数是一个标准配置。 

//2017年9月13日17:17:12 
//明明显示的是插入三个元素。但是就输出来一个，问题应该在于没插进去。 
//准备写一个寻找特定位置元素的函数，来检验我的链表到底有没有插进去

//2017年9月13日17:21:27
//还有一个问题就是我现在丝毫没有体会出双链表的感觉。 

//2017年9月13日17:29:51
//问题还是存在于InsertElem存在问题。 问题就是双链表的插入存在着吉大的问题。是双链表啊啊啊啊啊。 
//错误的原因是因为下一个元素是空的，也就是HeadInsert的问题。 

//2017年9月13日20:41:56
//放弃双链表，改为学习已有的单链表的实现。
//改为调用已有单链表的接口实现操作。
//改为改写重构已有单链表。 
