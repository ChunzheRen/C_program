#include <stdio.h>
#include <stdlib.h>
//int main(){
//	int a[10] ={1,2,3,4,5,6,7,8,9,10};
//	int *pt = &a[2];
//	printf("%d\n",pt[0]);
//	printf("%d\n",(pt[1]));
//	printf("%d\n",*(pt+2));
//	printf("%d\n",(2[a]));  //��˼���� *(2+a[0]) 
//	return 0;	
//}
//�������ֵ�ᱻ����Ϊһ��������Ҳ���ǻᱻ����һ���̶���С�Ŀռ䣬�����أ����ָ���ǲ��ᱻ����ָ��Ĵ�С�ģ����ԣ�ʹ��ָ������������ǿ���ָ�����㣬���������˵�ǲ����Խ������������
//�������ݵĶ��ǰ�����ֵ���д��ݣ���ʹ��ָ�룬������Ҳ�Ǵ���һ��ָ��Ŀ���������ȥ�����ǽ����˵�ַ�Ĵ���
//���ԣ�����һ��non const��ָ����ʵ������ȫ����û��Ǵ���һ��const ָ�룬����㲻ϣ�����޸ĵ������ 





//void strcpy(char *buffer ,char*const string ) {
//	while ((*buffer++==*string++ )!='\0') {
//		continue ;
//	}
//}
//constһ�����ε�����ߣ�Ȼ�����õ���char *const string Ҳ����һ��ָ��char��constָ�룬��ר�ŷ�ֹ���޸ĵģ�����˵���ָ��ֻ��ָ��̶���λ�á�
//��const char *pt ����ָ���ַ��������ǿ����޸�ָ���λ�õģ�Ӧ��Ҳ���ܽ����滻�ġ� 
void strcpy(char *buffer,char * string) {
	while ((*buffer ++==*string ++)!='\0'){
		continue;
	}
}
//	char *buffer ="buffer"; //���Ʋ��ԣ���Ϊ��һ��non constָ�����һ��const���ַ�������������ÿ��ܶ���
//	��ʵ���char *�������C���Զ�������Ķ��صĹ涨��

//int strlen(char *str){
//	int len =0;
//	char ch=*str;
//	while(ch){
//		ch=*(str++);
//		printf("%c\n",ch);
//		len++;
//	}
//	return len;
//}
//int main(){
//	char pt[] ="12345";
//	int num = strlen(pt);
//	printf("%d\n",num);
//}


//
//char str[] = "This is the end";
//char input[100];
//
//printf("%s\n", str);
//printf("%c\n", *str);
//
//scanf("%99s", input);



//%s will get all the values until it gets NULL i.e. '\0'.

int main(){
	char *pt ="hello\0world";
	printf("%s",pt);
	printf("\n");
	char *pt1="const stirng";
	while (*pt1){
//		printf("%c",*(pt1));
//		printf("%s",*(pt1));��������ͻᵼ�����ʧ�ܡ� 
		pt1++;
	}
}

//strcpy�Ĺ��ܾ��ǽ����ַ����Ŀ������Լ��Զ������\0�ں��档 



For both *printf and *scanf, %s expects the corresponding argument to be of type char *, 
and for scanf, it had better point to a writable buffer (i.e., not a string literal).
//���� *scanf �� *printf ��˵��%s��ϣ����������char*���� ��Ȼ�����scanf����þ���ָ��һ�������޸ĵı������ͣ���ò�Ҫ���ַ���������
char *str_constant = "I point to a string literal";  //�ַ������� 
char str_buf[] = "I am an array of char initialized with a string literal"; //�ַ������ɱ䳤�ȡ� 

printf("string literal = %s\n", "I am a string literal");  //�ɵ������ַ������� 
printf("str_constant = %s\n", str_constant);				//�ַ�������    ����ָ��ָ��� 
printf("str_buf = %s\n", str_buf);
//printf��%s ������char *��""  ��������char pt[]��"" ������ "" ,��֮���Ƿǳ��Ĺ㷺�� 
scanf("%55s", str_buf);
//scanf��%s ����ÿɵ�����[] �������� ������Ҫ���ַ�����
//scanfһ���漰����%s,�˳��Ƕ���������޸ģ����Ծ���û�к��£����Ծ;����ÿɵ���������Ϊ����Ľ����ߡ�Ҳ�����ַ������顢

//�����ַ����� 
//Ȼ�����ϲ���ּ���scanf����¼���getsҲһ����������fgets��fputs
//��printf��һ�����ǣ����Խ��� �����С���������ơ�
//��scanf���ڵ�һ���հ׵�λ��ͣ������ 
 


 
