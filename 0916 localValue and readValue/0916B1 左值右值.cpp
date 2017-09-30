// reference_declarator.cpp  
// compile with: /EHsc  
// Demonstrates the reference declarator.  
#include <iostream>  
using namespace std;  
  
struct Person  
{  
    char* Name;  
    short Age;  
};  
  
int main()  
{  
   // Declare a Person object.  
   Person myFriend;  
  
   // Declare a reference to the Person object.  
   Person& rFriend ;        //����һ��Person���������͡� 
   rFriend = myFriend;      
  
   // Set the fields of the Person object.  
   // Updating either variable changes the same object.  
   myFriend.Name = "Bill";  
   rFriend.Age = 40;  			///rFriend��myFriend�����á��൱�ڶ���myFriend��ֱ�Ӹı䡣 
  
   // Print the fields of the Person object to the console.  
   cout << rFriend.Name << " is " << myFriend.Age << endl;  
}  
//BILL is 40 
//[Warning] deprecated conversion from string constant to 'char*' [-Wwrite-strings]
