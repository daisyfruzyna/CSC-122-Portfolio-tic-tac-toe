#include <string>
#include <vector>

// Your functions go here
using namespace std;

struct player {
  char name;
  int wins;
  int isHuman;
};

class Board {
  vector<char> board;
  public:
  Board();
  void makeBoard();
  void displayBoard() const; //prints the board
  bool checkPlay(int location) const; //checks if the play is legal
  void makePlay(const int location, char marker); //sets the vector at location to the marker
  bool didWin() const;  // checks if someone has one
  bool isBoardFull() const;  // checks if there are no empty spaces left
  int firstAvailable();
};

class Game {
  enum gameMode{NA, HUMAN_VS_HUMAN, HUMAN_VS_COMP, COMP_VS_HUMAN};
  enum gameMode gameMode;
  player play1{};
  player play2{};
  player *curPlay;
  Board board;

  void changePlayer();

  //game state info
public:
  Game();
  ~Game();
  void playGame();
  int validation(const string &prompt, const string &errorMessage) const;
  void gameEnd(bool didWin) const;
  static bool continuePlaying();


  //p2 idea stuff
  void selectMode();

};

//int validation(const int turn, const string &prompt, const string &errormessage, const vector<char> table);
//bool validation(const string &prompt, const string &errormessage);