/*******
 * Name:  Brian Stamm
 * Date:  3.1.15
 * Description:  This is the hpp file for Fraction, which also has the definations at the end of the 
 * file.  This is  1 of 2 for exercise.
 * *********/

#include<iostream>

#ifndef FRACTION_HPP
#define FRACTION_HPP

using namespace std;

class Fraction{
   
   private:
      int numerator;
      int denominator;

   public:
      class divByZero //empty class, used for exception
      {};
      
      Fraction(); //Default constructor
      Fraction(int a, int b); //Constructor

      //Mutator methods
      void setNumerator(int a);
      void setDenominator(int b);

      //Assessor methods
      int getNumer();
      int getDenom();
      int getNumer() const;  
      int getDenom() const;

      //Friend of class, used for overloading ostream
      friend ostream &operator<<(ostream &outs, const Fraction& frac);

      //Overloading *
      const Fraction operator*(const Fraction &RHS){
	 return Fraction((this->getNumer() * RHS.getNumer()), (this->getDenom()*RHS.getDenom()));  
      }

      //Overloading /
      const Fraction operator/(const Fraction &RHS){
         return Fraction((this->getNumer()*RHS.getDenom()),(this->getDenom()* RHS.getNumer())); 
      }
};

#endif

Fraction::Fraction(){ //Default
   setNumerator(1);
   setDenominator(1);
}

Fraction::Fraction(int a, int b){ //Constructor
   setNumerator(a);
   setDenominator(b);
}

//Defining friend, prints out fraction in "a/b" form
ostream &operator<<(ostream& outs, Fraction &frac){
   outs << frac.getNumer() << "/" <<frac.getDenom();
   return outs;
}

//Sets nummerator
void Fraction::setNumerator(int a){
   numerator = a;
}

//Sets denominator.  Has exception, throwing empty class
void Fraction::setDenominator(int b){
   if (b ==0){
      throw divByZero();
   }
   else
      denominator = b;
}

//Assessor methods, defined
int Fraction::getNumer(){
   return numerator;
}

int Fraction::getDenom(){
   return denominator;
}

int Fraction::getNumer() const{
   return numerator;
}

int Fraction::getDenom() const{
   return denominator;
}
