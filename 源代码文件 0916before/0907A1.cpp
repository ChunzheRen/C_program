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
		#���´������һ����ʹ�ÿ���֮��Ľ�� ����ʵ�ǿ��Խ����жϳ��ȵġ� 
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



