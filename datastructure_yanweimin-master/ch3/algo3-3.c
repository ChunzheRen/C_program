 /* algo3-3.c 括号匹配的检验，（限于()、[]） */
 ///这个程序就是不管你的非字符类型的字符串，直接往里面进行插入，然后就是对于括号使用一个stack的存储方式。
 ////然后就是，stack的存储实际山亦可以用is 
  
 typedef char SElemType;
 #include "../ch1/c1.h"
 #include "c3-1.h"
 #include "bo3-1.c"

 void check()
 { /* 对于输入的任意一个字符串，检验括号是否配对 */
   SqStack s;
   SElemType ch[80],*p,e;   
   if(InitStack(&s)) /* 初始化栈成功 */
   {
     printf("请输入表达式\n");
     gets(ch); //不检查范围，直接全部发送到指定的位置. 
     p=ch;
     while(*p) /* 没到串尾 */
       switch(*p)
       {
         case '(':
         case '[':Push(&s,*p++);
                  break; /* 左括号入栈，且p++ */
         case ')':
         case ']':if(!StackEmpty(s)) /* 栈不空 */
                  {
                    Pop(&s,&e); /* 弹出栈顶元素 */
                    
                    if(*p==')'&&e!='('||*p==']'&&e!='[') /* 弹出的栈顶元素与*p不配对 */
                    {
                      printf("左右括号不配对\n");
                      exit(ERROR);
                    }
                    
                    else
                    {
                      p++;
                      break; /* 跳出switch语句 */
                    }
                    
                  }
                  
                  
                  
                  else /* 栈空 */
                  {
                    printf("缺乏左括号\n");
                    exit(ERROR);
                  }
                  
         default: p++; /* 其它字符不处理，指针向后移 */
       }
       if(StackEmpty(s)) /* 字符串结束时栈空 */
         printf("括号匹配\n");
       else
         printf("缺乏右括号\n");
   }
 }
//() (())   ([]())  // [) [(]) 
 void main()
 {
   check();
 }

