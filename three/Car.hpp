/*******
 * Name:  Brian Stamm
 * Date:  1.25.15
 * Description:  This is the Car class.  It sets the class called car and is needed to run Car.cpp.
 * *********/

#include<iostream>
#include <string>
#ifndef CAR_HPP
#define CAR_HPP

using namespace std;

class Car
{
  private:
     int Year;
     string Make;
     int Speed;

  public:
     Car();  //Default Constructor
     Car(int y, string m, int sp); //Constructor
     //Mutator  methods, setting the members
     void setYear(int y);
     void setMake(string m);
     void setSpeed(int s);
     //Also mutator methods in a different way, set up to play the "game"
     int accelerate();  //increase Speed
     int brake();  //Decreases speed
};
#endif

Car::Car(){
   setYear(0);
   setMake("");
   setSpeed(0);
}

Car::Car(int y, string m, int sp){
   setYear(y);
   setMake(m);
   setSpeed(sp);
}

void Car::setYear(int y){
   if (y <=0){
      Year = 0;
   }
   else{
      Year = y;
   }
}

void Car::setMake(string m){
   Make = m;
}

void Car::setSpeed(int s){
   if (s <=0){
      Speed = 0;
   }
   else if (s >= 80){
      Speed = 80;
   }
   else{
      Speed = s;
   } 
}

int Car::accelerate(){
   Speed += 10;
   setSpeed(Speed);
   return Speed;
}

int Car::brake(){
   Speed -= 10;
   setSpeed(Speed);
   return Speed;
}
