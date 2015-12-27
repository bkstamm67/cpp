/*******
 * Name:  Brian Stamm
 * Date:  2.22.15
 * Description:  This is the hpp file for the class Rectangle.  More explanation in cpp file.
 * 1 of 4 for assignment
 * *********/

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

class Rectangle{
   
   protected:
      double length;
      double width;
   
   public:
      Rectangle();
      Rectangle(double, double);
      void setLength(double);
      void setWidth(double);
      double area();
      double perimeter();

};

#endif
