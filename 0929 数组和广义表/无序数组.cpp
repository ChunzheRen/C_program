//示例 无序数组 Cpp 

//初始化就是分配空间。 
//删除操作就是覆盖+指针移动操作。 
//Traverse操作就是指针操作。 

//额外操作——判断数组中是不是已经存在了这个元素，如果存在就不插入。如果不存在就插入。不一定按照顺序。
//按照顺序的就是有序表了。 
 
public class Array {  
       
      private String [] strArray;  
      private int length = 0;       //数组元素个数  
              
      //构造方法，传入数组最大长度  
      public Array(int max){        //构造函数  
             strArray = new String [max];  //分配空间  
      }  
       
      //检测数组是否包含某个元素，如果存在返回其下标，不存在则返回-1  
      public int contains(String target){  
             int index = -1;  
             for(int i=0;i<length;i++){  
                    if(strArray[i].equals(target)){  
                           index = i;  
                           break;  
                    }  
             }  
             return index;  
      }  
       
      //插入  
      public void insert(String elem) {  
             strArray[length] = elem;  
             length++;  
      }  
      //删除某个指定的元素值，删除成功则返回true，否则返回false  
      public boolean delete(String target){  
             int index = -1;  
             if((index = contains(target)) !=-1){  
                    for(int i=index;i<length-1;i++){  
                           //删除元素之后的所有元素前移一位  
                           strArray[i] =strArray[i+1];//指针操作   
                    }  
                    length--;  
                    return true;  
             }else{  
                    return false;  
             }  
      }  
       
      //列出所有元素  
      public void display(){  
             for(int i=0;i<length;i++){  
                    System.out.print(strArray[i]+"\t");  
             }  
      }  
       
}   
