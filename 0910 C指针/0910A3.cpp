Status InitList(SqList *L) 
 {
   (*L).elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
   if(!(*L).elem)
     exit(OVERFLOW); 
   (*L).length=0; 
   (*L).listsize=LIST_INIT_SIZE; 
   return OK;
 }
 

// L作为一个指向指针的东西，*L 相当于L指向的实例对象。
// 然后*(L.elem) 是没有意义的，只有(*L).elem 才有实际意思。
// 而由于运算符的优先级的关系，.会比解除引用应用的范围更广。 

//2017年9月11日09:08:01
//？？？？ 
 
