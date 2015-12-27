/*Name:  Brian Stamm
 * Date:  3.15.15
 * This is the header file.  Given to us.  Most explanation in cpp file.
 * ****/


#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <string>
#include <vector>


class Patron;
class LibraryItem;

class Library
{
   private:
      std::vector<LibraryItem*> holdings;
      std::vector<Patron*> members;
      int currentDate;
      static const double FINE = .10; //Added as a constant
   
   public:
      Library();
      ~Library();
      void printHoldings();  //Added
      void printMembers();  //Added
      int printDay();  //Added
      bool memIdCheck(std::string); //Added
      bool holdIdCheck(std::string); //Added
      void addLibItem(LibraryItem*);
      void addMember(Patron*);
      void checkOutLibraryItem(std::string, std::string);
      void returnLibraryItem(std::string);
      void requestLibraryItem(std::string patronID, std::string ItemID);
      void incrementCurrentDate();
      void incrementCurrentDate(int);   //Added
      void payFine(std::string patronID, double payment);
      void viewPatronInfo(std::string patronID);
      void viewItemInfo(std::string ItemID);

};

#endif
