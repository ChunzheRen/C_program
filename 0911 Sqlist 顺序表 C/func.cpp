//2017��9��11��21:50:20
///author ��Justin.Shaohui.Chunzhe.Ren 

//�µ���ᣬһ��elem���ǵ�һ��Ԫ�ص�λ�ã����Ԫ�������������0��Ԫ�� 

//��Sqlist��β��*Sqlist ��β�кܴ��𡣺���ֱ����һ������ʵ���ˣ������� 
//����Ҫ��Ҫ�ö���ָ�룿������ 

//typedef struct Sqlist {
//	ElemType *elem;
//	int length;
//	int listsize;
//}Sqlist;
int InitList(Sqlist *L) {
	(*L).elem = (ElemType *)malloc(LISTSIZE * sizeof(ElemType));
	if ((*L).elem) return -1;
	(*L).length = 0;
	(*L).listsize = LISTSIZE;
	return 0;
}
int DestroyList(Sqlist *L) {
	if (!(*L).elem) free((*L).elem);
	//���free�����ǵĳ�ʼ���ķ�ʽ�кܴ�Ĺ�ϵ 
//	(*L).elem = (ElemType*) malloc(size);________free((*L).elem);
	//�ͷ���Ͽռ�֮�� 
	(*L).elem =NULL;
	(*L).length =0;
	(*L).listsize = 0;
	return 0; 
}
 //clearlist  ��destroylist�Ĳ�𣿣��� ����Ҫѧϰ InsertList��
//destroylist����ͷ������׽��ָ��ָ������Դ洢�ռ�
//clearlist  �����޸��߼���ϵֵ 
int ClearList(Sqlist *L){
	(*L).length =0;
	return 0;
}

//��Щ���漰�б�ӹ�����������б����ԵĶ�������Ҫָ�롣 
//һ�� ���������ǰ�б��Ƿ�Ϊ�յ���������ǿ��Ժ�������Ⱥϲ���
 
int ListEmpty(Sqlist *L){
	if ((*L).length ==0) {
		printf("it`s empty now\n"); 
		return 1;
	}
	else {
		printf("it`s not empty\n"); 
		return 0;
	}
}

int ListLength(Sqlist *L){
	printf("list length : %d \n",(*L).length); 
	return (*L).length;
} 

ElemType GetElem(Sqlist *L,int pos ){
	if ( pos<1 || pos>((*L).length))
		printf("input erroe");
		return -1;
	ElemType e;
	e = *((*L).elem+pos-1);
	return e;
}

int LocateElem (Sqlist *L,ElemType e){
	int cts;
	for (cts=0;cts<=(*L).length-1;cts++){
		if (*((*L).elem+cts) == e) return cts+1;
	}
	return -1;
}
//�������pos����ֵȷ�������⡣������������ 
//���ڿ��������������˳���ĵ�һ��Ԫ�ص�����ɶ�����⡣ 
int InsertElem(Sqlist *L,int pos,ElemType e){
	//��ʼ������ 
	ElemType *newbase,*p,*q;
	//�����ж��ǲ��ǿ��еġ�����������
	if (pos<1 || pos>(*L).length+1) return -1;
	//�ж��ǲ�����Ҫ���ӿռ�
	if ((*L).length>(*L).listsize) {
		newbase = (ElemType *)realloc((*L).elem,sizeof(ElemType)*((*L).listsize+LISTINCREMENT));
		if (!newbase) return -1;
		(*L).elem = newbase;
		(*L).listsize+=LISTINCREMENT;
	}
	q=(*L).elem +pos-1; ///�µĸ��룬ָ��Ӽ������ǵ����ļӼ��������Ǹ��ݴ洢�ռ���мӼ��� 
	//Ȼ��ΪɶҪ�������ַ�һ��ǲ�֪�� 
	for(p =(*L).elem+(*L).length-1;p>=q;p--) 
		*(p+1)=*p;
	*q =e;
	(*L).length +=1;
	return 0;
}
ElemType DeleteElem(Sqlist *L,int pos){
	ElemType e= -1 ;
	if (pos<1||pos>(*L).length +1) return -1;
	ElemType *p ,*q;//Ҫ��ɾ���Ķ�����p ������ָ��q
	p=(*L).elem + pos -1; //�����������pos�Ķ����Ҹ����Ƕ���Ϊ��pos����Ч����Ԫ�أ�Ҳ���������[pos-1] 
	e = *p;
	q =(*L).elem+ (*L).length-1;
	for (q;q>=p;p--){
		*(p-1)=*p;
	}
	(*L).length -=1;
	return e;
}
//int main() {
//	Sqlist La;
//	int length;
//	ElemType e [10]={1,2,3,4,5,6,7,8,9,10};
////	һ��ʼ��������Sqlist *La �����ƺ�������û�з���ռ䣿 
////	�����õ���Sqlist *La = NULL ����ָ����ǿյ�λ�� ���Ҳ���� 
//	InitList(&La);
//	
//	if ((La).elem)//һ��Ҫע�����ж�La�ĵ�ַ�ǲ���һ���յġ� 
//	//������&La ����La.x�����жϡ��������ˣ��жϵ��ǲ���һ���ڴ��ַ�����ݡ� 
//		printf("ok ,successfully initialized\n");
//	
//	ListEmpty(&La);
//	printf("%d",La.listsize);
//	printf("\n");
//	
//	ClearList(&La);
//	ListEmpty(&La);
//	DestroyList(&La);
//	ListEmpty(&La);
//
//	ElemType *p,*q;
//	for (int pos=0;pos<10;pos++) {
//		p = (La).elem +pos-1;
//		for(q = (La).elem+(La).length -1;q>p;q--){
//			*(q+1)=*q;
//		}
//		p=&e[pos];
//		(La).length +=1;
//	}
//	printf("i am here\n");
//	
//	for (int i=0;i<10;i++){
//		printf("the %d element is: %d\n",(i+1),((La).elem+i));
//	}
//	
//	printf("congratulations\n");
//	return 0;
//}


///Ȼ���������Merge�ȵȶ��β��� 

