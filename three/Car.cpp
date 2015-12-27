/*******
 * Name:  Brian Stamm
 * Date:  1.25.15
 * Description:  This is the Car.cpp and needs the Car.hpp included to work.
 * *********/

#include<iostream>
#include <string>
#include "Car.hpp"

using namespace std;

void instructions();  //basic instruction function

string m;
int year, speed, choice;

int main(){
   
   instructions();
   
   cout <<"Year of car: ";  //This block gets the input from the user
   cin >> year;
   cout <<"Make of car: ";
   cin >> m;
   cout <<"Max speed: ";
   cin >> speed;
   cout <<endl;

   Car lucy (year, m, speed);  //Creates lucy object 

   do{  //Beginning of menu for program, lets user decide btw 3 options
      cout <<"Menu: "<< endl;
      cout <<"1. Accelerate" <<endl;
      cout <<"2. Brake" <<endl;
      cout <<"3. Quit" <<endl;
      cout <<endl;
      cout <<"Selection: ";
      cin >> choice;
      
      while ((choice < 1 || choice > 3))  //in case user input invalid 
      {
         cout <<"Please enter an integer between 1 and 3.";
	 cin >> choice;
      }
      
      if (choice != 3){
         switch(choice)
	 {  //First case will call accelerate method in Car call, increasing speed
	    case 1: cout <<endl;
		    cout << m <<"'s new speed: "<< lucy.accelerate() << endl;
		    cout <<endl;
		    break;
		    //Second case will call brake, decreasing the speed
	    case 2: cout<< endl;
		    cout << m <<"'s new speed: "<< lucy.brake() << endl;
		    cout <<endl;
		    break; 
	 }
      }
   } while (choice !=3);//Ends program
   
   cout <<"Thanks for playing!" <<endl; //Little farewell

   return 0;
}

/****
 * Description:  This is basic instructions, tells user what the program is.
 * parameters:  nope.
 * ***/

void instructions(){
   cout <<endl;
   cout << "This program will make a car for you!" << endl;
   cout << "You will be providing the year it was" <<endl;
   cout << "made, what its make it, and its top speed." <<endl;
   cout << "The fastest any car can go is 80 mph in" <<endl;
   cout << "program.  Then you'll get a chance to take" <<endl;
   cout << "it for a spin.  Enjoy!" <<endl;
   cout <<endl;
}
