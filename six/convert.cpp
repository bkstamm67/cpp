/*******
 * Name:  Brian Stamm
 * Date:  2.15.15
 * Description:  This program converts a binary to a decimal number and vice versa.
 * It uses recursive funcitons to do so and has some helper functions as well.
 * *********/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>

using namespace std;

/*******
 * I tend to like having all the prototypes at the top of the program with all the functions 
 * at the bottom.  All are here, explanation of function will be below.
 * *****/

void instructions(); 
void menu();
bool decimalCheck(string);
bool binaryCheck(string);
int binary2Decimal(string, int);
int binary2Decimal(string, int, int, int);
string decimal2Binary(string);
string decimal2Binary(int, int);
string decimal2Binary(int, int, string);

int main(){
   int choice, i;
   string string;
   
   instructions();

   do{
      menu();
      cin >>choice;
      switch(choice){
	 case 1:  cout <<endl;
		  cout <<"Number you want to convert: ";  //base10 to base2
		  cin >> string;
		  if (decimalCheck(string)){
		     cout <<"The new binary is: " <<decimal2Binary(string)<< endl <<endl;;
		     break;
		  }
		  else{
		     cout <<"Error.  Number inputted not in correct form." <<endl; 
		     cout <<"Please try again"<< endl << endl;
		     break;
		  }
	 case 2:  cout <<endl;
		  cout <<"Binary number you want to convert: "; //base2 to base10 
		  cin >> string;
		  if (binaryCheck(string)){
		     i = string.length();
		     cout <<"The number as a decimal is: " << binary2Decimal(string, i)<<endl <<endl;;
		     break;
		  }
		  else{
		     cout <<"Error.  Number inputted not in the correct form." <<endl;
		     cout <<"Please try again." << endl <<endl;;
		     break;
		  }
      }
   } while(choice != 3);

   cout <<"Thanks for playing!" <<endl;

   return 0;
}
/*Description:  Basic instructions for user.
 * Parameters:  None.
 * **/
void instructions(){
   cout <<endl;
   cout <<"This program is designed to convert a base 2 or base 10 number" <<endl;
   cout <<"into the other.  Be sure to enter the appropriate positive integer" <<endl;
   cout <<"value, or there will be an error message.  You can convert as many" <<endl;
   cout <<"numbers as you would like.  Enjoy!" <<endl <<endl;
}

/* Description:  Menu for user, including Choice selection print out
 * Parameters:  None.
 * **/
void menu(){
   cout <<"Menu:" <<endl <<endl;
   cout <<"1.  Decimal to binary." <<endl;
   cout <<"2.  Binary to decimal." <<endl;
   cout <<"3.  End program." <<endl <<endl;
   cout <<"Choice: ";
}

/* Description:  Checks user input for decimal
 * Parameter:  string - input from user, is number they want to convert to base2, 
 * currently saved as a string
 * **/
bool decimalCheck(string str){
   for(int i=0; i<str.length(); i++){  //goes through each item in string to make sure all digits
      if(!(str.at(i)>='0' && str.at(i) <= '9'))
	 return false;
   }
   return true;
}

/* Description:  Checks user input for binary, almost same as previous
 * Parameter:  string - input from user, is number they want to convert to base10
 * currently saved as a string
 * **/
bool binaryCheck(string str){
   for(int i=0; i<str.length(); i++){
      if(!(str.at(i)=='0' || str.at(i) == '1'))//difference from previous function, only 1&0 okay
	 return false;
   }
   return true;
}

/* Description:  Helper function which adds counter and sum to next step
 * Parameters:  string, which is the base2 number, the length of the string
 * **/
int binary2Decimal(string string, int length){
   return binary2Decimal(string, length, 1, 0);
}

/*Description:  This function goes through the string and sums up the total
 * to return a base10 number.  It uses the sum to keep track of the number, and the
 * counter to determine the power of 2 and if through the entire string
 * Parameters:  string (base2 number), length (lenght of string), counter, sum
 * ***/
int binary2Decimal(string string, int length, int counter, int sum){
   if (counter == length){ //Base case.  If this true, at end of string
      if (string[length-1] == '0'){
	 return sum;
      }
      else
	 return sum+1;
   }
   else{
      if (string[counter-1] =='0'){
         return sum + binary2Decimal(string, length, counter+1, sum);  //Recursive part
      }
      else{
         return sum + pow(2,(length - counter)) + binary2Decimal(string, length, counter+1, sum); //Recursive part
      }
   }
}

/* Description:  This is a helper function, takes the string base10 number, converts it
 * to an int and then passes it to the next helper function for the next step in the 
 * journey of a base10.
 * Parameters:  string, which is the number inputted by user
 * **/
string decimal2Binary(string string){
   int number = atoi(string.c_str());
   return decimal2Binary(number, 0);
}

/* Description:  This function is also a helper function.  It determines the highest power of
 * two needed, since this was another step in the process.  Then calls recursive function.
 * Parameters:  int number, which came from previous function - base10 number to be converted, and
 * counter, to keep track of power of two.
 * **/
string decimal2Binary(int number, int counter){
   int artemis = pow(2, counter); 
   if (artemis > number){
      string emptyString = ""; //creates the empty string to pass to next function
      return decimal2Binary(number, counter-1, emptyString); //Actual recursive funct
   }
   else if(artemis == number){
      string emptyString = ""; //Creates empty string...
      return decimal2Binary(number, counter, emptyString);
   }
   else{
      return decimal2Binary(number, counter+1);
   }
}

/*Description:  This is the recursive function taking the base10 and converting into
 * a base2 (as a string variable).  It uses the previous pieces from the other functions
 * to complete the task.  
 * Parameters:  sum, which is the number wanting to convert.  It changes each function call;
 * counter, keeps track of the highest power of 2 and counts back to 0, to ensure the proper 
 * amount of 0&1 in the string; string - to be actual base2 number.
 * ***/
string decimal2Binary(int sum, int counter, string binaryString){
   if (counter == 0){ //Base case
      if (sum == 1)
         return binaryString+='1';
      else
         return binaryString+='0';
   }/**recursive part.  creates apollo to see if 1 or 0 goes at this point of binaryString,
      and then calls function again.  Depending on result, either subtracts apollo from
      sum or not.  Continues subtracting counter and adding value to string***/
   else{
      int apollo = pow(2, counter);
      if (sum >= apollo)
	 return decimal2Binary((sum - apollo), counter-1,binaryString+='1');
      else
	 return decimal2Binary(sum, counter-1, binaryString+='0');
   }
}
