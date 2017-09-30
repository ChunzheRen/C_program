//单链表 目标：暂时用单链表来写，双链表存在着问题。 
//基本的功能：插入删除查找反转 
//2017年9月12日20:31:44 
//尝试实现双链表头结点记录链表长度 
///Arthur: Justin.ShaoHui.ChunZhe.Ren 
///IDE ：Dev C++ 5.11 
//Tips：不需要改变原来链表的函数就用数值传递就好了 
 
#include <stdlib.h> 
#include <stdio.h>
#include <typeinfo.h>
typedef int ElemType ;
typedef struct LNode{
	ElemType data;
	struct LNode* next; 
}LNode,*LinkList; 

int InitList(LinkList *L) {
	(*L)=(LinkList)malloc(sizeof(struct LNode));
	if (!*L) return -1;
	(*L)->data= 0;
	(*L)->next =NULL;
	printf("successfully initialized.\n");
	return 0;
}

//int InitList(LinkList *L) {
//	//初始化的实质就是用 malloc或者new进行空间的分配 
//	(*L)=(LinkList)malloc(sizeof(struct LNode));
//	//【修改】 LinkList 为 struct LNode  
//	if (!*L) return -1;
//	//【修改】 ！L—>！*L 
//	//return 的作用就是返回主函数 
//	(*L)->data= 0;//其实列表的初始化是不需要进行data的赋值的，因为是头结点。 
//	//（*L）->data存储元素的数据 
//	(*L)->next =NULL;
//	printf("successfully initialized.\n");
//	return 0;
//}
int ListEmpty(LinkList L){
	if (!(L->next)){
	 	printf("Empty!\n") ;
		return -1;} 
	else {
		printf("Not Empty!\n");
		return 0;}
}
//涉及到一个对于链表自身的改变，就要求使用二重指针 LinkList*. 
//注意空间的分配，是给结点分配空间，返回一个指向链表的指针，也就是返回LinkList类型，然后分配struct LNode类型。 

//LinkList是指向struct的指针，虽然返回值是这个，但是指针指向的对象所分配的空间是按照struct LNode标准，而不是LinkList 
//到底struct LNode还是LinkList我真是不懂啊。 
int HeadInsert(LinkList *L,ElemType e){
//	工作指针之间,LinkList对象实例化就好,q是要插入的结点 
	LinkList q = (LinkList)malloc(sizeof(struct LNode)); 
	q ->data = e;
	q ->next = (*L)->next;
	(*L)->next = q;
	(*L)->data+=1;
	return 1;
}
int DisplayList(LinkList L){
	if (!(L->next)){
		printf("An empty list\n");
	}
	else{
	LinkList p=(LinkList)malloc(sizeof(struct LNode));  //本质是指针 ,而用ElemType对象的时候就要使用*了。 
	p = L->next;//p指向的是第一个数据元素
	int cts= 1; //计数器 
	if (! p) {
		printf("An empty list\n");
		return -1;//或者判定p 
		}
	else{
		printf("Output the list\n");
		LinkList pointer =(LinkList) malloc(sizeof(struct LNode));
		pointer = L->next;
		while (pointer){
			printf("%d--",pointer->data);
			pointer = pointer->next;	
		}
		free(pointer);
		printf("\n");
//		while(p->next){ //工作指针不是最后一个元素，另外一种方法：用p=L->prev; 
//			printf("the %d element is:%d\n",cts,p->data);
//			p+=1;	//工作指针移向下一个单元 
//		}
//		printf("%d",p->next->data);
	}
	printf("that is all\n");
	return 0;		
	}
	
}
//destroy和clear的区别在于对头结点的保留 ,destroy可以调用clear 
//然后二者都是基于删除结点的。 
//下面的函数用来删除第一个节点 
//删除链表的第一个数据元素  
ElemType DeleteElem(LinkList *L){
	LinkList p=(*L)->next;
	ElemType e=p->data;
	(*L) ->next = p->next;
	free(p);
	(*L)->data-=1;//头结点存储链表的长度 
	return e;
}

int ClearList(LinkList*L) {
	LinkList p=(*L)->next;//p指向第一个节点 
	while(p){//如果链表存在着第一个结点 
		ElemType e;
		e = DeleteElem(L);
		printf("%d\n",e);
		p=(*L) ->next;
	}
	printf("totally cleared,but not destroyed.\n");
	return 0;
}

int DestroyList(LinkList*L){
	ClearList(L);
	free(L);//free操作专门针对的是指针。 
	printf("totally destroyed.\n");
}

ElemType GetElem(LinkList*L,int pos){
	int length =(*L)->data;
	if (pos>length){
		printf("error.\n");
		return -1;
	}
	LinkList p=(*L)->next;
	int cts=1;
	
	for (;cts<pos;){
		p =p->next;			
		cts++;
		}
	ElemType e=p->data;
	return e;
}

int LocateElem(LinkList L,ElemType e){
	LinkList p = L->next;
	int cts =1;
	int elem;
	while (cts<L->data && p){
		if ((p->data) == e){
			elem = cts;
			return elem;
		}
		else{
			cts++;
			p = p->next;
		}
	}
	if (cts>L->data || !p){
		return -1;
	}
}

ElemType PriorElem(LinkList L,ElemType cur_e){
	LinkList p =L->next ;
	if (p->data==cur_e){
		printf("no prior.\n");
		return -1;
	}
	else{
		int pos = LocateElem(L,cur_e);
		ElemType elem1 =GetElem(&L,pos-1);
		printf("the cur_e`s prior element is %d.\n",elem1);
		return elem1;	
	}
}

ElemType DeletePos (LinkList *L,int pos){
	LinkList p= (*L)->next;
	int cts= 1;
	while (cts<pos-1){
		cts++;
		p= p->next;
	}//p当前指向的就是要被删除的元素的前一个。 
	LinkList q =p->next; //q要被删除 
	p->next  = q->next;
	ElemType e = q->data;
	free(q);
	return e;
}

//其实本质上是Simplify的一个变性吧。 
//但是最好是进行位置的插入操作，我去。。。这个涉及到了链表的移动啊。。。。极为复杂啊。。。 
//比较简单的方法：直接输出新的链表，每一个元素，进行新表的比较，要用任意位置的前插和后插。

//前插全部是基于元素的。——突然想到了简化acend的方法，按照元素前插。而且由于是重组列表完全不用在意顺序。
 
int InsertPos (LinkList *L,int pos,ElemType e) {
	LinkList p=(*L)->next;
	int cts =1;
	while(cts<pos-1) {
		p =p->next;
		cts++;
	}//p当前指向的是插入位置前一个 
	LinkList q = (LinkList)malloc(sizeof(struct LNode));
	q->data= e;
	q->next =p->next;
	p->next=q;
	(*L)->data+=1;
	return 0;
}
//不需要写单独的前插后插函数2017年9月14日03:35:14 
//一个逐渐变长的链表 
LinkList AscendList(LinkList *L) {	
	LinkList newL;
	InitList(&newL);
	LinkList p =(*L)->next;
	HeadInsert(&newL,p->data);
	p=p->next;
	int cts=2;
	
	while((cts<((*L)->data+1)) && p){
		int cts2=1;//cts2记录q的情况 
		LinkList q=(newL)->next;//q是刚刚插入的第一个节点 	
		
		int situation=0;
		while((cts2<cts)){
//			printf("q->data: %d\n",q->data);//2
//			printf("p->data: %d\n",p->data);//3
			
			if ((p->data)<=(q->data)){
				situation = 1;
				break; 
			}
			else{
				cts2++;
				q=q->next;
				continue;
			}
		}	
		if (situation ==1){//前面插入 
			if(cts2==1){
				HeadInsert(&newL,ElemType(p->data));//mmp头插入也有问题？？？？？ 
			}
			else{
				InsertPos(&newL,cts2-1,p->data);	
			}
		}
		else{//后面插入 
			InsertPos(&newL,cts2,p->data);
		}
		p=p->next;
		cts++;
	}
	DisplayList(newL);
	return newL;
}

LinkList DescendList(LinkList *L){
	LinkList newL;
	InitList(&newL);
	LinkList p  =(*L)->next;
	HeadInsert(&newL,p->data);
	p=p->next;
	int cts=2;
	
	while((cts<(*L)->data+1) && p){
		int cts2 =1;
		LinkList q =(newL)->next;
		
		int situation =0;
		while (cts2<cts){
			if ((p->data)>=(q->data)){
				situation =1;
				break;
			}
			else{
				cts2++;
				q=q->next;
				continue;
			}
		}
		
		if (situation ==1){//前面插入 
			if(cts2==1){
				printf("END Insert\n");
				HeadInsert(&newL,ElemType(p->data));//mmp头插入也有问题？？？？？ 
			}
			else{
				InsertPos(&newL,cts2-1,p->data);	
			}
		}
		else{//后面插入 
			InsertPos(&newL,cts2,p->data);
		}
		p=p->next;
		cts++;
	}
	return newL;
}

//simplyfy itself needs simplify.
LinkList Simplify(LinkList *L){
	ElemType list[(*L)->data]={};
	LinkList p =(*L)->next;
	int cts=1,length =0;
	
	for (;cts<(*L)->data+1;){
		int i=0;
		for(;i<(*L)->data;i++){
			if(p->data==list[i]){
//				printf("#2A\n");
				break;
			}
		}
		if(i==(*L)->data){
			list[length]=p->data;
//			printf("#3A\n");
			length++;
		}
		p=p->next;
		cts++;
	}

//	for(int i=0;i<length+1;i++){
//		printf("#1A : %d\n",list[i]);
//	}

	LinkList Lb;
	InitList(&Lb);
	for (;length>0;length--){
		HeadInsert(&Lb,list[length-1]);
	}
//	printf("Lb`s lenght :\n%d\n",Lb->data);
	
	return Lb;
}

int main(){
	LinkList La;
	InitList (&La);
	ElemType *pt= (ElemType*)malloc(sizeof(ElemType));

	printf("input a int(press 'q' to quit)\n"); 
	while ((scanf("%d",pt))) {
		//pt本身就是指针，所以不需要额外的地址运算符
		//这种方式：pt指向的就是ElemType类型，所以就是说输入的就是ElemType类型的，可以用typeinfo中的typeid(ElemType)进行验证 
		printf("you have entered:%d  This is the %d elems in this LinkList。\n",*pt,La->data+1);
		HeadInsert(&La,*pt);
	}
	free(pt);
	DisplayList(La);
	
//	ElemType e1=GetElem(&La,2);
//	printf("the 2 position`s number is : %d\n",e1);
//	int pos1=LocateElem(La,4);
//	printf("the element`s position is : %d\n",pos1);
	
//	PriorElem(La,2);

	
//	printf("Destroy all of the list.\n");
//	ClearList(&La);
//	//是DestroyList函数的问题。 
//	DisplayList(La);
//	DestroyList(&La);
//	DisplayList(La);//估计会出错 
	//以上实现了对于第一个La的全部删除。////////////////
	
	
	printf("time to simpltfy the list.\n");
	LinkList Lb =Simplify(&La);
	DisplayList(Lb);

//主要是为了进行递增输出	
	printf("AcendList \n");
	LinkList Lc=AscendList(&Lb);
	DisplayList(Lc);
	
//	printf("descending list \n");
//	LinkList Ld =DescendList(&La);
//	DisplayList(Ld);
	return 0;
}

//注意
//函数的定义，一般我是不会把一个&list平白无故的赋给一个函数作为参数的，
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

//2017年9月13日21:38:33  
//got it!

//2017年9月13日21:50:26
//不骄不躁 ，继续努力。 

//2017年9月13日22:04:32
//注意：一个是malloc函数的使用情况，一个是malloc对于工作指针以及结点的声明是 LinkList pointer = (LinkList) malloc(sizeof(struct LNode));
//还有就是while循环以及循环尽量是用上大括号。 
//然后就是如何实现全局作用域函数的掉用. 

//2017年9月13日23:47:09
//DeleteElem

//2017年9月14日00:34:26
//DestroyElem ClearElem based on DeleteElem 

//2017年9月14日03:13:30
//顺利完成Simplify函数 

//2017年9月14日03:52:50 
//InsertPos 和 AscendList都要检查。都有问题，不过框架大体正确。
 
//2017年9月14日13:07:50
//修复InsertPos  //验证最后一个插入的可能性，尾插的可能性。 没毛病
//怀疑是头结点插入存在问题 -----
//2017年9月14日15:27:29
//头结点插入存在严重问题  
//最令人骄傲的功能就是递增输出了，递减输出。 

//2017年9月14日16:10:45
//还是有BUG存在。。。。 
