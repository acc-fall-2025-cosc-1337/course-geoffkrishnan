#include <iostream>
#include <vector>
#include <memory>
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::unique_ptr;
using std::make_unique;

int main() {
	TicTacToeManager manager;
	string user_input = "";
	int game_type = 0;

	// Prompt user for game type
	do {
		cout << "Choose game type:\n";
		cout << "1. TicTacToe 3 (3x3 board)\n";
		cout << "2. TicTacToe 4 (4x4 board)\n";
		cout << "Enter choice (1 or 2): ";
		cin >> game_type;

		if(game_type != 1 && game_type != 2) {
			cout << "Invalid choice. Please enter 1 or 2.\n";
		}
	} while(game_type != 1 && game_type != 2);

	do {
		unique_ptr<TicTacToe> game;

		// Create appropriate game instance
		if(game_type == 1) {
			game = make_unique<TicTacToe3>();
		}
		else {
			game = make_unique<TicTacToe4>();
		}

		string first_player = "";

		do {
			cout << "Enter first player (X or O): ";
			cin >> first_player;

			if(first_player != "X" && first_player != "O") {
				cout << "Invalid input. Please enter X or O.\n";
			}
		} while(first_player != "X" && first_player != "O");

		game->start_game(first_player);
		game->display_board();

		int max_position = (game_type == 1) ? 9 : 16;

		while(!game->game_over()) {
			auto position = 0;
			bool valid_move = false;

			do {
				cout << "Enter position (1-" << max_position << "): ";
				cin >> position;

				if(cin.fail()) {
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "Invalid input. Please enter a number.\n";
					game->display_board();
					valid_move = false;
				}
				else if(position < 1 || position > max_position) {
					cout << "Invalid position. Please enter a number between 1 and " << max_position << ".\n";
					game->display_board();
					valid_move = false;
				}
				else if(!game->is_position_available(position)) {
					cout << "Position already taken. Please choose another position.\n";
					game->display_board();
					valid_move = false;
				}
				else {
					valid_move = true;
				}
			} while(!valid_move);

			game->mark_board(position);
			game->display_board();
		}

		if(game->get_winner() == "C") {
			cout << "Game is a tie!\n";
		}
		else {
			cout << "Winner is: " << game->get_winner() << "\n";
		}

		manager.save_game(game);

		int x_wins = 0, o_wins = 0, ties = 0;
		manager.get_winner_total(x_wins, o_wins, ties);
		cout << "X wins: "  << x_wins << "\n";
		cout << "O wins: " << o_wins << "\n";
		cout << "Ties: " << ties << "\n";

		cout << "Play again? (y/n or q to quit): ";
		cin >> user_input;

	} while(user_input != "n" && user_input != "q");

	manager.display_games();

	cout << "\n=== FINAL RESULTS ===\n";
	int x_wins = 0, o_wins = 0, ties = 0;
	manager.get_winner_total(x_wins, o_wins, ties);
	cout << "X wins: " << x_wins << "\n";
	cout << "O wins: " << o_wins << "\n";
	cout << "Ties: " << ties << "\n";

	cout << "\nThanks for playing!\n";

	return 0;
}