Status InitList(SqList *L) 
 {
   (*L).elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
   if(!(*L).elem)
     exit(OVERFLOW); 
   (*L).length=0; 
   (*L).listsize=LIST_INIT_SIZE; 
   return OK;
 }
 

// L��Ϊһ��ָ��ָ��Ķ�����*L �൱��Lָ���ʵ������
// Ȼ��*(L.elem) ��û������ģ�ֻ��(*L).elem ����ʵ����˼��
// ����������������ȼ��Ĺ�ϵ��.��Ƚ������Ӧ�õķ�Χ���㡣 

//2017��9��11��09:08:01
//�������� 
 
