 /* bo2-32.c һ��������������ɾ�̬����(���ݽṹ��c2-3.h����)�Ļ�������(12��) */
 void InitSpace(SLinkList L) /* �㷨2.14������ */
 { /* ��һά����L�и���������һ������������L[0].curΪͷָ�롣��0����ʾ��ָ�� */
   int i;
   for(i=0;i<MAXSIZE-1;i++)
     L[i].cur=i+1;
   L[MAXSIZE-1].cur=0;
 }

 int InitList(SLinkList L)
 { /* ����һ��������������ֵΪ�ձ��������е�λ�� */
   int i;
   i=Malloc(L); /* ����Malloc()���򻯳��� */
   L[i].cur=0; /* �������ı�ͷָ��Ϊ��(0) */
   return i;
 }

 Status ClearList(SLinkList L,int n)
 { /* ��ʼ������L�б�ͷλ��Ϊn�ľ�̬�����Ѵ��ڡ�������������˱�����Ϊ�ձ� */
   int j,k,i=L[n].cur; /* ������һ������λ�� */
   L[n].cur=0; /* ������ */
   k=L[0].cur; /* ����������һ������λ�� */
   L[0].cur=i; /* �������Ľ���������������ı�ͷ */
   while(i) /* û������β */
   {
     j=i;
     i=L[i].cur; /* ָ����һ��Ԫ�� */
   }
   L[j].cur=k; /* ���������ĵ�һ�����ӵ�������β�� */
   return OK;
 }

 Status ListEmpty(SLinkList L,int n)
 { /* �ж�L�б�ͷλ��Ϊn�������Ƿ��,���ǿձ�����TRUE;���򷵻�FALSE */
   if(L[n].cur==0) /* �ձ� */
     return TRUE;
   else
     return FALSE;
 }

 int ListLength(SLinkList L,int n)
 { /* ����L�б�ͷλ��Ϊn������������Ԫ�ظ��� */
   int j=0,i=L[n].cur; /* iָ���һ��Ԫ�� */
   while(i) /* û����̬����β */
   {
     i=L[i].cur; /* ָ����һ��Ԫ�� */
     j++;
   }
   return j;
 }

 Status GetElem(SLinkList L,int n, int i,ElemType *e)
 { /* ��e����L�б�ͷλ��Ϊn�������ĵ�i��Ԫ�ص�ֵ */
   int l,k=n; /* kָ���ͷ��� */
   if(i<1||i>ListLength(L,n)) /* iֵ������ */
     return ERROR;
   for(l=1;l<=i;l++) /* �ƶ�i-1��Ԫ�� */
     k=L[k].cur;
   *e=L[k].data;
   return OK;
 }

 int LocateElem(SLinkList L,int n,ElemType e)
 { /* ��L�б�ͷλ��Ϊn�ľ�̬�������в��ҵ�1��ֵΪe��Ԫ�ء� */
   /* ���ҵ����򷵻�����L�е�λ�򣬷��򷵻�0 */
   int i=L[n].cur; /* iָʾ���е�һ����� */
   while(i&&L[i].data!=e) /* �ڱ���˳������(e�������ַ���) */
     i=L[i].cur;
   return i;
 }

 Status PriorElem(SLinkList L,int n,ElemType cur_e,ElemType *pre_e)
 { /* ��ʼ��������L�б�ͷλ��Ϊn�ľ�̬�������Ѵ��� */
   /* �����������cur_e�Ǵ˵�����������Ԫ�أ��Ҳ��ǵ�һ���� */
   /*           ����pre_e��������ǰ�����������ʧ�ܣ�pre_e�޶��� */
   int j,i=L[n].cur; /* iΪ������һ������λ�� */
   do
   { /* ����ƶ���� */
     j=i;
     i=L[i].cur;
   }while(i&&cur_e!=L[i].data);
   if(i) /* �ҵ���Ԫ�� */
   {
     *pre_e=L[j].data;
     return OK;
   }
   return ERROR;
 }

 Status NextElem(SLinkList L,int n,ElemType cur_e,ElemType *next_e)
 { /* ��ʼ��������L�б�ͷλ��Ϊn�ľ�̬�������Ѵ��� */
   /* �����������cur_e�Ǵ˵�����������Ԫ�أ��Ҳ������һ���� */
   /* ����next_e�������ĺ�̣��������ʧ�ܣ�next_e�޶��� */
   int i;
   i=LocateElem(L,n,cur_e); /* �������в��ҵ�һ��ֵΪcur_e��Ԫ�ص�λ�� */
   if(i) /* �ھ�̬�������д���Ԫ��cur_e */
   {
     i=L[i].cur; /* cur_e�ĺ�̵�λ�� */
     if(i) /* cur_e�к�� */
     {
       *next_e=L[i].data;
       return OK; /* cur_eԪ���к�� */
     }
   }
   return ERROR; /* L������cur_eԪ��,cur_eԪ���޺�� */
 }

 Status ListInsert(SLinkList L,int n,int i,ElemType e)
 { /* ��L�б�ͷλ��Ϊn�������ĵ�i��Ԫ��֮ǰ�����µ�����Ԫ��e */
   int l,j,k=n; /* kָ���ͷ */
   if(i<1||i>ListLength(L,n)+1)
     return ERROR;
   j=Malloc(L); /* �����µ�Ԫ */
   if(j) /* ����ɹ� */
   {
     L[j].data=e; /* ��ֵ���µ�Ԫ */
     for(l=1;l<i;l++) /* �ƶ�i-1��Ԫ�� */
       k=L[k].cur;
     L[j].cur=L[k].cur;
     L[k].cur=j;
     return OK;
   }
   return ERROR;
 }

 Status ListDelete(SLinkList L,int n,int i,ElemType *e)
 { /* ɾ����L�б�ͷλ��Ϊn�������ĵ�i������Ԫ��e����������ֵ */
   int j,k=n; /* kָ���ͷ */
   if(i<1||i>ListLength(L,n))
     return ERROR;
   for(j=1;j<i;j++) /* �ƶ�i-1��Ԫ�� */
     k=L[k].cur;
   j=L[k].cur;
   L[k].cur=L[j].cur;
   *e=L[j].data;
   Free(L,j);
   return OK;
 }

 Status ListTraverse(SLinkList L,int n,void(*vi)(ElemType))
 { /* ���ζ�L�б�ͷλ��Ϊn��������ÿ������Ԫ��,���ú���vi()��һ��vi()ʧ��,�����ʧ�� */
   int i=L[n].cur; /* ָ���һ��Ԫ�� */
   while(i) /* û����̬����β */
   {
     vi(L[i].data); /* ����vi() */
     i=L[i].cur; /* ָ����һ��Ԫ�� */
   }
   printf("\n");
   return OK;
 }