/****
 * Name:  Brian Stamm
 * Date: 1.18.15
 * Description:  This program asks the user to enter to different numbers and then adds up all
 * the integers between them (including the two selected).
 * *******/

#include<iostream>

int main(){
   int num1, num2, range, count;
   int sum = 0;//This totals the intergers
   
   //Basic instruction block, also has in the input
   std::cout << "This program will ask for two numbers, and then" << std::endl;
   std::cout << "add up those numbers and all those between them." << std::endl;
   std::cout << "Please enter a whole integer: ";
   std::cin >> num1;
   std::cout << "Please enter another different whole integer: ";
   std::cin >> num2;


   if (num1 > num2){//If statement to determine which number is larger, so correct range is gotten	   
      range = num1 - num2;
      for (count = 0; count <= range; count++){//For loop to add up all the number between 
	   sum += num2 + count;
      }
      std::cout<<"The sum of the range is: "<< sum <<std::endl;
   }

   else if (num2 > num1){//Same as the above, just to determine if correct range gotten
      range = num2 - num1;
      for (count = 0; count <= range; count++){
	 sum += num1 + count;
      }
      std::cout<<"The sum of the range is: "<< sum <<std::endl;
   }
   
   else if (num1 == num2){// In case user inputs two of the same numbers
      std::cout << "Please enter 2 different numbers." << std::endl;
   } 
   
   else{
      std::cout << "Error.  Please try again." << std::endl; //Catch all error phrase
   }
   
   return 0;
}   
