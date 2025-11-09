#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Test is game over with a vector that has 9 pegs with value of space") {
	TicTacToe tic_tac_toe;

	REQUIRE(false == tic_tac_toe.game_over());
}

TEST_CASE("Test first player set to X") {
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	REQUIRE(tic_tac_toe.get_player() == "X");
}

TEST_CASE("Test first player set to O") {
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("O");

	REQUIRE(tic_tac_toe.get_player() == "O");
}

TEST_CASE("Test game over if 9 slots are selected - tie") {
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");
	REQUIRE(tic_tac_toe.get_player() == "X");

	// Board will look like:
	// X | O | X
	// O | O | X
	// X | X | O

	tic_tac_toe.mark_board(1);  // X
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(2);  // O
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(3);  // X
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(4);  // O
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(6);  // X
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(5);  // O
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(7);  // X
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(9);  // O
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(8);  // X
	REQUIRE(true == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "C");
}

TEST_CASE("Test win by first column") {
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(1);  // X
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(2);  // O
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(4);  // X
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(3);  // O
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(7);  // X wins
	REQUIRE(true == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "X");
}

TEST_CASE("Test win by second column") {
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(2);  // X
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(1);  // O
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(5);  // X
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(3);  // O
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(8);  // X wins
	REQUIRE(true == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "X");
}

TEST_CASE("Test win by third column") {
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(3);  // X
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(1);  // O
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(6);  // X
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(2);  // O
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(9);  // X wins
	REQUIRE(true == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "X");
}

TEST_CASE("Test win by first row") {
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(1);  // X
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(4);  // O
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(2);  // X
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(5);  // O
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(3);  // X wins
	REQUIRE(true == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "X");
}

TEST_CASE("Test win by second row") {
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(4);  // X
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(1);  // O
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(5);  // X
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(2);  // O
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(6);  // X wins
	REQUIRE(true == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "X");
}

TEST_CASE("Test win by third row") {
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(7);  // X
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(1);  // O
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(8);  // X
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(2);  // O
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(9);  // X wins
	REQUIRE(true == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "X");
}

TEST_CASE("Test win diagonally from top left") {
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(1);  // X
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(2);  // O
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(5);  // X
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(3);  // O
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(9);  // X wins
	REQUIRE(true == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "X");
}

TEST_CASE("Test win diagonally from bottom left") {
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(7);  // X
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(1);  // O
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(5);  // X
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(2);  // O
	REQUIRE(false == tic_tac_toe.game_over());

	tic_tac_toe.mark_board(3);  // X wins
	REQUIRE(true == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "X");
}
