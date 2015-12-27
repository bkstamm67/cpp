/**********************
 * Author:  Brian Stamm
 * Date:  1.11.15
 * Description:  This program will be generating a set of 5  random integers.
 * ********************/

#include<iostream>
#include<cstdlib> //So rand can be used
#include<ctime> //Used for the seed, to ensure a new set of random numbers each time used

int main(){

   int upper, lower, range;
   unsigned seed;

   seed = time(0); //Used to start generating the numbers, time produces new seed value each run
   srand(seed);

   std::cout << "What is the upper bound for the random set: "; //Creates ceiling for range
   std::cin >> upper;
   std::cout << "What is the lower bound for the random set: ";//Creates basement for range
   std::cin >> lower;

   range = upper - lower + 1; //Actual range 

   std::cout<<"Here is 5 random numbers between "<< lower << " and " << upper << std::endl;

   std::cout<< rand() % range + lower << std::endl;  //Creates a random number *5 within the range given
   std::cout<< rand() % range + lower << std::endl;
   std::cout<< rand() % range + lower << std::endl;
   std::cout<< rand() % range + lower << std::endl;
   std::cout<< rand() % range + lower << std::endl;

   return 0;
}
