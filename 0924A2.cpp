//����ʵ��
 
 int InitQueue(LinkQueue &Q) {
 	Q.front =Q.rear=(QNode)malloc(sizeof(QNode));//�������Ǳ���� 
 	if(!(Q.front)) return -1;
 	Q->front->next =NULL;//Ҳ����ͷָ�����һ���ǿյġ� ����Ǳ����� 
 	return OK;
 }
 int DestroyQueue(LinkQueue &Q){
 	while(Q.front){
 		Q.rear=Q.front->next;
 		free(Q.front);
 		Q.front =Q.rear;
	}
	return OK;
}
int DestroyQueue(LinkQueue &Q){
	while(Q.front){
		Q.rear =Q.front->next;
		free(Q.front);
		Q.front =Q.rear;
	}
	return 0;
}

int EnQueue(LinkQueue &Q){
	while(Q.front){
		Q.rear =Q.front->next;
		free(Q.front);
		Q.front =Q.rear;
	}
}
int EnQueue(LinkQueue &Q,ElemType e){
	p = (QNode)malloc(sizeof(QNode));
	if(!p) return -1;
	p->data =e ;
	p->next =NULL;
	
	Q.rear->next=p;
	Q.rear = p;
	return 1;
}
//���ֲ��뷽���Ļ�������˵ ������һ���հ׵�ͷ��㣬Ҳ���Ǵ�����һ���Ŀռ���������о��� 
int DeQueue(LinkQueue &Q,ElemType &e){
	if(Q.front ==Q.rear )return -1;
	p= Q.front->next;
	e=p->data;
}

