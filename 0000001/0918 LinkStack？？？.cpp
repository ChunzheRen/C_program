//��ջ 
//û�н��ɾ���������⡣ 
#include<stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct Stack{
	struct Stack *next;
	ElemType data;
}Stack,*LinkStack;

int InitStack(LinkStack *S){
	//�������ˣ�����LinkStackû�б�����һ���ռ䡣
	*S = (LinkStack)malloc(sizeof(struct Stack));
	if(!*S) return -1;
//	(*S)->next=(LinkStack)malloc(sizeof(struct Stack));  ���������� 
	(*S)->next=NULL;
	(*S)->data =0;
	printf("Maybe successfully initialized.\n");
	return 0;
}
int DestroyStack(LinkStack *S){
	while(*S){
		LinkStack pt=(*S);
		(*S)=(*S)->next;
		printf("#a\n");
		DestroyStack(S);
		
	}
	printf("LinkStack Destroyed!");
	return 0;
}

 

int StackEmpty(LinkStack S){
	if(S->next==0) printf("Empty!\n");
	else printf("Not Empty!\n");
	return 0;
}

ElemType GetTop(LinkStack S){
	LinkStack pt=(LinkStack)malloc(sizeof(struct Stack));
	pt=(S)->next;
	while (pt->next){
		pt =pt->next;
	}
	ElemType e = pt->data;
	free(pt);
	return e;
}//��Ҫ��������ſ���֪�����յĽ�� 
int LocateElem(LinkStack S,ElemType e){
	LinkStack pt=(LinkStack)malloc(sizeof(struct Stack));
	pt = S->next;
	int pos = 1;
	while(pt->next){
		if (e==pt->data)	return pos;
		pt=pt->next;
		pos++;
	}
	free(pt);
	return 0;
}//δ֪ 

int Push(LinkStack *S,ElemType e){
	LinkStack pt=(LinkStack)malloc(sizeof(struct Stack));
	LinkStack newpt=(LinkStack)malloc(sizeof(struct Stack));
	newpt->data =e;
	pt=(*S)->next;
	int number=0;
	
	if (!pt){
		printf("#a one time \n");
		(*S)->next = newpt;
		(*S)->data++;
		return 1;
	}
	else{
		while(number<(*S)->data){
			pt=pt->next;
			number++;
		}
		pt->next=newpt;
		newpt->next =NULL;
		(*S)->data++;
		return 0;	
	}
}
//ע��topָ��ָ��������һ������Ԫ�ص���һ���� 
//ɾ�����һ����� 
ElemType Pop(LinkStack *S){
	LinkStack pt=(LinkStack)malloc(sizeof(struct Stack));
	LinkStack prev=(LinkStack)malloc(sizeof(struct Stack));
	pt= (*S)->next;
	while(pt->next){
		prev=pt;
		pt=pt->next;
	}
	ElemType e=pt->data; 
	prev ->next =NULL;
	free(pt);
	free(prev);
	return e;
}
//�ӵ�һ��Ԫ�ؿ�ʼ������Ҳ���Ǵ�base��ʼ���ϵ�top�� 
int StackTraverse(LinkStack S){
	LinkStack pt=(LinkStack)malloc(sizeof(struct Stack));
	pt = (S)->next;
	while(pt){
		printf("%d__",pt->data);
		pt =pt->next;
	}
	return 0;
}




int main(){
	LinkStack Sb;
	InitStack(&Sb);
	ElemType *e=(ElemType*)malloc(sizeof(ElemType));
	while (scanf("%d",e)){
		Push(&Sb,*e);
		printf("you have entered : %d.\n",*e);
	}
	free(e);
	printf("%d\n",Sb->next->next->data);
	StackTraverse(Sb);
	DestroyStack(&Sb);
	if(!Sb){
		printf("succeed\n");
	}
	return 0;
}


//solution1: 	//available
//void DestroyStack(LinkStack *S){
//	while(*S){
//		LinkStack pt=(*S);
//		(*S)=(*S)->next;
//		printf("#a\n");
//		DestroyStack(S);
//	}
//	printf("LinkStack Destroyed!");
//}
//solution2:  //unavailable
//void DestroyStack(LinkStack *S){
//	while(*S){
//		LinkList pt=(*S)->next;
//		free(*S);
//		(*S)=pt;
//	}
//}

����LinkList��delete������
��ʵ�ǿ��Էֽ�Ϊpop�����Ĳ���ѭ���ġ�
ElemType Pop(Stack **S){
	ElemType res;
	Stack *rem =*S; //rem is a pointer to Stack 
	if(*S==NULL){
		fprintf(stderr,"Stack underflow.\n");
		return -1;
	}
	res =(*S)->data;
	(*S)=(*S)->next;
	free(rem);	
	
	return res;
}


void DestroyStack (Stack**S){
	while (*S)  Pop(*S);
}

�����ϣ�����иı�Ļ�����ֱ����const Stack *S ���д��ݣ���ֹ��ֵ���޸ġ��ó�ָ�롣 ͬʱ��������ֵ���д��ݣ��������С�
 
