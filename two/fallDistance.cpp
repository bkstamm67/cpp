/****
 * Name:  Brian Stamm
 * Date:  1.18.15
 * Description:  This program will use the formula d=.5gt^2 to determine the distance an
 * object has fallen.  The user will input the time the object has fallen and then the 
 * distance will be displayed. 
 * *******/

#include <iostream>
#include <iomanip>

//Function prototype
double getDist(double g, double t);

int main(){

   const double GRAVITY = 9.8;//Constant, since gravity is one.  Thought it'd be mean to demote it
   double seconds, distance;

   //Basic instructions, get input for seconds
   std::cout<< "This program will display the distance" <<std::endl;
   std::cout<< "an object has fallen in a given time." <<std::endl;
   std::cout<< "You will provide the time (in sec)." << std::endl;
   std::cout<< "How long has the object been falling: ";
   std::cin >> seconds;
   
   //std::cout << std::fixed << std::showpoint << std::setprecision(1);//Sets the decimal to tenths place

   distance = getDist(GRAVITY, seconds); //Function call

   std::cout << std::fixed << std::showpoint << std::setprecision(1);//Sets the decimal place
   std::cout << "The distance the object fell: " << distance <<" meters." <<std::endl;
   
   return 0;
}
/*******
 * getDist function does basic calculation of distance traveled when falling.
 * It does the calculation and then returns the result
 * parameters: g, which is gravity constant, and t, which is time (inputted by user)
 *
 * *************/

double getDist(double g, double t){
   return .5 * g * (t*t);
}
