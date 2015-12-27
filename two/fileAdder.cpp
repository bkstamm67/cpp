/*******
 * Name:  Brian Stamm
 * Date:  1.18.15
 * Description:  This program will read a file called nums.txt, which will consist of numbers.
 * It will add up all the numbers, and then it will print the sum of those numbers to a
 * file called sum.txt.
 * **********/

#include<iostream>
#include<fstream>  //Needed to work with files

int main(){
   
   std::ifstream input;
   std::ofstream output;
   double textNum, totalNum = 0;
   int count = 0;

   std::cout <<"This program will be totaling all the numbers in the file 'nums.txt', and" << std::endl;
   std::cout <<"then writing that total to the 'sum.txt'." << std::endl;
   input.open("nums.txt"); // Opens the numbers file, needed prior to running program
   output.open("sum.txt");  // Opens the sum file, needed prior to running program

   if (input && output){//If else to check that files were opened correctly
      while(input >> textNum){// While loop looks at numbers in nums.txt, adds up
         totalNum += textNum;//Adding total of values
         count++;//Counter, for user for another check
      }
      output << "The sum of the values is " << totalNum << std::endl;//Writing to the sum.txt
      input.close();
      output.close();

      std::cout << "How many numbers in the file: " << count << std::endl;  //Another error check for user
      std::cout << "Sum of the numbers: " << totalNum << std::endl;  //Show's total to user, another error check
   }
   
   else{//In case of error, message appears
      std::cout<< "There was an error processing your files." << std::endl;
      std::cout <<"Please try again." << std::endl;
   }

   return 0;
}
