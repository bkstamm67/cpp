/*******
 * Name:  Brian Stamm
 * Date:  1.25.14
 * Description:  This is Box.hpp, the header for the Box class.
 * *********/

#include<iostream>

using namespace std;

class Box
{
   private:  //Private members
      double Height;
      double Width;
      double Length;

   public:
      Box();  //Default constructor
      Box(double h, double w, double len); //Constructor
      void setHeight(double);  //Accessor to  member Height
      void setWidth(double);  //Sets the member Width
      void setLength(double);  //Sets the member Length
      double getVolume();  //Mutator method, gets volume
      double getSurfaceArea();  //Mutator method, calculates the sa
};

Box::Box(){  //Default values 1 
   setHeight(1);
   setWidth(1);
   setLength(1);
}

Box::Box(double h, double w, double len){  //Constructor, passes values to the accessor methods
   setHeight(h);
   setWidth(w);
   setLength(len);
}

void Box::setHeight(double h){
   if (h> 0){
      Height = h;
   }
   else{  //Else is in case of error, input less than zero
      Height = 0;
      cout << "There was an error with the height entered." << endl;
   }
}

void Box::setWidth(double w){
   if (w > 0){
      Width = w;
   }
   else{  //Same as above, error check
      Width = 0;
      cout << "There was an error with the width entered." << endl;
   }
}

void Box::setLength(double i){
   if ( i > 0){
      Length = i;
   }
   else{  //Same as above, error check
      Length = 0;
      cout << "There was an error with the length entered" << endl;
   }
}

double Box::getVolume(){  //Gets volume, no error because it will zero out b/c it's multiplication
   return Height * Width * Length;
}

double Box::getSurfaceArea(){
   if (Length != 0 && Width != 0 && Height != 0){  //Calculates sa if no value is zero
      return (2 * Length * Width) + (2 * Length * Height) + (2 * Width *Height);
   }
   else{  //Creates error message and zero out sa
      cout <<"Please try again." <<endl;
      return 0;
   }
}
