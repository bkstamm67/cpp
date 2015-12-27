/*********************
 * Author:  Brian Stamm
 * Date:  1.11.15
 * Description:  Exercise 3 - Asking user for number of tickets in various seats
 * and then calculating total cost
 * *******************/

#include<iostream>
#include<iomanip>

int main(){

   int ticketA, ticketB, ticketC; //Creates variable for each section
   double total;
   const int COST_A = 15;  //Created a constant for each section for easier changes later and decrease possible errors
   const int COST_B = 12;
   const int COST_C = 9;

   std::cout<< "This program will calculate the total cost for going to the game."<<std::endl; //basic instructions
   std::cout<<"Please enter the total number of seats in section A: ";//Obtaining total number of seats for each section
   std::cin>>ticketA;
   std::cout<<"Total number in section B: ";
   std::cin>>ticketB;
   std::cout<<"Total in section C: ";
   std::cin>>ticketC;

   total = ticketA*COST_A + ticketB*COST_B + ticketC*COST_C; //Calculate total cost

   std::cout<<"Thank you.  Your total today is:   $ "<< std::fixed <<std::setprecision(2) << total <<std::endl;//Displays total, with formatting

   return 0;
}
