#include <stdio.h>66
#include <string.h>
#define TSIZEE  45
#define FMAX  5

struct film{
	char title[TSIZE];
	int rating;
};
char *s_gets(char str[],int lim);
//���ص���һ���洢���ַ���ָ����ʽŶ 

int main(void){
	struct film movie[FMAX];
	//һ���洢��5�����ֶ���ʵ�������飬���ڸ��߼�һ��Ľṹ�� 
	int i = 0;
	int j;
	
	puts("Enter first movie title: ") ;
	while (i<FMAX&&s_gets(movies[i].title,TSIZE)!=NULL&&movies[i].title[0]!='\0'){
		puts("Enter your rating<1_10");
		scanf("%d",&movies[i++].rating);
		while(getchar()!='\n') continue;
		puts("enter next movie title (input an empty line to stop)");
	}
	
	if (i==0) printf("No data erntered");
	else printf("here is the movie list");
	
	for (j=0;j<i;j++)
		printf ("movie :%s Rating :%d \n",movies[j].title,movies[j].rating);
	printf("bye!\n");
	return 0;
}

char *s_gets(char *st,int n){
	char *ret_val;
	char* find;
	
	ret_val =fgets(st,n,stdin);
	if(ret_val)
	{
		find =strchr(st,'\n');
		if find
			*find = '\0';
		else
			while (getchar()!='\n')
				continue;
	}
	return ret_val;
}

