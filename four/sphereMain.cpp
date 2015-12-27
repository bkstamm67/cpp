/*******
 * Name:  Brian Stamm
 * Date:  2.1.15
 * Description:  This is sphereMain.cpp.  3 of 3.  This is the final program
 * or the main program.  It will use the Sphere object to complete calculations
 * *********/

#include<iostream>
#include "Sphere.hpp"

using namespace std;

void printSphereInfo(Sphere *psphere);  //prototype function using pointer, described below

int main(){

   Sphere *psphere;  //creates a pointer to a sphere object
   double rad;  

   //Basic instructions
   cout <<"This program will ask you for a sphere's" <<endl;
   cout <<"radius, and then it will return its basic" <<endl;
   cout <<"information.  Enjoy." <<endl;
   cout <<endl;

   cout << "What is the radius: "; //Gets user input
   cin >> rad;
   cout << endl;
   
   Sphere circle(rad);  //Creates a sphere called circle & passes rad to it
   
   psphere = &circle;  //Using pointer to point to circle's address


   printSphereInfo(psphere);  //Using pointer to get sphere information


   return 0;
}

/*
 * This fucntion uses the pointer to get access to member functions within the 
 * Sphere class.  Using the actual -> to make it easier than (*p)
 * parameters:  sphere *p, which is pointing to the address of circle.
 * */

void printSphereInfo(Sphere *p){
   cout << "Here is the sphere information: " <<endl;
   cout << p->getRadius() << endl;
   cout << p->getVolume() <<endl;
}
