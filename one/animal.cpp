/*****************
 * Author:  Brian Stamm
 * Date: 1.11.15
 * Description: Completing Exercise One, wrote the program same as
 * what was listed in Canvas, so there will be limited comments
 * within the program.
 * **************/

#include <iostream>
#include <string>

// a simple example program
int main()
{
   std::string faveAnimal;
   std::cout << "Please enter your favorite animal" << std::endl;
   std::cin >> faveAnimal;
   std::cout << "Your favoriet animal is the " << faveAnimal;
   std::cout << "." << std::endl;

   return 0;
}
