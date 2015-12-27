/*******
 * Name:  Brian Stamm
 * Date:  3.1.15
 * Description:  This is the 3 of 7, this is hpp file for RegularProject
 * *********/

#include<iostream>
#include "CustomerProject.hpp"
#ifndef REGULARPROJECT_HPP
#define REGULARPROJECT_HPP

using namespace std;

class RegularProject : public CustomerProject{ //child class, taking from parent class

    public:
       RegularProject();  //default constructor
       RegularProject(double, double, double); //constructor
       double billAmount(); //defines pvf w/i child class
		            
};

#endif

