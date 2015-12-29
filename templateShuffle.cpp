/*******
 * Name:  Brian Stamm
 * Date:  3.1.15
 * Description:  This shuffles an array of inputted ints into a random
 * order.  The function uses an adapted KFY shuffle (more about it below).
 * 
 * Need to go through and correct for current assignment.
 *
 * *********/

#include<iostream>
#include <string>
#include<cstdlib>  //Used for the rand
#include<ctime>  //Used to seed rand

using namespace std;

//Prototypes for functions
template<typename T> 
void shuffleFunction(T arr[], int size);
void instructions();
void menu();

int main(){

   int choice, size;
   
   instructions(); //basic instructions, more later
   
   //Simple loop so user can create numerous shuffled arrays
   do{
      cout <<endl;
      menu(); //basic menu, more later
      cin >> choice;
      cout <<endl;
      switch(choice){
	 
	 //First case for strings.  Within each case, creates an array a size
	 //user determines.  Then passes this array and size to function.
	 //function then fills and shuffles it.  Deletes array at end 
	 //each time, allowing loop to continue on w/o issue
	 case 1: cout <<"How many items: ";
		 cin >> size;
		 string *stringArray;
		 stringArray = new string[size];
		 shuffleFunction(stringArray, size);
		 delete [] stringArray;
		 break;
	 
	 //Second case for ints
	 case 2: cout <<"How many items: ";
		 cin >> size;
		 int *intArray;
		 intArray = new int[size];
		 shuffleFunction(intArray, size);
		 delete [] intArray;
		 break;
	 
	 //Third case for doubles
	 case 3: cout <<"How many items: ";
		 cin >> size;
		 double *doubleArray;
		 doubleArray = new double[size];
		 shuffleFunction(doubleArray, size);
		 delete [] doubleArray;
		 break;
      }
   }while (choice != 4); //exit choice

   cout <<endl;
   cout <<"Thanks for shuffling with us!" <<endl;

   return 0;
}

/********************
 * Function:  shuffleFunction
 * Parameter:  an array and an int, which is the size
 * This is a template function, which can take a variety of types of arrays
 * and then shuffles them into a random order.  As mentioned in the previous 
 * program this is based off of, I found the Knuth_fisher_Yates shuffle and
 * variations of it on numerous websites.  
 * *****************/

template<typename T>
void shuffleFunction(T arr[], int size){
   //First block fills array.  Since this is repeatative, put it within
   //the loop rather than have it in each case
   T thing;  //creates variable thing, can be whatever type is passed in
   cout <<endl;
   cout <<"Filling the array." <<endl <<endl;
   for (int i = 0; i < size; i++){
      cout << "Number " << (i+1) << " : ";
      cin >> thing;
      arr[i] = thing;
   }
   
   srand(time(0)); //seeding random
   
   //Shuffles array
   for (int j = size -1; j > 0; j--){ //based off of Knuth-Fisher-Yates shuffle
      int b = rand() % (j+1);
         if (b != j){
	    T temp; //creates temp, which is same type as items in array
	    temp = arr[b];
	    arr[b] = arr[j];
	    arr[j] = temp;
	 }
   }
   
   cout <<endl;
   cout <<"Here is your shuffled array: " <<endl <<endl;; //Prints array
   for (int i = 0; i < size; i++){
      cout << "Number " << (i+1) << ": " << arr[i] <<endl;
   }
}

/* Function:  basic instructions
 * Parameter:  none
 * ***/

void instructions(){
   cout <<endl;
   cout <<"This program will shuffle a list of items given to it" <<endl;
   cout <<"into a random order.  It will first ask you for what type" <<endl;
   cout <<"of items, then how many you would want to enter.  Then, you" <<endl;
   cout <<"will enter them.  Once finished, the program will print out" <<endl;
   cout <<"those numbers shuffled.  Enjoy!" <<endl;
   cout <<endl;
}

/* Function:  Menu.  Menu for user
 * Parameters:  none
 * **/

void menu(){
   cout <<"Menu: " <<endl;
   cout <<endl;
   cout <<"1. String Array " <<endl;
   cout <<"2. Int Array " <<endl;
   cout <<"3. Double Array " <<endl;
   cout <<"4. End " <<endl;
   cout <<endl;
   cout <<"Choice: ";
}
