/***********
 * Name:  Brian Stamm
 * Date:  3.15.15
 * Description:  Header file for patron.  Given to us
 * File:  Patron.hpp
 * *******/

#ifndef PATRON_HPP
#define PATRON_HPP

#include <string>
#include <vector>

class LibraryItem;

class Patron
{
   private:
    std::string idNum;
    std::string name;
    std::vector<LibraryItem*> checkedOutItems;
    double fineAmount;
   
   public:
    Patron();
    Patron(std::string idn, std::string n);
    std::string getIdNum();
    std::string getName();
    std::vector<LibraryItem*> getCheckedOutItems();
    void addLibraryItem(LibraryItem* b);
    void removeLibraryItem(LibraryItem* b);
    double getFineAmount();
    void amendFine(double amount);

};

#endif
