/***************
 * Name:  Brian Stamm
 * Date:  3.15.15
 * Discription:  This is a file cpp for Book. 
 * Title:  Book.cpp
 * ************/

#include "LibraryItem.hpp"
#include "Book.hpp"
#include <string>
#include <iostream>

using namespace std;

void Book::setAuthor(string a){ //Sets author
   author = a;
}

string Book::getAuthor(){ //returns author
   return author;
}

void Book::returnInformation(){ //returns all the book information.
   cout <<"Book Title: " << LibraryItem::getTitle()<<endl;
   cout <<"Book Author: " << author <<endl;
   cout <<"Code: " << LibraryItem::getIdCode() << endl;
}

int Book::getCheckOutLength(){ //Returns the max time book is able to be checked out
   return CHECK_OUT_LENGTH;
}
