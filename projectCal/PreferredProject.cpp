/*******
 * Name:  Brian Stamm
 * Date:  3.1.15
 * Description:  6 of 7.  PP.cpp.  This defines the member functions within PP.hpp
 * *********/

#include<iostream>
#include "CustomerProject.hpp"
#include "PreferredProject.hpp"

using namespace std;

//Constructor, basically calls the constructor from the Parent
PreferredProject::PreferredProject():CustomerProject(){
}
 
//Constructor, takes parameters from Preferred and passes them to Parent 
PreferredProject::PreferredProject(double hours, double material, double trans):CustomerProject(hours, material, trans){
}

//Defines billAmount from the pure virtual function in Parent
double PreferredProject::billAmount(){
   double h = CustomerProject::getHours(); //gets hours from Parent
   //and then has if else statement capping the total hours for preferred
   if (h>100){
      return (100 * 80) + (0.85 * materials) + (.9 * transportation);
   }
   else{
      return (h * 80) + (0.85 * materials) + (.9 * transportation);
   }      
}
