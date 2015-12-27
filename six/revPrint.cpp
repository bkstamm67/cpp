/*******
 * Name:  Brian Stamm
 * Date:  2.15.15
 * Description:  This program will ask the user for an array size and inputs for array.  It
 * will then use a recursive function to print the elements of that array back to the user
 * in reverse order.  Enjoy the inputting!
 * *********/

#include<iostream>

using namespace std;

void recursiveFunction(int[], int);  //Prototype for the recursiveFunction

int main(){
   int *darray; //creates pointer to array
   int size, i; //for other variables

   //Basic instructions
   cout <<endl;
   cout <<"This program will be asking you for how many numbers" <<endl;
   cout <<"you will be entering.  Then, storing those number and printing" <<endl;
   cout <<"them back out in reverse order." <<endl << endl;
   
   //Gets size of array from user
   cout << "How many numbers: ";
   cin >>size;

   darray = new int[size]; //creates array

   //For loop to get input for array
   cout <<"Enter numbers: " <<endl;
   for (i = 0; i <size; i++){
      cout <<"Number "<<(i+1)<<": ";
      cin >> darray[i];
   }

   //Recursive function
   recursiveFunction(darray, size);

   //Deletes the array
   delete [] darray;

   return 0;
}
/*******
 * Function:  recursiveFunction, it will print out the elements of an array
 * in the reverse order by calling itself until it reaches the base case
 * which is 0.  It will also not change the array at all.
 * Parameters:  int array, int big.
 * ******/

void recursiveFunction(int array[], int big){
   int i = big - 1;
   if(i >= 0){
      cout << array[i] <<endl;
      recursiveFunction(array, i);  //This is the recursive part.
   }
}

