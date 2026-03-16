#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include <vector>
#include "../src/tictactoe.hpp"

#include "catch2/internal/catch_windows_h_proxy.hpp"

TEST_CASE("it works") {
    REQUIRE( true );
}

// functions to test
// void displayBoard(const vector<char>& table);  - Not Testable!
// int requestPlay(const int move, const int turn, vector<char>* table);
// bool didWin(const vector<char> table);
// int validation(const int turn, const string &prompt, const string &errormessage, const vector<char> table); - Not Testable!

//checkPlay Tests
TEST_CASE( "checkPlay - empty" ) {
    Board board;
    REQUIRE( board.checkPlay(1) == true );
    REQUIRE( board.checkPlay(2) == true );
    REQUIRE( board.checkPlay(3) == true );
    REQUIRE( board.checkPlay(4) == true );
    REQUIRE( board.checkPlay(5) == true );
    REQUIRE( board.checkPlay(6) == true );
    REQUIRE( board.checkPlay(7) == true );
    REQUIRE( board.checkPlay(8) == true );
    REQUIRE( board.checkPlay(9) == true );
}

TEST_CASE( "checkPlay - out of bounds " ) {
    Board board;
    REQUIRE( board.checkPlay(-43) == false );
    REQUIRE( board.checkPlay(-1) == false );
    REQUIRE( board.checkPlay(0) == false );
    REQUIRE( board.checkPlay(10) == false );
    REQUIRE( board.checkPlay(687) == false );
}

TEST_CASE( "can't make made play" ) {
    Board board;
    board.makePlay(1, 'X');
    REQUIRE( board.checkPlay(1) == false );
}

//win states
TEST_CASE( "diagonal wins" ) {
    Board board;
    board.makePlay(1, 'X');
    REQUIRE( board.didWin() == false );
    board.makePlay(5, 'X');
    REQUIRE( board.didWin() == false );
    board.makePlay(9, 'X');
    REQUIRE( board.didWin() == true );

    Board board2;
    board2.makePlay(3, 'X');
    REQUIRE( board2.didWin() == false );
    board2.makePlay(5, 'X');
    REQUIRE( board2.didWin() == false );
    board2.makePlay(7, 'X');
    REQUIRE( board2.didWin() == true );
}

TEST_CASE( "horizontal wins" ) {
    Board board;
    board.makePlay(1, 'X');
    REQUIRE( board.didWin() == false );
    board.makePlay(2, 'X');
    REQUIRE( board.didWin() == false );
    board.makePlay(3, 'X');
    REQUIRE( board.didWin() == true );

    Board board2;
    board2.makePlay(4, 'X');
    REQUIRE( board2.didWin() == false );
    board2.makePlay(5, 'X');
    REQUIRE( board2.didWin() == false );
    board2.makePlay(6, 'X');
    REQUIRE( board2.didWin() == true );

    Board board3;
    board3.makePlay(7, 'X');
    REQUIRE( board3.didWin() == false );
    board3.makePlay(8, 'X');
    REQUIRE( board3.didWin() == false );
    board3.makePlay(9, 'X');
    REQUIRE( board3.didWin() == true );
}

TEST_CASE( "vertical wins" ) {
    Board board;
    board.makePlay(1, 'X');
    REQUIRE( board.didWin() == false );
    board.makePlay(4, 'X');
    REQUIRE( board.didWin() == false );
    board.makePlay(7, 'X');
    REQUIRE( board.didWin() == true );

    Board board2;
    board2.makePlay(2, 'X');
    REQUIRE( board2.didWin() == false );
    board2.makePlay(5, 'X');
    REQUIRE( board2.didWin() == false );
    board2.makePlay(8, 'X');
    REQUIRE( board2.didWin() == true );

    Board board3;
    board3.makePlay(3, 'X');
    REQUIRE( board3.didWin() == false );
    board3.makePlay(6, 'X');
    REQUIRE( board3.didWin() == false );
    board3.makePlay(9, 'X');
    REQUIRE( board3.didWin() == true );
}


TEST_CASE( "is the board full" ) {
    Board board;
    board.makePlay(1, 'X');
    REQUIRE( board.isBoardFull() == false );
    board.makePlay(2, 'X');
    REQUIRE( board.isBoardFull() == false );
    board.makePlay(3, 'X');
    REQUIRE( board.isBoardFull() == false );
    board.makePlay(4, 'X');
    REQUIRE( board.isBoardFull() == false );
    board.makePlay(5, 'X');
    REQUIRE( board.isBoardFull() == false );
    board.makePlay(6, 'X');
    REQUIRE( board.isBoardFull() == false );
    board.makePlay(7, 'X');
    REQUIRE( board.isBoardFull() == false );
    board.makePlay(8, 'X');
    REQUIRE( board.isBoardFull() == false );
    board.makePlay(9, 'X');
    REQUIRE( board.isBoardFull() == true );
}
//validation cant be tested as it requires user inputs