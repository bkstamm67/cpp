/***
 * Name:  Brian Stamm
 * Date: 2.1.5
 * Description:  This program will sort 3 values in ascending order using pointers.
 * **/

#include <iostream>

using namespace std;

void sorting(int *x, int *y, int *z);  //This is the prototype w pointers for the sorting function.  
//More info below

int main(){

   int num1, num2, num3;  // 3 ints for variables

   //This is basic instructions for user
   cout <<"This is a basic sorter.  It will ask you for" <<endl;
   cout <<"3 different integers, and then it will print" <<endl;
   cout <<"out those numbers sorted, from lowest to highest" <<endl;
   cout <<"Enjoy!" <<endl;

   //Next block asks user for numbers to be sorted
   cout <<"Input first number: ";
   cin >> num1;
   cout <<"Input second number: ";
   cin >> num2;
   cout <<"Input third number: ";
   cin >> num3;
   cout <<endl;  //To add a space
   
   //Reprints numbers
   cout <<"Here are the values as entered: " <<endl;
   cout << num1 << "\t" << num2 << "\t" << num3 << endl;
   cout <<endl; //to add a space
   
   cout <<"And here are the values sorted:" <<endl;
   sorting (&num1, &num2, &num3); //Sorting function, sending address of num# variables to function
   cout <<"Thanks!" <<endl;

   return 0;
}

/*
 * Description:  This function uses pointers as the parameters.  It will sort the 3 values
 * from lowest to highest through a series of if/else/ else if statements.
 * Parameters:  pointer x, pointer y, pointer z, all of which are pointing to the numbers 
 * the user inputted.
 * */

void sorting (int *x, int *y, int *z){
   if (*x < *y){
     if (*x < *z){
       if (*y < *z){
          cout << *x << "\t" << *y << "\t" << *z <<endl;
       }
       else{
          cout << *x <<"\t" << *z <<"\t" << *y <<endl;
       }
     }
     else{
        cout << *z << "\t" << *x << "\t"<< *y <<endl;
     }
   }
   else if(*x > *y){
      if (*x > *z){
	 if (*z > *y){
	    cout << *y << "\t" << *z << "\t"<< *x <<endl;
	   }
	 else{
	    cout << *z << "\t" << *y << "\t"<< *x <<endl;
	   }
	}
	else {
	   cout << *y << "\t" << *x << "\t"<< *z <<endl;
	}
     }
}
