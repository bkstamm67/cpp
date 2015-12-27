/****************
 * Name:  Brian Stamm
 * Date:  3.15.15
 * Description:  This is a file.  It's big.  It creates the library's functions
 * File:  Library.cpp
 * *************/

#include "Library.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include "LibraryItem.hpp"
#include "Patron.hpp"

using namespace std;

//Creator.  Creates things.
Library::Library(){
   currentDate = 0;
}
/***Destructor.  Destroys things  ****/
Library::~Library(){
   if(holdings.empty()){
      holdings.clear();
   }
   else{
      for (int i = 0; i<holdings.size(); i++){
	 delete(holdings[i]);
	 holdings[i] = 0;
      }
      holdings.clear();
   } 
   if(members.empty()){
      members.clear();
   }
   else{
      for(int i = 0; i<members.size(); i++){
	 delete(members[i]);
	 members[i] = 0;
      }
      members.clear();
   }
   cout <<"Thanks again, GO SOUNDERS!" <<endl;
}
/**Function - prints the holdings of the library
 * parameters - none   ********/
void Library::printHoldings(){
   int size = holdings.size();
   for (int i = 0; i<size; i++){
      holdings.at(i)->returnInformation();
      cout <<endl;
   }
}
/**Function - Prints the current members
 * Parameters - None   *****/
void Library::printMembers(){
   int size = members.size();
   for (int i = 0; i<size; i++){
      cout <<"Member ID: " << members.at(i)->getIdNum()<<endl;
      cout <<"Member Name: " << members.at(i)->getName()<<endl;
      cout <<endl;
   }
}
/*Function - prints the current day
 * parameters - none  */
int Library::printDay(){
   return currentDate;
}
/**Function:  bool mem check.  Checks if members are members
 * paramter, string of member id. ****/
bool Library::memIdCheck(string mem){
   int found = 0;
   int size = members.size();
   for(int i = 0; i<size; i++){
      string temp = members.at(i)->getIdNum();
      if(temp == mem)
	 found = 1;
   }
   return found;
}
/***Function - bool hold check - checks holdings to verify if in holdings
 * paramters - string of holdings ****/
bool Library::holdIdCheck(string hold){
   int found = 0;
   int size = holdings.size();
   for(int j = 0; j<size; j++){
      string temp = holdings.at(j)->getIdCode();
      if (temp == hold)
	 found = 1;
   }
   return found;
}
/***Function:  addLibItem - adds a library item pointer to the vector of holdings
 * parameter - library item pointer  ******/
void Library::addLibItem(LibraryItem* b){
   holdings.push_back(b);
}
/*Function - addmember.  Add's member pointer to the vector of members
 * parameter:  patron pointer ************/
void Library::addMember(Patron* p){
   members.push_back(p);
}
/*Function:  checkOutLIbraryItem - lets people check out items
 * Parameters:  string of ids for member and item ***/
void Library::checkOutLibraryItem(string patronID, string itemId){
   int foundM;//Searches for each position
   int foundH;
   for(int i = 0; i< members.size(); i++){
      string tempM = members.at(i)->getIdNum();
      if(tempM == patronID)
	 foundM = i;
   }
   for(int j = 0; j < holdings.size(); j++){
      string tempH = holdings.at(j)->getIdCode();
      if (tempH == itemId)
	 foundH = j;
   }
   Patron *p = members.at(foundM);//sets pointers
   LibraryItem *lib = holdings.at(foundH);
   
   if (lib->getLocation()== 0){ //Checks location, and sets location and date
      lib->setLocation(CHECKED_OUT);
      lib->setCheckedOutBy(p);
      lib->setDateCheckedOut(currentDate);
      p->addLibraryItem(lib);
      cout <<"Item has been checked out." <<endl;
   }
   
   else if(lib->getLocation()==1){ //If on hold shelf and person requesting it asks for it
      Patron* p2get = lib->getRequestedBy();
      if (p->getIdNum() == p2get->getIdNum()){
	 lib->setLocation(CHECKED_OUT); //Sets the various locations/dates
	 lib->setCheckedOutBy(p2get);
	 lib->setDateCheckedOut(currentDate);
	 p2get->addLibraryItem(lib);
	 cout <<"Item has been checked out." <<endl;
      }
      else{
	 cout<<"Currently on Hold Shelf"<<endl; //If tried to get by someone not requesting it
	 cout <<"On Hold for: " <<p2get->getName()<<endl;
      }
   }
   else if(lib->getLocation()==2){ //If it is already checked out
      cout <<"Sorry, it is checked out" <<endl;
      Patron* temp = lib->getRequestedBy();
      if (temp == NULL){
        cout <<"It is available for request" <<endl;
	cout <<"Please go to 'Request' option in main menu." <<endl;
      }
      else{
         cout <<"And there is a request on it as well." <<endl;
      }
   }
}
/*Function - returnLibraryItem.  Let's person return item
 * parameters:  itemid in string*****/
void Library::returnLibraryItem(string itemId){
   int found;//Searches for pointers
   for(int j = 0; j < holdings.size(); j++){
      string temp = holdings.at(j)->getIdCode();
      if (temp == itemId)
	 found = j;
   }
   
   LibraryItem *libReturn = holdings.at(found);//sets pointer
   //If item checked out and no one wants it
   if (libReturn->getLocation()== 2 && libReturn->getRequestedBy() == NULL){
      Patron *pReturn = libReturn->getCheckedOutBy();
      pReturn->removeLibraryItem(libReturn);
      libReturn->setLocation(ON_SHELF);
      libReturn->setDateCheckedOut(-1);
      pReturn = NULL;
      libReturn->setCheckedOutBy(pReturn);
      cout <<"Item returned." <<endl;
   }
   //If checked out and someone wants it, sets hold
   else if(libReturn->getLocation()==2 && libReturn->getRequestedBy() != NULL){
      Patron *p2get = libReturn->getRequestedBy();
      Patron *p2return = libReturn->getCheckedOutBy();
      p2return->removeLibraryItem(libReturn);
      libReturn->setDateCheckedOut(-1);
      p2return = NULL;
      libReturn->setCheckedOutBy(p2return);
      libReturn->setLocation(ON_HOLD_SHELF);
      cout <<"Item returned." <<endl;
      cout <<"Item now on hold for: " <<p2get->getName() <<endl;
   }
   //If person mistaken, on hold shelf
   else if(libReturn->getLocation()==1){
      Patron *p2get = libReturn->getRequestedBy();
      cout<<"On Hold Shelf"<<endl; 
      cout <<"On hold for: " << p2get->getName()<<endl;
   }
   //If available
   else if(libReturn->getLocation()==0){
      cout <<"Sorry, it is not checked out." <<endl; 
   }
}
/**Function:  Request item, puts member's pointer on requestedBy in LibraryItem
 * Parameter - strings of member and holdings code.  ****/
void Library::requestLibraryItem(string patronID, string itemID){
   int foundM; //Searches for item and member
   int foundH;
   for(int i = 0; i <members.size(); i++){
      string temp = members.at(i)->getIdNum();
      if(temp == patronID)
	 foundM = i;
   }
   for(int j = 0; j <holdings.size(); j++){
      string temp = holdings.at(j)->getIdCode();
      if (temp == itemID)
	 foundH = j;
   }
   //Sets pointers, checks location of item 
   Patron *p = members.at(foundM);
   LibraryItem *lib = holdings.at(foundH);
   if (lib->getLocation()== 0){
      cout << "Item is available, please go to check out to proceed."<<endl; 
   }
   
   else if(lib->getLocation()==1){ //If on hold 
      Patron* temp = lib->getRequestedBy();
      Patron* tempFooling = lib->getCheckedOutBy();
      if (p->getIdNum() == temp->getIdNum()){ //And person requested it asks for it
	 cout <<"Item is available for you to pick up."<<endl;
	 cout <<"Please go to the 'Check Out' option." <<endl;
      }
      else if(p->getIdNum() == tempFooling->getIdNum()){ //If person already has it
         cout <<"Item is already checked out by this member" <<endl;
	 cout <<"Did they loose it?" <<endl;
	 cout <<"Just kidding.  Remind them and send them on their way." <<endl;
      }
      else{
	 cout <<"Sorry, item is already on request." <<endl; //Anyone else requesting
      }
   }
   else{ //If there is no person requesting it
      Patron* temp = lib->getRequestedBy();
      if(temp == NULL){
	 lib->setRequestedBy(p);
	 cout <<"Item on request." <<endl;
	 cout <<"When it is returned, you will be notified, and it will" <<endl;
	 cout <<"be on hold until you pick it up." <<endl;
      }
      else{
	 cout <<"Sorry, item is on hold for another member." <<endl;
      }
   }
}
/**Function:  increment date,  increases the day by one
 * parameters, none *********/
void Library::incrementCurrentDate(){
   ++currentDate;
   int size = holdings.size();
   for(int i = 0; i<size; i++){ //For loop to look at all the holdings and see if they're 
      LibraryItem *libDate = holdings.at(i);//overdue, then adds to the fine.
      int checkOut = libDate->getDateCheckedOut();
      int difference = currentDate - checkOut;
      int length = libDate->getCheckOutLength();
      if(difference > length){
	 Patron *pDate = libDate->getCheckedOutBy();
	 pDate->amendFine(FINE);
      }
   }
}
/**Function:  increment date, increases by more than one, user decision
 * parameter - int, days - total number of days***/

void Library::incrementCurrentDate(int d){
   int past = currentDate; 
   currentDate += d;
   int size = holdings.size();
   for(int i = 0; i<size; i++){
      LibraryItem *libDate = holdings.at(i);
      int checkOut = libDate->getDateCheckedOut();
      if (checkOut != -1){
	 int difference = currentDate - checkOut;
	 int length = libDate->getCheckOutLength();
	 if(difference > length){
	    if (past - checkOut >= length){
	       Patron *pDate = libDate->getCheckedOutBy();
	       double newFine = (currentDate - past) * FINE;
	       pDate->amendFine(newFine);
	    }
	    else{
	       Patron *pDate = libDate->getCheckedOutBy();
	       int fineTime = currentDate - checkOut - length;
	       double newFine = FINE * fineTime;
	       pDate->amendFine(newFine);
	    }
	 }
      }
   }
}
/**Function:  payFine, lets person pay fines
 * Parameters:  patron id, which is a string, and payment amount, which is a double
 * ***/
void Library::payFine(string patronID, double payment){
   int found;  //Finds person's location
   for(int i = 0; i < members.size(); i++){
      string temp = members.at(i)->getIdNum();
      if(temp == patronID)
	 found = i;
   }
   cout << fixed << showpoint << setprecision(2);
   cout <<"Payment is: " << payment <<endl; //Show's payment amount
   payment *=(-1);
   Patron *pFine = members.at(found);
   pFine->amendFine(payment);
   cout <<pFine->getName() <<"'s Current Balance:  " <<pFine->getFineAmount()<<endl; //Current balance
}
/**Function:  viewPatronInfo - can see the various member info
 * Parameters:  patron id, in string.
 * **/
void Library::viewPatronInfo(string patronID){
   int found; //Gets the location of patron
   int size = members.size();
   for (int i = 0; i<size; i++){
      string temp = members.at(i)->getIdNum();
      if (temp == patronID)
	 found = i;
   }
   
   Patron *libPatPtr = members.at(found);//sets pointer
   cout <<"Member information: " <<endl<<endl; //returns information
   cout <<"Name:  " << libPatPtr->getName()<<endl;
   cout <<"Member Id: " << libPatPtr->getIdNum()<<endl;
   //Then looks at members' holdings, returning their information
   vector<LibraryItem*> memberHoldings = libPatPtr->getCheckedOutItems();
      if (memberHoldings.empty()){
         cout <<"Currently does not have anything checked out."<<endl;
      }
      else{
	 int size = memberHoldings.size();
	 cout <<"Current checked out items: " <<endl;
	 cout <<endl;
	 for(int i = 0; i<size; i++){
	    LibraryItem* ptr = memberHoldings[i];
	    ptr->returnInformation();
	    cout <<endl;
	 }
      }
      cout << fixed << showpoint << setprecision(2);
      cout <<"Current Fine Amount:  $" <<libPatPtr->getFineAmount()<<endl <<endl;
}
/**
 * Function:  to view a library item information
 * Parameters:  takes the string id of the library item
 * ***/
void Library::viewItemInfo(string itemID){
   int found;
   for (int i = 0; i < holdings.size(); i++){ //Search for the location of item
      string temp = holdings.at(i)->getIdCode();
      if (temp == itemID)
	 found = i;
   }
   LibraryItem *libItem = holdings.at(found);//sets pointer & returns information
   cout <<"Holdings information: "<<endl<<endl;
   libItem->returnInformation();
   
   //Block of if else if statements for the location of item, gives various responses
   if(libItem->getLocation() == 0){
      cout <<"Location:  On the shelf" << endl;//On Shelf
      }
   
   else if (libItem->getLocation() == 1){ //Hold Shelf
      cout <<"Location:  On HOLD Shelf"<<endl;
      Patron* pWhoWant = libItem->getRequestedBy(); //and if there's a request
      if (pWhoWant != NULL){
	 cout <<"Requested by:  " <<pWhoWant->getName()<<endl;
      }
   }
   else if(libItem->getLocation() == 2){//Checked out
      cout <<"Location:  Checked Out" <<endl;
      Patron* pWhoGot = libItem->getCheckedOutBy();
      cout <<"Checked out by: " << pWhoGot->getName()<<endl;
      cout <<"Date Checked Out: " << libItem->getDateCheckedOut() <<endl;
      int remaining = (currentDate - libItem->getDateCheckedOut());
      if (remaining > libItem->getCheckOutLength()){ //And various options for due date if checked out
	 cout <<"Due back:  OVERDUE" <<endl;
	 }
      else if( remaining == libItem->getCheckOutLength()){
	 cout <<"Due back:  TODAY" <<endl;	    
	 }
      else{
	 cout <<"Due back:  "<< libItem->getCheckOutLength() - remaining <<" days" <<endl;
	 }
      Patron*pWhoWant = libItem->getRequestedBy();//And if checked out, if there's a request
      if (pWhoWant != NULL)
	 cout <<"Requested by:  " <<pWhoWant->getName()<<endl;
      else
	 cout <<"Requested by:  NONE" <<endl;
   }
   else //Just in case
      cout <<"Error." <<endl;
}
