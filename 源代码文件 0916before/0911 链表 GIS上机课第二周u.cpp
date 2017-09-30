#include<iostream>
using namespace std;
//链表不需要连续的内存存储元素，动态存储分配。 
//而顺序表就是一整块连续的内存，静态存储分配。
//链表就是动态存储分配，运行的时候分配更加的灵活。
//元素之间的逻辑关系用指针表示 ，见缝插针，指针如何表示逻辑关系？每个指针指向的是下一个逻辑位置。类似犯罪团伙，单线联系，找到头目就可以联系下线。 

//链表的结构就是若干个结点构成的，是若干个结点构成的。
//数据域存放数据，指针域存放指针。
template <class DataType>
struct Node{
	DataType data;
	Node<DataType> *next;
}; 就可以创建一个节点。 
数据类型不确定 可以把DataType改一下来获得对应的东西。
要写的时候可以加上模板类  类似于 typedef int DataType 

如何引用结点的元素？ 指针的两种操作
s =new Node <int>;
(*s).data  或者  s->data 
如何引用指针域

struct A {
}; 
 int *pointer = &a;
 struct A * psa  =&sa;
 指针 存储的就是地址，需要的是取地址的操作。 *表示解除引用 
 加上星号的意思加上.
 
 struct A {}  其实就是跟 int是同等地位的数据类型。
 A就是一个标识符
 
 对于链表来说引用结点里面的内容就是用 
 空表就是 LinkedList  =NULL; 一个空的和非空的会很不一样。
 一般的把存放数据结点的才叫非空，没有头结点的话，就要多一步判断功能。
  
  然后链表可以没有头结点但是不可以没有头指针，没有头结点的话，头指针指向 
  
==========================================
  
  #include <iostream> 
using namespace std;
template <class DataType>
class Node{
	public:
		
	private:
};
class LinkList {
	public:
		LinkList();
		LinkList(DataType a[],int n);
		~LinkList();
		
		int Length();
		DataType Get(int i);//获得第i个数据元素的数据.
		int Locate(DataType x);
		void Insert(int i ,DataType x);
		DataType Delete (int i );
		void PrintList();
	private:
		Node<DataType> *first;
}; 

//一般的都需要进行遍历拉进行操作。 

核心操作：工作指针的后移，通过工作指针的反复后移将着呢哥哥单链表遍历。
工作指针指向一个位置，指针的后移就是：s->next
让first->next就会使得工作指针移向下一个指针
//p=p->next 或者用p++？？？？？？不可以啊，链表不是一个物理，而是一个逻辑关系，必须要用指针更新。
//遍历的基本操作思想之后就按照位置进行查找，用位置进行查找。 
工作指针初始化，然后累加器count进行初始化。
p为空或者p指向了目标节点就停止。 p后移+（计数器+1） 
p为空的话，第i个元素就不存在了。
while (p!=NULL&&count<i) {
	p=p->next;
	count++;
}
//按照位置查找和按照数值查找 ，从头到尾遍历一遍，以指针指向最后作为结束的标志。
//插入操作——创建节点，改变当前指针的指向，改变后面指针的指向。
s=new Node<DataType >;
s->data =x;
s->next =p->next ;
p->next =s; 

//头结点和元素结点，
没有头结点的话，要把S的地址给头结点。
没有头结点的链表？？？

//头插法——每次都插在头结点的后面，头指针后面的第一个位置。 
s-> data =a[0] ;
s->next =first->next;
first ->next =s;
//尾插法相对来说更难

删除操作
q=p->next ;
x=q->data ;
p->next =q->next;
delete q;  //工作指针 是 p，然后 q是工作指针衍生的下一个指针。  
//首先保留要被删除的结点
//但是不考虑内存吗？？？？

//delete q是删除一个地址  删除方面 链表和顺序表时间复杂度差一级。
//结点的特性就是我们一个节点只能指向下一个节点。

// 单链表为何要设置一个头结点__________ 
// 头指针就是链表的名字。有了头结点，主要是头插入和删除第一个数据元素时候非常方便。 
//头指针具有标识作用，故常用头指针冠以链表的名字。

//typdef struct LNode{
//	int data,
//	LinkList *next;
//}LNode,*LinkList;
//
//LinkList head=new LNode();
//head->next=null;
////插入n个元素
//LinkList p=head;
//for(int i=0;i<n;i++)
// {  LinkList q=new LNode();
//    q->data=i; q->next=null;
//    p->next=q;}
    

 
 
