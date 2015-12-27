/*******
 * Name:  Brian Stamm
 * Date:  1.25.15
 * Description:  This file creates the class Date.  This is used with the program Date.cpp.
 * *********/

#include<iostream>
#ifndef DATE_HPP
#define DATE_HPP

using namespace std;

class Date
{
   private:
      int Month;
      int Day;
      int Year;
   
   public:
      Date();  //Default constructor
      Date(int, int, int);  //Constructor
      
      //Mutator methods to follow
      void setMonth(int);
      void setDay(int);
      void setYear(int);
      
      //Accessor methods, printing the various versions of the calendar
      void print1();
      void print2();
      void print3();
};
#endif

Date::Date(){ //Default
   setMonth(1);
   setDay(1);
   setYear(2001);
   }

Date::Date(int m, int d, int y){ //Constructor
  setMonth(m);
  setDay(d);
  setYear(y);
}

void Date::setMonth(int m){ //Sets the month, also if value not valid, then assigns 0, which will
   if (m >=1 && m <= 12){  // cause an error message
      Month = m;
   }
   else{
      Month = 0;
   }
}

void Date::setDay(int d){ //Sets day, also if not valid, depending on the month, it'll assign 0
   if (Month == 2){
      if (d >=1 && d <= 28)
	 Day = d;
      else
	 Day = 0;
   }
   else if (Month == 4 || Month == 6 || Month == 9 || Month == 11){
      if (d >=1 && d <=30)
	 Day = d;
      else
	 Day = 0;
   }
   else{
      if (d >= 1 && d <= 31)
	 Day = d;
      else
	 Day = 0;
      }
}

void Date::setYear(int y){ // Assigns month, no negative values or assigns 0
   if (y>0){
      Year = y;
   }
   else{
      Year = 0;
   }
}

void Date::print1(){ // General format for number date.  Error message if any value 0
   if (Month == 0 || Day == 0 || Year == 0){
      cout <<"There was an error.  Please try again." <<endl;
      return;
   }
   else{
      cout << Month << "/" << Day << "/" << Year <<endl;
      cout <<endl;
      return;
   }
}

void Date::print2(){  //Prints month then numbered date.  Error message if any value 0
   if (Month == 0 || Day == 0 || Year == 0){
      cout <<"There was an error.  Please try again." <<endl;
      return;
   }
   else if (Month == 1){
      cout << "January " << Day<< ", " << Year << endl;
      return;
   }
   else if (Month == 2){
      cout << "Febuary " << Day<< ", " << Year << endl;
      return;
   }
   else if (Month == 3){
      cout << "March " << Day<< ", " << Year << endl;
      return;
   }
   else if (Month == 4){
      cout << "April " << Day<< ", " << Year << endl;
      return;
   }
   else if (Month == 5){
      cout << "May " << Day<< ", " << Year << endl;
      return;
   }
   else if (Month == 6){
      cout << "June " << Day<< ", " << Year << endl;
      return;
   }
   else if (Month == 7){
      cout << "July " << Day<< ", " << Year << endl;
      return;
   }
   else if (Month == 8){
      cout << "August " << Day<< ", " << Year << endl;
      return;
   }
   else if (Month == 9){
      cout << "September " << Day<< ", " << Year << endl;
      return;
   }   
   else if (Month == 10){
      cout << "October " << Day<< ", " << Year << endl;
      return;
   }
   else if (Month == 11){
      cout << "Novemeber " << Day<< ", " << Year << endl;
      return;
   }
   else if (Month == 12){
      cout << "December " << Day<< ", " << Year << endl;
      return;
   }
}

void Date::print3(){  // First day, then month and year.  Error if any values are 0
   if (Month == 0 || Day == 0 || Year == 0){
      cout <<"There was an error.  Please try again." <<endl;
      return;
   }
   else if (Month == 1){
      cout << Day << " January " <<  Year << endl;
      return;
   }
   else if (Month == 2){
      cout << Day << " Febuary " << Year << endl;
      return;
   }
   else if (Month == 3){
      cout << Day << " March " << Year << endl;
      return;
   }
   else if (Month == 4){
      cout << Day << " April " << Year << endl;
      return;
   }
   else if (Month == 5){
      cout << Day<< " May " << Year << endl;
      return;
   }
   else if (Month == 6){
      cout << Day << " June " << Year << endl;
      return;
   }
   else if (Month == 7){
      cout << Day << " July " << Year << endl;
      return;
   }
   else if (Month == 8){
      cout << Day << " August " << Year << endl;
      return;
   }
   else if (Month == 9){
      cout << Day << " September " << Year << endl;
      return;
   }   
   else if (Month == 10){
      cout << Day << " October " << Year << endl;
      return;
   }
   else if (Month == 11){
      cout << Day << " Novemeber " << Year << endl;
      return;
   }
   else if (Month == 12){
      cout << Day << " December " << Year << endl;
      return;
   }
}
