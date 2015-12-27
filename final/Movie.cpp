/*************
 * Name:  Brian Stamm
 * Date:  3.15.15
 * Description:  File, cpp styling.  This is for Movie.
 * File:  Movie.cpp  
 * ***********/

#include "Movie.hpp"
#include "LibraryItem.hpp"
#include <string>
#include <iostream>

using namespace std;

void Movie::setDirector(string d){ //sets director
   director = d;
}

string Movie::getDirector(){ //returns director
   return director;
}

int Movie::getCheckOutLength(){ //returns max time check out 
   return CHECK_OUT_LENGTH;
}

void Movie::returnInformation(){ //Returns all information about movie
   cout <<"Movie Title: " <<LibraryItem::getTitle()<<endl;
   cout <<"Movie Director: " << director <<endl;
   cout <<"Code: " <<LibraryItem::getIdCode() <<endl;
}
