/**
 * Name:  Brian Stamm
 * Date:  2.1.15
 * Description:  This is Item.cpp.  2 of 4.
 * **/

#include "Item.hpp"
#include <string>

using namespace std;

Item::Item(){
   setName("");
   setPrice(0.00);
   setQuantity(0);
   }

void Item::setName(string s){
   name = s;   
}

void Item::setPrice(double p){
   price = p;
}

void Item::setQuantity(int q){
   quantity = q;
}

string Item::getName(){
   return name;
}

double Item::getPrice(){
   return price;
}

int Item::getQuantity(){
   return quantity;
}
