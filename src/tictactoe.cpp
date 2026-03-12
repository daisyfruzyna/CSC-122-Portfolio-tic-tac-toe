#include "tictactoe.hpp"

#include <algorithm>
#include <iostream>
#include <optional>
#include <string>
#include <vector>

// Your code goes here

using namespace std;

constexpr int BOARD_SIZE = 3;

int validation(const int turn, const string &prompt, const string &errormessage,const vector<char> table) {
  string inputStr;
  int inputInt = -1;
  // cout << "Please enter your move:" << endl;
  while (true) {
    cout << prompt << endl;
    getline(cin, inputStr);

    //int check
    if (inputStr.length() == 0) {
      cout << errormessage << endl;
      continue;
    } else if (all_of(inputStr.begin(), inputStr.end(), [](char c) {return isdigit(c);})) {
      inputInt = stoi(inputStr);
    }

    // inputInt = stoi(inputStr);
    if (inputInt > 0 && inputInt <= table.size() && table.at(inputInt - 1) == '\0') {
    // if (inputInt >= lower && inputInt <= (table.size()+1)-turn) {
      return inputInt;
    } else {
      cout << errormessage << endl;
    }
  }
  return false;
}
bool validation(const string &prompt, const string &errormessage) {
  string inputStr;
  vector<string> yesStrings = {"yes", "Yes", "y", "Y"};
  vector<string> noStrings = {"no", "No", "n", "N"};
  // cout << "Please enter your move:" << endl;
  while (true) {
    cout << prompt << endl;
    getline(cin, inputStr);
    if (any_of(yesStrings.begin(), yesStrings.end(), [&inputStr](string yes) { return yes == inputStr; })) {
      return true;
    }
    if (any_of(noStrings.begin(), noStrings.end(), [&inputStr](string no) { return no == inputStr; })) {
      return false;
    }
    cout << errormessage << endl;
  }
}

// 3 win types horizontal, vertical, or diagonal
bool didWin(const vector<char> table) {
  char temp;
  char won = false;
  //horizontal checks
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (table.at(i*3) != '\0' && table.at(i*3) == table.at(i*3 + 1) && table.at(i*3 + 1) == table.at(i*3 + 2)) {
      return true;
    }
  }
  //vertical checks
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (table.at(i) != '\0' && table.at(i) == table.at(i + 3) && table.at(i + 3) == table.at(i+ 6)) {
      return true;
    }
  }
  if (table.at(0) != '\0' && table.at(0) == table.at(4) && table.at(4) == table.at(8)) return true;
  if (table.at(2) != '\0' && table.at(2) == table.at(4) && table.at(4) == table.at(6)) return true;
  return false;
}

int requestPlay(const int move, const int turn, vector<char>* table) {
  int openSpots = 0;
  // // move--;
  if (move <= 0 || move > table->size()) { return -1; }
  if (table->at(move-1) == '\0') {
    table->at(move-1) = (turn%2 == 1) ? 'X' : 'O';
    return 1;
  }
  // for (int i =0; i < table->size(); i++) {
  //   if (table->at(i) == '\0') {
  //     openSpots++;
  //   }
  //   if (move == openSpots && openSpots != 0) {
  //     table->at(i) = (turn%2 == 1) ? 'X' : 'O';
  //     // cout << table->at(i) << endl;
  //     return 1;
  //   }
  //}

  return -1;
}

void displayBoard(const vector<char>& table) {
  int empty = 1;

  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      cout << (j > 0 ? "|" : "") << "  ";
      if (table.at(i*3 + j) != '\0') {
        cout << table.at(i*3 + j);
      } else {
        cout << empty;
      }
      cout << "  ";
      empty++;
    }
     cout << endl << (i < BOARD_SIZE-1 ? "-----+-----+-----" : "") << endl;
  }
return;
}

Board::Board() {
  makeBoard();
}
void Board::makeBoard() {
  for (int i = 0; i < 9; i++) {
    board.push_back('\0');
  }
}
void Board::displayBoard() const {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      cout << (j > 0 ? "|" : "") << "  ";
      if (board.at(i*3 + j) != '\0') {
        cout << board.at(i*3 + j);
      } else {
        cout << (i *BOARD_SIZE +j +1);
      }
      cout << "  ";
    }
    cout << endl << (i < BOARD_SIZE-1 ? "-----+-----+-----" : "") << endl;
  }
  return;
}

bool Board::requestPlay(const int location, Player player) {
  int openSpots = 0;
  if (location <= 0 || location > board.size()) { return false; }
  if (board.at(location-1) == '\0') {
    // board.at(location-1) = player.name;
    return makePlay(location, player);
  }
  return false;
}

bool Board::makePlay(const int location, Player player) {
  board.at(location-1) = player.name;
}

bool Board::didWin() {

}


Game::Game() {
  playerX = new Player('X');
  playerY = new Player('Y');
  currentPlayer = playerX;
  cout << "Welcome to Tic-Tac-Toe!" << endl;
};

void Game::playGame() {
  do {

  } while (!board.didWin());
}


// cout << "  " << (table[i*BOARD_SIZE + j] != '\0' ? table.at(i*3 + j) : empty++) << "  ";
