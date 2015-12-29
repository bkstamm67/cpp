/*******
 * Name:  Brian Stamm
 * Date:  3.1.15
 * Description:  hpp file for the Preferred Class.  5 of 7 with assignment
 * *********/

#include<iostream>
#include "CustomerProject.hpp"
#ifndef PREFERREDPROJECT_HPP
#define PREFERREDPROJECT_HPP

using namespace std;

class PreferredProject : public CustomerProject{ //Child class, with parent class of CustomerProject
   
   public:
      PreferredProject(); //default Constructor
      PreferredProject(double, double, double); //Constructor 
      double billAmount(); // Member function
		            
};

#endif

