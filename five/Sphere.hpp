/*******
 * Name:  Brian Stamm
 * Date:  2.8.15
 * Description:  This is the Sphere.hpp file.  1 of 3.  This is the
 * specification file which defines the class of Sphere.  There is not
 * much to explain here, but it defines the variables / members of sphere
 *
 * This is the same file used in the previous week.  No changes
 * *********/

#include<iostream>

#ifndef SPHERE_HPP
#define SPHERE_HPP

class Sphere{
   private:
      double radius;
      double Pi;  //Pi could have been just added in the method calling it
//But I thought it might be usesful as a private variable.
      
   public:
	 Sphere();  //  Default constructor
	 Sphere(double n);  //Constructor takes a parameter of a number
	 void makingPi(double p);  //I just liked the name
	 void setRadius(double r);  //Sets the radius variable
	 double getRadius();
	 double getVolume();
};

#endif
