//简单来说就是技术的操作加上一些push和pop的操作

//mmp游程编码啊！
//矩阵初始化 
typedef struct{
	int x;
	int y;
}PosType; 

typedef int MAZETYPE[25][25];
MAZETYPE m;
//一个指针二维数组？每一个指针指向的都是一个小的数组或者结构？ 

typedef struct{
	int ord;   //通道的序号 
	PosType seat; //通道的位置
	int di;    ///下一个方向是啥 （0~3） 规定东边是0，顺时针操作。 
}ElemType;

int curstep=1;
#include "C:\Users\Ren Chunzhe\Desktop\C\ch3\SqStack.h"
#include "C:\Users\Ren Chunzhe\Desktop\C\ch3\SqStack.cpp"

//基础：每一个位置的可通过性 
int Pass(PosType b){
	if (m[b.x][b.y]==1)
		return 0;
	else return-1;
}
//基础：当前点+方向=下一个点的位置 
void NextPos (PosType c,int di){
	//定义四个方向实际都是啥，主要跟具体实现方式有关。 
	PosType direc[4]={{0,1},{1,0},{0,-1},{-1,0}};
	c.x+=direc[di].x;
	c.y+=direc[di].y;
} 
//基础：为了防止你在搜索di的时候走到原来的位置，我们把原来走过的变成-1； 
void Mark(PosType b){
	m[b.x][b.y]=-1;
}
//防止死胡同 
判断当前位置的可通过性 di 
	R  	标记当前位置-1  mark 			---1 
		push当前数据（位置、序号，方向）---1 
	F	改变方向，寻找下一个位置		---2 
		判断下一个位置的可通过性 Pass -----2 
			R  	标记当前位置-1  mark  -----1 
				push当前位置。 	SqStack ---1 
			F	-----2
					-----1 
判断下一个位置的可通过性  

记录当前位置到下一个位置的方向

记录下一个位置
//基础操作：当前位置是不是可以通过的， 对于当前位置数据的记录，对于stack和heap的输入和输出情况，对于下一个位置的寻找
 



//求算任意两个点之间的路径，并且存在stack里面 
void MazePath(PosType start,PosType end) {
	SqStack S;//存储数据 
	PosType cur_pos;
	ElemType e;
	
	InitStack(&S);
	
	//首先判断start和end是不是存在。 但是这个不应该在循环里面 
	cur_pos =start;
	do{
		if(Pass(cur_pos)){
			Mark(cur_pos);
			e.ord=cur_pos;
			e.seat.x=cur_pos.x;
			e.seat.y=cur_pos.y; 
			e.di =0;
			Push(&S,e);
			curstep++; //这个是第几个点 
			if (curpos.x==end.x&&curpos.y=end.y)
					return 0;
			else curpos=NextPos(curpos,e.di);
		}
		else{
			pass 
		}
	}while(!StackEmpty(S));
	//先进行一次计算，如果S是空的，继续，如果找出来答案了，出去。 
	//每一次循环的目的都是为了找到end而走出的一步。 
	//每一步就是当前的位置可不可以通过。可以的话，记录；不可以的话，pop。
	//但是每进行一次就开始下一次了。 
}

//基础判断当前位置的通过性
//我觉得其实C语言中已经有了一点C++的面向对象的感觉，或者说这种面向过程的语言也是可以进行面向对象的操作的。
//比如说你用一个stack作为操作的单元，然后用一些基本的成员函数和非成员函数进行操作。 

 
