/*******
 * Name:  Brian Stamm
 * Date:  1.25.14
 * Description:  This is the herro program, which the player
 * gets to make their own here.  Enjoy.
 * *********/

#include<iostream>
#include "Hero.hpp"

using namespace std;

void instructions(); //basic instructions
int hp, str, sp, m, damage;

int main(){
   instructions();  

   //Gets the attributes for the hero
   cout << "Hit Points: ";
   cin >> hp;
   cout << "Strength: ";
   cin >> str;
   cout << "Speed: ";
   cin >> sp;
   cout<< "Money: ";
   cin >> m;

   Hero bueller(hp, str, sp, m);  //"Bueller, you're my hero"
   cout <<"And now the game begins!" <<endl;
   cout <<endl;


   do{  //Do loop, starts the "game"
      cout <<"How much damage: ";
      cin >> damage;
      bueller.setHitPoints(-damage); //Takes variable damage and subtracts from HP
      cout <<"With that damage, here are your attributes:" <<endl;
      //Displays the attributes after damage assessed
      cout << bueller.getHitPoints() << " Hit Points" <<endl;
      cout << bueller.getStrength() << " Strength" <<endl;
      cout << bueller.getSpeed() << " Speed" <<endl;
      cout << bueller.getMoney() << " Money" <<endl;
   } while (bueller.takeDamage(damage) == true);//Continues to run the loop until takeDame
   //is false

   cout << "Sorry, your Hero is dead." << endl;  //End statements
   cout << "Like Queen said, 'Who wants to live forever?'" <<endl;

   return 0;
}

void instructions(){ //Instructions to the game
   cout << "This is a simple game, where you get to design a " << endl;
   cout << "Hero and their attributes.  Please enter all positive" <<endl;
   cout <<"values, and the program will create the Hero." <<endl;
   cout << "After creating the Hero, then you play the game " <<endl;
   cout <<"which you will assess damage to your Hero." <<endl;
   cout <<"Enjoy!" <<endl;
   cout <<endl;
}
