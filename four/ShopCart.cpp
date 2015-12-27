/**
 * Name:  Brian Stamm
 * Date:  2.1.15
 * Description:  This is ShopCart.cpp.  4 of 4.
 * This should run the program.  It's a simple cart program
 * **/

#include "Item.hpp"
#include "ShopCart.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void ShoppingCart::addItem(){ //Adds items to cart
   double price;
   string name;
   int num;
   Item thingy;//creates an item
   
   cout << "Item name: ";
   //getline(cin, name); Attempted to use, but didn't work
   cin >> name;

   cout << "Price: ";
   cin >> price;
   
   cout << "Quantity: ";
   cin >>num;
   
   thingy.setPrice(price);//makes the item
   thingy.setName(name);
   thingy.setQuantity(num);
   item.push_back(thingy);//puts item in vector of "item"
   
}

void ShoppingCart::listContents(){//Creates list of contents
   int numItem = item.size();
   cout << numItem << endl;
   cout << "Here is your shopping cart: " <<endl;
   cout <<endl;

   for (int i = 0; i< numItem; i++){//for loop to go through vector
      cout <<"Name:  " << item[i].getName() <<endl;//printing off each one
      cout <<"Price:  $"<< item[i].getPrice() <<endl;
      cout <<"Quantity:  "<< item[i].getQuantity() <<endl;
      cout <<endl;
   }
}

void ShoppingCart::totalPrice(){ //gets total price
   int numItem = item.size();
   double total = 0;
   for (int i =0; i< numItem; i++){ //for loop to total it
      total += item[i].getPrice();
   }
   cout <<"The total price is: $" << total <<endl;
   cout <<endl;
}

void menu();  //function prototype

int main(){
   
   ShoppingCart carty;  //creates object carty
   int choice;

   //Basic instructions
   cout <<"This is a basic shopping cart program" <<endl;
   cout <<"where you have options to add items, " <<endl;
   cout <<"view your items and get a total." <<endl;
   cout <<"Enjoy!" <<endl;
   cout <<endl;

   cout <<fixed <<showpoint <<setprecision(2);  //Sets decimal place
   
   do{//Do loop, using switch to pick the item out of menu
      menu();
      cin >> choice;
      switch(choice){
	 case 1:  carty.addItem();  //Adds item
		  break;
	 case 2:  carty.listContents();  //List Contents
		  break;
	 case 3:  carty.totalPrice();  //Gets total price
		  break;
    
      }
   }while(choice !=4);  //do while loop, continues menu
   
   cout <<"Thanks for using Shopping Cart!" <<endl;

   return 0;

}
/**
 * Function:  To create a basic menu for user
 * parameters:  None.
 * */

void menu(){
   cout << "Menu:" <<endl;
   cout <<endl;
   cout << "1.  Add an item." <<endl;
   cout <<"2.  List contents." <<endl;
   cout <<"3.  Total price." <<endl;
   cout <<"4.  Quit." <<endl;
   cout <<endl;
   cout <<"Choice: ";
}
