/*******
 * Name:  Brian Stamm
 * Date:  3.1.15
 * Description:  This is the fraction program, using header Fraction.  Part 2 of 2
 * *********/

#include<iostream>
#include "Fraction.hpp"

using namespace std;

//Prototypes of basic instruction and error message
void instruction(); 
void errorMessage();

int main(){

   int a, b, c, d, choice;
   
   instruction(); //has instructions
   
   //Block gets numerators and denominators from user
   cout <<"Enter numerator for first fraction: ";
   cin >>a;
   cout <<"Enter denominator for the first fraction: ";
   cin >>b;
   cout <<"Enter numerator for the second fraction: ";
   cin >>c;
   cout <<"Enter denominator for the second fraction: ";
   cin >>d;

   //Exception block, starts with creating fractions
   try{ 
      //First area where exception can be thrown
      Fraction first(a, b);
      Fraction second(c, d);
      cout<<"Would you like to (1) multiple or (2) divide these fractions? ";
      cin >> choice;
      if(choice==1){
  	 Fraction mult = (first * second); //Other area where exception can be thrown
	 cout <<"The product of your fractions is: " <<mult <<endl;
      }
      else if(choice ==2){
	 Fraction div = (first / second);//Other area where exception can be thrown
	 cout <<"The result of dividing the fractions: " <<div <<endl;
      }
      else
	 cout <<"I'm sorry.  I did not understand that." <<endl; //In case choice different
      
      cout <<"Thanks for using the Fraction Program!" <<endl;
   }
     
   catch(Fraction::divByZero){ //Catch - if error, will throw divByZero(empty class)
      errorMessage(); //and then print error message
   }

   return 0;
}

/* Function: Basic instructions for user
 * Parameter: none
 * **/

void instruction(){
   cout <<endl;
   cout <<"This program will multiple or divide two fractions together." <<endl;
   cout <<"It will ask you for two fractions, a numerator and denominator" <<endl;
   cout << "for each, and then ask you which mathematical operation you" <<endl;
   cout <<"would like to perform." <<endl; 
   cout <<endl;
}

/**Function: Error message - basic error message
 * Parameter:  none.
 * **/

void errorMessage(){
   cout <<"There was an error with the fractions." <<endl;
   cout <<"At some point, there was zero in a denominator." <<endl;
   cout <<endl;
}
