#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

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

TEST_CASE("Test TicTacToeManager save_game with X winner") {
	TicTacToeManager manager;
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(1);  // X
	tic_tac_toe.mark_board(2);  // O
	tic_tac_toe.mark_board(4);  // X
	tic_tac_toe.mark_board(3);  // O
	tic_tac_toe.mark_board(7);  // X wins
	tic_tac_toe.game_over();  // Set the winner

	REQUIRE(tic_tac_toe.get_winner() == "X");
	manager.save_game(tic_tac_toe);

	int x_wins = 0, o_wins = 0, ties = 0;
	manager.get_winner_total(x_wins, o_wins, ties);
	REQUIRE(x_wins == 1);
	REQUIRE(o_wins == 0);
	REQUIRE(ties == 0);
}

TEST_CASE("Test TicTacToeManager save_game with O winner") {
	TicTacToeManager manager;
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(1);  // X
	tic_tac_toe.mark_board(2);  // O
	tic_tac_toe.mark_board(4);  // X
	tic_tac_toe.mark_board(5);  // O
	tic_tac_toe.mark_board(3);  // X
	tic_tac_toe.mark_board(8);  // O wins
	tic_tac_toe.game_over();  // Set the winner

	REQUIRE(tic_tac_toe.get_winner() == "O");
	manager.save_game(tic_tac_toe);

	int x_wins = 0, o_wins = 0, ties = 0;
	manager.get_winner_total(x_wins, o_wins, ties);
	REQUIRE(x_wins == 0);
	REQUIRE(o_wins == 1);
	REQUIRE(ties == 0);
}

TEST_CASE("Test TicTacToeManager save_game with tie") {
	TicTacToeManager manager;
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	// Board will look like:
	// X | O | X
	// O | O | X
	// X | X | O

	tic_tac_toe.mark_board(1);  // X
	tic_tac_toe.mark_board(2);  // O
	tic_tac_toe.mark_board(3);  // X
	tic_tac_toe.mark_board(4);  // O
	tic_tac_toe.mark_board(6);  // X
	tic_tac_toe.mark_board(5);  // O
	tic_tac_toe.mark_board(7);  // X
	tic_tac_toe.mark_board(9);  // O
	tic_tac_toe.mark_board(8);  // X - game ends in tie
	tic_tac_toe.game_over();  // Set the tie result

	REQUIRE(tic_tac_toe.get_winner() == "C");
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
	TicTacToe game1;
	game1.start_game("X");
	game1.mark_board(1);  // X
	game1.mark_board(2);  // O
	game1.mark_board(4);  // X
	game1.mark_board(3);  // O
	game1.mark_board(7);  // X wins
	game1.game_over();  // Set the winner
	REQUIRE(game1.get_winner() == "X");
	manager.save_game(game1);

	// Game 2: O wins
	TicTacToe game2;
	game2.start_game("X");
	game2.mark_board(1);  // X
	game2.mark_board(2);  // O
	game2.mark_board(4);  // X
	game2.mark_board(5);  // O
	game2.mark_board(3);  // X
	game2.mark_board(8);  // O wins
	game2.game_over();  // Set the winner
	REQUIRE(game2.get_winner() == "O");
	manager.save_game(game2);

	// Game 3: Tie
	TicTacToe game3;
	game3.start_game("X");
	game3.mark_board(1);  // X
	game3.mark_board(2);  // O
	game3.mark_board(3);  // X
	game3.mark_board(4);  // O
	game3.mark_board(6);  // X
	game3.mark_board(5);  // O
	game3.mark_board(7);  // X
	game3.mark_board(9);  // O
	game3.mark_board(8);  // X - tie
	game3.game_over();  // Set the tie result
	REQUIRE(game3.get_winner() == "C");
	manager.save_game(game3);

	// Verify totals
	int x_wins = 0, o_wins = 0, ties = 0;
	manager.get_winner_total(x_wins, o_wins, ties);
	REQUIRE(x_wins == 1);
	REQUIRE(o_wins == 1);
	REQUIRE(ties == 1);
}
