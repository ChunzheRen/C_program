public class OrderArray {  
      private int [] intArray;  
      private int length = 0;       //����Ԫ�ظ���  
       
      //���췽��������������󳤶�  
      public OrderArray(int max){  
             intArray = new int [max];   
      }  
//��ʼ������һ������· ���Ƿ���ռ䣬�Ҿ��ö�ά����Ŀռ����
//���������Ƿ��������ڴ棬���������ָ����в����������е�ָ�������int����λ�þ����ˡ� 
//����Ҫ���ǡ����ձ�������һ����Ԫ�ı����ַ�����������Ԫ�صı���������Ԫ�صĶ��ַ����Ҳ����ı� 

      //�ö��ֲ��ҷ���λĳ��Ԫ�أ�������ڷ������±꣬�������򷵻�-1  
      public int find(int target){  
             int lowerBound = 0;                 //��������СԪ�ص�С��  
             int upperBound = length-1;      //���������Ԫ�ص��±�  
             int curIn;                                   //��ǰ���Ԫ�ص��±�  //����ָ�� 
              
             while(true){  
                    curIn =(lowerBound+upperBound)/2;  
                     									//�ù���ָ�������Ķ������б����� 
                    if(target == intArray[curIn]){  
                           return curIn;  
                    }else if(curIn ==lowerBound){  
                    //�ڵ�ǰ�±��������ε���С�±��غ�ʱ��������������ֻ����1����2��Ԫ�أ�  
                    //�����λԪ�غ͸�λԪ�ض�������Ŀ��Ԫ�أ�֤��������û�и�Ԫ�أ���������  
                           if(target !=intArray[upperBound]){  
                                  return -1;  
                           }  
                    		}else{//�������е�Ԫ���������������ҵ�ǰԪ�ز�����Ŀ��Ԫ��  
                           		if(intArray[curIn]< target){  
                                  //�����ǰԪ��С��Ŀ��Ԫ�أ�����һ�������ε���С�±���Ϊ��ǰԪ�ص��±�  
                                  	lowerBound =curIn;  
                          		 }else{  
                                  //�����ǰԪ�ش���Ŀ��Ԫ�أ�����һ�������ε�����±���Ϊ��ǰԪ�ص��±�  
                                  	upperBound =curIn;  
                           }  
                    }  
             }  
      }  
       
      //����  
      public void insert(int elem) {  
             int location = 0;  
              
             //�ж�Ӧ����λ�õ��±�  
             for(;location<length;location++){  
                    if(intArray[location] >elem)  
                           break;  
             }  
             //System.out.println(location);  
             //�������±�֮�������Ԫ�غ���һλ  
             for(inti=length;i>location;i--){  
                    intArray[i] = intArray[i-1];  
             }  
              
             //����Ԫ��  
             intArray[location] = elem;  
              
             length++;  
      }  
       
      //ɾ��ĳ��ָ����Ԫ��ֵ��ɾ���ɹ��򷵻�true�����򷵻�false  
      public boolean delete(int target){  
             int index = -1;  
             if((index = find(target)) != -1){  
                    for(inti=index;i<length-1;i++){  
                           //ɾ��Ԫ��֮�������Ԫ��ǰ��һλ  
                           intArray[i] = intArray[i+1];   
                    }  
                    length--;  
                    return true;  
             }else{  
                    return false;  
             }  
      }  
       
      //�г�����Ԫ��  
      public void display(){  
             for(int i=0;i<length;i++){  
                    System.out.print(intArray[i]+"\t");  
             }  
             System.out.println();  
      }  
}  
