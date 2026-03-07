#include <string>

// Your functions go here
using namespace std;

void displayBoard(const vector<char>& table);
int requestPlay(const int move, const int turn, vector<char>* table);
bool didWin(const vector<char> table);
int validation(const int turn, const string &prompt, const string &errormessage, const vector<char> table);
bool validation(const string &prompt, const string &errormessage);