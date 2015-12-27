/*
 * Name:  Brian Stamm
 * Date:  2.1.15
 * Description:  This is Board.cpp.  2 of 4
 * A big part of the game occurs in this file as well
 * **/

#include "Board.hpp"
#include <iostream>

using namespace std;

Board::Board(){  //initializes board w 0's in all the spots
   for (int i = 0; i<3; i++){
      for(int j = 0; j<3; j++){
         barray[i][j] = 0;
      }
   }
}

bool Board::makeMove(int y, int x, char xo){  //Makes movement
   if(xo == 'x'){  //For x movement, taken from char
      if (barray[y][x] == 0 ){
         barray[y][x] = 1;
	 return true;//Check to move game forward
      }
      else{
         return false;  //Sets up loop to stop foward movement of game
      }
   }
   else if (xo == 'o'){// for o movement, same as above, but for o
      if (barray[y][x] == 0){
         barray[y][x] = (-1);
	 return true;
      }
      else{
         return false;
      }
   }
}

int Board::getGame(){ //returns the value of game
   return game;
}

void Board::setGame(int state){  //sets game value
   game = state;
} 

int Board::gameState(){  //checks the various ways to win
   int game = getGame();  //again, confirming game is 0
   int i, j, total;

   for (i = 0; i < 3; i++){  //checks rows
      total = 0;
      for (j = 0; j <3; j++){
         total += barray[j][i];
      }

   if (total == 3){  //if positive value, x win
      game = 2;
   }
   else if (total == (-3)){  //negative, o
      game = 3;
   }
   }

   for (j = 0; j < 3; j++ ){  //does same as above, but for columns....it could be reverse, I can't remember
      total = 0;
      for (i = 0; i <3; i++){
	 total += barray[j][i];
      }
      if (total == 3){
         game = 2;//x win
      }
      else if (total == (-3)){
         game = 3;//o win
      }
   }
   int total_a = barray[0][0] + barray[1][1] + barray[2][2];//totals other diag
   int total_b = barray[2][0] + barray[1][1] + barray[0][2];//Totals diag
   
   if (total_a == 3 || total_b ==3){ //Checks for diag win
      game = 2;
   }
   else if (total_a == (-3) || total_b==(-3)){  //same as above
      game = 3;
   }
   
   int draw_counter = 0;//Checks for draw.  Goes through array, counting each spot
   for (i = 0; i < 3; i++){
      for(j = 0; j < 3; j++){
         if (barray[j][i] == 1 || barray[j][i] == (-1)){
	    draw_counter++;
	 }
      }
   }
   if (draw_counter == 18)
        game = 1;
   
   return game;
}

void Board::print(){
   cout << "   0  1  2"<<endl;  //Headerline
   for(int i = 0; i<3; i++){
     cout << i  << "  "; //Prints the row lines
      for(int j = 0; j<3; j++){
         if (barray [j][i] == 0)
	    cout <<".  "; //puts a dot for unoccupied space
	 else if (barray [j][i] == 1)
	    cout << "X  ";  // x in an x space
	 else if (barray[j][i] == (-1))
	    cout <<"O  "; //o in an o space
      }
      cout <<endl;
   }
}

