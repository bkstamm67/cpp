/*******
 * Name:  Brian Stamm
 * Date:  2.22.15
 * Description:  This is the cpp file for Square.  4 of 4 for assignment.
 * *********/

#include<iostream>
#include "Rectangle.hpp"
#include "Square.hpp"

using namespace std;

//Function prototypes, more information below.

void instructions();
void menu();
void square();
void rectangle();

int main(){
   int choice;
   
   instructions(); //Basic instructions

   //Created a loop for user so they can create as many squares / rectangles as 
   //they would like
   do{
      menu();  //Basic menu
      cin >>choice;  //input for loop.  
      switch (choice){
         case 1:  square();  //Takes to square function, creates a square
		  break;
	 case 2:  rectangle();  //Takes to rectangle
		  break;
      }
   }while (choice != 3); //choice three exits

   cout <<"Thanks for using square/rectangle maker!" <<endl;
   
   return 0;
}

/**
 * Instruction function: basic instructions for user
 * Parameters:  None
 * ***/

void instructions(){
   cout <<endl;
   cout <<"This program takes measurements for either a square."  <<endl;
   cout <<"or a rectangle.  Then it will return the area and perimeter" <<endl;
   cout <<"of the object.  When you are done, select 'Exit'." <<endl;
   cout <<endl;
}

/**
 * Menu function:  basic menu.  Also prints "Choice: " out.
 * Parameters:  none.
 * ***/

void menu(){
   cout <<"Menu: " <<endl;
   cout <<endl;
   cout<<"1.  Enter a square."<<endl;
   cout <<"2.  Enter a rectangle."<<endl;
   cout <<"3.  Quit." <<endl;
   cout <<endl;
   cout <<"What is your choice: ";
}

/***
 * Square function.  Creates a square object and returns the area.  In function asks for 
 * measurements and then creates object, calling on the specific methods.
 * Parameters:  None.
 ****/

void square(){
   double length;
   cout <<"What is the length of the sides: ";
   cin >>length;
   Square s(length);
   cout <<"Square area: " <<s.area() <<endl;
   cout <<"Square perimeter: " <<s.perimeter() <<endl;
   cout <<endl;
}

/***
 * Rectangle function.  Same as above, but for rectangle
 * Parameter:  None.
 * **/

void rectangle(){
  double length, width;
  
  cout <<"What is the length: ";
  cin >>length;
  cout <<"What is the width: ";
  cin >>width;
  Rectangle r(length, width);
  cout <<"The rectangle's area is: " <<r.area() <<endl;
  cout <<"The rectangle's perimeter is: " <<r.perimeter() <<endl;
  cout <<endl;
}
