/*****************
 * Name:  Brian Stamm
 * Date:  1.18.15
 * Description: This program asks the user for a series of numbers.  After getting the series,
 * the program will print back the low and high.
 * *****************/

#include<iostream>

int main(){
   
   double numHigh, numLow, numInput, iteration, count = 1;

   //First block, basic instructions & obtain how many inputs
   
   std::cout << "This program will ask you for a series of numbers," << std::endl;
   std::cout << "and then show the high and low from that series." << std::endl;
   std::cout << "First, how many numbers will you be entering: ";
   std::cin >> iteration;
   std::cout << "Thank you, and let us being...." << std::endl;

   //Start of if loop
   
   if (iteration >= 2){//First, to ensure at least 2 numbers inputted
      std::cout << "Enter a number: ";
      std::cin >> numHigh;
      numLow = numHigh;  //sets up 1st number to compare the various inputs against one another
     
      while (iteration > count){//While loop continues asking for numbers, count already 1 becuase 
         std::cout << "Enter a number: ";//Start of comparision btw 1st input and while input loop
         std::cin >> numInput;
         if (numInput > numHigh){//Compares to the first input, if higher, then sets to high
            numHigh = numInput;
         }  
         else if (numInput < numLow){//Compares to first input, if lower, then sets to low
            numLow = numInput;
         }
         count++;//Counter
      }  
   }
   else{//If user put in anythin least than 2 iterations
      std::cout << "Please try again.  Need at least 2 numbers." << std::endl;
   }

   std::cout << "Here is both the high and low from the numbers you inputted." << std::endl;
   std::cout << "Low: " << numLow << std::endl;
   std::cout << "High: " << numHigh << std::endl;

   return 0;
}
