/*************************
 * Name:  Brian Stamm
 * Date:  2.1.15
 * Description:  This is caesar.cpp.  1 of 1.  This is a simple encoding program
 * that takes an entered cstring from the user and then spits out
 * an encoded one.
 *************************/

#include <iostream>
#include<cstring>
#include <string>

using namespace std;

char alpha[27] ="abcdefghijklmnopqrstuvwxyz";  //Key for the encoding

string encipher(int, char *a);  //Proto function, more below

int main(){

   int offset;
   char words[100];
   string newPhrase;
//Basic instructions
   cout <<"This is a simple encoding program called a Caesar cipher." <<endl;
   cout <<"It will ask you for a phrase, and then translate that into" <<endl;
   cout <<"a code NO ONE can crack!  Then it will ask for how big of" <<endl;
   cout <<"an offset from a you want.  If you pick 1, a will be replace" <<endl;
   cout <<"b.  If you pick two, a would be replaced by c, and so forth." <<endl;
   cout <<"Enjoy!" <<endl;
   cout <<endl;

   //Getting the phrase user wants to translate
   cout << "What would you like to use as a string: ";
   cin.getline(words, 100);
   
   //Getting the offset
   cout <<endl;
   cout <<"What would you like the offset to be: ";
   cin >> offset;

//Function that returns the new phrase
   newPhrase = encipher(offset, words);
   
   //Returning the new phrase
   cout <<endl;
   cout << "New phrase: " <<endl;
   cout << newPhrase << endl;
  
   return 0;
}
/*****
 * This function will cycle through each character of the cstring the user
 * inputted, and depending on the value of it, it will either replace it
 * or just reinsert the character.
 * parameters:  int and array, int is the offset user wants for the coding
 * and the array is the cstring.
 * ********/


string encipher(int change, char *phrase){
   int i, j, k, diff;  //each are counters or holders
   string newPhrase = "";  //the string to hold the new phrase the is enciphered
   for (i = 0; i<= strlen(phrase); i++){  //loop to go through cstring w/i
      char temp;
      temp = phrase[i];  //takes character out of string at i into holder
      if (isalpha(temp)){  //If string that tests what the temp is, first if an alphabet
	    if(islower(temp)){  //then if it's lower case 
	       for (j=0; j<= strlen(alpha); j++){  //Loop to go through key w / j
		  if (alpha[j] == temp){  //Determines place of letter in key
		     k = j; 
		     k += change; //sets new int as new position for new phrase
		     if (k > 25){  //if statement in case if offset larger than z
			diff = k - 25;
			temp = alpha[diff - 1]; //Replaces temp with new letter
			newPhrase += temp;  //Adds new letter to holder string
			break;// break to do it again.
		     }
		     else{ //  Else statment if offset not more than z
			temp = alpha[k];
			newPhrase +=temp;
			break;
		  }}}}
	    else if(isupper(temp)){  //Same type of loop as above, but for upper case
	       temp = tolower(temp);  //  makes it lower case for the key and to replace 
	       for (j=0; j<= strlen(alpha); j++){ //with upper before put in string
		  if (alpha[j] == temp){
		     k = j;
		     k+= change;
		     if (k > 25){
			diff = k - 25;
			temp = alpha[diff - 1];
			newPhrase += temp;
			break;
		     }
		     else{
			temp = alpha[k];
			newPhrase += toupper(temp);
			break;
		  }}}  
		     }}
      else if (isdigit(temp)){ //If a digit, replaces with same digit
	 newPhrase += temp;
	 }
      else if (ispunct (temp)){//Same as above, puncutation
         newPhrase += temp;
      }
      else if (isspace(temp)){//Same, whitespace
         newPhrase += temp;
      }
   }
   return newPhrase; //returns the phrase when done
}
