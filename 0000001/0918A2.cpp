//单链表插入删除结点
int insert(LinkList *L,char keyword,char newdata) {
	LinkList newpt =(LinkList)malloc(sizoef(struct LNode));
	newpt->data =newdata;
	LinkList pt=(LinkList)malloc(sizeof(struct LNode));
	pt=(*L)->next;
	if((*L)==NULL||pt==NULL){
		newpt->next =(*L);
		(*L)=newpt; //这个是插在头结点前面的那种，而对于newpt来说插入的位置是L的前面。 
		//以前的话我们是把头结点当做链表的象征，而这个表仅仅是有头指针而没有头结点的概念。 
	}
	else{
		newpt->next =pt->next;
		pt->next=newpt;//插在关键字结点的后面。 
	}
	free(newpt);
	return 0; 
}
//插在头结点或者关键字结点的后面。 
int Insert(LinkList L,ElemType e,ElemType data) {
	LinkList pt=(LinkList)malloc(sizeof(struct LNode));
	LinkList target=(LinkList) malloc(sizeof(struct LNode));
	target->data=data;
	if((*L)==NULL){
		target->next =(*L);
		(*L)=target;
	}
	pt =(*L)->next;
	while(pt->next){
		if(pt->data==e){
			target->next =pt->next;
			pt->next =target;
		}
		pt=pt->next;
	}
	if (!pt){
		target->next =(*L);
		(*L)=target;
	}
	free(pt);
	free(target);
}
//三种情况：找到了，不在头结点的位置，插在目标的后面位置。 
//没有结点，直接插在头结点位置。
//没有找到，插在头结点位置。 

1.	我们必须知道对哪个链表进行操作，所以表头指针head是必须知道的。
2.	一般来说，待删除的结点是由结点的数据确定的。然而我们还要操作待删除结点之前的结点（或指针），以连接前后两段链表。之前所写的search函数只能找到待删除的结点，却无法找到这个结点的前趋结点。所以，我们只好放弃search函数，另起炉灶。
3.	令pGuard指针为待删除结点的前趋结点指针。
4.	由于要对待删除结点作内存释放，需要有一个指针p指向待删除结点。
5.	如果待删除结点为头结点，则我们要操作表头head，作为特殊情况处理。
6.	在删除结点的过程中，仍然要始终保持所有的结点都在我们的控制范围内，保证链表的完整性。为了达到这一点，我们还是采用先连后断的方式：先把待删除结点的前趋结点和它的后继结点连接，再把待删除结点与它的后继结点断开，并释放其空间。如下图9.6.4所示。
7.	如果链表没有结点或找不到待删除结点，则给出提示信息。

//找到了删除的结点，不在头结点的位置
//没找大
//找打了，但是是头结点。
LinkList *temp;
pt->next=(*L);
(*L)= pt;

temp =(*L);
(*L) = (*L) ->next ;
free(temp); 



 	p=head;//头结点是待删除结点
    head=head->next;//先连
    delete p;//后断
    似乎是说p指向的东西被删除，但是delete操作真的存在吗？？
	C中的delete？？？ 狗屁！ 
	
//free仅仅用来处理malloc  realloc 或者calloc的分配的动态内存，而不用于其余的变量。	
// 如果 ptr 所指向的内存空间不是由上面的三个函数所分配的，
// 或者已被释放，那么调用 free() 会有无法预知的情况发生。



