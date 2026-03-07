#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include <vector>
#include "../src/tictactoe.hpp"

TEST_CASE( "it works" ) {
    REQUIRE( true );
}

// functions to test
// void displayBoard(const vector<char>& table);  - Not Testable!
// int requestPlay(const int move, const int turn, vector<char>* table);
// bool didWin(const vector<char> table);
// int validation(const int turn, const string &prompt, const string &errormessage, const vector<char> table); - Not Testable!

//requestPlay Tests
TEST_CASE( "requestPlay - move -1 - out of bounds" ) {
    int move = -1;
    int turn = 5;
    vector<char> table =
    {'O', 'O', 'X',
    '\0', 'X', '\0',
    '\0', '\0', '\0'};
    vector<char> retTable =
    {'O', 'O', 'X',
    '\0', 'X', '\0',
    '\0', '\0', '\0'};
    REQUIRE( (requestPlay(move,  turn, &table) == -1 && table == retTable));
}
TEST_CASE( "requestPlay - move Zero - illegal" ) {
    int move = 0;
    int turn = 5;
    vector<char> table =
    {'O', 'O', 'X',
    '\0', 'X', '\0',
    '\0', '\0', '\0'};
    vector<char> retTable =
    {'O', 'O', 'X',
    '\0', 'X', '\0',
    '\0', '\0', '\0'};
    REQUIRE( (requestPlay(move,  turn, &table) == -1 && table == retTable));
}
TEST_CASE( "requestPlay - move 1  - already taken" ) {
    int move = 1;
    int turn = 1;
    vector<char> table =
        {'O', 'O', 'X',
        '\0', 'X', '\0',
        '\0', '\0', '\0'};
    vector<char> retTable =
        {'O', 'O', 'X',
        '\0', 'X', '\0',
        '\0', '\0', '\0'};
    REQUIRE( (requestPlay(move,  turn, &table) == -1 && table == retTable));
}
TEST_CASE( "requestPlay - move 1  - untaken" ) {
    int move = 1;
    int turn = 3;
    vector<char> table =
    {'\0', 'O', '\0',
    '\0', '\0', '\0',
    '\0', '\0', 'X'};
    vector<char> retTable =
    {'X', 'O', '\0',
    '\0', '\0', '\0',
    '\0', '\0', 'X'};
    REQUIRE( (requestPlay(move,  turn, &table) == 1 && table == retTable));
}
TEST_CASE( "requestPlay - move 7  - untaken" ) {
    int move = 7;
    int turn = 4;
    vector<char> table =
    {'X', 'O', '\0',
    '\0', '\0', '\0',
    '\0', '\0', 'X'};
    vector<char> retTable =
    {'X', 'O', '\0',
    '\0', '\0', '\0',
    'O', '\0', 'X'};
    REQUIRE( (requestPlay(move,  turn, &table) == 1 && table == retTable));
}
TEST_CASE( "requestPlay - move 9  - last" ) {
    int move = 9;
    int turn = 1;
    vector<char> table =
        {'\0', '\0', '\0',
        '\0', '\0', '\0',
        '\0', '\0', '\0'};
    vector<char> retTable =
        {'\0', '\0', '\0',
        '\0', '\0', '\0',
        '\0', '\0', 'X'};
    REQUIRE( (requestPlay(move,  turn, &table) == 1 && table == retTable));
}
TEST_CASE( "requestPlay - move 10  - out of bounds" ) {
    int move = 10;
    int turn = 1;
    vector<char> table =
        {'\0', '\0', '\0',
        '\0', '\0', '\0',
        '\0', '\0', '\0'};
    vector<char> retTable =
        {'\0', '\0', '\0',
        '\0', '\0', '\0',
        '\0', '\0', '\0'};
    REQUIRE( (requestPlay(move,  turn, &table) == -1 && table == retTable));
}

TEST_CASE( "didWin - no - clear board" ) {
    vector<char> table =
        {'\0', '\0', '\0',
        '\0', '\0', '\0',
        '\0', '\0', '\0'};
    REQUIRE(didWin(table) == false);
}
TEST_CASE( "didWin - no - cats game or soemthing idk" ) {
    vector<char> table =
        {'O', 'X', 'X',
        'X', 'X', 'O',
        'O', 'O', 'X'};
    REQUIRE(didWin(table) == false);
}
TEST_CASE( "didWin - no - No Clear Horizontal Wins" ) {
    vector<char> tableRow =
    {'X', 'O', 'X',
    '\0', '\0', '\0',
    'O', 'X', 'O'};
    REQUIRE(didWin(tableRow) == false);
} // NOT NEEDED AS CLEAR BOARD SHOWS TRUTH
TEST_CASE( "didWin - yes - Horizontal Wins" ) {
    vector<char> tableRow1x =
        {'X', 'X', 'X',
        '\0', '\0', '\0',
        '\0', '\0', '\0'};
    vector<char> tableRow2x =
        {'\0', '\0', '\0',
        'X', 'X', 'X',
        '\0', '\0', '\0'};
    vector<char> tableRow3x =
        {'\0', '\0', '\0',
        '\0', '\0', '\0',
        'X', 'X', 'X'};
    vector<char> tableRow1o =
    {'O', 'O', 'O',
    '\0', '\0', '\0',
    '\0', '\0', '\0'};
    vector<char> tableRow2o =
    {'\0', '\0', '\0',
    'O', 'O', 'O',
    '\0', '\0', '\0'};
    vector<char> tableRow3o =
    {'\0', '\0', '\0',
    '\0', '\0', '\0',
    'O', 'O', 'O'};
    REQUIRE(((didWin(tableRow1x) == true && didWin(tableRow2x) == true && didWin(tableRow3x) == true)
        && (didWin(tableRow1o) == true && didWin(tableRow2o) == true && didWin(tableRow3o) == true)));
}
TEST_CASE( "didWin - yes - Vertical Wins" ) {
    vector<char> tableCol1x =
    {'X', '\0', '\0',
    'X', '\0', '\0',
    'X', '\0', '\0'};
    vector<char> tableCol2x =
    {'\0', 'X', '\0',
    '\0', 'X', '\0',
    '\0', 'X', '\0'};
    vector<char> tableCol3x =
    {'\0', '\0', 'X',
    '\0', '\0', 'X',
    '\0', '\0', 'X'};
    vector<char> tableCol1o =
    {'O', '\0', '\0',
    'O', '\0', '\0',
    'O', '\0', '\0'};
    vector<char> tableCol2o =
    {'\0', 'O', '\0',
    '\0', 'O', '\0',
    '\0', 'O', '\0'};
    vector<char> tableCol3o =
    {'\0', '\0', 'O',
    '\0', '\0', 'O',
    '\0', '\0', 'O'};
    REQUIRE(((didWin(tableCol1x) == true && didWin(tableCol2x) == true && didWin(tableCol3x) == true)
        && (didWin(tableCol1o) == true && didWin(tableCol2o) == true && didWin(tableCol3o) == true)));
}
TEST_CASE( "didWin - yes - Diagonal Wins" ) {
    vector<char> tableDiag1x =
    {'\0', '\0', 'X',
    '\0', 'X', '\0',
    'X', '\0', '\0'};
    vector<char> tableDiag2x =
    {'X', '\0', '\0',
    '\0', 'X', '\0',
    '\0', '\0', 'X'};
    vector<char> tableDiag1o =
    {'\0', '\0', 'O',
    '\0', 'O', '\0',
    'O', '\0', '\0'};
    vector<char> tableDiag2o =
    {'O', '\0', '\0',
    '\0', 'O', '\0',
    '\0', '\0', 'O'};
    REQUIRE(((didWin(tableDiag1x) == true && didWin(tableDiag2x) == true)
        && (didWin(tableDiag1o) == true && didWin(tableDiag2o) == true)));
}


//validation cant be tested as it requires user inputs