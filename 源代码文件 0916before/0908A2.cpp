#include<stdio.h> 
char * s_gets(char *st,int n ){
	char *ret_val;
	int i =0;
//������Ķ�����ɶ�ô��� 
	ret_val =fgets(st,n,stdin);
//	#�����ȷ�ܵ��˶����ͽ���ѭ�����������һ��NULL 
	if (ret_val){
		while(st[i]!='\n'&&st[i]!='\0') {
			i++;
		}
		if(st[i]='\n')
			st[i]='\0';//�൱�ڽ����ַ��� 
		else:
			while (getchar()!='\n')
			continue;
//	#������������� 
	}
	return ret_val;
}
//#����һ��������Ȼ��������ָ�����ȵ��ַ����� 
//����������滻ǰ���gets�����ģ�Ȼ��һ�ǿ���������������룬���ǲ����ʵ��������ֱ�ӷ���-1�������� 
