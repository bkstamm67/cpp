/*************************
 * Author:  Brian Stamm
 * Date:  1.11.15
 * Description:  This is a program that should covert C to F
 * ***********************/

#include<iostream>

int main(){

   float fahr, cels;//2 temperature variables
   

   std::cout<<"This program converts Celsius into Fahrenheit."<<std::endl;//Basic instructions
   std::cout<<"What is the degrees in Celsius? ";
   std::cin>>cels;

   fahr = cels * 9 / 5 + 32;//Equation to convert C into F

   std::cout<<"The temperature in Fahrenheit is: "<<fahr<<std::endl;

   return 0;

}
