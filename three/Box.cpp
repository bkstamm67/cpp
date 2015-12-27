/*******
 * Name:  Brian Stamm
 * Date:
 * Description:  This program calculates the volume and surface area of a box.  It creates an
 * object from the class Box, so Box.hpp is needed to run properly.  Enjoy
 * *********/

#include<iostream>
#include "Box.hpp"

void instruction();  //Basic instructions
double height, length, width;

int main(){
   instruction();
   cout << "Set Height: ";
   cin >> height;
   cout <<"Set Length: ";
   cin >> length;
   cout <<"Set Width: ";
   cin >> width;
   Box hueyLewis (height, length, width);  //Creates and object, hueyLewis, because if
   //there's anyone who can make squares and boxes hip, it's hueyLewis


   //Next both getVolume and getSurfaceArea is called to get their values
   cout << "Here is the volume: " <<hueyLewis.getVolume() << endl;  
   cout <<"Here the surface area: " <<hueyLewis.getSurfaceArea() << endl;

   return 0;
}

void instruction(){  //Basic instructions
   cout << "This program will ask for the dimensions of a" << endl;
   cout << "box, and then it will calculate the surface" <<endl;
   cout << "area and volume of that box.  Be sure not to enter" <<endl;
   cout << "any negative values.  Enjoy." << endl;
}
