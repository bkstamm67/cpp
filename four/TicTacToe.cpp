/**
 * Name:  Brian Stamm
 * Date:  2.1.15
 * Description:  TTT.cpp.  Final 4 of 4
 * This takes the other 3 files together to make the tic tac toe game
 * **/

#include <iostream>
#include "Board.hpp"
#include "TicTacToe.hpp"

using namespace std;

TicTacToe::TicTacToe(char p, Board){  //Constructor
   Board funTime;
   setPlayer(p);
   funTime.setGame(0);
}

char TicTacToe::getPlayer(){  //Gets player, used for turns
   return playerXO;
}

void TicTacToe::setPlayer(char who){  //Sets the player
   playerXO = who;
}

void TicTacToe::play(char p, Board funTime){  //The core of the game.  
   int game = funTime.getGame();  //For while loop, should be zero when starting
   setPlayer(p);  //Sets the player, in case there was an issue
         
   while (game == 0){  //While loop for game, 0 progress.  1 draw, 2 x win, 3 o win
      int x, y;
      funTime.print();  //Prints board
      char p = getPlayer();
      cout <<endl;
      cout << p << " player's turn!" <<endl; //States player's turn
      
      cout <<"Row: ";  //get's row coordinate
      cin >> x;
      while (x < 0 || x > 3){//To catch errors
	 cout << "I'm sorry, I didn't understand." << endl;
         cout << "X - Coordinate: ";
	 cin >> x;
      }

      cout <<"Column: ";//get's columns
      cin >> y;
      while (y < 0 || y > 3){ //Error catcher
	 cout << "I'm sorry, I didn't understand." << endl;
	 cout << "Y - Coordinate: ";
	 cin >> y;
      }

      if (funTime.makeMove(y, x, p)){ //makes the move, if spot taken, then goes again
	 char p = getPlayer(); //gets player to switch
	 if (p == 'x'){ //way to switch
	    setPlayer('o');
	 }
	 else{
	    setPlayer('x');
	}
      }
      else{ //If false (spot taken), returns false, no switch of players and error message
         cout <<"I'm sorry, that spot is taken." <<endl;
	 cout <<"Try again!" <<endl;
	 cout <<endl;
      }
      game = funTime.gameState(); //game state checked after move, value assigned to game
      
      
      if (game == 1){ //And messages depending on game value
         cout <<"AAAHHH, a draw!" <<endl;
         cout <<"I guess if you want to winner, you have to play again...." <<endl;
         cout <<endl;
      }
   
      else if (game == 2){
         cout <<"And that's a winner folks!" <<endl;  //Ode to Jack Buck.
         cout <<"Congrats player X!" <<endl;
	 cout <<endl;
      }

      else if (game == 3){
         cout <<"It might be.  It could be.  It is!" <<endl;//Ode to Harry Caray
         cout <<"Congrats player O!" <<endl;
	 cout <<endl;
     }
   }
}

int main(){
   char p;
   int dog;  //was the name when checking for errors, too lazy to change it

   cout <<"This is a simple tic tac toe game." <<endl;
   cout <<"Who will start (x or o): ";
   cin >> p;

   Board funTime;  //initial board
   funTime.setGame(0);//starts board
   TicTacToe ttt(p, funTime); //starting game

   do{  //Do loop, starts game
      ttt.play(p, funTime);  //game loop

      cout <<"Do you want to play again?" <<endl;  //If want to play again
      cout <<"(1) for yes, or any other number for no: ";
      cin >> dog;

   
   } while (dog == 1);

   cout <<"Thanks for playing!" <<endl;
   
   return 0;
}

