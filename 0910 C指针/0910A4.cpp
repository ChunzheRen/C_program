#include <stdio.h>
#include <conio.h>
int main(void)
{
    int i;
    char string[20];
    for(i=0;i<10;i++)
        string[i]='a';
    string[10]='\0';//注意
    puts(string);
    getch();//用来换行 /
    return 0;
}
