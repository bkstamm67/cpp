/*******
 * Name:  Brian Stamm
 * Date:  3.1.15
 * Description:  This defines the member functions of RegularProject.hpp.  4 of 7 for assignment.
 * *********/

#include<iostream>
#include "CustomerProject.hpp"
#include "RegularProject.hpp"

using namespace std;

RegularProject::RegularProject():CustomerProject(){ //Calls default constructor from Parent
}

RegularProject::RegularProject(double hour, double material, double trans):CustomerProject(hour, material, trans){ //Sends values to Parent constructor
}

//defines pvf from parent, takes protected members and does some math on them
double RegularProject::billAmount(){
   return (hours * 80) + (materials) + (transportation);
}
