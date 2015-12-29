/*******************
 * Name:  Brian Stamm
 * Date:  3.15.15
 * Description:  This is the final file.
 * File:  Menu.cpp
 ***********************/

#include "LibraryItem.hpp"
#include "Patron.hpp"
#include "Library.hpp"
#include "Book.hpp"
#include "Album.hpp"
#include "Movie.hpp"
#include <string>
#include <iostream> 

using namespace std;

void instructions();
void menuMain();
int additionMenu();

int main(){
   
   Library libOfCongress;
   Library* loc = &libOfCongress;
   int choice;

   instructions();

   do{
      menuMain();
      cin >> choice;
      cout << endl;
      switch(choice){
         case 1:  cout <<"List of Holdings." << endl << endl;
		  libOfCongress.printHoldings();
		  cout <<endl;
		  break;
	 case 2:  cout <<"List of Members." << endl << endl;
		  libOfCongress.printMembers();
		  cout <<endl;
		  break;
	 case 3:  cout <<"Current day." << endl;
		  cout <<"Day is: " <<libOfCongress.printDay() <<endl;
		  cout <<endl;
		  break;
	 case 4:  cout <<"Add a New Item to Library." <<endl;
		  {
		     int record = additionMenu();
		     if (record == 1){
			string author, title, idc;
			cout <<"Author: ";
			cin.ignore();
		        getline(cin, author);
		        cout <<"Book Title: ";
			getline(cin, title);
		        cout <<"Identification Code: ";
			getline(cin, idc);
			if (libOfCongress.holdIdCheck(idc)){
			   cout <<"Sorry, ID taken."<<endl;
			   cout <<"Please try again."<<endl;
			}
			else{
			   LibraryItem* p;
			   p = new Book(idc, title, author);
			   libOfCongress.addLibItem(p);
			   cout <<"Book has been added to the library."<<endl;
			}
		     }
		     else if(record == 2){
			string artist, title, idc;
			cout <<"Artist: ";
		        cin.ignore();
			getline(cin, artist);
		        cout <<"Album Title: ";
		        getline(cin, title);
		        cout <<"Identification Code: ";
		        getline(cin, idc);
			if(libOfCongress.holdIdCheck(idc)){
			   cout <<"Sorry, ID taken."<<endl;
			   cout <<"Please try again."<<endl;
			}
			else{
			   LibraryItem* p;
			   p = new Album(idc, title, artist);
			   libOfCongress.addLibItem(p);
			   cout <<"Album has been added to the library."<<endl;
			}
			}
		     else if(record == 3){ 
			string director, title, idc;
			cout <<"Director: ";
		        cin.ignore();
			getline(cin, director);
		        cout <<"Movie: ";
		        getline(cin, title);
		        cout <<"Identification Code: ";
		        getline(cin, idc);
			if(libOfCongress.holdIdCheck(idc)){
			   cout <<"Sorry, ID taken."<<endl;
			   cout <<"Please try again."<<endl;
			}
			else{
			   LibraryItem* p;
			   p = new Movie(idc, title, director);
			   libOfCongress.addLibItem(p);
			   cout <<"Movie has been added to the library."<<endl;
			}
		     }
		  }
		  break;
	 case 5:  cout <<"Adding a New Member." <<endl;
		  {
		     string name, code;
		     cout<<"Member name: ";
		     cin.ignore();
		     getline(cin, name);
		     cout<<"ID Code: ";
		     getline(cin, code);
		     if(libOfCongress.memIdCheck(code)){
			cout <<"Sorry, ID taken." <<endl;
			cout <<"Please try again." <<endl;
		     }
		     else{
			Patron *pat = new Patron(code, name);
			libOfCongress.addMember(pat);
		     }
		     cout <<endl;
		  }
		  break;
	 case 6:  cout <<"Checkout" <<endl;
		  {
		     string memID, holdID;
		     cout << "Member ID: ";
		     cin.ignore();
		     getline(cin, memID);
		     if(libOfCongress.memIdCheck(memID)){
			cout << "Holding ID: ";
			getline (cin, holdID);
			if(libOfCongress.holdIdCheck(holdID)){
			   libOfCongress.checkOutLibraryItem(memID, holdID);
			}
			else{
			   cout <<"There is no article with that ID Code."<<endl;
			   cout <<"Please try again." <<endl <<endl;
			}
		     }
		     else{
			cout <<"Sorry, there is no member with that ID." <<endl;
			cout <<"Please try again." <<endl;
		     }
		     cout <<endl;
		  }
		  break;
	 case 7:  cout <<"Return" <<endl;
		  {
		     string holdID;
		     cout <<"Holding ID: ";
		     cin.ignore();
		     getline(cin, holdID);
		     if(libOfCongress.holdIdCheck(holdID)){
			libOfCongress.returnLibraryItem(holdID);
		     }
		     else{
			cout <<"There is no article with that ID Code."<<endl;
			cout <<"Please try again." <<endl <<endl;
		     }
		     cout <<endl;
		  }
		  break;
	 case 8:  cout <<"Request" <<endl;
		  {
		     string memID, holdID;
		     cout << "Member ID: ";
		     cin.ignore();
		     getline(cin, memID);
		     if (libOfCongress.memIdCheck(memID)){
			cout <<"Holding ID: ";
			getline (cin, holdID);
			if(libOfCongress.holdIdCheck(holdID)){
			   libOfCongress.requestLibraryItem(memID, holdID);
			}
			else{
			   cout <<"There is no article with that ID Code."<<endl;
			   cout <<"Please try again." <<endl <<endl;
			}	
		     }
		     else{
			 cout <<"Sorry, there is no member with that ID." <<endl;
			 cout <<"Please try again." <<endl;
		     }
		  }
		  cout <<endl;
		  break;
	 case 9:  cout <<"Pay Fines." <<endl;
		  {
		     string memID;
		     cout <<"Member ID: ";
		     cin.ignore();
		     getline(cin, memID);
		     if (libOfCongress.memIdCheck(memID)){
			 double amount;
			 cout <<"How much: ";
			 cin >> amount;
			 libOfCongress.payFine(memID, amount);
		     }
		     else{
			 cout <<"Sorry, there is no member with that ID." <<endl;
			 cout <<"Please try again." <<endl;
		     }   
		  cout <<endl;
		  }
		  break;
	 case 10:  cout <<"Change Date." <<endl;//If want to do more days at once need to change!!
		   {
		      int pick, day;
		      cout <<"If you want to change one day, enter (1) or if"<<endl;
		      cout <<"you want to enter the amount of days to change,"<<endl;
		      cout <<"enter (2)"<<endl<<endl;
		      cout <<"Choice: ";
		      cin >> pick;
		      if (pick == 1){
			 libOfCongress.incrementCurrentDate();
			 cout <<"Now the day is: " << libOfCongress.printDay() <<endl;
		      }
		      else if(pick ==2){
			 cout <<"How many days: ";
			 cin >>day;
			 libOfCongress.incrementCurrentDate(day);
			 cout <<"Now the day is: "<< libOfCongress.printDay() <<endl;
		      }
		      /**libOfCongress.incrementCurrentDate();
		      cout <<"Now the day is: " <<libOfCongress.printDay()<<endl;
		      cout <<endl;**/
		      
		   }
		   break;     
	 case 11:  cout <<"Member Information." <<endl;
		   {
		      string memID;
		      cout <<"Member ID: ";
		      cin.ignore();
		      getline(cin, memID);
		      if (libOfCongress.memIdCheck(memID)){
			 libOfCongress.viewPatronInfo(memID);
		      }
		      else{
			 cout <<"Sorry, there is no member with that ID." <<endl;
			 cout <<"Please try again." <<endl;
		      }
		      cout <<endl;
		   }
		  break;
	 case 12:  cout <<"Item's Information." <<endl;
		   {
		      string holdID;
		      cout <<"Holding ID: ";
		      cin.ignore();
		      getline(cin, holdID);
		      if(libOfCongress.holdIdCheck(holdID)){
			 libOfCongress.viewItemInfo(holdID);
		      }
		      else{
		        cout <<"There is no article with that ID Code."<<endl;
			cout <<"Please try again." <<endl <<endl;
		      }
		      cout <<endl;
		   }
		  break;
      }
   }while(choice != 13);

   cout<<endl;
   cout <<"Thanks for playing!" <<endl;
   cout <<endl;

   return 0;
}

void instructions(){
   cout <<endl;
   cout <<"This is a simple library program.  It will let you add items, like"<<endl;
   cout <<"books, albums, or library members.  You can pay fines, request items," <<endl;
   cout <<"and alot of other things.  Enjoy!" <<endl;
   cout <<endl;
}

void menuMain(){
   cout <<endl;
   cout <<"Menu" <<endl<<endl;
   cout <<"1.  Holdings" <<endl;
   cout <<"2.  Members" <<endl;
   cout <<"3.  Current Date" <<endl;
   cout <<"4.  Add Library Item" <<endl;
   cout <<"5.  Add Member" <<endl;
   cout <<"6.  Check Out Item" <<endl;
   cout <<"7.  Return Item" <<endl;
   cout <<"8.  Request Item" <<endl;
   cout <<"9.  Pay Fine" <<endl;
   cout <<"10.  Change date" <<endl;
   cout <<"11.  Member Information" <<endl;
   cout <<"12.  Item Information" <<endl;
   cout <<"13.  Quit" <<endl<<endl;
   cout <<"Selection: ";  
}

int additionMenu(){
  int a;
  cout <<endl;
  cout <<"What would you like to add:" <<endl<<endl;
  cout<<"1.  Book" <<endl;
  cout <<"2.  Album" <<endl;
  cout <<"3.  Movie" <<endl <<endl;
  cout<<"Selection: ";
  cin >>a;
  return a;
}
