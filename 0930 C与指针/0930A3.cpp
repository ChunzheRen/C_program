//数组中传递给函数的指针是一个拷贝，所以不必担心数组会修改原来的指针，但是你要是传递一个二重指针就会改变一次指针的指向。
//由于传递进去的是一个一次指针，因而你给这个一次指针malloc是完全没有任何意义的，必须要传递二次指针解除引用才会malloc？？？
//数组虽然表现为传递地址，但是实际上也是传递一个指针的拷贝，不会修改作为实际参数的指针。
//函数对于指针的影响仅仅限于影响局部作用域中的指针拷贝的指向，但是却不会影响函数实际参数本身？？？
//函数不会修改实际参数本身的内容？？数组是一个const指针，所以不会修改内容。 
/////一般的数组和字符串都是用\0结尾。C 

//数组的操作用下标和指针都可以 
int Traverse(char array[10]){
	while(*array!='\0'){//但是我就始终想不出来到底判断条件是啥。 字符串的末尾倒是\0 
		printf("%c>>",*array);
		array++;
	}
	return 0;//字符串由于末尾是自动加上了\0，所以直接判断就好。 
}
int main(){
	char array[10]="helloworl"; //(9+\0)
	Traverse(array);
	printf("%c",array[1]);
	return 0 ;
}



int Traverse(int array[10]){
	while(*array!='\0'){//但是我就始终想不出来到底判断条件是啥。 字符串的末尾倒是\0 
		printf("%d>>",*array);
		array++;
	}
	return 0;//字符串由于末尾是自动加上了\0，所以直接判断就好。 
}
int main(){
	int array[10]={1,2,3,4,5,6,7,8,9}; //(9+\0)字符串char类型  
	Traverse(array);//一般的数组后面都是\0结尾，直接判断指针解除引用之后是不是\0就好了。 
	return 0 ;
}



int Traverse(int*pt) {
	printf("\nStarting Traversing.\n");
	while((*pt)!='\0'){
		printf("ok!\n");
		printf("%d",*pt);
		pt++; //当你用数组作为元素参数时候，数组的东西会被填充为 
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
		array[cts]=*pt;//array = pt 的意思是让array指向pt，所以必须用*array 
		cts++;
	}
	printf("Entering terminated.\n");
//	int cts1=0;
//	while(cts1<=cts){
//		printf("%d__",*array);
//		array[cts];
//		cts1++;
//	}
	
	Traverse(array);//一般的数组后面都是\0结尾，直接判断指针解除引用之后是不是\0就好了。 
	
	free(pt);
	printf("unable to exit.\n");
//	free(array);//一个不是malloc的东西没办法用malloc释放。 
	
//	&array是int (*)[10]类型 
	return 0 ;
}



//////////////成功的用指针在逻辑上替代了数组 
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
	int* pt=array;//pt指向array，修改pt来修改array的值。 
	
	while ((scanf("%d",pt))){		
//		array[cts]=*pt;//array = pt 的意思是让array指向pt，所以必须用*array 
//		*array=*pt;array++;//因为是实际的操作，所以array每次的移动都是指向了一个新的位置，所以说同样大小的指针空间和数组空间并不一样。
		pt++;
	}
	
	Traverse(array);//一般的数组后面都是\0结尾，直接判断指针解除引用之后是不是\0就好了。 
	
//	free(array);//一个不是malloc的东西没办法用malloc释放。 动态内存专用 
	
//	&array是int (*)[10]类型 
	return 0 ;
}
