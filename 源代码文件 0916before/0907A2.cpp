void MergeList(List A,List B,List &C){
	InitList(C);
	i=j=1;//不是很懂系列 
	k=0;
	LaLen=ListLength(A);
	LbLen=ListLength(B);
	while ()(i<LaLen)&&(J<LbLen)){
		GetElem(A,i,ai);
		GetElem(B,j,bj);
		if (ai<bj){
			ListInsert(C,++k,ai);
		}
		else {
			ListInsert(C,++k,bj);
		}
	}
	//表的长度和最终结果没有关系 
	while(i<=LaLen){
		GetElem(A,i++,ai);
		ListInsert(C,++k,ai);
	}
	while(j<LbLen){
		GetElem(B.j++,bj);
		ListINsert(C,++k,bj);
	}
}
