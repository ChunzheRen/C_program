//�����д��ݸ�������ָ����һ�����������Բ��ص���������޸�ԭ����ָ�룬������Ҫ�Ǵ���һ������ָ��ͻ�ı�һ��ָ���ָ��
//���ڴ��ݽ�ȥ����һ��һ��ָ�룬���������һ��ָ��malloc����ȫû���κ�����ģ�����Ҫ���ݶ���ָ�������òŻ�malloc������
//������Ȼ����Ϊ���ݵ�ַ������ʵ����Ҳ�Ǵ���һ��ָ��Ŀ����������޸���Ϊʵ�ʲ�����ָ�롣
//��������ָ���Ӱ���������Ӱ��ֲ��������е�ָ�뿽����ָ�򣬵���ȴ����Ӱ�캯��ʵ�ʲ�����������
//���������޸�ʵ�ʲ�����������ݣ���������һ��constָ�룬���Բ����޸����ݡ� 
/////һ���������ַ���������\0��β��C 

//����Ĳ������±��ָ�붼���� 
int Traverse(char array[10]){
	while(*array!='\0'){//�����Ҿ�ʼ���벻���������ж�������ɶ�� �ַ�����ĩβ����\0 
		printf("%c>>",*array);
		array++;
	}
	return 0;//�ַ�������ĩβ���Զ�������\0������ֱ���жϾͺá� 
}
int main(){
	char array[10]="helloworl"; //(9+\0)
	Traverse(array);
	printf("%c",array[1]);
	return 0 ;
}



int Traverse(int array[10]){
	while(*array!='\0'){//�����Ҿ�ʼ���벻���������ж�������ɶ�� �ַ�����ĩβ����\0 
		printf("%d>>",*array);
		array++;
	}
	return 0;//�ַ�������ĩβ���Զ�������\0������ֱ���жϾͺá� 
}
int main(){
	int array[10]={1,2,3,4,5,6,7,8,9}; //(9+\0)�ַ���char����  
	Traverse(array);//һ���������涼��\0��β��ֱ���ж�ָ��������֮���ǲ���\0�ͺ��ˡ� 
	return 0 ;
}



int Traverse(int*pt) {
	printf("\nStarting Traversing.\n");
	while((*pt)!='\0'){
		printf("ok!\n");
		printf("%d",*pt);
		pt++; //������������ΪԪ�ز���ʱ������Ķ����ᱻ���Ϊ 
	} 
	printf("i am here.\n");
	
}
int main(){
//	int *array;
//	array =(int*) malloc (sizeof(int)*SIZE);
	int array[SIZE];
	int* pt=(int*)malloc(sizeof(int));
	
	int cts=0;
	
	printf("Start Entering.\n");
	while ((scanf("%d",pt))&& cts<10){
		array[cts]=*pt;//array = pt ����˼����arrayָ��pt�����Ա�����*array 
		cts++;
	}
	printf("Entering terminated.\n");
//	int cts1=0;
//	while(cts1<=cts){
//		printf("%d__",*array);
//		array[cts];
//		cts1++;
//	}
	
	Traverse(array);//һ���������涼��\0��β��ֱ���ж�ָ��������֮���ǲ���\0�ͺ��ˡ� 
	
	free(pt);
	printf("unable to exit.\n");
//	free(array);//һ������malloc�Ķ���û�취��malloc�ͷš� 
	
//	&array��int (*)[10]���� 
	return 0 ;
}



//////////////�ɹ�����ָ�����߼������������ 
int Traverse(int*pt) {
	printf("\nStarting Traversing.\n");
	while((*pt)){
		printf("ok!\n");
		printf("%d",*pt);
		pt++; 
	} 
	printf("i am here.\n");
	
}
int main(){
	int *array;
	array =(int*) malloc (sizeof(int)*SIZE);  //	int array[SIZE];
	int* pt=array;//ptָ��array���޸�pt���޸�array��ֵ�� 
	
	while ((scanf("%d",pt))){		
//		array[cts]=*pt;//array = pt ����˼����arrayָ��pt�����Ա�����*array 
//		*array=*pt;array++;//��Ϊ��ʵ�ʵĲ���������arrayÿ�ε��ƶ�����ָ����һ���µ�λ�ã�����˵ͬ����С��ָ��ռ������ռ䲢��һ����
		pt++;
	}
	
	Traverse(array);//һ���������涼��\0��β��ֱ���ж�ָ��������֮���ǲ���\0�ͺ��ˡ� 
	
//	free(array);//һ������malloc�Ķ���û�취��malloc�ͷš� ��̬�ڴ�ר�� 
	
//	&array��int (*)[10]���� 
	return 0 ;
}
