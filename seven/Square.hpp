/*******
 * Name:  Brian Stamm
 * Date:  2.22.15
 * Description:  This is the hpp file to the Square class.  More detail in cpp file.  3 of 4 for assignment
 * *********/

#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "Rectangle.hpp" 

class Square : public Rectangle {  //Inherits from class Rectangle
   
   protected:
      double side;
   
   public:
      Square(double side) : Rectangle(side, side)  //Constructor, using rectangle.
      {
      };
      
      double area(){  //Calls method from Rectangle to return the area
         return Rectangle::area();
      };

      double perimeter(){ //Calls method from Rectangle to return the perimeter
         return Rectangle::perimeter();
      };

      void setSide(double s){  //Sets the side of Square.  Not used, but could be depending on
         side = s;             //the development of the class
      };
      
};
#endif
