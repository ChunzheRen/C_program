//������ Ŀ�꣺��ʱ�õ�������д��˫������������⡣ 
//�����Ĺ��ܣ�����ɾ�����ҷ�ת 
//2017��9��12��20:31:44 
//����ʵ��˫����ͷ����¼������ 
///Arthur: Justin.ShaoHui.ChunZhe.Ren 
///IDE ��Dev C++ 5.11 
//Tips������Ҫ�ı�ԭ������ĺ���������ֵ���ݾͺ��� 
 
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
//	//��ʼ����ʵ�ʾ����� malloc����new���пռ�ķ��� 
//	(*L)=(LinkList)malloc(sizeof(struct LNode));
//	//���޸ġ� LinkList Ϊ struct LNode  
//	if (!*L) return -1;
//	//���޸ġ� ��L��>��*L 
//	//return �����þ��Ƿ��������� 
//	(*L)->data= 0;//��ʵ�б�ĳ�ʼ���ǲ���Ҫ����data�ĸ�ֵ�ģ���Ϊ��ͷ��㡣 
//	//��*L��->data�洢Ԫ�ص����� 
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
//�漰��һ��������������ĸı䣬��Ҫ��ʹ�ö���ָ�� LinkList*. 
//ע��ռ�ķ��䣬�Ǹ�������ռ䣬����һ��ָ�������ָ�룬Ҳ���Ƿ���LinkList���ͣ�Ȼ�����struct LNode���͡� 

//LinkList��ָ��struct��ָ�룬��Ȼ����ֵ�����������ָ��ָ��Ķ���������Ŀռ��ǰ���struct LNode��׼��������LinkList 
//����struct LNode����LinkList�����ǲ������� 
int HeadInsert(LinkList *L,ElemType e){
//	����ָ��֮��,LinkList����ʵ�����ͺ�,q��Ҫ����Ľ�� 
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
	LinkList p=(LinkList)malloc(sizeof(struct LNode));  //������ָ�� ,����ElemType�����ʱ���Ҫʹ��*�ˡ� 
	p = L->next;//pָ����ǵ�һ������Ԫ��
	int cts= 1; //������ 
	if (! p) {
		printf("An empty list\n");
		return -1;//�����ж�p 
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
//		while(p->next){ //����ָ�벻�����һ��Ԫ�أ�����һ�ַ�������p=L->prev; 
//			printf("the %d element is:%d\n",cts,p->data);
//			p+=1;	//����ָ��������һ����Ԫ 
//		}
//		printf("%d",p->next->data);
	}
	printf("that is all\n");
	return 0;		
	}
	
}
//destroy��clear���������ڶ�ͷ���ı��� ,destroy���Ե���clear 
//Ȼ����߶��ǻ���ɾ�����ġ� 
//����ĺ�������ɾ����һ���ڵ� 
//ɾ������ĵ�һ������Ԫ��  
ElemType DeleteElem(LinkList *L){
	LinkList p=(*L)->next;
	ElemType e=p->data;
	(*L) ->next = p->next;
	free(p);
	(*L)->data-=1;//ͷ���洢����ĳ��� 
	return e;
}

int ClearList(LinkList*L) {
	LinkList p=(*L)->next;//pָ���һ���ڵ� 
	while(p){//�����������ŵ�һ����� 
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
	free(L);//free����ר����Ե���ָ�롣 
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
	}//p��ǰָ��ľ���Ҫ��ɾ����Ԫ�ص�ǰһ���� 
	LinkList q =p->next; //qҪ��ɾ�� 
	p->next  = q->next;
	ElemType e = q->data;
	free(q);
	return e;
}

//��ʵ��������Simplify��һ�����԰ɡ� 
//��������ǽ���λ�õĲ����������ȥ����������漰����������ƶ�������������Ϊ���Ӱ������� 
//�Ƚϼ򵥵ķ�����ֱ������µ�����ÿһ��Ԫ�أ������±�ıȽϣ�Ҫ������λ�õ�ǰ��ͺ�塣

//ǰ��ȫ���ǻ���Ԫ�صġ�����ͻȻ�뵽�˼�acend�ķ���������Ԫ��ǰ�塣���������������б���ȫ��������˳��
 
int InsertPos (LinkList *L,int pos,ElemType e) {
	LinkList p=(*L)->next;
	int cts =1;
	while(cts<pos-1) {
		p =p->next;
		cts++;
	}//p��ǰָ����ǲ���λ��ǰһ�� 
	LinkList q = (LinkList)malloc(sizeof(struct LNode));
	q->data= e;
	q->next =p->next;
	p->next=q;
	(*L)->data+=1;
	return 0;
}
//����Ҫд������ǰ���庯��2017��9��14��03:35:14 
//һ���𽥱䳤������ 
LinkList AscendList(LinkList *L) {	
	LinkList newL;
	InitList(&newL);
	LinkList p =(*L)->next;
	HeadInsert(&newL,p->data);
	p=p->next;
	int cts=2;
	
	while((cts<((*L)->data+1)) && p){
		int cts2=1;//cts2��¼q����� 
		LinkList q=(newL)->next;//q�Ǹող���ĵ�һ���ڵ� 	
		
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
		if (situation ==1){//ǰ����� 
			if(cts2==1){
				HeadInsert(&newL,ElemType(p->data));//mmpͷ����Ҳ�����⣿�������� 
			}
			else{
				InsertPos(&newL,cts2-1,p->data);	
			}
		}
		else{//������� 
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
		
		if (situation ==1){//ǰ����� 
			if(cts2==1){
				printf("END Insert\n");
				HeadInsert(&newL,ElemType(p->data));//mmpͷ����Ҳ�����⣿�������� 
			}
			else{
				InsertPos(&newL,cts2-1,p->data);	
			}
		}
		else{//������� 
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
		//pt�������ָ�룬���Բ���Ҫ����ĵ�ַ�����
		//���ַ�ʽ��ptָ��ľ���ElemType���ͣ����Ծ���˵����ľ���ElemType���͵ģ�������typeinfo�е�typeid(ElemType)������֤ 
		printf("you have entered:%d  This is the %d elems in this LinkList��\n",*pt,La->data+1);
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
//	//��DestroyList���������⡣ 
//	DisplayList(La);
//	DestroyList(&La);
//	DisplayList(La);//���ƻ���� 
	//����ʵ���˶��ڵ�һ��La��ȫ��ɾ����////////////////
	
	
	printf("time to simpltfy the list.\n");
	LinkList Lb =Simplify(&La);
	DisplayList(Lb);

//��Ҫ��Ϊ�˽��е������	
	printf("AcendList \n");
	LinkList Lc=AscendList(&Lb);
	DisplayList(Lc);
	
//	printf("descending list \n");
//	LinkList Ld =DescendList(&La);
//	DisplayList(Ld);
	return 0;
}

//ע��
//�����Ķ��壬һ�����ǲ����һ��&listƽ���޹ʵĸ���һ��������Ϊ�����ģ�
//һ��Ļ���Ҫ��һ��������ֵ���ݵķ�ʽ���ݲ�������C��������&La���ݲ�����һ����׼���á� 
//2017��9��13��17:17:12 
//������ʾ���ǲ�������Ԫ�ء����Ǿ������һ��������Ӧ������û���ȥ�� 
//׼��дһ��Ѱ���ض�λ��Ԫ�صĺ������������ҵ���������û�в��ȥ

//2017��9��13��17:21:27
//����һ���������������˿��û������˫����ĸо��� 

//2017��9��13��17:29:51
//���⻹�Ǵ�����InsertElem�������⡣ �������˫����Ĳ�������ż�������⡣��˫�������������� 
//�����ԭ������Ϊ��һ��Ԫ���ǿյģ�Ҳ����HeadInsert�����⡣ 

//2017��9��13��20:41:56
//����˫������Ϊѧϰ���еĵ������ʵ�֡�
//��Ϊ�������е�����Ľӿ�ʵ�ֲ�����
//��Ϊ��д�ع����е����� 

//2017��9��13��21:38:33  
//got it!

//2017��9��13��21:50:26
//�������� ������Ŭ���� 

//2017��9��13��22:04:32
//ע�⣺һ����malloc������ʹ�������һ����malloc���ڹ���ָ���Լ����������� LinkList pointer = (LinkList) malloc(sizeof(struct LNode));
//���о���whileѭ���Լ�ѭ�����������ϴ����š� 
//Ȼ��������ʵ��ȫ�����������ĵ���. 

//2017��9��13��23:47:09
//DeleteElem

//2017��9��14��00:34:26
//DestroyElem ClearElem based on DeleteElem 

//2017��9��14��03:13:30
//˳�����Simplify���� 

//2017��9��14��03:52:50 
//InsertPos �� AscendList��Ҫ��顣�������⣬������ܴ�����ȷ��
 
//2017��9��14��13:07:50
//�޸�InsertPos  //��֤���һ������Ŀ����ԣ�β��Ŀ����ԡ� ûë��
//������ͷ������������� -----
//2017��9��14��15:27:29
//ͷ�����������������  
//�����˽����Ĺ��ܾ��ǵ�������ˣ��ݼ������ 

//2017��9��14��16:10:45
//������BUG���ڡ������� 
