#include "tictactoe.hpp"

#include <algorithm>
#include <iostream>
#include <optional>
#include <string>
#include <vector>

// Your code goes here

using namespace std;

constexpr int BOARD_SIZE = 3;

Board::Board() {
  makeBoard();
}

void Board::makeBoard() {
  board.clear();
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
}

bool Board::checkPlay(const int location) const {
  if (location <= 0 || location > board.size()) return false;
  if (board.at(location-1) == '\0') return true;
  return false;
}

//just a setter function basically
void Board::makePlay(const int location, const char marker) {
  board.at(location-1) = marker;
}

//v no need to check who is playing as most recent player to make a move WILL be the winner
bool Board::didWin() const {
  //horizontal checks
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board.at(i*3) != '\0' && board.at(i*3) == board.at(i*3 + 1) && board.at(i*3 + 1) == board.at(i*3 + 2)) {
      return true;
    }
  }
  //vertical checks
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board.at(i) != '\0' && board.at(i) == board.at(i + 3) && board.at(i + 3) == board.at(i+ 6)) {
      return true;
    }
  }
  if (board.at(0) != '\0' && board.at(0) == board.at(4) && board.at(4) == board.at(8)) return true;
  if (board.at(2) != '\0' && board.at(2) == board.at(4) && board.at(4) == board.at(6)) return true;
  return false;
}
bool Board::isBoardFull() const {
  for (int i = 0; i < 9; i++) {
    if (board.at(i) == '\0') return false;
  }
  return true;
}

int Board::firstAvailable() {
  for (int i = 0; i < board.size(); i++) {
    if (board.at(i) == '\0') return i+1;
  }
  return -1;
}

Game::Game() : gameMode() {
  gameMode = NA;
  play1 = {'X', 0, true};
  play2 = {'O', 0, true};
  curPlay = &play1;
  cout << "Welcome to Tic-Tac-Toe!" << endl;
  selectMode();
}
Game::~Game() {
  cout << "have a nice day!" << endl;
}

void Game::changePlayer() {
  curPlay = ((curPlay == &play1) ? &play2 : &play1);
  // switch (gameMode) {
  //   case HUMAN_VS_HUMAN:
  //     curPlay = ((curPlay == &play1) ? &play2 : &play1);
  //     break;
  //   case HUMAN_VS_COMP:
  //     break;
  //   case COMP_VS_HUMAN:
  //     break;
  //   default: ;
  // }
}

int Game::validation(const string &prompt, const string &errorMessage) const {
  string inputStr;
  int inputInt = -1;
  do {
    cout << prompt << endl;
    getline(cin, inputStr);

    //int check
    if (inputStr.empty()) {
      cout << errorMessage << endl;
      continue;
    } else if (all_of(inputStr.begin(), inputStr.end(), [](char c) {return isdigit(c);}) && inputStr.length() < 3) {
      inputInt = stoi(inputStr);
    }
    if (inputInt > 0 && inputInt <= 9 && board.checkPlay(inputInt)) {
      return inputInt;
    }
    cout << errorMessage << endl;
  } while (true);
}
bool Game::continuePlaying() {
  string inputStr;
  string errormessage = "That is not a valid entry!";
  do {
    cout << "Would you like to play again (yes/no)? " << endl;
    getline(cin, inputStr);

    //int check
    if (inputStr.empty()) {
      cout << errormessage << endl;
      continue;
    }

    if (inputStr == "YES" || inputStr == "Yes" || inputStr == "yes" || inputStr == "Y" || inputStr == "y") return true;
    if (inputStr == "NO" || inputStr == "No" || inputStr == "no" || inputStr == "N" || inputStr == "n") return false;
    cout << errormessage << endl;

  } while (true);
  return true;
}

void Game::gameEnd(bool didWin) const {
  if (didWin)cout << "Player " << curPlay->name << " wins!" << endl << "The score is: ";
  else cout << "Looks like it was a tie" << endl << "The score remains: ";
  cout << play1.name << ": " << play1.wins << " - " << play2.name << ": " << play2.wins << endl;
}
void Game::playGame() {
  int playerMove;
  switch (gameMode) {
    case HUMAN_VS_COMP:
      play1 = {'X', 0, true};
      play2 = {'O', 0, false};
      break;
    case COMP_VS_HUMAN:
      play1 = {'X', 0, false};
      play2 = {'O', 0, true};
      break;
    default:
      play1 = {'X', 0, true};
      play2 = {'O', 0, true};
  }

  do {
    board.displayBoard();
    if (curPlay->isHuman) {
      playerMove = validation("Whats your move: ", "That is not a valid move! Try again.");
    } else {
      playerMove = board.firstAvailable();
    }

    cout << playerMove << endl;
    board.makePlay(playerMove, curPlay->name);

    if (board.didWin() || board.isBoardFull()) {
      board.displayBoard();
      curPlay->wins++;
      gameEnd(board.didWin());
      if (!continuePlaying()) {break;

      }

      board.makeBoard();
    }

    changePlayer();

  } while (true);

}

void Game::selectMode() {
  cout << "What kind of game would you like to play?" << endl << endl;
  cout << "1. Human vs. Human" << endl;
  cout << "2. Human vs. Computer" << endl;
  cout << "3. Computer vs. Human" << endl << endl;
  string inputStr;
  int inputInt = -1;
  string errorMessage = "That is not a valid entry!";
  do {
    cout << "What is your selection? " << endl;
    getline(cin, inputStr);

    if (inputStr.empty()) {
      cout << errorMessage << endl;
      continue;
    }
    if (inputStr == "1") gameMode = HUMAN_VS_HUMAN;
    if (inputStr == "2") gameMode = HUMAN_VS_COMP;
    if (inputStr == "3") gameMode = COMP_VS_HUMAN;
    if (gameMode != NA) return;
    cout << errorMessage << endl;

  } while (true);
}

