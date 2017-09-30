#include <stdio.h>
#define SIZE 12500
typedef struct{
	int i,j;
	ElemType e;
}Triple;
typedef struct{
	Triple data[MAXSIZE+1];
	int ln,cn,nn;
}TSMatrix;
int TransposeMatrix(TSMatrix M,TSMatrix *N){
	N.rn=M.cn;N.cn=M.rn;N.nn=M.nn;
	if (M.nn){
		q=1;
		for(col=1;col<=M.rn;col++){ //col是主序 
			for(p=1;p<M.nn;++p)
			if (M.data[p].)
		}
	}
}

//在不确定每一行的个数的情况下，选择双重循环，并且增加判断条件，如果当前元素的列数==循环当前列数，则进行转置，否则，进入下一行进行专注。
//每次转置都是在列和元素个数的判断之下，结合矩阵。

typedef struct {
	int x,y;
	ElemType e;
}Tripoint; 
typedef struct{
	Tripoint data[MAX+1];
	int a,b,c;
}TriMatrix;

int func(TriMatrix M,TriMatrix *N){
	N.a=M.b; N.b=M.a;N.c=M.c;
	if (N.c){
		q=1;
		for(pt1=1;pt1<M.b;pt1++){
			for(pt2=1;pt2<M.c;pt2++){
				if(M[pt2].x==pt1){
					N.[pt2].x=M.[pt2].y;
					N.[pt2].y=M.a[pt2].x;
					N.[pt2].e=M.a[pt2].e;
					++q;
				}
			}
		}
	}
	return 0;
}
//就是首先进行列的遍历。之后进行数据的遍历，然后就是如果数据的列不满足当前的列，就进行下一次列的操作
//然后继续遍历非零元。就是一种暴力匹配。
//每一个列，都要进行全部的非零元的遍历，只有满足了当前的列，才会进行操作（遍历）。 

