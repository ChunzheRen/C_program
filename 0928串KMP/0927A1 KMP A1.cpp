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
			i=i-(j-1);//可以将j理解为i移动的次数，一开始是0 
			j=0;
		}
	}
	if(j=T[0]) return i-j;
	else return -1 ;
}
//一种不移动i，单纯移动j的算法。 

//匹配失败的时候，j变成j-next[j];
//next[j]=k代表，当前字符的字符串之中，j之前有最大长度为k的相同的前缀后缀。
//此也意味着在某个字符失配时，该字符对应的next 值会告诉你下一步匹配中，模式串应该跳到哪个位置（跳到next [j] 的位置）。如果next [j] 等于0或-1，则跳到模式串的开头字符，若next [j] = k 且 k > 0，代表下次匹配跳到j 之前的某个字符，而不是跳到开头，且具体跳过了k 个字符。
//i一直是规规矩矩的移动的，只不过是j在移动，并且j移动被称为向右滑动了多少多少。 
int 
