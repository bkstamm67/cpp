/*****************************
 * Name:  Brian Stamm
 * Date:  2.1.15
 * Description:  This is findMode.cpp.  1 of 1  In this program
 * the user will be asked how many numbers they have
 * and then input them to create an array(dynamic), and then
 * a function will sort it and then find the mode.
 * ****************************/

#include <iostream>
#include <algorithm>  //Needed for the sort (shown in the Lecture section)

using namespace std;

typedef int arrayType[];

int modeFinder(arrayType, int s);  //Function Prototype

int main(){

   int *array;
   int size, i, mode;

   cout << "How many numbers: ";
   cin >> size;
   
   array = new int[size];  //assigns the size to the array

   for (i = 0; i<size; i++){  //Inputs the array
      int num = 0;
      cout << "Enter number: ";
      cin >> num;
      array[i] = num;
   }

   sort(array, array + size);  //to sort array
   
   cout <<"Here is the sorted array: " <<endl;

   for (i = 0; i<size; i++){  //prints out sorted array
      cout << array[i] << endl;
   } 
   mode = modeFinder(array, size);

   cout << "Here is the mode: " << mode << endl;

   delete [] array;
   return 0;
}

/*********************
 * Function:  Finds the mode.
 * Parameters:  array
********************/

int modeFinder(arrayType array, int s){
   int count, mode, pre, j, preCount = 0;
   
   for (int i = 0; i < s; i++){         
      count = 0;
      pre = array[i];
      for (j=i; j<s; j++){
         if(pre==array[j])
	    count++;
	 else
	    break;
      }
      if (count>preCount){
         preCount = count;
	 mode = array[i];
      }
   }
   return mode;
}
