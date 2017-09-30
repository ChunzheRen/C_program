#include<stdio.h> 
#include <stdlib.h>
#include <typeinfo.h>
#include <math.h>
#include <string.h>
//之前我们的问题都集中在这个线性表和int 类型，但是没有考虑到·char的类型。之前纠结char的线性表其实本质上的原因就是是串类型。 

//就是用从pos位置开始求T中的元素，和S中的元素进行比较，然后如果失败，就从pos+i的位置取出来T中元素并和S中的元素进行比较。
#define SIZE 20
//发现对于char的操作基本都是靠数组实现的。 
typedef char SString[SIZE+1];
int StrAssign(SString T,char *chars){
	int i;   //chars指向的是一堆字符构成的数组长度 
			//根据cpp的概念，可以把chars理解为数组。 
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
			return S[i]-T[i];//判断元素是不是相同 
	return S[0]-T[0];//判断长度 
	}
}
///////////////////////////////////////////
#include <stdio.h> 
#include <string.h>
#define SIZE 100
typedef String [SIZE+1];

//注意的就是string的第一个元素，也就是数组的第一个元素，也就是S[0]表示的是数组的长度。
//S[0]就是数组的长度

//Str的copy操作是依靠的长度的cts，外加上元素的逐个复制进行的。 

//Str Assign (String T,char *chars)
//就是把一些新的元素分配到一个数组里面去。
//但是要求就是赋值的元素长度小于目标字符串的长度 

//元素之间的赋值操作 T[i]=*(chars+i-1); =chars[i-1]
//因为你T的第一个元素是没有数据的，单纯存储长度，而chars的第一个元素存储产的长度。
//所以会有不对的情况出限。 

//String是被看做数组的，所以不需要额外的指针。 

//compare操作非常精妙
for(int i=0;i<=S[0]&&i<=T[0];i++) {
	if (S[i]!=T[i]) return S[i]-T[i];
	return S[0]-T[0]
}

//定长存储串的长度就靠串的第一个元素的位置决定了。
int ClearString (String S){
	S[0]=0;//就执行覆盖操作就行了。 
}

void DestroyString()
 { /* 由于SString是定长类型,无法销毁 */
 }//就是你的销毁都是基于一个malloc的。 

StrPrint(String T) {
	int i;
	for (i=0;i<=T[0];i++){
		printf("%c",T[i]);
	}
	printf("\n");
}
 
 
 
 //返回子串在位置pos后面的第一次出现的位置。 
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

终极串的操作：
//定位串的元素的位置。 求子串位置的定位函数 

//字符串操作的核心就是字符串匹配Substring search然后比较的最好办法是用KMP进行比较
主要是一个next函数

int_IndexKMP(String A,String T,int pos=0) {
	i=pos; j=1;
	while (i<=A[0]&&j<=T[0]){
		if (j==0 || S[i]=T[j]){
			++i;++j; //如果刚刚开始匹配或者已经发现一个匹配 
		}
		else{
			j=next[j];  //如果发现不匹配的情况，就需要对j进行移动位置，而i的位置不变。 
		} 
		if(j>T[0]) return i-T[0] ;//最后一个匹配完成 ，成功匹配之后，此时j=T[0] ，然后返回i的位置，就是当前的i减去pattern的长度。 
		else return 0;
	}
}
//下面是next算法和next_plus算法,就是对于string进行一次预处理的操作。 
int get_next(String T,int next[]){
	i=1;next[1]=0;j=0;
	while(j<T[0]){
		if(j==0 || T[i]==T[j]){//刚开始匹配或者已经匹配完成 
			++i;++j;
			next[i]=j;
		}
		else {
			j=next[j];
		}
	}
}//不是特别好

int next_plus(String T,int next[]) {
	i=1;next[1]=0;j=0;//next矩阵从1开始 
	while(i<T[0]){
		if(j==0 || T[i]==T[j]){
			++i;++j;next[i]=next[j];
		}
		else{
			j=next[j];
		}
	}
}//首先在模式串里面寻找一个子串 








