//一个逐渐插入的有序链表的构建。 
#include<stdio.h>
#include<stdlib.h>
/*定义一个linklist结构体类型*/
typedef struct linklist
{
    int data;
    struct linklist *next;
}list, *plist;




/*按从小到大顺序插入*/
void order_insert_list(plist *head,int number)
{
    plist p_new = (plist)malloc(sizeof(list));   
    plist pre = NULL;           /* pre指针作为temp指向next前的备份 */
    p_new->data = number;       /* 赋予新值给新结点 */
    p_new->next = NULL;         
	//伊桑都是创建一个结点新的点 

    plist temp = (plist)malloc(sizeof(list)); //工作指针 
    temp = *head;  /*每次插入前从链表头开始的位置*/    //初始化 、null、malloc分配空间三选一。 


	//第一种情况，表格是空的。head*指向的也是一个空指针，这个时候直接插入就行了。 
    /*首位空结点赋初值*/
    if (NULL == *head)
    {
        *head = p_new;
        return;
    }
	
	//情况二： 比头指针还要小啊。。。 temp是工作指针，指向第一个元素，new是一个随机的指针，指向的东西随意。
	//直接在头指针之前插入
	//情况三： 比头指针要大，然后就是工作指针的便利操作，可以是while操作或者是for操作。 
	//然后就是工作指针和你的结点的比较了， 
	
	//两个在工作指针，temp是当前的工作指针 ，而pre是temp之前的东西，用来备份。 
	
	 
    /*若新data比头结点小，头结点前插入*/
    if (p_new->data < temp->data)
    {
        p_new->next = temp; 
        *head = p_new;
        return;
    }
    else
    {
        while (NULL != temp)
        {   
            if (p_new->data >= temp->data)/* 新结点对当前结点data比较 */
            {
                pre = temp;      //pre是当前指针的前面，用来备份 
                temp= temp->next;/*当前结点后移，直至5（比如1 2 3 5 插入4）的位置*/
                continue;
            }
            else
            {
                p_new->next = temp;/* 插入新结点 */
                pre->next = p_new; /* temp的前一个的位置的next指向新结点p_new */
                break;
            }           
        }
        
        if (NULL == temp)/* 当temp最终为尾结点时，说明新元素data最大，将结点作为尾结点 */
        {
            p_new->next = NULL;
            pre->next = p_new;   /* temp的前一个的位置的next指向新结点p_new */
        }
    }
}

 


void print_list(plist head)
{
    plist elem = head;     //elem指向的是这个类型的头指针，然后用head进行初始化。 
    while (elem != NULL)	//如果头指针不是空的话。。。。都是常见的处理措施 
    {
        printf("%d ", elem->data);
        elem = elem->next;
    }
    printf("\n");
}

void main()
{
    int number;
	plist head=NULL;     /*定义表头*/   //也就是一个叫做head的链表 ,但是目前这个指针没有指向，为了安全我们进行NULL处理。 

    printf("input some numbers:\n");
    scanf("%d", &number);
    while (number != -1) /*输入-1终止*/
    {
        order_insert_list(&head,number);     //也就是创建list，向list里面进行按照顺序的填充元素。 
        scanf("%d", &number);
    }

    print_list(head);/*打印输出*/

}
