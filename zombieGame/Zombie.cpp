/*******
 * Name:  Brian Stamm
 * Date:  2.22.15
 * Description:  This is the zombie cpp file.  This is 2 of 2.
 * *********/

#include<iostream>
#include "Zombie.hpp"
#include <vector>

using namespace std;

//Basic prototypes for functions, more below

void menu();
void instructions();

int main(){
   
   int choice, size;
   vector<Zombie*> horde; //Creates a vector of Zombie objects, named horde.

   instructions();

   do{ //Do while loop for user to create, destroy, etc
      menu();
      cin >>choice;
      switch(choice){
         case 1:  cout <<endl;
	          cout <<"AAAAHHHH!!  HERE COMES ANOTHER ONE!!!!!!" <<endl;
		  horde.push_back(new Zombie); //creates new zombie and puts in vector
		  break;
	 case 2:  if(horde.empty()){ //Checks to make sure there's something in vector
		    cout <<endl;
		    cout <<"No zombies to kill :( " <<endl;
		  }
		  else{
		     size = horde.size(); //If there is, deletes one object
		     delete horde[size-1];
		     horde.pop_back(); //and shrinks size of vector by one
		     cout <<endl;
		     cout <<"BANG!  BANG!" <<endl;
		     cout <<"Got one." <<endl;
		  }
		  break;
	 case 3:  cout <<endl;
		  size = horde.size(); //Gets size of vector, and uses method's static value to print total
		  cout <<"I can see " <<horde[size-1]->getTotal()<< " zombies out there!" <<endl;  
		  break;
	 case 4:  cout <<endl;
		  cout <<"Shhhhh.....  If you're quiet, you can hear all of them....." <<endl;
		  size = horde.size(); //For loop to go through each zombie and call speak method.
		  for (int i = 0; i<size; i++){
		     horde[i] ->speak();
		  }
		  break;
      }
   }while (choice !=5);
   
   cout <<endl;
   cout <<"Thank goodness that's over." <<endl;

   return 0;
}

/***
 * Function:  Instructions.  Basic instructions for user
 * Parameters:  None.
 * **/

void instructions(){
   cout <<endl;
   cout <<"This is a Zombie game, where you get some choices," <<endl;
   cout <<"which is better than if it was really happening." <<endl;
   cout <<"When you're done, pick 'Exit', but have fun with it." <<endl;
   cout <<endl;
}

/**
 * Function: Menu.  Basic menu for user
 * Parameters:  none
 * ***/

void menu(){
   cout <<endl;
   cout <<"Menu: " <<endl;
   cout <<endl;
   cout <<"1.  Create a Zombie!" <<endl;
   cout <<"2.  Destroy a Zombie!" <<endl;
   cout <<"3.  See total number of Zombies!" <<endl;
   cout <<"4.  Can you hear that!" <<endl;
   cout <<"5.  Quit." <<endl;
   cout <<endl;
   cout <<"Choice: ";
}
