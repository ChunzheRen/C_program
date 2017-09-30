 /* algo3-5.c ����ջ����Թ����⣨ֻ���һ���⣬�㷨3.3�� */
 typedef struct /* �Թ�����λ������ */
 {
   int x; /* ��ֵ */
   int y; /* ��ֵ */
 }PosType;

 #define MAXLENGTH 25 /* ���Թ����������Ϊ25 */
 typedef int MazeType[MAXLENGTH][MAXLENGTH]; /* �Թ�����[��][��] */

 /* ȫ�ֱ��� */
 MazeType m; /* �Թ����� */
 int curstep=1; /* ��ǰ�㼣,��ֵΪ1 */

 typedef struct /* ջ��Ԫ������ */
 {
   int ord; /* ͨ������·���ϵģ���ţ� */
   PosType seat; /* ͨ�������Թ��еģ�����λ�ã� */
   int di; /* �Ӵ�ͨ����������һͨ����ģ�����(0��3��ʾ������) */
 }SElemType;

 #include "../ch1/c1.h"
 #include "c3-1.h" /* ����˳��ջ�洢�ṹ */
 #include "bo3-1.c" /* ����˳��ջ�Ļ����������� */

 /* ����ǽԪ��ֵΪ0,��ͨ��·��Ϊ1,����ͨ��·��Ϊ-1,ͨ��·��Ϊ�㼣 */

 Status Pass(PosType b)
 { /* ���Թ�m��b������Ϊ1(��ͨ��·��)��return OK; ����return ERROR�� */
   if(m[b.x][b.y]==1)
     return OK;
   else
     return ERROR;
 }

 void FootPrint(PosType a)
 { /* ʹ�Թ�m��a�����ű�Ϊ�㼣(curstep) */
   m[a.x][a.y]=curstep;
 }
//��������ܹؼ��������漰���˶��ڵ�ǰ·���ı�ǡ� 
//ͬʱ����������ҷ����ǰ��մ�0~3�ı�׼��������push����pop�������õġ� 


 
 PosType NextPos(PosType c,int di)
 { /* ���ݵ�ǰλ�ü��ƶ����򣬷�����һλ�� */
   PosType direc[4]={{0,1},{1,0},{0,-1},{-1,0}}; /* {������,������} */
   /* �ƶ�����,����Ϊ�������� */
//   int number[4]Ҳ����һ��struct���ɵ����顣 
   c.x+=direc[di].x;
   c.y+=direc[di].y;
   return c;
 }

 void MarkPrint(PosType b)
 { /* ʹ�Թ�m��b�����ű�Ϊ-1(����ͨ����·��) */
   m[b.x][b.y]=-1;
 }

 Status MazePath(PosType start,PosType end) /* �㷨3.3 */
 { /* ���Թ�maze�д��ڴ����start������end��ͨ���������һ�� */
   /* �����ջ��(��ջ�׵�ջ��)��������TRUE�����򷵻�FALSE */
   SqStack S;
   PosType curpos;
   SElemType e;
   InitStack(&S);
   curpos=start;
   do
   {
     if(Pass(curpos))
     { /* ��ǰλ�ÿ���ͨ��������δ���ߵ�����ͨ���� */
       FootPrint(curpos); /* �����㼣 */
       e.ord=curstep;
       e.seat.x=curpos.x;
       e.seat.y=curpos.y;
       e.di=0;
       Push(&S,e); /* ��ջ��ǰλ�ü�״̬ */
       curstep++; /* �㼣��1 */
       if(curpos.x==end.x&&curpos.y==end.y) /* �����յ�(����) */
         return TRUE;
       curpos=NextPos(curpos,e.di);
     }
     else
     { /* ��ǰλ�ò���ͨ�� */
       if(!StackEmpty(S))
       {
         Pop(&S,&e); /* ��ջ��ǰһλ�� */
         curstep--;
         while(e.di==3&&!StackEmpty(S)) /* ǰһλ�ô������һ������(��) */
         {
           MarkPrint(e.seat); /* ���²���ͨ���ı��(-1) */
           Pop(&S,&e); /* �˻�һ�� */
           curstep--;
         }
         if(e.di<3) /* û�����һ������(��) */
         {
           e.di++; /* ����һ������̽�� */
           Push(&S,e);
           curstep++;
           curpos=NextPos(e.seat,e.di); /* �趨��ǰλ���Ǹ��·����ϵ����ڿ� */
         }
       }
     }
   }while(!StackEmpty(S));
   return FALSE;
 }

 void Print(int x,int y)
 { /* ����Թ��Ľ� */
   int i,j;
   for(i=0;i<x;i++)
   {
     for(j=0;j<y;j++)
       printf("%3d",m[i][j]);
     printf("\n");
   }
 }

 void main()
 {
   PosType begin,end;
   int i,j,x,y,x1,y1;
   printf("�������Թ�������,����(������ǽ)��");
   scanf("%d,%d",&x,&y);
   for(i=0;i<x;i++) /* �����ܱ�ֵΪ0(ͬǽ) */
   {
     m[0][i]=0; /* ���ܱ� */
     m[x-1][i]=0;
   }
   for(j=1;j<y-1;j++)
   {
     m[j][0]=0; /* ���ܱ� */
     m[j][y-1]=0;
   }
   for(i=1;i<x-1;i++)
     for(j=1;j<y-1;j++)
       m[i][j]=1; /* ����ͨ����ֵΪ1 */
   printf("�������Թ���ǽ��Ԫ����");
   scanf("%d",&j);
   printf("�����������Թ���ǽÿ����Ԫ������,������\n");
   for(i=1;i<=j;i++)
   {
     scanf("%d,%d",&x1,&y1);
     m[x1][y1]=0; /* ����ǽ��ֵΪ0 */
   }
   printf("�Թ��ṹ����:\n");
   Print(x,y);
   printf("��������������,������");
   scanf("%d,%d",&begin.x,&begin.y);
   printf("�������յ������,������");
   scanf("%d,%d",&end.x,&end.y);
   if(MazePath(begin,end)) /* ���һ��ͨ· */
   {
     printf("���Թ�����ڵ����ڵ�һ��·������:\n");
     Print(x,y); /* �����ͨ· */
   }
   else
     printf("���Թ�û�д���ڵ����ڵ�·��\n");
 }