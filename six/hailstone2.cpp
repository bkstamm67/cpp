/*******
 * Name:  Brian Stamm
 * Date:  2.15.15
 * Description:  This program is exactly the same from the previous hailstone project
 * except rather than using a regular function, it uses a recursive function.
 * ***********/

#include<iostream>
#include <string>
#include <cstdlib>

using namespace std; 

int hailstone(int, int); //function prototype

/*************
 * is_num Function - it will determine if what the user inputted is a positive 
 * whole number.  If it isn't, then false.  If it is, then true
 * parameters - str, will come from user input
 * **********/

bool is_num(string str){
   for(int i=0; i<str.length(); i++){//goes through each item in string to make sure all digits
      if(!(str.at(i)>='0' && str.at(i) <= '9'))
	 return false;
   }
   return true;
}

int main(){

   int given_num, iterations;
   string input;
   int counter = 0;
   
   //Basic instructions
   cout <<endl;
   cout << "This program will run a hailstone sequence, or a Collatz conjecture for" <<endl;
   cout << "all those mathematics lovers out there.  You will enter a number and " <<endl;
   cout <<"the program will show how many sequences it takes to get to 1." <<endl;
   cout <<endl;

   //Obtains number from user (as a string to check value)
   cout << "Please enter a positive whole number: ";
   cin >> input;
   cout <<endl;
   
   if (is_num(input)){//First function within if - makes sure input is a number
      given_num = atoi(input.c_str()); //Changes input into a int!!!!
      if (given_num ==0){//Error message if number is zero, no call to hailstone function
         cout << "Sorry, please enter a positive, non-zero number." <<endl;
         cout << "Try again." <<endl;
      }
      else if (given_num == 1){//message if 1, no call to hailstone function
         iterations = 0;
         cout << "Given " << given_num << " the hailstone sequence would" <<endl;
         cout << "run " << iterations << " times until it reached 1." <<endl;
      }
      else if(given_num > 1){
         iterations = hailstone(given_num, counter);//only call to hailstone function
         cout << "Given " << given_num << " the hailstone sequence would" <<endl;
         cout << "run " << iterations << " times until it reached 1." <<endl;
      }
   }
   else{//if is_num false, prints error message
      cout << "Sorry, please enter a positive, non-zero number." <<endl;
      cout << "Try again." <<endl;
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

int hailstone (int num, int counter){
   //static int counter = 0;
   
   if (num == 1) //Base Case
      return counter;
   else if (num % 2 == 0){ //even
      num /= 2;
      counter++;
      return hailstone(num, counter);
   }
   else if (num % 2 !=0){
      num = (3 * num) + 1;
      counter++;
      hailstone(num, counter);
      }
}
