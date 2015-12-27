/*******
 * Name:  Brian Stamm
 * Date:  1.25.15
 * Description:  This is the Date.cpp program.  It is a basic calendar.
 * It gets user input for month day and year, and then displays those in
 * the format the user picks.
 * *********/

#include<iostream>
#include "Date.hpp"

using namespace std;

void instructions();  //Basic instructions

int main(){

   int choice, month, day, year; 

   instructions();

   do{  //Do Loop starts after instructions
      //Gets user's input for variables
      
      cout <<"What is the month: ";
      cin >> month;
      cout << "What is the day: ";
      cin >> day;
      cout << "What is the year: ";
      cin >> year;
      
      Date calendar(month, day, year);  //Creates object calendar from class Date.
      cout<< endl;

      //Display of menu, showing different formats for user to pick
      cout << "Which format:" << endl;
      cout << "1.  Numeric MM/DD/YR (i.e. 1/25/2015)" << endl;
      cout << "2.  Written MDY (i.e. January 25, 2015)" <<endl;
      cout << "3.  Written DMY (i.e. 25 January 2015)" <<endl;
      cout << "4.  Quit." <<endl;
      cout << "Selection: ";
      cin >> choice;
   
      while ((choice < 1 || choice > 4))// In case user inputs incorrect number for menu
      {
         cout << "Please enter an integer between 1 and 4.";
         cin >> choice;
      }
      if (choice != 4){  //If statement for menu, as long as not "quit" option
         switch (choice)  //Choice dictates the case in switch
	 {
	    case 1: cout << endl;
		    calendar.print1();//Choice 1 takes to same format in calendar
		    cout <<endl;
		    break;
	    case 2: cout << endl;
		    calendar.print2();//Same as choice 1, different format
		    cout <<endl;
		    break;
	    case 3: cout << endl;
		    calendar.print3();//Same
		    cout <<endl;
		    break;
	 }     
      }
   } while (choice != 4);//End of program if selection is 4

   return 0;
}

void instructions(){
   cout <<"This program will ask you for integers of the" <<endl;
   cout <<"month, day, and year.  It will then express those" <<endl;
   cout <<"in the format you choose.  Enjoy." << endl;
   cout <<endl;
}
