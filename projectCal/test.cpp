/*******
 * Name:  Brian Stamm
 * Date:  3.1.15
 * Description:  7 of 7 for project.  This program uses all the previous ones to create a
 * simple project calculator with some simple selections.
 * *********/

#include<iostream>
#include <iomanip>

//All the previous hpp files needed.
#include "CustomerProject.hpp" 
#include "RegularProject.hpp"
#include "PreferredProject.hpp"

using namespace std;

//Prototypes for basic instructions and farewell
void instructions();
void finish();

int main(){
   
   CustomerProject *pCustProj;  //Pointer to CustomerProject
   double mat, hrs, trans;
   int choice;

   instructions();

   //Block gets input for user on variables
   cout<<"What is the total hours: ";
   cin >>hrs;
   cout <<"What is the total cost of materials: ";
   cin >> mat;
   cout <<"What is the total cost of transportation: ";
   cin >>trans;
   cout <<endl;

   //Simple if else statements for user to pick type of project
   cout <<"If your project is Preferred, please enter 1." <<endl;
   cout <<"Or if your project is Regular, please enter 2." <<endl;
   cout <<"Project Type: ";
   cin >> choice;
   cout <<endl;

   cout <<"The estimate for you project is - " <<endl;

   /*  Within the block, the pointer will be pointing to a "new" project,
    *  with the user will indicate with their selection.
    *  the new project will construct the object, and then call the 
    *  billed amount defined in that project type.    ***/
   if (choice == 1){
      pCustProj = new PreferredProject(hrs, mat, trans);  
      cout << fixed << showpoint << setprecision(2);
      cout <<"Total cost:  $" << pCustProj->billAmount() <<endl;
   }
   else if (choice == 2){
      pCustProj = new RegularProject(hrs, mat, trans);
      cout << fixed << showpoint << setprecision(2);
      cout <<"Total cost:  $" <<pCustProj->billAmount() <<endl;
   }
   else{
      cout <<"Why didn't you pick 1 or 2?" <<endl; //Just because, why?
   }

   finish(); 
   
   return 0;
}

/**Function:  instructions.  Provides basic instructions for user.
 * Parameters:  None 
 * **/

void instructions(){
   cout <<endl;
   cout <<"Welcome to Petey's Perfunctory Project Projector!" <<endl;
   cout <<"We can give you a quick estimate of cost for your" <<endl;
   cout <<"project.  You will need to enter the total hours, "<<endl;
   cout <<"material cost, and transportation costs, and then " <<endl;
   cout <<"through the magic of P^4, we will present you with an" <<endl;
   cout <<"estimate." <<endl;
   cout <<endl;
   cout <<"If your project is a Preferred Contract or Regular Contract,"<<endl;
   cout <<"there will be an option to select it." <<endl;
   cout <<endl;
   cout <<"And thanks once again for using Petey's Perfunctory Project Projector!"<<endl;
   cout <<endl;
}

/**Function: Finish.  Just a little farewell.  Just because I finished early
 * Parameters:  none
 * ***/

void finish(){
   cout <<endl;
   cout <<"Thanks for using Petey's Pefunctory Project Projector!" <<endl;
   cout <<"As we say at Petey's 'Perfection is Pursued in Perpetuity'" <<endl;
   cout <<"If you are interested in more information, please call us" <<endl;
   cout <<"at our 800 number.  Thanks again!" <<endl;
}
