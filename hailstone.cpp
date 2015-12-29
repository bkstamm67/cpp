/*******
 * Name:  Brian Stamm
 * Date:  1.18.15
 * Description:  This program runs a hailstone sequence.  It will ask the user for 
 * a number, and from that number perform the hailstone sequence, counting how many
 * steps it takes to get to 1.
 * ***********/

#include<iostream>
#include <string>
#include <cstdlib>

//Function prototype
int hailstone(int num);

/*************
 * is_num Function - it will determine if what the user inputted is a positive 
 * whole number.  If it isn't, then false.  If it is, then true
 * parameters - str, will come from user input
 * **********/
bool is_num(std::string str){
   for(int i=0; i<str.length(); i++){//goes through each item in string to make sure all digits
      if(!(str.at(i)>='0' && str.at(i) <= '9'))
	 return false;
   }
   return true;
}

int main(){

   int given_num, iterations;
   std::string input;
   
   std::cout << "This program will run a hailstone sequence, or a Collatz conjecture for" <<std::endl;
   std::cout << "all those mathematics lovers out there.  You will enter a number and " <<std::endl;
   std::cout <<"the program will show how many sequences it takes to get to 1." <<std::endl;
   std::cout << "Please enter a positive whole number: ";
   std::cin >> input;//INPUT STARTS AS A STRING!!!!
   
   if (is_num(input)){//First function within if - makes sure input is a number
      given_num = atoi(input.c_str()); //Changes input into a int!!!!
      if (given_num ==0){//Error message if number is zero, no call to hailstone function
         std::cout << "Sorry, please enter a positive, non-zero number." <<std::endl;
         std::cout << "Try again." <<std::endl;
      }
      else if (given_num == 1){//message if 1, no call to hailstone function
         iterations = 0;
         std::cout << "Given " << given_num << " the hailstone sequence would" <<std::endl;
         std::cout << "run " << iterations << " times until it reached 1." <<std::endl;
      }
      else if(given_num > 1){
         iterations = hailstone(given_num);//only call to hailstone function, using given_num as argm 
         std::cout << "Given " << given_num << " the hailstone sequence would" <<std::endl;
         std::cout << "run " << iterations << " times until it reached 1." <<std::endl;
      }
   }
   else{//if is_num false, prints error message
      std::cout << "Sorry, please enter a positive, non-zero number." <<std::endl;
      std::cout << "Try again." <<std::endl;
   }
      
   return 0;
}
/***********
 * hailstone function
 * do while loop - does basic math of hailstone sequence w/i if else if statement
 * each time goes through the if else if loop, adds to counter.  Counter result is the
 * one being return
 * 
 *parameter - num (from given_num), creates counter within function
 * ********/
int hailstone (int num){
   int counter = 0;
   do{
      if (num % 2 == 0){ //even
         num /= 2;
         counter++;
      }
      else if (num % 2 !=0){
         num = (3 * num) + 1;
	 counter++;
      }
   } while (num !=1);
   return counter;
}
