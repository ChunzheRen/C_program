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
		for(col=1;col<=M.rn;col++){ //col������ 
			for(p=1;p<M.nn;++p)
			if (M.data[p].)
		}
	}
}

//�ڲ�ȷ��ÿһ�еĸ���������£�ѡ��˫��ѭ�������������ж������������ǰԪ�ص�����==ѭ����ǰ�����������ת�ã����򣬽�����һ�н���רע��
//ÿ��ת�ö������к�Ԫ�ظ������ж�֮�£���Ͼ���

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
//�������Ƚ����еı�����֮��������ݵı�����Ȼ�����������ݵ��в����㵱ǰ���У��ͽ�����һ���еĲ���
//Ȼ�������������Ԫ������һ�ֱ���ƥ�䡣
//ÿһ���У���Ҫ����ȫ���ķ���Ԫ�ı�����ֻ�������˵�ǰ���У��Ż���в������������� 

