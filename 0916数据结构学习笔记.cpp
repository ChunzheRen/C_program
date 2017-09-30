//线性表的话 
Initlist 	列表初始化 
ListEmpty	判断列表是不是空的 
ClearList	清除表格 
GetElem 	根据元素获得位置信息 
LocateElem	根据位置确定元素 
ListInsert	添加某个位置的元素 
ListDelete 删除某个位置的元素 
Listlength 返回长度 

typedef int ElemType;
//线性表就是一块连续的地址,你可以把sqlist中的elem理解为一个数组。 
typedef struct Sqlist() {
	ElemType *int ;
	int length;
	int listsize; 
}
//union的操作用到了ListLength,GetElem,LocateElem,ListInsert等基本方法。
void Union(Sqlist *A ,Sqlist B) {
	int La_len,Lb_len ,cts;
	ELemType e;
	for (cts=1;i<Lb_len;i++){
		GetElem (Lb,i,&e);
		if (!LocateElem(&La,&e)){
			ListInsert(&La,&e)
		}
	}
}
//了解大体思路：找元素，确定位置，列表插入。
//关于e的&e，其实这个不是很C语言，引用传递参数应用较少。
//C更多的是 用指针指向这个地址，之后传递指针。 
//引用根本就不是C语言的概念。 

//线性表就是不断的想一个连续的内存空间里面插入元素，然后也许需要一定的malloc和realloc操作，当然不要忘记free
 SQLIST Init() {
 	Sqlist L;
 	L.length =0;
 	return L;
 }
 
 SQLIST CREATE(){
 	//线性表的插入方式就是对于存储空间的重新分配，
	//也就是,不断的插入元素。 
	L.data[] =e;
 }	
//其实线性表也是存在着工作指针的，只不过数组名就是。不需要额外的。 

//插入操作 
//插入的位置不合理就error
//线性表的长度大于数组的长度——动态realloc进行扩大容量
//最后一个元素开始，向后移动一个位置，然后插入位置之后的元素都要做这些操作。
//要插入的元素放在要插入的位置。 
//修改表长+1 

//删除
//如果删除位置不合理，抛出异常
//取出删除元素
//从删除元素位置开始遍历到最后一个元素位置，分别将它们向前移动一个位置
//表长减1.

//线性表的顺序存储结构，在存/读数据时，不管是哪个位置，时间复杂度O(1)，而插入或删除时，时间复杂度都是O(n)。

//链表的插入O(1) ,但是寻找元素O(n)

//使用链表结构可以克服数组链表需要预先知道数据大小的缺点，
//链表结构可以充分利用计算机内存空间，实现灵活的内存动态管理。
//但是链表失去了数组随机读取的优点，同时链表由于增加了结点的指针域，
//空间开销比较大。在计算机科学中，链表作为一种基础的数据结构可以用来生成其它类型的数据结构。

//插入操作处理顺序：中间节点的逻辑，后节点逻辑，前节点逻辑。按照这个顺序处理可以完成任何链表的插入操作。
//删除操作的处理顺序：前节点逻辑，后节点逻辑，中间节点逻辑。

//单链表实际上是由节点（Node）组成的，一个链表拥有不定数量的节点。而向外暴露的只有一个头节点（Head）
//二重指针可以实现对于指针的修改，否则单纯的指针传递会被传递为副本，其实还好，但是一旦是对于副本指针进行插入和删除的操作，
//结果就会导致出现副本指针指向了一个新的位置，而原来的指针指向的位置是另外一码事情。
 
//链表的作用是可以存储一些顺序类型的元素比如说是字符串 

//尾插法 
void CreateListTail(LinkList *L, ElemType e)
{
	LinkList p,r;
	int i;
	*L = (LinkList)malloc(sizeof(Node)); /* L?????? */
	r=*L;                                /* r???????? */
	for (i=0; i < n; i++)
	{
		p = (Node *)malloc(sizeof(Node)); /*  ????? */
		p->data = rand()%100+1;           /*  ????100????? */
		r->next=p;                        /* ??????????????? */
		r = p;                            /* ???????????????? */
	}
	r->next = NULL;                       /* ???????? */
}

//需要一个工作指针时刻指向最后一个元素
//p->next =q;
//p=q;//将当前的元素指向最后一个元素的位置 


void Merge(List La,List Lb,List &Lc) {
	Init
}
 
// 关于函数选用的东西到底是用Struct LNODE
// 还是用一个struct LNODE*   完全看你想传递数值还是地址。
// LinkList 其实是一个指向 头指针的变量，然后这个变量的二重指针LinkList*也经常被是用 

