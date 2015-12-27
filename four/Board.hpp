/***
 * Name:  Brian Stamm
 * Date:  2.1.15
 * Description:  This is Board.hpp.  1 of 4
 * **/

#ifndef BOARD_HPP
#define BOARD_HPP

using namespace std;

class Board{
   private:
      double barray[3][3];
      enum game {progress, draw, x_win, o_win};
      int game;
   
   public:
      Board();
      bool makeMove(int y, int x, char xo);
      int gameState();
      void print();
      int getGame();
      void setGame(int);
};

#endif
