/****
 * Name:  Brian Stamm
 * Date:  1.18.15
 * Description:  This function will ask the user for an input.  It will then
 * tell user if that input is a palindrome or not.
 * **********/

#include <iostream>
#include <string>

/******
 * Function bool, will return true if the input is palindrome,
 * false if not.  Because usign a string, it will also work
 * with phrases too.
 * parameters - i, which is a string
 * *********/
bool palin_test(std::string i){
   if (i == std::string(i.rbegin(), i.rend())){//w/i if statement, .rbegin and .rend basically flips string
      return 1; 
   }
   else{
     return 0;
   }  
}

int main(){

   std::string input;

   //Basic instructions and getting input
   std::cout <<"This program will tell if the word you enter is a" << std::endl;
   std::cout <<"palindrome or not." << std::endl;
   std::cout << "Enter a word: ";
   std::cin >> input;
     
   palin_test(input);//Function, will return either true or false.  input is arg

   if (palin_test(input)){//If statement depending on result of palin_test
      std::cout << "It is a palindrome!" <<std::endl;
   }
   else{
      std::cout <<"It isn't a palindrome!" <<std::endl;
   }

   return 0;
}
