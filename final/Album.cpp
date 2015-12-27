/*************
 * Name:  Brian Stamm
 * Date:  3.15.15
 * Description:  File  This is the cpp file for Album.
 * File:  Album.cpp
 * ****************/

#include "Album.hpp"
#include "LibraryItem.hpp"
#include <string>
#include <iostream>

using namespace std;

void Album::setArtist(string a){ //sets artist
   artist = a;
}

string Album::getArtist(){ //get's artist
   return artist;
}

void Album::returnInformation(){ //Returns all information about item
   cout <<"Album Title: " << LibraryItem::getTitle()<<endl;
   cout <<"Album Artist: " << artist <<endl;
   cout <<"Code: " <<LibraryItem::getIdCode() <<endl;
}
int Album::getCheckOutLength(){ //returns check out max time
   return CHECK_OUT_LENGTH;
}
