/***
 * Name:  Brian Stamm
 * Date:  2.1.15
 * Description:  This is TTT.hpp.  3 of 4
 * **/

#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include "Board.hpp"

using namespace std;

class TicTacToe{
  
   private:
      char playerXO;
      Board funTime;
   
   public:
      TicTacToe();
      TicTacToe(char, Board);
      char getPlayer();
      void setPlayer(char);
      void play(char p, Board);
      
};
#endif
