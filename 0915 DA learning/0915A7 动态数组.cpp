#include <stdio.h>
#include <stdlib.h>
int main(){
    int arrLen;  // 数组长度
    int *array;  // 数组指针
    int *arrayCopy;  // 数组指针副本 
    int i;  // 数组下标
    printf("输入数组长度：");
    scanf("%d", &arrLen);
    
    // 动态分配内存空间，如果失败就退出程序
    arrayCopy = array = (int*)malloc( arrLen*sizeof(int) );
    if(!array){
        printf("创建数组失败！\n");
        exit(1); 
    }
    
    // 向内存中写入数据 
    for(i=0; i<arrLen; i++){
        *arrayCopy++ = i+1;
    }//就是改变指针的地址来间接改变指针的指向 
    
    // 循环输出数组元素
    arrayCopy = array;
    for(i=0; i<arrLen; i++){
        printf("%d  ", *arrayCopy++);
    }
    
    printf("\n");
    free(array); 
    
    system("pause");
    return 0;
}
