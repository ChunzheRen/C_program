//���������ɾ�����
int insert(LinkList *L,char keyword,char newdata) {
	LinkList newpt =(LinkList)malloc(sizoef(struct LNode));
	newpt->data =newdata;
	LinkList pt=(LinkList)malloc(sizeof(struct LNode));
	pt=(*L)->next;
	if((*L)==NULL||pt==NULL){
		newpt->next =(*L);
		(*L)=newpt; //����ǲ���ͷ���ǰ������֣�������newpt��˵�����λ����L��ǰ�档 
		//��ǰ�Ļ������ǰ�ͷ��㵱���������������������������ͷָ���û��ͷ���ĸ�� 
	}
	else{
		newpt->next =pt->next;
		pt->next=newpt;//���ڹؼ��ֽ��ĺ��档 
	}
	free(newpt);
	return 0; 
}
//����ͷ�����߹ؼ��ֽ��ĺ��档 
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
//����������ҵ��ˣ�����ͷ����λ�ã�����Ŀ��ĺ���λ�á� 
//û�н�㣬ֱ�Ӳ���ͷ���λ�á�
//û���ҵ�������ͷ���λ�á� 

1.	���Ǳ���֪�����ĸ�������в��������Ա�ͷָ��head�Ǳ���֪���ġ�
2.	һ����˵����ɾ���Ľ�����ɽ�������ȷ���ġ�Ȼ�����ǻ�Ҫ������ɾ�����֮ǰ�Ľ�㣨��ָ�룩��������ǰ����������֮ǰ��д��search����ֻ���ҵ���ɾ���Ľ�㣬ȴ�޷��ҵ��������ǰ����㡣���ԣ�����ֻ�÷���search����������¯�
3.	��pGuardָ��Ϊ��ɾ������ǰ�����ָ�롣
4.	����Ҫ�Դ�ɾ��������ڴ��ͷţ���Ҫ��һ��ָ��pָ���ɾ����㡣
5.	�����ɾ�����Ϊͷ��㣬������Ҫ������ͷhead����Ϊ�����������
6.	��ɾ�����Ĺ����У���ȻҪʼ�ձ������еĽ�㶼�����ǵĿ��Ʒ�Χ�ڣ���֤����������ԡ�Ϊ�˴ﵽ��һ�㣬���ǻ��ǲ���������ϵķ�ʽ���ȰѴ�ɾ������ǰ���������ĺ�̽�����ӣ��ٰѴ�ɾ����������ĺ�̽��Ͽ������ͷ���ռ䡣����ͼ9.6.4��ʾ��
7.	�������û�н����Ҳ�����ɾ����㣬�������ʾ��Ϣ��

//�ҵ���ɾ���Ľ�㣬����ͷ����λ��
//û�Ҵ�
//�Ҵ��ˣ�������ͷ��㡣
LinkList *temp;
pt->next=(*L);
(*L)= pt;

temp =(*L);
(*L) = (*L) ->next ;
free(temp); 



 	p=head;//ͷ����Ǵ�ɾ�����
    head=head->next;//����
    delete p;//���
    �ƺ���˵pָ��Ķ�����ɾ��������delete������Ĵ����𣿣�
	C�е�delete������ ��ƨ�� 
	
//free������������malloc  realloc ����calloc�ķ���Ķ�̬�ڴ棬������������ı�����	
// ��� ptr ��ָ����ڴ�ռ䲻�����������������������ģ�
// �����ѱ��ͷţ���ô���� free() �����޷�Ԥ֪�����������



