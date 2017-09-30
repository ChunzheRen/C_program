//�Ƚϳ��������˫�����ˣ� 
//�д����ƵĹ��ܣ�ɾ��˫�������Բ��ñ����ķ�ʽɾ���� 
#include<stdio.h> 
#include<stdlib.h>
typedef int ElemType;
typedef struct Node{
	struct Node *next;
	struct Node *prev;
	ElemType data; 
}LNode;
//���Ƕ��У��������˫������������ 
typedef struct List{
	struct Node* head; 
	struct Node* tail; 
	int size=0;
}LinkList; 
//�ж��������LNode��struct�����ǽ�����һ��LinkList��struct�� 
int InitList(LinkList *L) {
	L = (LinkList*)malloc(sizeof(struct List));
	if(!L) return -1;
	L->head = L->tail =NULL;
	L->size=0;   //û��ͷ��� 
	printf("maybe initialized.\n");
	return 0;
}
///����Ҫ���´���һ���ڵ��б� 

int ListTraverse(LinkList L){
	if (L.size==0){
		printf("An Empty List.\n");
		return 0;
	}
	LNode *pt =(LNode*)malloc(sizeof(struct Node));
	pt=L.head;
	int cts=0;
	do{
		printf("%d__",pt->data);
		pt=pt->next;
		cts++;
	}while(cts<L.size);
	printf("\n");
	return 0;//һ��������ǣ����ʹ����pt=pt->next�������ָ��Խ������������ʹ�ü������ķ����� 
}

int Insert(LinkList *L,ElemType e) {
	printf("before insertion.\n");
	ListTraverse(*L);
	LNode *newNode=(LNode*)malloc(sizeof(LNode));
	newNode->data=e;
	
	if(L->size==0){
		newNode->prev=newNode;
		newNode->next=newNode;
		L->head=newNode;
		L->tail=newNode;
		L->size++;
		return 0;
	}
	//ֱ�Ӳ��� 1 �� 2 �����㡣 
	
	if (L->head->data>=e){
		newNode->prev=L->tail; 
		newNode->next=L->head;
		L->head->prev=newNode;
		L->tail->next=newNode;
		L->head=newNode;
		L->size++;
		return 0;
	}
	else{	
		
		LNode*pt =(LNode*)malloc(sizeof(LNode));
		LNode*prev_pt=(LNode*)malloc(sizeof(LNode));
		pt=L->head; 
		prev_pt=pt;//��Ҫ����һ����������������롣 
		
		while(pt->next!=L->tail){//pt->nextӦ��6 8 9����  //���û�취��ָ���жϣ�ֱ���ü������� 
			if (pt->data<e) {        //Ӧ��8 01 12 ���� 
				prev_pt=pt;  
				pt=pt->next;	
			}	//1 3 4 --2 
			else{//����8 10 12 ���⣺ֱ����pt��ǰ�棬prev�ĺ�����롣 
				printf("#BB\n");
				newNode->next=pt;  
				newNode->prev=prev_pt;
				pt->prev = newNode;
				prev_pt->next = newNode;
				L->size++;
				printf("After insertion.\n");
				ListTraverse(*L);
				return 0;
			}
		}
		// ���Ͼ����ж������ֻ��pt �� pt->next 
		//8 10 12 ---9 ��֤������һ�����ڡ� ������prev�ĺ����pt��ǰ�档 
		//6 8----9  ��ʱptָ�����8��Ȼ��Ȼ����Ӧ����pt�ĺ��档 
		if(L->tail->data<e){ //�����3 5 ��ô��ֱ�Ӳ��롣 
			printf("#CC\n");
			newNode->prev=L->tail;
			newNode->next=L->head;
			L->tail->next=newNode;
			L->head->prev=newNode;
			L->tail=newNode;
			L->size++;
			printf("After insertion.\n");
			ListTraverse(*L);
			return 0;
		}
		
		else if(pt->data>e){ // 1 3 4  -----2 
			printf("#DD\n");
			newNode->next=pt;
			newNode->prev=pt->prev;
			pt->prev->next =newNode;
			pt->prev=newNode;
			L->size++;
			printf("After insertion.\n");
			ListTraverse(*L);
			return 0;
		}
		
		else{//����� 5 3  
			printf("#EE\n");
			printf("before insertion.\n");
			ListTraverse(*L);
			newNode->next =L->tail;
			newNode->prev =L->tail->prev;
			L->tail->prev->next =newNode;
			L->tail->prev=newNode; //һ��Ҫע������˳��Ҳ����˵��Ĳ������һ��Ҫ����ʵ������Ӧ�� 
			L->size++;
			printf("After insertion.\n");
			ListTraverse(*L);
			return 0; 
		}
		
		printf("data:%d\n",L->tail->prev->data);
		printf("##FF\n");
		L->size++;
		free(pt);
		free(prev_pt);
		printf("After insertion.\n");
		ListTraverse(*L);
		return 0;
	}
	printf("After insertion.\n");
	ListTraverse(*L);
	return 0;
}

int DestroyList(LinkList*L) {
	LNode *pt=L->tail;
	while(pt!=L->head){
		pt=pt->prev;
	}//��Ҫ������һ��ָ��ָ��β��㣬Ȼ���������ɾ���ĸо��� 
}
int main(){
	LinkList LA;
	InitList(&LA);
	ElemType *e=(ElemType*)malloc(sizeof(ElemType));
	while(scanf("%d",e)){
		Insert(&LA,*e);	
		printf("you just entered:%d\n",*e);
	}
	free(e);
	printf("the whole list after insertion.\n");
	ListTraverse(LA);
//	printf("#A\n");
//	printf("%d\n",LA.head->data);
//	printf("%d\n",LA.head->next->data);
//	printf("%d\n",LA.head->next->next->data);
	return 0;
	} 
//	���������1֮��ͻ��л��ң�˵������Ĳ����Ǵ�������ġ�	
//  ����˫��������������ǻ���ֶ��ڲ�ͬ��ѭ���Ĳ������⣬���ر����ڣ�û�н������ ͷ���ǰ����� β��������� ��ȵ�ʱ����� 
