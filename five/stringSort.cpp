/*******
 * Name:  Brian Stamm
 * Date:  2.8.15
 * Description:  This program sorts an array of strings in alphabetical order
 * using a selection sort.  The template is that the text book uses in Chapter 9.
 * *********/

#include<iostream>
#include <cctype>
#include <string>


using namespace std;

void selectionSort(string[], int);

int main(){
   string *darray;
   int size, i;

   cout <<"This program will take however many phrases or words you" <<endl;
   cout <<"decide to input and alphabetize them.  Enjoy!" <<endl;
   cout <<endl;
   cout << "How many phrases do you wish to alphabetize: ";
   cin >> size;

   darray = new string[size];

   cout << "Please enter the phrases: " << endl;
   cin.ignore();
   for (i = 0; i < size; i++){
      string stringy;
      cout <<"Phrase " << (i+1) <<": ";
      getline(cin, stringy);
      darray[i] = stringy;
   }

   selectionSort(darray, size);
   
   delete [] darray;

   return 0;
}

/******************
 * Function:  selectionSort
 * Parameter:  And string array and an int, which is suppose to be its size
 * This will go through the array and sort it.  It starts at the first position,
 * classifies the first one array as the lowest value, and then checks it compared 
 * to the rest of the array, finding the one that is the lowest.  Once at the last
 * position, whatever is the lowest is swapped with the first one.  Then it continues
 * through the rest of the array from the second position. 
 *
 * Also, I used the template from the text book, using some of the same variable names to ensure
 * the correct form for this sort.  Beside the text, the lecture also had the same sort (different
 * variable names), and several webpages had the same sort. 
 * ****************/

void selectionSort(string array[], int bigness){  //bigness is size
   string minValue; //sets the low value, also stores the original state of the string
  //To make sure capitalization stays the same 
   int startScan, minIndex;  //the start of the array and what the index value of minValue

   for (startScan = 0; startScan < (bigness - 1); startScan++){  //For loop to go through array
      minIndex = startScan; //Sets the minIndex the same as the starting array position
      minValue = array[startScan]; //Sets the minValue as athe same as the starting array position
      /* The next variable is an empty string, and the for loop following it is used to 
       * create an all capitalized version of the string.  This allows the comparison to 
       * work and not be messed up by lower case letters.  The same is done in the next for loop as well
       * */
      string minString = ""; 
      for (int j = 0; j < minValue.size(); j++){
	 char temp;
	 temp = minValue[j];
	 minString += toupper(temp);
      }
      /* The next for loop goes through the rest of the array, capitalizing the other elements in
       * the array and comparing them to the first.  Once the lowest is found, it replaces it.  Then
       * the loop advances to the next element in the array, going down the line until the entire array
       * is sorted
       * */
      for (int index = startScan + 1; index < bigness; index++){
         string tester = array[index];
	 string testerString = "";
	 for (int b = 0; b < tester.size(); b++){
	    char temp;
	    temp = tester[b];
	    testerString += toupper(temp);
	 }
	 if (testerString < minString){
	    minString = testerString;
	    minValue = array[index];
	    minIndex = index;
	 }
      }
      array[minIndex] = array[startScan];
      array[startScan] = minValue;
   }

   cout <<endl;
   cout << "Here are the phrases, alphabetized! "<< endl; //Prints out sorted array
   for (int i = 0; i < bigness; i++){
      cout <<"Phrase " << (i+1) <<": " << array[i] <<endl; 
   }
}
