/************
 * Name:  Brian Stamm
 * Date:  3.15.15
 * Description:  This is a header file for movie, more info in cpp file.
 * File:  Movie.hpp
 * **********/

#ifndef MOVIE_HPP
#define MOVIE_HPP

#include <string>
#include "LibraryItem.hpp"

using namespace std;

class Movie : public LibraryItem{

   private:
      string director;

   public:
      Movie(string icd, string t, string d):LibraryItem(icd, t){
         director = d;
      }
      void setDirector(string d);
      string getDirector();
      int getCheckOutLength();
      static const int CHECK_OUT_LENGTH = 7;
      void returnInformation();

};

#endif
