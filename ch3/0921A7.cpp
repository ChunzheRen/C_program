//mmp�γ̱��밡��
//�����ʼ�� 
typedef struct{
	int x;
	int y;
}PosType; 

typedef int MAZETYPE[25][25];
MAZETYPE m;
//һ��ָ���ά���飿ÿһ��ָ��ָ��Ķ���һ��С��������߽ṹ�� 

typedef struct{
	int ord;   //ͨ������� 
	PosType seat; //ͨ����λ��
	int di;    ///��һ��������ɶ ��0~3�� �涨������0��˳ʱ������� 
}ElemType;

int curstep=1;
#include "C:\Users\Ren Chunzhe\Desktop\C\ch3\SqStack.h"
#include "C:\Users\Ren Chunzhe\Desktop\C\ch3\SqStack.cpp"

//������ÿһ��λ�õĿ�ͨ���� 
int Pass(PosType b){
	if (m[b.x][b.y]==1)
		return 0;
	else return-1;
}
//��������ǰ��+����=��һ�����λ�� 
void NextPos (PosType c,int di){
	//�����ĸ�����ʵ�ʶ���ɶ����Ҫ������ʵ�ַ�ʽ�йء� 
	PosType direc[4]={{0,1},{1,0},{0,-1},{-1,0}};
	c.x+=direc[di].x;
	c.y+=direc[di].y;
} 
//������Ϊ�˷�ֹ��������di��ʱ���ߵ�ԭ����λ�ã����ǰ�ԭ���߹��ı��-1�� 
void Mark(PosType b){
	m[b.x][b.y]=-1;
}
//��ֹ����ͬ 
�жϵ�ǰλ�õĿ�ͨ���� di 
	R  	��ǵ�ǰλ��-1  mark 			---1 
		push��ǰ���ݣ�λ�á���ţ�����---1 
	F	�ı䷽��Ѱ����һ��λ��		---2 
		�ж���һ��λ�õĿ�ͨ���� Pass -----2 
			R  	��ǵ�ǰλ��-1  mark  -----1 
				push��ǰλ�á� 	SqStack ---1 
			F	-----2
					-----1 
�ж���һ��λ�õĿ�ͨ����  

��¼��ǰλ�õ���һ��λ�õķ���

��¼��һ��λ��
//��������������֮���·�������Ҵ���stack���� 
void MazePath(PosType start,PosType end) {
	SqStack S;//�洢���� 
	PosType cur_pos;
	ElemType e;
	
	InitStack(&S);
	
	//�����ж�start��end�ǲ��Ǵ��ڡ� ���������Ӧ����ѭ������ 
	cur_pos =start;
	do{
		if(Pass(cur_pos)){
			Mark(cur_pos);
			e.ord=cur_pos;
			e.seat.x=cur_pos.x;
			e.seat.y=cur_pos.y; 
			e.di =0;
			Push(&S,e);
			curstep++; //����ǵڼ����� 
			if (curpos.x==end.x&&curpos.y=end.y)
					return 0;
			else curpos=NextPos(curpos,e.di);
		}
		else{
			pass 
		}
	}while(!StackEmpty(S));
	//�Ƚ���һ�μ��㣬���S�ǿյģ�����������ҳ������ˣ���ȥ�� 
	//ÿһ��ѭ����Ŀ�Ķ���Ϊ���ҵ�end���߳���һ���� 
	//ÿһ�����ǵ�ǰ��λ�ÿɲ�����ͨ�������ԵĻ�����¼�������ԵĻ���pop��
	//����ÿ����һ�ξͿ�ʼ��һ���ˡ� 
}




//�����жϵ�ǰλ�õ�ͨ����
stack�ǲ��ǿյ�
�����ǲ��ǿյ�
�洢����push��pop 


