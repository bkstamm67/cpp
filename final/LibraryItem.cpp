/*********
 * Name:  Brian Stamm
 * Date:  3.15.15
 * Description:  File.
 * File:  LibraryItem.cpp
 *****************/

#include "LibraryItem.hpp"
#include <iostream>

using namespace std;

LibraryItem::LibraryItem(){
   setIdCode("0");
   setTitle("0");
   setLocation(ON_SHELF);
   Patron* p = NULL;
   setCheckedOutBy(p);
   setRequestedBy(p);
   setDateCheckedOut(-1);//OR do you set this to zero?, if change, remember Library::return
}

LibraryItem::LibraryItem(string idc, string t){
   setIdCode(idc);
   setTitle(t);
   setLocation(ON_SHELF);
   Patron* p = NULL;
   setCheckedOutBy(p);
   setRequestedBy(p);
   setDateCheckedOut(-1);
}

void LibraryItem::setIdCode(string code){
   idCode = code;
   //Need to check against the other id codes
}

string LibraryItem::getIdCode(){
   return idCode;
}

void LibraryItem::setTitle(string t){
   title = t;
}

string LibraryItem::getTitle(){
   return title;
}

void LibraryItem::setLocation(Locale lo){
   location = lo;
}

Locale LibraryItem::getLocation(){
   return location;
}

void LibraryItem::setCheckedOutBy(Patron* p){
   checkedOutBy = p;
}

Patron* LibraryItem::getCheckedOutBy(){
  return checkedOutBy;
}

void LibraryItem::setRequestedBy(Patron* p){
   requestedBy = p;
}

Patron* LibraryItem::getRequestedBy(){
   return requestedBy;
}

void LibraryItem::setDateCheckedOut(int d){
   dateCheckedOut = d;
}

int LibraryItem::getDateCheckedOut(){
   return dateCheckedOut;
}
