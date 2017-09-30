#include <stdio.h>
#include <time.h>

//void getSeconds(unsigned long *par) {
//   /* get the current number of seconds */
//   *par = time( NULL );
//   return;}
//int main () {
//   unsigned long sec;
//   getSeconds( &sec );
//   /* print the actual value */
//   printf("Number of seconds: %ld\n", sec );
//   return 0;}
//   
////虽然没有返回second ，但是确实改变了second 的内存数值。






//#include <stdio.h>
// 
///* function declaration */
//double getAverage(int *arr, int size);
// 
//int main () {
//
//   /* an int array with 5 elements */
//   int balance[5] = {1000, 2, 3, 17, 50};
//   double avg;
// 
//   /* pass pointer to the array as an argument */
//   avg = getAverage( balance, 5 ) ;
// 
//   /* output the returned value  */
//   printf("Average value is: %f\n", avg );
//   return 0;
//}
//
//double getAverage(int *arr, int size) {
//
//   int  i, sum = 0;  //i是计数器 sum是总和     
//   double avg;          
// 
//   for (i = 0; i < size; ++i) {		
//      sum += arr[i];
//   }
// 
//   avg = (double)sum / size;
//   return avg;
//}




#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
/* function to generate and return random numbers. */
int * getRandom( ) {

   static int  r[10];//声明静态的数组很有必要 
   int i;  //计数器 
 
   /* set the seed */
   srand( (unsigned)time( NULL ) );
	
   for ( i = 0; i < 10; ++i) {
      r[i] = rand();
      printf("%d\n", r[i] );
   }
 
   return r;
}
 
/* main function to call above defined function */
int main () {

   /* a pointer to an int */
   int *p;
   int i;

   p = getRandom();
	
   for ( i = 0; i < 10; i++ ) {
      printf("*(p + [%d]) : %d\n", i, *(p + i) );
   }
 
   return 0;
}







