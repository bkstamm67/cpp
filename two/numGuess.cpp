/**********
 * Name:  Brian Stamm
 * Date:  1.18.15
 * Description:  This is a number guessing game - the computer generates a random number.  The
 * user has to guess the number.  While guessing the computer gives prompts telling the
 * user if the number guessed is too high or low.  
 * **********/

#include<iostream>
#include<cstdlib>
#include<ctime>

int main(){
   
   int num, guess, count = 1;

   srand(time(NULL));//seeds the random number generator

   num = rand() % 100 + 1; //creates the random number between 1 and 100

   do{  //Starts the game without a prompt or test
      std::cout << "What is your guess? ";//initial guess
      std::cin >> guess;
      if(guess > num){//if, else if comparing guess to num
         std::cout << "TOO HIGH, try again!" <<std::endl;
	 count++;  //counter to keep track of how many times person guesses
      }
      else if (guess < num){
         std::cout << "too low, try again!" <<std::endl;
	 count++;  //see above re:counter
      }
   } while (guess != num);//while loop section, continues while guess doesn't equal num

   std::cout << "CONGRATS!  You were able to guess the number!" << std::endl;
   std::cout << "And it only took you " << count <<" times!  Way to go!"<< std::endl;

   return 0;
}
