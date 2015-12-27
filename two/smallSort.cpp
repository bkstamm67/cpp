/********
 * Name:  Brian Stamm
 * Date:  1.18.15
 * Description:  This program will ask user to input 3 different numbers, show those numbers to
 * the user, and then sort those numbers  from lowest to highest. 
 * *******/

#include<iostream>

//Function prototype
void sortFunct(double value1, double value2, double value3);

int main(){

   double num1, num2, num3;

   //Basic instructions, obtaining numbers for users
   std::cout << "The program will ask for 3 numbers, and then sort those." << std::endl;
   std::cout << "Enter first number: ";
   std::cin >> num1;
   std::cout << "Enter second number: ";
   std::cin >> num2;
   std::cout << "Enter third number: ";
   std::cin >> num3;

   //Showing numbers back to user in same order
   std::cout << "Here are the numbers you entered: " << std::endl;
   std::cout << num1 <<"\t" << num2 << "\t" << num3 << std::endl;

   std::cout << "And here are those ordered from highest to lowest: " << std::endl;
   //Call to function, arg are numbers inputted by user, in order inputted
   sortFunct(num1, num2, num3);

   return 0;
}
/******************
 * sortFuction - This function will sort the 3 values given to it.  Through various
 * if/else if/ else statements, it determines which value is highest and lowest
 * and then prints back the sorted values.  There is no check prior to ensure
 * the values are doubles, since instructor specified how we could expect
 * only numbers would be entered. 
 *
 * parameters: value1, value2, and value3
 *
 * ***************/
void sortFunct(double value1, double value2, double value3){
   if(value1 > value2){
      if(value1 > value3){
         if(value2 >= value3)
	    std::cout << value1 << "\t" << value2 << "\t" << value3 << std::endl;
	 else
	    std::cout << value1 << "\t" << value3 << "\t" << value2 << std::endl;
      }
      else if(value1 < value3)
          std::cout << value3 << "\t" << value1 << "\t" << value2 << std::endl;
   }
   else if(value2 >= value1){
      if(value2 >= value3){
	 if(value3 > value1)
	    std::cout << value2 << "\t" << value3 << "\t" << value1 << std::endl;
	 else 
	    std::cout << value2 << "\t" << value1 << "\t" << value3 << std::endl;
      }
      else if(value2 < value3)
         std::cout << value3 << "\t" << value2 << "\t" << value1 << std::endl;
   }
}   
