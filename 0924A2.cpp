//书上实现
 
 int InitQueue(LinkQueue &Q) {
 	Q.front =Q.rear=(QNode)malloc(sizeof(QNode));//分配结点是必须的 
 	if(!(Q.front)) return -1;
 	Q->front->next =NULL;//也就是头指针的下一个是空的。 这个是必须的嘛》 
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
//这种插入方法的话，还是说 存在着一个空白的头结点，也就是存在着一定的空间进行深入研究。 
int DeQueue(LinkQueue &Q,ElemType &e){
	if(Q.front ==Q.rear )return -1;
	p= Q.front->next;
	e=p->data;
}

