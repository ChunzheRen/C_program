int ListInsert(SqList &L, int i, ElemType e)
{
    //判断插入位置的合法性
    if (i<1 || i>L.length+1) return -1;
    //判断存储空间是否够用
    if (L.length >= L.listsize)
    {
        ElemType *newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT)*sizeof(ElemType));
        if (!newbase) return -1;//存储空间分配失败
        L.elem = newbase;//新基址
        L.listsize += LISTINCREMENT;//增加存储容量
    }
    //插入操作
    ElemType *q, *p; //定义2个指针变量
    q = &(L.elem[i-1]); //q为插入位置(注意形参i是序号，序号是从从1开始的，而下标是从0开始的，因此这里转成下标后是i-1)
    for (p = &(L.elem[L.length - 1]); p >= q; --p) //从ai到an-1依次后移，注意后移操作要从后往前进行
    {
        *(p + 1) = *p;
    }
    *q = e;
    ++L.length;//表长加1
    return 0;
}
