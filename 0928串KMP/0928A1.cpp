#include<stdio.h> 
#include <stdlib.h>
#include <typeinfo.h>
#include <math.h>
#include <string.h>
//֮ǰ���ǵ����ⶼ������������Ա��int ���ͣ�����û�п��ǵ���char�����͡�֮ǰ����char�����Ա���ʵ�����ϵ�ԭ������Ǵ����͡� 

//�����ô�posλ�ÿ�ʼ��T�е�Ԫ�أ���S�е�Ԫ�ؽ��бȽϣ�Ȼ�����ʧ�ܣ��ʹ�pos+i��λ��ȡ����T��Ԫ�ز���S�е�Ԫ�ؽ��бȽϡ�
#define SIZE 20
//���ֶ���char�Ĳ����������ǿ�����ʵ�ֵġ� 
typedef char SString[SIZE+1];
int StrAssign(SString T,char *chars){
	int i;   //charsָ�����һ���ַ����ɵ����鳤�� 
			//����cpp�ĸ�����԰�chars���Ϊ���顣 
	if (strlen(chars)>SIZE) return -1;
	else {
		T[0]=strlen(chars);
		for(i=1;i<T[0];i++) T[i]=*(chars+i-1);
		return 0;
	}
}
int StrCopy(SString T,SString S){
	int i;
	for(i=0;i<S[0];i++) T[i]=S[i];
	return 0;
}

int StrEmpty(SString S){
	if(S[0]==0)
		return 1;
	else 
		return 0;
}

int StrCompare(SString S,SString T){
	int i;
	for (i=1;i<=S[0]&&i<=T[0];++i){
		if S[i]!=T[i] 
			return S[i]-T[i];//�ж�Ԫ���ǲ�����ͬ 
	return S[0]-T[0];//�жϳ��� 
	}
}
///////////////////////////////////////////
#include <stdio.h> 
#include <string.h>
#define SIZE 100
typedef String [SIZE+1];

//ע��ľ���string�ĵ�һ��Ԫ�أ�Ҳ��������ĵ�һ��Ԫ�أ�Ҳ����S[0]��ʾ��������ĳ��ȡ�
//S[0]��������ĳ���

//Str��copy�����������ĳ��ȵ�cts�������Ԫ�ص�������ƽ��еġ� 

//Str Assign (String T,char *chars)
//���ǰ�һЩ�µ�Ԫ�ط��䵽һ����������ȥ��
//����Ҫ����Ǹ�ֵ��Ԫ�س���С��Ŀ���ַ����ĳ��� 

//Ԫ��֮��ĸ�ֵ���� T[i]=*(chars+i-1); =chars[i-1]
//��Ϊ��T�ĵ�һ��Ԫ����û�����ݵģ������洢���ȣ���chars�ĵ�һ��Ԫ�ش洢���ĳ��ȡ�
//���Ի��в��Ե�������ޡ� 

//String�Ǳ���������ģ����Բ���Ҫ�����ָ�롣 

//compare�����ǳ�����
for(int i=0;i<=S[0]&&i<=T[0];i++) {
	if (S[i]!=T[i]) return S[i]-T[i];
	return S[0]-T[0]
}

//�����洢���ĳ��ȾͿ����ĵ�һ��Ԫ�ص�λ�þ����ˡ�
int ClearString (String S){
	S[0]=0;//��ִ�и��ǲ��������ˡ� 
}

void DestroyString()
 { /* ����SString�Ƕ�������,�޷����� */
 }//����������ٶ��ǻ���һ��malloc�ġ� 

StrPrint(String T) {
	int i;
	for (i=0;i<=T[0];i++){
		printf("%c",T[i]);
	}
	printf("\n");
}
 
 
 
 //�����Ӵ���λ��pos����ĵ�һ�γ��ֵ�λ�á� 
int Index (String S,String T,int pos){
	int i,j;
	i=pos;		
	j=1;
	while(i<=S[0]&&j<=T[0]){
		if(S[i]==T[j]){
			++i;				
			++j;
		}
		else{
			i=i-j+2;//???????//
			j=1;
		}
	}
	
	if (j>T[0]) return i-T[0];//????????
	else return 0;
}

 
 
 
 
 
 
 
int Replace(String A,String B,String C){
	int i=0;
	if(StrEmpty(T)){
		return -1;
	}
	do{
		i=Index(S,T,i);
	}while(i);
	return OK;
}

�ռ����Ĳ�����
//��λ����Ԫ�ص�λ�á� ���Ӵ�λ�õĶ�λ���� 

//�ַ��������ĺ��ľ����ַ���ƥ��Substring searchȻ��Ƚϵ���ð취����KMP���бȽ�
��Ҫ��һ��next����

int_IndexKMP(String A,String T,int pos=0) {
	i=pos; j=1;
	while (i<=A[0]&&j<=T[0]){
		if (j==0 || S[i]=T[j]){
			++i;++j; //����ոտ�ʼƥ������Ѿ�����һ��ƥ�� 
		}
		else{
			j=next[j];  //������ֲ�ƥ������������Ҫ��j�����ƶ�λ�ã���i��λ�ò��䡣 
		} 
		if(j>T[0]) return i-T[0] ;//���һ��ƥ����� ���ɹ�ƥ��֮�󣬴�ʱj=T[0] ��Ȼ�󷵻�i��λ�ã����ǵ�ǰ��i��ȥpattern�ĳ��ȡ� 
		else return 0;
	}
}
//������next�㷨��next_plus�㷨,���Ƕ���string����һ��Ԥ����Ĳ����� 
int get_next(String T,int next[]){
	i=1;next[1]=0;j=0;
	while(j<T[0]){
		if(j==0 || T[i]==T[j]){//�տ�ʼƥ������Ѿ�ƥ����� 
			++i;++j;
			next[i]=j;
		}
		else {
			j=next[j];
		}
	}
}//�����ر��

int next_plus(String T,int next[]) {
	i=1;next[1]=0;j=0;//next�����1��ʼ 
	while(i<T[0]){
		if(j==0 || T[i]==T[j]){
			++i;++j;next[i]=next[j];
		}
		else{
			j=next[j];
		}
	}
}//������ģʽ������Ѱ��һ���Ӵ� 








