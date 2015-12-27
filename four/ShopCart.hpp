/***
 * Name:  Brian Stamm
 * Date:  2.1.15
 * Description:  This is ShopCart.hpp.  3 of 4
 ***/

#ifndef SHOPCART_HPP
#define SHOPCART_HPP

#include<string>
#include <vector>
#include "Item.hpp"

using namespace std;

class ShoppingCart{
   
   private:
      vector <Item> item;

   public:
      //Item item;
      void addItem();
      void listContents();
      void totalPrice();

};
#endif
