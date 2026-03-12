#include <string>
#include <vector>

// Your functions go here
using namespace std;

class Player {

  int wins;
  public:
  Player(char name);
    ~Player();
  char name;

};
class Board {
  vector<char> board;
  public:
    Board();
    ~Board();
    void makeBoard();

    void displayBoard() const;
    bool requestPlay(int location, Player player);
    bool makePlay(const int location, Player player);
    bool didWin();
    bool didTie();

};
class Game {
  Player *playerX;
  Player *playerY;
  Player *currentPlayer;
  Player *winner;
  Board board;
  void changePlayer();



  //game state info
public:
  Game();
  ~Game();
  void playGame();

};

void displayBoard(const vector<char>& table);
int requestPlay(const int move, const int turn, vector<char>* table);
bool didWin(const vector<char> table);
int validation(const int turn, const string &prompt, const string &errormessage, const vector<char> table);
bool validation(const string &prompt, const string &errormessage);