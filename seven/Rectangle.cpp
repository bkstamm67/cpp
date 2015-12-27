/*******
 * Name:  Brian Stamm
 * Date:  2.22.15
 * Description:  This is cpp file for Rectangle, which defines the public member 
 * functions.  2 of 4 for assignment
 * *********/

#include <iostream>
#include "Rectangle.hpp"

using namespace std;

Rectangle::Rectangle(){  //Default constructor
   setLength(0);
   setWidth(0);
}

Rectangle::Rectangle(double len, double wid){  //Constructor
   setLength(len);
   setWidth(wid);
}

void Rectangle::setLength(double len){  //Sets variable length
   length = len; 
}

void Rectangle::setWidth(double wid){  //Sets variable width
   width = wid;
}

double Rectangle::area(){  //Returns the value of the area for object
   return width*length;
}

double Rectangle::perimeter(){  //Returns the value of the perimeter for object
   return (width*2) + (length*2);
}

