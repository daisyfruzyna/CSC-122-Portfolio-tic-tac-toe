#include <iostream>
// #include <string>
#include <vector>
constexpr int BOARD_SIZE = 3;
#include "src/tictactoe.hpp"
using namespace std;




int main() {
  // Your driver program goes here
  bool rematch = false;
  string inputStr;
  bool won = false;
  int move;
  int turn = 1;
  char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
  //char moveTable[MATRIX_SIZE][MATRIX_SIZE] = {{'\0', '\0', '\0'}, {'\0', '\0', '\0'}, {'\0', '\0', '\0'}};
  vector<char> table;
  for (int i = 0; i < 9; i++) {
    table.push_back('\0');
  }


  // table = {'O', 'O', 'X',
  //   '\0', 'X', '\0',
  //   '\0', '\0', '\0'};


  cout << "Welcome to Tic-Tac-Toe! \n\n";
  while (!won && turn < 10) {
    //display board state
    displayBoard(table);

    //encase in legality check loop thing
    // cout << turn << endl;
    move = validation(turn, "Whats your move: ", "That is not a valid move! Try again.", table);
    requestPlay(move, turn, &table);

    if (turn > 3){
      won = didWin(table);
    }
    turn++;


    if (turn > 10 || won) {

      displayBoard(table);
      won ? (cout << "Game over, player " << ((turn % 2 == 0) ? "X" : "O") << " is the winner" << endl)
        : cout << "Game over, it was a draw" << endl;

      rematch = validation("Would you like to play again (yes/no)? ", "Not a valid answer: ");
    }
    if (rematch) {
      rematch = false;
      turn = 1;
      won = false;
      table =
      {'\0', '\0', '\0',
      '\0', '\0', '\0',
      '\0', '\0', '\0'};

    }
  }

  cout << "Goodbye!" << endl;
}
