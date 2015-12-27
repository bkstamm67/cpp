/*******
 * Name:  Brian Stamm
 * Date:  2.15.15
 * Description:  This program will ask the user for how many numbers they have to add up
 * and then enter those numbers into a dynamic array.  Then it will send the size and array 
 * to a recursive function that sums the values in the array..
 * *********/

#include<iostream>

using namespace std;

double recursiveFunction(double[], int); 

int main(){

   double *darray;
   double sum;
   int size, i;

   //Basic instructions
   cout <<endl;
   cout <<"This program will take the numbers you input and then total" <<endl;
   cout <<"them for you.  First, we have to know how many numbers you" <<endl;
   cout <<"want totaled.  So......" <<endl <<endl; 
   
   //Getting size of array
   cout << "How many numbers: ";
   cin >>size;

   //Creating the array
   darray = new double[size]; 

   //Getting user input for creation of array
   cout <<"Enter numbers - " <<endl;
   for (i = 0; i <size; i++){
      cout <<"Number "<<(i+1)<<": ";
      cin >> darray[i];
   }
   //Since function has a return value, created sum variable
   //going to recursive function
   sum = recursiveFunction(darray, size);  

   cout <<endl;
   cout <<"Sum is: " << sum << endl << endl;  //Prints total from recursive function
   

   cout <<"That's all folks!" <<endl;  //Ode to Porky.

   delete [] darray;  //Deletes array at end of program

   return 0;
}

/*******
 * Function:  recursiveFunction.  This function will take an array and int (size of array)
 * and then recursively obtain the sum of all the elements in the array.
 * Parameters:  double array (the array to be totaled) and int, which is the size of the
 * array
 * ********/


double recursiveFunction(double array[], int big){
   /**
    * variable sum has to be static to keep the running total, since the recusive function
   continues to call itself each time through the array
   static double sum = 0;  
   int i = big - 1;
   if (i >= 0){
      recursiveFunction(array, i);
      sum += array[i];
   }
   return sum;
   Had this originally, but unsure if using static variable was intent of exercise.  
   ****/

   double sum;
   int i = big - 1;  //also works.  If not using, need to delete double sum parameter 
   if (i == 0)
      return array[i];
   else
      return sum + array[i] + recursiveFunction(array, i);
}
