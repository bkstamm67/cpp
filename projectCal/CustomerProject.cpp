/*******
 * Name:  Brian Stamm
 * Date:  3.1.15
 * Description:  2 of 7.  This defines the member functions within base/parent class
 * *********/

#include<iostream>
#include "CustomerProject.hpp"

using namespace std;

//The default constructor, sends one to each variable
CustomerProject::CustomerProject(){
   setHours(1);
   setMaterials(1);
   setTransportation(1);
}

//Constructor
CustomerProject::CustomerProject(double hours, double material, double trans){
   setHours(hours);
   setMaterials(material);
   setTransportation(trans);
}

//Mutator Method (mm) for hours
void CustomerProject::setHours(double h){
   hours = h;
}

//MM for material
void CustomerProject::setMaterials(double m){
   materials = m;
}

//MM for Transportation
void CustomerProject::setTransportation(double trans){
   transportation = trans;
}

//Assessor Method (AM) for hours  - for all AM's:
//Don't really need because parents variables are protected
//Not used in my program as is
double CustomerProject::getHours(){
   return hours;
}

//AM for materials
double CustomerProject::getMaterials(){
   return materials;
}

//AM for transportation
double CustomerProject::getTransporation(){
   return transportation;
}
