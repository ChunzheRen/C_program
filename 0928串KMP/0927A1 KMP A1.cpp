#include<stdio.h> 
#include <stdlib.h>
#include<string.h>
#define SIZE 10
typedef char[SIZE+1];
int ViolentMatch(String A,String T,int pos){
	int i=pos;int j=0;
	while(i<=A[0]&&j<=T[0]){
		if(A[i]==T[j]){
			i++;j++;
		}
		else{
			i=i-(j-1);//���Խ�j���Ϊi�ƶ��Ĵ�����һ��ʼ��0 
			j=0;
		}
	}
	if(j=T[0]) return i-j;
	else return -1 ;
}
//һ�ֲ��ƶ�i�������ƶ�j���㷨�� 

//ƥ��ʧ�ܵ�ʱ��j���j-next[j];
//next[j]=k������ǰ�ַ����ַ���֮�У�j֮ǰ����󳤶�Ϊk����ͬ��ǰ׺��׺��
//��Ҳ��ζ����ĳ���ַ�ʧ��ʱ�����ַ���Ӧ��next ֵ���������һ��ƥ���У�ģʽ��Ӧ�������ĸ�λ�ã�����next [j] ��λ�ã������next [j] ����0��-1��������ģʽ���Ŀ�ͷ�ַ�����next [j] = k �� k > 0�������´�ƥ������j ֮ǰ��ĳ���ַ���������������ͷ���Ҿ���������k ���ַ���
//iһֱ�ǹ��ؾص��ƶ��ģ�ֻ������j���ƶ�������j�ƶ�����Ϊ���һ����˶��ٶ��١� 
int 
