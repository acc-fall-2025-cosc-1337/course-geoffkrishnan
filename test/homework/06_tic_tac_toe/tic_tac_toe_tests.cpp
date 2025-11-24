#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"
#include <memory>

using std::unique_ptr;
using std::make_unique;

TEST_CASE("Test is game over with a vector that has 9 pegs with value of space") {
	unique_ptr<TicTacToe> tic_tac_toe = make_unique<TicTacToe3>();

	REQUIRE(false == tic_tac_toe->game_over());
}

TEST_CASE("Test first player set to X") {
	unique_ptr<TicTacToe> tic_tac_toe = make_unique<TicTacToe3>();
	tic_tac_toe->start_game("X");

	REQUIRE(tic_tac_toe->get_player() == "X");
}

TEST_CASE("Test first player set to O") {
	unique_ptr<TicTacToe> tic_tac_toe = make_unique<TicTacToe3>();
	tic_tac_toe->start_game("O");

	REQUIRE(tic_tac_toe->get_player() == "O");
}

TEST_CASE("Test game over if 9 slots are selected - tie") {
	unique_ptr<TicTacToe> tic_tac_toe = make_unique<TicTacToe3>();
	tic_tac_toe->start_game("X");
	REQUIRE(tic_tac_toe->get_player() == "X");

	// Board will look like:
	// X | O | X
	// O | O | X
	// X | X | O

	tic_tac_toe->mark_board(1);  // X
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(2);  // O
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(3);  // X
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(4);  // O
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(6);  // X
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(5);  // O
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(7);  // X
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(9);  // O
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(8);  // X
	REQUIRE(true == tic_tac_toe->game_over());
	REQUIRE(tic_tac_toe->get_winner() == "C");
}

TEST_CASE("Test win by first column") {
	unique_ptr<TicTacToe> tic_tac_toe = make_unique<TicTacToe3>();
	tic_tac_toe->start_game("X");

	tic_tac_toe->mark_board(1);  // X
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(2);  // O
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(4);  // X
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(3);  // O
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(7);  // X wins
	REQUIRE(true == tic_tac_toe->game_over());
	REQUIRE(tic_tac_toe->get_winner() == "X");
}

TEST_CASE("Test win by second column") {
	unique_ptr<TicTacToe> tic_tac_toe = make_unique<TicTacToe3>();
	tic_tac_toe->start_game("X");

	tic_tac_toe->mark_board(2);  // X
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(1);  // O
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(5);  // X
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(3);  // O
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(8);  // X wins
	REQUIRE(true == tic_tac_toe->game_over());
	REQUIRE(tic_tac_toe->get_winner() == "X");
}

TEST_CASE("Test win by third column") {
	unique_ptr<TicTacToe> tic_tac_toe = make_unique<TicTacToe3>();
	tic_tac_toe->start_game("X");

	tic_tac_toe->mark_board(3);  // X
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(1);  // O
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(6);  // X
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(2);  // O
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(9);  // X wins
	REQUIRE(true == tic_tac_toe->game_over());
	REQUIRE(tic_tac_toe->get_winner() == "X");
}

TEST_CASE("Test win by first row") {
	unique_ptr<TicTacToe> tic_tac_toe = make_unique<TicTacToe3>();
	tic_tac_toe->start_game("X");

	tic_tac_toe->mark_board(1);  // X
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(4);  // O
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(2);  // X
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(5);  // O
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(3);  // X wins
	REQUIRE(true == tic_tac_toe->game_over());
	REQUIRE(tic_tac_toe->get_winner() == "X");
}

TEST_CASE("Test win by second row") {
	unique_ptr<TicTacToe> tic_tac_toe = make_unique<TicTacToe3>();
	tic_tac_toe->start_game("X");

	tic_tac_toe->mark_board(4);  // X
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(1);  // O
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(5);  // X
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(2);  // O
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(6);  // X wins
	REQUIRE(true == tic_tac_toe->game_over());
	REQUIRE(tic_tac_toe->get_winner() == "X");
}

TEST_CASE("Test win by third row") {
	unique_ptr<TicTacToe> tic_tac_toe = make_unique<TicTacToe3>();
	tic_tac_toe->start_game("X");

	tic_tac_toe->mark_board(7);  // X
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(1);  // O
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(8);  // X
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(2);  // O
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(9);  // X wins
	REQUIRE(true == tic_tac_toe->game_over());
	REQUIRE(tic_tac_toe->get_winner() == "X");
}

TEST_CASE("Test win diagonally from top left") {
	unique_ptr<TicTacToe> tic_tac_toe = make_unique<TicTacToe3>();
	tic_tac_toe->start_game("X");

	tic_tac_toe->mark_board(1);  // X
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(2);  // O
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(5);  // X
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(3);  // O
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(9);  // X wins
	REQUIRE(true == tic_tac_toe->game_over());
	REQUIRE(tic_tac_toe->get_winner() == "X");
}

TEST_CASE("Test win diagonally from bottom left") {
	unique_ptr<TicTacToe> tic_tac_toe = make_unique<TicTacToe3>();
	tic_tac_toe->start_game("X");

	tic_tac_toe->mark_board(7);  // X
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(1);  // O
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(5);  // X
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(2);  // O
	REQUIRE(false == tic_tac_toe->game_over());

	tic_tac_toe->mark_board(3);  // X wins
	REQUIRE(true == tic_tac_toe->game_over());
	REQUIRE(tic_tac_toe->get_winner() == "X");
}

TEST_CASE("Test TicTacToeManager save_game with X winner") {
	TicTacToeManager manager;
	unique_ptr<TicTacToe> tic_tac_toe = make_unique<TicTacToe3>();
	tic_tac_toe->start_game("X");

	tic_tac_toe->mark_board(1);  // X
	tic_tac_toe->mark_board(2);  // O
	tic_tac_toe->mark_board(4);  // X
	tic_tac_toe->mark_board(3);  // O
	tic_tac_toe->mark_board(7);  // X wins
	tic_tac_toe->game_over();  // Set the winner

	REQUIRE(tic_tac_toe->get_winner() == "X");
	manager.save_game(tic_tac_toe);

	int x_wins = 0, o_wins = 0, ties = 0;
	manager.get_winner_total(x_wins, o_wins, ties);
	REQUIRE(x_wins == 1);
	REQUIRE(o_wins == 0);
	REQUIRE(ties == 0);
}

TEST_CASE("Test TicTacToeManager save_game with O winner") {
	TicTacToeManager manager;
	unique_ptr<TicTacToe> tic_tac_toe = make_unique<TicTacToe3>();
	tic_tac_toe->start_game("X");

	tic_tac_toe->mark_board(1);  // X
	tic_tac_toe->mark_board(2);  // O
	tic_tac_toe->mark_board(4);  // X
	tic_tac_toe->mark_board(5);  // O
	tic_tac_toe->mark_board(3);  // X
	tic_tac_toe->mark_board(8);  // O wins
	tic_tac_toe->game_over();  // Set the winner

	REQUIRE(tic_tac_toe->get_winner() == "O");
	manager.save_game(tic_tac_toe);

	int x_wins = 0, o_wins = 0, ties = 0;
	manager.get_winner_total(x_wins, o_wins, ties);
	REQUIRE(x_wins == 0);
	REQUIRE(o_wins == 1);
	REQUIRE(ties == 0);
}

TEST_CASE("Test TicTacToeManager save_game with tie") {
	TicTacToeManager manager;
	unique_ptr<TicTacToe> tic_tac_toe = make_unique<TicTacToe3>();
	tic_tac_toe->start_game("X");

	// Board will look like:
	// X | O | X
	// O | O | X
	// X | X | O

	tic_tac_toe->mark_board(1);  // X
	tic_tac_toe->mark_board(2);  // O
	tic_tac_toe->mark_board(3);  // X
	tic_tac_toe->mark_board(4);  // O
	tic_tac_toe->mark_board(6);  // X
	tic_tac_toe->mark_board(5);  // O
	tic_tac_toe->mark_board(7);  // X
	tic_tac_toe->mark_board(9);  // O
	tic_tac_toe->mark_board(8);  // X - game ends in tie
	tic_tac_toe->game_over();  // Set the tie result

	REQUIRE(tic_tac_toe->get_winner() == "C");
	manager.save_game(tic_tac_toe);

	int x_wins = 0, o_wins = 0, ties = 0;
	manager.get_winner_total(x_wins, o_wins, ties);
	REQUIRE(x_wins == 0);
	REQUIRE(o_wins == 0);
	REQUIRE(ties == 1);
}

TEST_CASE("Test TicTacToeManager with multiple games - X, O, and tie") {
	TicTacToeManager manager;

	// Game 1: X wins
	unique_ptr<TicTacToe> game1 = make_unique<TicTacToe3>();
	game1->start_game("X");
	game1->mark_board(1);  // X
	game1->mark_board(2);  // O
	game1->mark_board(4);  // X
	game1->mark_board(3);  // O
	game1->mark_board(7);  // X wins
	game1->game_over();  // Set the winner
	REQUIRE(game1->get_winner() == "X");
	manager.save_game(game1);

	// Game 2: O wins
	unique_ptr<TicTacToe> game2 = make_unique<TicTacToe3>();
	game2->start_game("X");
	game2->mark_board(1);  // X
	game2->mark_board(2);  // O
	game2->mark_board(4);  // X
	game2->mark_board(5);  // O
	game2->mark_board(3);  // X
	game2->mark_board(8);  // O wins
	game2->game_over();  // Set the winner
	REQUIRE(game2->get_winner() == "O");
	manager.save_game(game2);

	// Game 3: Tie
	unique_ptr<TicTacToe> game3 = make_unique<TicTacToe3>();
	game3->start_game("X");
	game3->mark_board(1);  // X
	game3->mark_board(2);  // O
	game3->mark_board(3);  // X
	game3->mark_board(4);  // O
	game3->mark_board(6);  // X
	game3->mark_board(5);  // O
	game3->mark_board(7);  // X
	game3->mark_board(9);  // O
	game3->mark_board(8);  // X - tie
	game3->game_over();  // Set the tie result
	REQUIRE(game3->get_winner() == "C");
	manager.save_game(game3);

	// Verify totals
	int x_wins = 0, o_wins = 0, ties = 0;
	manager.get_winner_total(x_wins, o_wins, ties);
	REQUIRE(x_wins == 1);
	REQUIRE(o_wins == 1);
	REQUIRE(ties == 1);
}

// TicTacToe 4 Test Cases
TEST_CASE("Test is game over with a vector that has 16 pegs with value of space 4") {
	unique_ptr<TicTacToe> board = make_unique<TicTacToe4>();

	REQUIRE(false == board->game_over());
}

TEST_CASE("Test first player set to X 4") {
	unique_ptr<TicTacToe> board = make_unique<TicTacToe4>();
	board->start_game("X");

	REQUIRE(board->get_player() == "X");
}

TEST_CASE("Test first player set to O 4") {
	unique_ptr<TicTacToe> board = make_unique<TicTacToe4>();
	board->start_game("O");

	REQUIRE(board->get_player() == "O");
}

TEST_CASE("Test win by first row 4") {
	unique_ptr<TicTacToe> board = make_unique<TicTacToe4>();
	board->start_game("X");

	board->mark_board(1);  // X
	REQUIRE(false == board->game_over());

	board->mark_board(5);  // O
	REQUIRE(false == board->game_over());

	board->mark_board(2);  // X
	REQUIRE(false == board->game_over());

	board->mark_board(6);  // O
	REQUIRE(false == board->game_over());

	board->mark_board(3);  // X
	REQUIRE(false == board->game_over());

	board->mark_board(7);  // O
	REQUIRE(false == board->game_over());

	board->mark_board(4);  // X wins
	REQUIRE(true == board->game_over());
	REQUIRE(board->get_winner() == "X");
}

TEST_CASE("Test win by first column 4") {
	unique_ptr<TicTacToe> board = make_unique<TicTacToe4>();
	board->start_game("X");

	board->mark_board(1);  // X
	REQUIRE(false == board->game_over());

	board->mark_board(2);  // O
	REQUIRE(false == board->game_over());

	board->mark_board(5);  // X
	REQUIRE(false == board->game_over());

	board->mark_board(3);  // O
	REQUIRE(false == board->game_over());

	board->mark_board(9);  // X
	REQUIRE(false == board->game_over());

	board->mark_board(4);  // O
	REQUIRE(false == board->game_over());

	board->mark_board(13);  // X wins
	REQUIRE(true == board->game_over());
	REQUIRE(board->get_winner() == "X");
}

TEST_CASE("Test win main diagonal 4") {
	unique_ptr<TicTacToe> board = make_unique<TicTacToe4>();
	board->start_game("X");

	board->mark_board(1);  // X
	REQUIRE(false == board->game_over());

	board->mark_board(2);  // O
	REQUIRE(false == board->game_over());

	board->mark_board(6);  // X
	REQUIRE(false == board->game_over());

	board->mark_board(3);  // O
	REQUIRE(false == board->game_over());

	board->mark_board(11);  // X
	REQUIRE(false == board->game_over());

	board->mark_board(4);  // O
	REQUIRE(false == board->game_over());

	board->mark_board(16);  // X wins (main diagonal: 1, 6, 11, 16)
	REQUIRE(true == board->game_over());
	REQUIRE(board->get_winner() == "X");
}

TEST_CASE("Test win anti-diagonal 4") {
	unique_ptr<TicTacToe> board = make_unique<TicTacToe4>();
	board->start_game("X");

	board->mark_board(4);  // X
	REQUIRE(false == board->game_over());

	board->mark_board(1);  // O
	REQUIRE(false == board->game_over());

	board->mark_board(7);  // X
	REQUIRE(false == board->game_over());

	board->mark_board(2);  // O
	REQUIRE(false == board->game_over());

	board->mark_board(10);  // X
	REQUIRE(false == board->game_over());

	board->mark_board(3);  // O
	REQUIRE(false == board->game_over());

	board->mark_board(13);  // X wins (anti-diagonal: 4, 7, 10, 13)
	REQUIRE(true == board->game_over());
	REQUIRE(board->get_winner() == "X");
}

TEST_CASE("Test TicTacToe4Manager save_game with X winner 4") {
	TicTacToeManager manager;
	unique_ptr<TicTacToe> board = make_unique<TicTacToe4>();
	board->start_game("X");

	board->mark_board(1);  // X
	board->mark_board(5);  // O
	board->mark_board(6);  // X
	board->mark_board(2);  // O
	board->mark_board(11);  // X
	board->mark_board(3);  // O
	board->mark_board(16);  // X wins
	board->game_over();  // Set the winner

	REQUIRE(board->get_winner() == "X");
	manager.save_game(board);

	int x_wins = 0, o_wins = 0, ties = 0;
	manager.get_winner_total(x_wins, o_wins, ties);
	REQUIRE(x_wins == 1);
	REQUIRE(o_wins == 0);
	REQUIRE(ties == 0);
}
