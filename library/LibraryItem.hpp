#ifndef LIBRARY_ITEM_HPP
#define LIBRARY_ITEM_HPP

#include <string>

class Patron;

//These three locations are mutually exclusive, but note that
// a LibraryItem can be on request for a Patron while being checked
// out to another Patron.  In that case the LibraryItem's location is
// CHECKED_OUT, and when it is returned, it's location will
// become ON_HOLD_SHELF.

enum Locale {ON_SHELF, ON_HOLD_SHELF, CHECKED_OUT};


class LibraryItem
{
   private:
      std::string idCode;
      std::string title;
      Locale location;
      Patron* checkedOutBy;
      Patron* requestedBy;
      int dateCheckedOut;
   
   public:
      LibraryItem();
      LibraryItem(std::string idc, std::string t);
      virtual int getCheckOutLength() = 0;
      virtual void returnInformation() = 0;
      void setIdCode(std::string code);
      std::string getIdCode();
      void setTitle(std::string t);
      std::string getTitle();
      void setLocation(Locale lo);
      Locale getLocation();
      void setCheckedOutBy(Patron* p);
      Patron* getCheckedOutBy();
      void setRequestedBy(Patron* p);
      Patron* getRequestedBy();
      void setDateCheckedOut(int d);
      int getDateCheckedOut();

};

#endif
