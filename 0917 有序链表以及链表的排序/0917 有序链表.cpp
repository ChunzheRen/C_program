//������ǰ����Ļ���.д�����ͺܼ���.�޷��Ǵ�firstѭ�������,һֱ�ҵ�һ�����ڵ�ǰ�����ؼ��ֵ��Ǹ������.��׷�ӵ�
//��������嵽ǰ�漴��.��Ҫע��ľ��ǲ�����ͷ����β�������⴦��.
//�洢��Ԫ��������ν�ģ���Ϊ���漰���ĵ�ָ��ĸı���� 
//����ͷβ�ڵ� ��ǰ�������� ѭ�� ����˫���� 
//����˫�������һ������Ԫ�ص�λ��ѡ�����λ�õ������ 

//���ǲ���ͷ��㣬����ÿһ���ڵ㶼��Ԫ�ؽ�㣬���ǣ�һֱ����ͷָ���β��ָ��ġ�ͬʱ�����֮�������໥��˫�����ӵġ� 
#include <stdio.h> 
#include <stdlib.h> 
typedef int ElemType;
typedef struct Node{
	struct Node *next;
	struct Node *prev;
	ElemType data; //???data��ʵҲ������һ�����飬����Ϊ�˼򻯾Ͳ�����ռ��ˡ���data����һ�������� 
}LNode;

//һ���LinkListֱ��ָ��ڵ㣬���ڽ������޸ģ���ָ��һ������struct�� 
//ȫ�滻װһ��ָ�� 
typedef struct List{
	struct Node* prev; 
	struct Node* next; //ָ�����Node���� ��LNodeҲ���ԡ�  LNode next 
	int size;//�򻯲��� 
}LinkList; //LinkListָ�����һ������ 
//Ȼ����Ƕ�����һ��ָ��ͷβ�ڵ�ı���ʵ����͹��ˡ�
//linklist�Ƕ��ڽ����м�ӿ��Ƶı�
int InitList(LinkList *L) {
	L = (LinkList*)malloc(sizeof(struct List));
	if(!L) return -1;
//	L->next=L->prev = (LNode*)malloc(sizeof(struct Node)); 
//	if(!L->prev) return -1;//�ҵ��뷨�����Ȳ���һ���㣬��Ϊͷ��㣬һ��ʼ��ָ����� 
	L->next = L->prev =NULL;
	L->size=0;   //û��ͷ��� 
	printf("maybe initialized.\n");
	return 0;
}//2017��9��26��11:35:45
//���Ľ��۾��ǣ��������mallocһ�����صĽṹ���Ҿ��û���Ҫ�ȳ�ʼ��һ��ͷ���źá� 
//һ����û�н���ʱ��һ������һ�����߶������ʱ�򣬽��Ĳ�������˳��ģ��������Ԫ�صĴ�С�� 
int Insert(LinkList *L,ElemType e){
	
	LNode *newNode=(LNode*) malloc(sizeof(struct Node));
	newNode -> data =e;
	printf("#B\n");
	if (L->size==0) {//Ҳ�����ö�ָ��NULL��ʱ����еĲ������������е㻳�ɡ� 
		printf("#C\n");
		(L)->next =(L)->prev = newNode;   //��struct Node* Ҳ����LNode*���ͣ�  
		newNode->next =newNode;
		newNode->prev =newNode;
		L->size++; 
		return 0;
	}
	printf("#B\n");
	LNode *pts=(LNode*)malloc(sizeof(struct Node)); //�ȷ��乤��ָ�� 
	pts=(L)->prev;
	printf("#A\n");
	if(pts->data>=e){
		newNode->next=L->prev;
		newNode->prev=L->next;
		L->prev=newNode;
		L->next=newNode;
		L->prev=newNode;
		L->size++;
		return 0;
	}
	printf("#B\n");
	if(L->size>=3){//�����Ѿ���һ�����߶������ʱ�� 
		
		L->prev =pts; 	//�ȼ���*(L->prev).data
		while(pts->data<newNode->data){
			pts=pts->next;
		}//11
		newNode->next=pts->prev;//8 9 
		newNode->prev=pts->prev->prev;//8 7
		pts->prev->prev->next=newNode;//7 8
		pts->prev->prev=newNode;//
		L->size++; 
	}
	else if(L->size==1){
		if(L->prev->data>e){   //����������ݱ���Ĳ���ĵ�һ���ڵ㻹С��ֱ�Ӳ��룬������ǰ���г�ͻ�� 
			L->next=L->prev;
			newNode->next=L->prev;
			newNode->prev=L->prev;
			L->prev->next=newNode;
			L->prev->prev=newNode;
			L->prev=newNode;
			L->size++; 
		}
		else{
			L->prev=L->next;
			newNode->next =L->prev;
			newNode->prev =L->next;
			L->prev->next =newNode;
			L->prev->prev =newNode;
			L->next=newNode;
			L->size++; 
		}
	}
	
	else if (L->size==2){
		if(pts->data<e)	{
			if (pts->next->data<e){
				pts->next->next=newNode;
				pts->prev=newNode;
				newNode->next =pts;
				newNode->prev = pts->next;
				L->next=newNode;
			}//��� 
			else {    //(pts->next->dta)
				newNode->next=pts->next;
				newNode->prev=pts;
				pts->next->prev=newNode;
				pts->next =newNode;
		}//�м� 
	}
	
	free(pts);
	return 0;
	}
}

int ListTraverse(LinkList L){
	if(L.size==0){
		printf("an enpty list.\n");
		return -1;
	}
	
	int cts=0;
	printf("here is the list.\n");
	LNode *pt =(L).prev;
	while(cts<L.size){
		printf("%d__",pt->data);
		pt=pt->next;
		cts++;
	}
	return 0;
}

int main(){
	LinkList LA;
	InitList(&LA);
	printf("%d\n",LA.size);
	
//	ElemType *e=(ElemType*)malloc(sizeof(ElemType));
//	while(scanf("%d",e)){
//		Insert(&LA,*e);
//		printf("you have just input: %d.\n",*e);
//	}
//	ListTraverse(LA);
	return 0;
}



//int InsertPos(LinkList *L,int pos,ElemType e){
//	LNode pt = (LNode)malloc(sizeof(struct Node));
//	LNode elem=(LNode)malloc(sizeof(struct Node));
//	if (pos==1){
//		InsertHead(L,e);
//	}
//	else{
//		pt = (*L)->head;
//		int cts=1;
//		while(cts<pos){
//			pt=pt->next;
//			cts++;
//		}
//		//ptָ�����Ҫ�����ƵĽ��
//		elem->next=pt->next;
//		elem->prev =pt->prev; 
//		pt->next->prev =elem;
//		pt->prev->next =elem; 
//		elem->data =e;	
//	}
//	(*L)->size++;
//	free(pt);
//}
//������ͷ��㲻ͬ������Ԫ�ؽ�㡣 
//ʵ�ֵ�����˳��Ĳ��� 



//int Insert(LinkList *L,ElemType e){
//	LNode pt=(LNode) malloc(sizeof(struct Node));
//	pt->data =e;
//	if ((*L)->size ==0) {
//		(*L)->head = pt;
//		(*L)->tail = pt;
//		pt->next =pt;
//		pt->prev =pt;
//	}
//}
//	
//	
//	
//	else{
//		//ʵ������Ĳ��� ,����ں��棬С����ǰ�档 
//		LNode pt1=(LNode) malloc(sizeof(struct Node));
//		pt1 =(*L)->head;
//		int cts=1;
//		while ((pt1!=(*L)->head)&&(pt->data>pt1->data)){
//			pt1=pt1->next;
//			cts++;
//			continue;	
//		}
//		//����һֱ���б������ҵ���ֹ�������
//		//���һ������ʧ���ˣ��Ͳ嵽1��λ�þͺ��ˡ� 
//		InsertPos(L,cts,e);
//		//��Ҫ�漰��L��head��tail��λ�ã�������е㷳������������
//		//Ӧ�øĵ���InsertPos������ 
//		free(pt1);
//	}
//	(*L)->size++;
//	return 0;
//}
