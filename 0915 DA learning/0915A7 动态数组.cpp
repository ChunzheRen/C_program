#include <stdio.h>
#include <stdlib.h>
int main(){
    int arrLen;  // ���鳤��
    int *array;  // ����ָ��
    int *arrayCopy;  // ����ָ�븱�� 
    int i;  // �����±�
    printf("�������鳤�ȣ�");
    scanf("%d", &arrLen);
    
    // ��̬�����ڴ�ռ䣬���ʧ�ܾ��˳�����
    arrayCopy = array = (int*)malloc( arrLen*sizeof(int) );
    if(!array){
        printf("��������ʧ�ܣ�\n");
        exit(1); 
    }
    
    // ���ڴ���д������ 
    for(i=0; i<arrLen; i++){
        *arrayCopy++ = i+1;
    }//���Ǹı�ָ��ĵ�ַ����Ӹı�ָ���ָ�� 
    
    // ѭ���������Ԫ��
    arrayCopy = array;
    for(i=0; i<arrLen; i++){
        printf("%d  ", *arrayCopy++);
    }
    
    printf("\n");
    free(array); 
    
    system("pause");
    return 0;
}
