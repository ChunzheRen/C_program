//һ���𽥲������������Ĺ����� 
#include<stdio.h>
#include<stdlib.h>
/*����һ��linklist�ṹ������*/
typedef struct linklist
{
    int data;
    struct linklist *next;
}list, *plist;




/*����С����˳�����*/
void order_insert_list(plist *head,int number)
{
    plist p_new = (plist)malloc(sizeof(list));   
    plist pre = NULL;           /* preָ����Ϊtempָ��nextǰ�ı��� */
    p_new->data = number;       /* ������ֵ���½�� */
    p_new->next = NULL;         
	//��ɣ���Ǵ���һ������µĵ� 

    plist temp = (plist)malloc(sizeof(list)); //����ָ�� 
    temp = *head;  /*ÿ�β���ǰ������ͷ��ʼ��λ��*/    //��ʼ�� ��null��malloc����ռ���ѡһ�� 


	//��һ�����������ǿյġ�head*ָ���Ҳ��һ����ָ�룬���ʱ��ֱ�Ӳ�������ˡ� 
    /*��λ�ս�㸳��ֵ*/
    if (NULL == *head)
    {
        *head = p_new;
        return;
    }
	
	//������� ��ͷָ�뻹ҪС�������� temp�ǹ���ָ�룬ָ���һ��Ԫ�أ�new��һ�������ָ�룬ָ��Ķ������⡣
	//ֱ����ͷָ��֮ǰ����
	//������� ��ͷָ��Ҫ��Ȼ����ǹ���ָ��ı���������������while����������for������ 
	//Ȼ����ǹ���ָ�����Ľ��ıȽ��ˣ� 
	
	//�����ڹ���ָ�룬temp�ǵ�ǰ�Ĺ���ָ�� ����pre��temp֮ǰ�Ķ������������ݡ� 
	
	 
    /*����data��ͷ���С��ͷ���ǰ����*/
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
            if (p_new->data >= temp->data)/* �½��Ե�ǰ���data�Ƚ� */
            {
                pre = temp;      //pre�ǵ�ǰָ���ǰ�棬�������� 
                temp= temp->next;/*��ǰ�����ƣ�ֱ��5������1 2 3 5 ����4����λ��*/
                continue;
            }
            else
            {
                p_new->next = temp;/* �����½�� */
                pre->next = p_new; /* temp��ǰһ����λ�õ�nextָ���½��p_new */
                break;
            }           
        }
        
        if (NULL == temp)/* ��temp����Ϊβ���ʱ��˵����Ԫ��data��󣬽������Ϊβ��� */
        {
            p_new->next = NULL;
            pre->next = p_new;   /* temp��ǰһ����λ�õ�nextָ���½��p_new */
        }
    }
}

 


void print_list(plist head)
{
    plist elem = head;     //elemָ�����������͵�ͷָ�룬Ȼ����head���г�ʼ���� 
    while (elem != NULL)	//���ͷָ�벻�ǿյĻ������������ǳ����Ĵ����ʩ 
    {
        printf("%d ", elem->data);
        elem = elem->next;
    }
    printf("\n");
}

void main()
{
    int number;
	plist head=NULL;     /*�����ͷ*/   //Ҳ����һ������head������ ,����Ŀǰ���ָ��û��ָ��Ϊ�˰�ȫ���ǽ���NULL���� 

    printf("input some numbers:\n");
    scanf("%d", &number);
    while (number != -1) /*����-1��ֹ*/
    {
        order_insert_list(&head,number);     //Ҳ���Ǵ���list����list������а���˳������Ԫ�ء� 
        scanf("%d", &number);
    }

    print_list(head);/*��ӡ���*/

}
