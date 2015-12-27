/*******
 * Name:  Brian Stamm
 * Date:  2.8.15
 * Description:  This program will sort spheres using the class Sphere, which was 
 * created in a previous exercise.  This will sort those spheres through a bubble sort,
 * which was used from the version in the text in Chapter 9.  
 * *********/

#include<iostream>
#include "Sphere.hpp" //Needed to use the class Sphere

using namespace std;

void bubbleSort(Sphere[], int);  //bubble sort prototype function, more later

int main(){

   int size, i;
   double radius;
   Sphere *darraySphere;  //Creates a dynamic array of spheres

   //Basic instructions
   cout <<"This program will take the radii of spheres," <<endl;
   cout <<"and then sort them for you.  It will also show" <<endl;
   cout <<"the sphere's volume.  Enjoy!" <<endl;
   cout <<"How many spheres: ";
   cin >> size;//size of array
   cout <<endl;

   darraySphere = new Sphere[size];  //creates the array based on input from user
   
   cout << "Enter the radius of each sphere." <<endl;
   for (i = 0; i < size; i++){ //For loop to input the radii of spheres into the array of Spheres
      cout <<"Sphere " <<(i+1) <<" raduis: ";
      cin >> radius;
      Sphere sphereInput(radius);  //creates the sphere
      darraySphere[i] = sphereInput; //inputs that sphere into the array of spheres
   }
   
   bubbleSort(darraySphere, size);  //Bubble sort, sorts and prints sorted spheres

   delete [] darraySphere; //deletes the dynamic array

   return 0;
}
/***
 * Function:  bubbleSort.  This will sort the array of spheres into lowest to highest.
 * This sort is found in the text book, chapter 9, but also in our lectures for this week
 * and on the internext.  Some of the same variables have the same name becaues of ease for understanding.
 *
 * What this function does is compare element n to n+1.  If n is higher than n+1, it swaps them.
 * It continues to go through the array while swaps are being made.  At the end it prints the spheres
 *
 * Parameters:  an array (it's an array of spheres, and int, which is size)
 * ***/

void bubbleSort(Sphere array[], int amount){
   Sphere temp, current, plusOne; //temp sphere holders
   bool swap; //to confirm there was a swap that happened
   //Starts as a do loop
   do
   { swap = false;
      for (int i = 0; i < (amount - 1); i++){ //For loop to make sure it goes through entire array
         current = array[i];  //temp variable for comparision
	 plusOne = array[i +1];
	 if(current.getRadius() > plusOne.getRadius()){ //Compares one radius to the next
	    temp = array[i];  //If true, then it swaps it
	    array[i] = array[i +1];
	    array[i + 1] = temp;
	    swap = true; //and returns a true value.
	 } 
      } 
   } while (swap);

   cout <<endl;
   cout <<"Sorted Spheres: " <<endl; //This prints the spheres
   for (int i = 0; i < amount; i ++){
      cout <<"Sphere " <<(i+1) << ": ";
      Sphere current = array[i];
      cout<<endl;
      cout << "Radius: " << current.getRadius() <<endl;  //Uses sphere methods, same as above
      cout <<"Volume: " <<current.getVolume() <<endl; 
   }
}
