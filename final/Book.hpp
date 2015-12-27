/**********
 * Name:  Brian Stamm
 * Date:  3.15.15
 * Description:  This is a file.  Header for the book class
 * File:  Book.hpp
 * ********/

#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>
#include "LibraryItem.hpp"

using namespace std;


class Book : public LibraryItem
{
   private:
      string author;
   
   public:
      Book(string icd, string t, string a):LibraryItem(icd, t)
   {
     author = a;
   }
      void setAuthor(string a);
      string getAuthor();
      int getCheckOutLength();
      void returnInformation(); 
      static const int CHECK_OUT_LENGTH = 21; //Constant
      	   
};

#endif
