int ListInsert(SqList &L, int i, ElemType e)
{
    //�жϲ���λ�õĺϷ���
    if (i<1 || i>L.length+1) return -1;
    //�жϴ洢�ռ��Ƿ���
    if (L.length >= L.listsize)
    {
        ElemType *newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT)*sizeof(ElemType));
        if (!newbase) return -1;//�洢�ռ����ʧ��
        L.elem = newbase;//�»�ַ
        L.listsize += LISTINCREMENT;//���Ӵ洢����
    }
    //�������
    ElemType *q, *p; //����2��ָ�����
    q = &(L.elem[i-1]); //qΪ����λ��(ע���β�i����ţ�����ǴӴ�1��ʼ�ģ����±��Ǵ�0��ʼ�ģ��������ת���±����i-1)
    for (p = &(L.elem[L.length - 1]); p >= q; --p) //��ai��an-1���κ��ƣ�ע����Ʋ���Ҫ�Ӻ���ǰ����
    {
        *(p + 1) = *p;
    }
    *q = e;
    ++L.length;//����1
    return 0;
}
