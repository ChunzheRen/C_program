 /* algo3-3.c ����ƥ��ļ��飬������()��[]�� */
 ///���������ǲ�����ķ��ַ����͵��ַ�����ֱ����������в��룬Ȼ����Ƕ�������ʹ��һ��stack�Ĵ洢��ʽ��
 ////Ȼ����ǣ�stack�Ĵ洢ʵ��ɽ�������is 
  
 typedef char SElemType;
 #include "../ch1/c1.h"
 #include "c3-1.h"
 #include "bo3-1.c"

 void check()
 { /* �������������һ���ַ��������������Ƿ���� */
   SqStack s;
   SElemType ch[80],*p,e;   
   if(InitStack(&s)) /* ��ʼ��ջ�ɹ� */
   {
     printf("��������ʽ\n");
     gets(ch); //����鷶Χ��ֱ��ȫ�����͵�ָ����λ��. 
     p=ch;
     while(*p) /* û����β */
       switch(*p)
       {
         case '(':
         case '[':Push(&s,*p++);
                  break; /* ��������ջ����p++ */
         case ')':
         case ']':if(!StackEmpty(s)) /* ջ���� */
                  {
                    Pop(&s,&e); /* ����ջ��Ԫ�� */
                    
                    if(*p==')'&&e!='('||*p==']'&&e!='[') /* ������ջ��Ԫ����*p����� */
                    {
                      printf("�������Ų����\n");
                      exit(ERROR);
                    }
                    
                    else
                    {
                      p++;
                      break; /* ����switch��� */
                    }
                    
                  }
                  
                  
                  
                  else /* ջ�� */
                  {
                    printf("ȱ��������\n");
                    exit(ERROR);
                  }
                  
         default: p++; /* �����ַ�������ָ������� */
       }
       if(StackEmpty(s)) /* �ַ�������ʱջ�� */
         printf("����ƥ��\n");
       else
         printf("ȱ��������\n");
   }
 }
//() (())   ([]())  // [) [(]) 
 void main()
 {
   check();
 }

