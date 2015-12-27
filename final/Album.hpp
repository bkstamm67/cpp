/****************
 * Name:  Brian Stamm
 * Date:  3.15.15
 * Description:  File.  Header for Album, more info in cpp file
 * File:  Album.hpp
 * **************/

#ifndef ALBUM_HPP
#define ALBUM_HPP

#include <string>
#include "LibraryItem.hpp"

using namespace std;

class Album : public LibraryItem{

   private:
      string artist;

   public:
      Album(string icd, string t, string a):LibraryItem(icd, t)
   {
      setArtist(a);
   }
      void setArtist(string a);
      string getArtist();
      static const int CHECK_OUT_LENGTH = 14;
      int getCheckOutLength();
      void returnInformation();

};

#endif
