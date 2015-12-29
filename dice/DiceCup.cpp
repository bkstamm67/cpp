/*******
 * Name:  Brian Stamm
 * Date:  1.25.15
 * Description:  This program is a type of dice game.  It asks the user for how many dice
 * and how many sides the dice have.  It will then randomly roll those dice, giving the 
 * user the total for each roll.
 * *********/

#include<iostream>
#include "DiceCup.hpp"

using namespace std;

void introduction();  //  Basic instructions

int faces, dice, rolls; //arguments 

int main(){

   introduction();
   
   cout << "How many faces on the die: ";
   cin >> faces;
   cout << "How many dices to be rolled: ";
   cin >> dice;
   cout << "And how many rolls: ";
   cin >> rolls;
   DiceCup rolling(faces, dice);  //Creates the object rolling, using arg faces and dice
      
   for (int i=1; i <= rolls; i++){
      int total = 0;
      total +=  rolling.rollDice();
      cout << "Total for roll " << i <<": " << total << endl; 
      }
   
   return 0;
}

void introduction(){
   cout <<"This program will be asking you for the" <<endl;
   cout <<"number of faces a die has, and then how"<<endl;
   cout <<"how many of those dice are going to be" <<endl;
   cout <<"rolled.  Enjoy!"<<endl;   

}
