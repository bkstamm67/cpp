/*******
 * Name:  Brian Stamm
 * Date:  2.1.15
 * Description:  This is the Sphere.cpp file.  2 of 3, this is the implementation file.
 * It will define the methods of the Sphere class.
 * *********/

#include<iostream>
#include "Sphere.hpp"
#include <cmath>  //Needed to use pow function

using namespace std;



Sphere::Sphere(){ //This is the default constructor, setting Radius to 0 and pi to pi
   setRadius(0);
   makingPi(3.1459);
}

Sphere::Sphere(double n){  //Constructor.  Will take users' input for radius
   setRadius(n);
   makingPi(3.1459);
}

void Sphere::makingPi(double p){ //Who doesn't love pie?  Personally, chocolate or marionberry.
   Pi = p;  //And again, I know I didn't have to make a method to do this
}

void Sphere::setRadius(double r){  //Sets radius
   radius = r;
}

double Sphere::getRadius(){  //Will return the value of the radius
   return radius;
}

double Sphere::getVolume(){ //Calculates the volume of the sphere
   return ((4 /3) * pow(radius, 3) * Pi);
}


