/*******
 * Name:  Brian Stamm
 * Date:  1.25.14
 * Description:  This creates the Hero class, needed to run the Hero.cpp game.  
 * *********/

#include<iostream>
#ifndef HERO_HPP
#define HERO_HPP

using namespace std;

class Hero{

   private:  //All members are attributes of the "hero" 
      int HitPoints;
      int Strength;
      int Speed;
      int Money;
   
   public:
      Hero();  //Default constructor
      Hero(int h, int str, int w, int m);  //Constructor
      //Mutators of the attributes
      void setHitPoints(int);
      void setStrength(int);
      void setSpeed(int);
      void setMoney(int);
      //Accessor to the attributes
      int getHitPoints();
      int getStrength();
      int getSpeed();
      int getMoney();
      //Assesses if the hero is still "alive", true if s/he is
      bool takeDamage(int hp);
};

#endif

Hero::Hero(){ //Default c
   setHitPoints(1);
   setStrength(1);
   setSpeed(1);
   setMoney(1);
}

Hero::Hero(int h, int str, int w, int m){ //Constructor
   setHitPoints(h);
   setStrength(str);
   setSpeed(w);
   setMoney(m);
}
   

bool Hero::takeDamage(int h){ //basic if else statement to see if HitPoints equal to/less than zero
   if (getHitPoints() > 0)
      return true;
   else
      return false;
}

void Hero::setHitPoints(int h){
    HitPoints += h;
}

void Hero::setStrength(int str){
   Strength += str;
}

void Hero::setSpeed(int speed){
   Speed = 0; //When testing, speed would always display some large number not inputted.  So, set to zero first
   Speed += speed;
}

void Hero::setMoney(int m){
   Money += m;
}

int Hero::getHitPoints(){
   return HitPoints;
}

int Hero::getStrength(){
   return Strength;
}

int Hero::getSpeed(){
   return Speed;
}

int Hero::getMoney(){
   return Money;
}
