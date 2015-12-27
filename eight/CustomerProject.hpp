/*******
 * Name:  Brian Stamm
 * Date:  3.1.15
 * Description:  hpp file for parent class.  
 * *********/

#include<iostream>

#ifndef CUSTOMERPROJECT_HPP
#define CUSTOMERPROJECT_HPP

using namespace std;

class CustomerProject{

   //Variables all are protected, allowing children to have access
   protected:
      double hours;
      double materials;
      double transportation;

   public:
      CustomerProject();  //default constructor
      CustomerProject(double, double, double); //constructor
      
      //Pure virtual function, not defined within parent, but w/i child classes
      virtual double billAmount() = 0; 
      
      //Mutator fucntions
      void setHours(double);
      void setMaterials(double);
      void setTransportation(double);
      
      //Accessor Methods - not used within my program
      //since variables are protected & not private.
      double getHours();
      double getMaterials();
      double getTransporation();

};

#endif
