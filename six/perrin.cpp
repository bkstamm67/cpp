/*******
 * Name:  Brian Stamm
 * Date:  2.15.15
 * Description:  This program asks users for an integer, and then goes that far 
 * down the Perrin sequence.  It uses a recursive function to determine, and it
 * prints off a x per instructions.
 * *********/

#include<iostream>

using namespace std;

int perrinFun(int);

int perrinFunRec(int, int, int, int);

int main(){

   int pNum;

   cout << "This program will ask you for an integer, and with" <<endl;
   cout <<"that integer, it will determine what number is that far" <<endl;
   cout <<"down the Perrin sequence.  And it'll print out alot of x's." <<endl;
   cout <<"Enjoy...." <<endl <<endl;

   cout << "How far down the Perrin sequence you want to go: ";
   cin >> pNum;
   cout <<endl;
   
   cout <<"Here is Perrin number " <<pNum <<" , which is that far down the sequence:  " <<perrinFun(pNum) <<endl;
   cout <<"Thanks for playing!" <<endl;
   cout <<endl;

   return 0;
}

int perrinFun(int num){
   return perrinFunRec(num, 3, 0, 2);
}

int perrinFunRec(int counter, int one, int two, int three){
   if (counter == 1){
      return two;
   }
   else{
      cout << "x" <<endl;
      return perrinFunRec(counter -1, two, three, one + two);
   }
}
