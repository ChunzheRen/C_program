 /* c5-4.h 稀疏矩阵的十字链表存储表示 */
 typedef struct OLNode
 {
   int i,j; /* 该非零元的行和列下标 */
   ElemType e; /* 非零元素值 */
   struct OLNode *right,*down; /* 该非零元所在行表和列表的后继链域 */
 }OLNode,*OLink;
 typedef struct
 {
   OLink *rhead,*chead; /* 行和列链表头指针向量基址,由CreatSMatrix_OL()分配 */
   int mu,nu,tu; /* 稀疏矩阵的行数、列数和非零元个数 */
 }CrossList;
 //感觉这个是一个网状的存储结构啊。。。
// 一个行指针一个列指针指向的都是第一个结点，然后就是每一个结点 
