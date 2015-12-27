/*******
 * Name:  Brian Stamm
 * Date:  2.8.15
 * Description:  This program shows the different/similarity  between both the selection and bubble
 * sort.  In the program there is an array of random numbers created and copied.  One copy is sorted
 * through a bubble array, then next through a selection sort.  This is done for progressively 
 * increasing size of arrays.  In this weeks exercises, I explain each sort in length, so
 * that is not covered in the comments here.  More will be detailed in the reflection paper,
 * especially about the big O and run time.
 * *********/

#include<iostream>
#include<cstdlib>
#include<ctime>
#include <cmath>

using namespace std;

void selectSort(int[], int);  //prototype for selection sort
void bubbleSort(int[], int);  //prototype for bubble

int main(){
   int counter = 0; //counter, started at zero
   int i, random; // ints used in program
   
   //Basic instructions
   cout <<"This program is comparing the selection sort to the bubble sort." << endl;
   cout <<"It will print out the number of comparisons done in each sort." << endl;
   cout <<"When the program is complete, it will notify it is done." <<endl;
   cout <<endl;

   /*  This is a do while loop.  It uses the counter to control the amount of
    *  loops done.  In the loop, arrays are created, randomly filled with 
    *  ints, and then sent to the sorting functions.  At the end of hte loop each
    *  array is deleted.  Then the loop is either continued or ended.
    *  **/

   do{
      int *selectArray, *bubbleArray;  //two arrays made
      int size = pow(10, (counter+2)); //using counter to increase the size.  
      int bubbleCount = 0;
      int selectCount = 0;
      
      cout <<"This is the current size of the arrays: " <<size <<endl; //states size
      cout <<endl;

      selectArray = new int[size]; //makes arrays the correct size
      bubbleArray = new int[size];

      srand(time(0)); //seeds random
      
      /*  This for loop uses rand to fill the variable random.  Then
       *  that variable is used to fill both the bubble and selection arrays
       *  to ensure they are the same. 
       *  */

      for (i = 0; i < size; i++){ 
         random = rand();
	 selectArray[i] = random;
	 bubbleArray[i] = random;
      }

      selectSort(selectArray, size);  //function, returns the iterations
      bubbleSort(bubbleArray, size);

      counter++;
      
      delete [] selectArray;  //deletes the arrays
      delete [] bubbleArray;

   }while (counter <4); //continues loop while counter less than four
   //This is more done to ensure that the program does an array the size of 100,000
   //since the counter is used to create the size of the array

   cout <<"Now the program is done.  Enjoy your day." <<endl;
   
   return 0;
}

void selectSort(int array[], int biggie){  //This is the basic selection sort, found in text book
   int startScan, minIndex, minValue;  //Biggie is size
   int counterA = 0;
   int counterB = 0;
   for (startScan = 0; startScan < (biggie -1); startScan ++){
      minIndex = startScan;
      minValue = array[startScan];
      counterA++;
      for(int index = startScan + 1;index < biggie; index++){
	 if (array[index] < minValue){
	    minValue = array[index];
	    minIndex = index;
	    counterB++;
	 }
      }
      array[minIndex] = array[startScan];
      array[startScan] = minValue;
   }
   cout <<"For the Selection Sort:" <<endl;
   cout <<"Outer For Loop Counter: " <<counterA <<endl;
   cout <<"Inner For Loop Counter: " <<counterB <<endl;
   cout <<endl;
}

void bubbleSort(int array[], int smalls){  //This is the basic bubble sort, found in text book
   int temp, current, plusOne; //Smalls is size.  Figure size and biggie have been used, why not smalls?
   bool swap;
   int counterA = 0;
   int counterB = 0;
   do
   {  swap = false;
      for(int i = 0; i < (smalls-1); i++){
         current = array[i];
	 plusOne =array[i+1];
	 counterA++;
	 if (current > plusOne){
	    temp = array[i];
	    array[i +1] = temp;
	    swap = true;
	    counterB++;
	 }
      }
   }while(swap);
   cout <<"For the Bubble Sort:" <<endl;
   cout <<"Outer For Loop Counter: " <<counterA <<endl;
   cout <<"Inner If Statement Counter: " <<counterB <<endl;
   cout <<endl;
}
