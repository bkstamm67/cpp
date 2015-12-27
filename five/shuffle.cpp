/*******
 * Name:  Brian Stamm
 * Date:  2.8.15
 * Description:  This shuffles an array of inputted ints into a random
 * order.  The function uses an adapted KFY shuffle (more about it below).
 * *********/

#include<iostream>
#include<cstdlib>  //Used for the rand
#include<ctime>  //Used to seed rand

using namespace std;

void shuffleFunction(int[], int);  //Shuffle prototype function.  More about it later

int main(){

   int *darray;  //Dynamic array
   int i, number, size;  //Ints used in program

   //Basic instructions
   cout <<"This program will shuffle a list of numbers given to it" <<endl;
   cout <<"into a random order.  It will first ask you for how many" <<endl;
   cout <<"numbers you wish to input and then to enter them.  Afterward" <<endl;
   cout <<"it will print out those numbers shuffled.  Enjoy!" <<endl;
   cout <<endl;
   cout <<"How many numbers: ";
   cin >> size;  //used to create array

   darray = new int[size]; //creates array

   cout << "Entering numbers: " <<endl;  //A for loop to enter users numbers into array
   for (i = 0; i < size; i++){
      cout << "Number " << (i+1) << " : ";
      cin >> number;
      darray[i] = number;
   }

   shuffleFunction(darray, size);  //shuffle function

   delete [] darray; //deletes array

   return 0;
}

/********************
 * Function:  shuffleFunction
 * Parameter:  int array and an int, which is the size
 * What this function does is take an array of ints and then
 * shuffles them into a random order.  In searching for ways to do this, there were some 
 * methods that cstdlib had that could have been used, but also posted on Piazza, cplusplus.com,
 * and stacksoverflow forums, and various coding blogs, they refered to the Knuth_fisher_Yates shuffle.
 * This shuffle apparently is unbaised, which makes it very useful.  It was designed by statisticians
 * smarter than myself.  Variations of this code was found on numerous websites.  
 * *****************/

void shuffleFunction(int inputArray[], int bigness){  //takes an array and its size
   
   srand(time(0)); //seeding random
   
   for (int j = bigness -1; j > 0; j--){ //based off of Knuth-Fisher-Yates shuffle
      int b = rand() % (j+1);
         if (b != j){
	    int temp;
	    temp = inputArray[b];
	    inputArray[b] = inputArray[j];
	    inputArray[j] = temp;
	 }
   }
   cout <<"Here is your shuffled numbers: " <<endl; //Prints array
   for (int i = 0; i < bigness; i++){
      cout << "Number " << (i+1) << ": " << inputArray[i] <<endl;
   }
  
}
   


