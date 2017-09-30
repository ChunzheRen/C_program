//void union(List &A,List B) {
//	laLen=ListLength(A);
//	lbLen=ListLength(B);
//	for (i=0;i<=lbLen;i++){
//		GetElem(B,i,&e);
//		if (LocateElem(A,e,equal)){
//			ListInsert(A,++laLen,e)
//		}
//	}
//}

void Mergelist(List A,List B,list &C){
	InitList(C);
	i=j=1,k=0;
	laLen=ListLength(A);
	lbLen=ListLength(B);
	while ()(i<laLen))&&(k<lbLen)){
		GetElem (A,i,ai);
		GetElem (B,j,bj);
		if (ai<bj){
			ListInsert(C,++k,ai);
			++i;
		}
		else {
			ListInsert(C,++k,bj);
			++j;
		}
}
		#以下处理的是一个表被使用空了之后的结果 ：其实是可以进行判断长度的。 
		while (i<=laLen){
			GetElem(A,i++,ai);
			ListInsert(C,++k,ai);
		}
		while(j<=lbLen) {
			GetElem(B,j++,bj);
			ListInsert(C,++k,bj)
		}
	}
}



