#include <stdio.h>
int main ()
{
	char string[100];
	int i,num=0,word=0;
	char c;
	gets(string);
	for (i=0;(c=string[i])!='\0';i++)                  //���ܹ�ʹ��\n����Ϊgets�Ķ�ȡ�����Զ��İ�\n�滻Ϊ\0 
	{
		if (c==' ') 
			word=0;
		else if(word==0)
		{
			word=1;
			num++;
		}
	}
//	The line consists of all characters up to and including the first newline character ('\n'). 
//	gets then replaces the newline character with a null character ('\0') before returning the line. 
	printf ("there are %d words in this line .\n",num);
	return 0;
}
