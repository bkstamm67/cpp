/*******
 * Name:  Brian Stamm
 * Date:  2.22.15
 * Description:  This is the hpp file for Zombie.  1 of 2 for assignment.
 * *********/

#include<iostream>

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

using namespace std;

class Zombie{
   
   private:
      static int total;
   
   public:
      Zombie();
      ~Zombie();
      void speak(); 
      void setTotal(); 
      void minusTotal();
      int getTotal();
};

#endif

int Zombie::total = 0; //initializes the static variable, which keeps track of total Zombies

Zombie::Zombie(){ //Constructor, adds to static variable
   setTotal();
}

Zombie::~Zombie(){ //Destructor, subtracts from the static variable
   minusTotal();
}

void Zombie::speak(){  //Repeats what zombies say.
   cout <<"Braaaainss!" <<endl;
}

void Zombie::setTotal(){ //Adds to static
   total+=1;
}

void Zombie::minusTotal(){ //Subtracts from static
   total-=1;
}

int Zombie::getTotal(){ //Reports static
   return total;
}
