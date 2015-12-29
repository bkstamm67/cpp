/****************
 * Name:  Brian Stamm
 * Date:  3.15.15
 * Description:  This is the cpp file of the Patron class.  Creates members for the library.
 * File:  Patron.cpp
 * *************/

#include "Patron.hpp"
#include "LibraryItem.hpp"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

Patron::Patron(){ //Default constructor
   idNum = "0";
   name = "0";
   fineAmount = 0;
}

Patron::Patron(string idn, string n){ //"real" constructor
  idNum = idn;
  name = n;
  fineAmount = 0.00;
}

/**Function:  getID - returns the id code for patron
 * parameters:  none  * **/
string Patron::getIdNum(){
   return idNum;
}
/**Function:  get Name - returns the name of member
 * paramters - none ****/
string Patron::getName(){
   return name;
}
/**Function:  get vector of checked out items, returns the vector of pointers to library items
 * this member has checked out
 * Paramters - none    ***/
vector<LibraryItem*> Patron::getCheckedOutItems(){
   return checkedOutItems;
}
/***Function:  Adds items to the vector
 * parameter:  pointer to library item  ***/
void Patron::addLibraryItem(LibraryItem* b){
   checkedOutItems.push_back(b);
}
/***Function:  removes items from vector, most likely becauuse it's returned
 * paramter:  pointer to library item   ****/
void Patron::removeLibraryItem(LibraryItem* b){
   int size = checkedOutItems.size();  //searches for item
   int i, remove;
   for (i =0; i<size; i++){
      if (checkedOutItems[i] == b){
	 remove = i; 
      }
   }
   checkedOutItems.erase(checkedOutItems.begin()+remove); //remove its
}
/**Function:  get fine amount, returns the total amount of fines
 * parameters:  none  *****/
double Patron::getFineAmount(){
   return fineAmount;
}
/***Function:  amend fine amount, adds / subtracts to fine amount
 * parameter - a double, amount.   *****/
void Patron::amendFine(double amount){
   fineAmount += amount;
}
