/**
 * Name:  Brian Stamm
 * Date:  2.1.15
 * Description:  This is Item.hpp.  1 of 4
 * */

#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
using namespace std;

class Item
{
   private:
      string name;
      double price;
      int quantity;
      
   public:
      Item();
      string getName();
      double getPrice();
      int getQuantity();
      void setName(string);
      void setPrice(double);
      void setQuantity(int);
      
};
#endif
