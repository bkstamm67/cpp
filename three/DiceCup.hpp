/*******
 * Name:  Brian Stamm
 * Date:  1.25.14
 * Description:  This is the header file for DiceCup, which creates the class DiceCup.
 * *********/

#include <iostream>
#include <cstdlib>//For the random gen
#include <ctime> //For seeding the random gen

using namespace std;

class DiceCup
{
   private:
      int NumDice;  //For the number of dice
      int NumFaces;  //For how many faces on the die
      
   public:
      DiceCup();  //Default constructor
      DiceCup(int f, int d);
      void setNumFaces(int);  //mutator method for NumFaces
      void setNumDice(int);  //mutator method for NumDice
      int rollDice();  //method simulating the dice roll
};

DiceCup::DiceCup(){  //Default constructor
   setNumFaces(2);
   setNumDice(1);
}

DiceCup::DiceCup(int f, int d){ //Constructor
   setNumFaces(f);
   setNumDice(d);
   srand(time(0));  //Sets the random number gen
}

void DiceCup::setNumFaces(int f){  //Sets the number of faces
   if (f >0 )
      NumFaces = f;
   else{
      NumFaces = 0;
      cout << "There was an error with the number of Faces on the die." << endl;  //Error message
   }}

void DiceCup::setNumDice(int d){  //Sets the number of dices
   if (d > 0)
      NumDice = d;
   else{
      NumDice = 0;
      cout << "There was an error with the number of Dice entered." << endl;  //Error message
   }
}

int DiceCup::rollDice(){  //Does the rolling of the dice
   int dice = NumDice;
   int face = NumFaces;
   int total = 0; 
   for (int n = 0; n < dice; n++){
      total += 1 + (rand() % face);
      return total;
   }
}

