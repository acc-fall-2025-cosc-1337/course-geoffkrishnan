#include <iostream>
#include <vector>
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;

int main() {
	TicTacToe tic_tac_toe;
	TicTacToeManager manager;
	vector<TicTacToe> all_games;
	string user_input = "";

	do {
		string first_player = "";

		do {
			cout << "Enter first player (X or O): ";
			cin >> first_player;

			if(first_player != "X" && first_player != "O") {
				cout << "Invalid input. Please enter X or O.\n";
			}
		} while(first_player != "X" && first_player != "O");

		tic_tac_toe.start_game(first_player);
		tic_tac_toe.display_board();

		while(!tic_tac_toe.game_over()) {
			auto position = 0;
			bool valid_move = false;

			do {
				cout << "Enter position (1-9): ";
				cin >> position;

				if(cin.fail()) {
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "Invalid input. Please enter a number.\n";
					valid_move = false;
				}
				else if(position < 1 || position > 9) {
					cout << "Invalid position. Please enter a number between 1 and 9.\n";
					valid_move = false;
				}
				else if(!tic_tac_toe.is_position_available(position)) {
					cout << "Position already taken. Please choose another position.\n";
					valid_move = false;
				}
				else {
					valid_move = true;
				}
			} while(!valid_move);

			tic_tac_toe.mark_board(position);
			tic_tac_toe.display_board();
		}

		if(tic_tac_toe.get_winner() == "C") {
			cout << "Game is a tie!\n";
		}
		else {
			cout << "Winner is: " << tic_tac_toe.get_winner() << "\n";
		}

		manager.save_game(tic_tac_toe);
		all_games.push_back(tic_tac_toe);

		int x_wins = 0, o_wins = 0, ties = 0;
		manager.get_winner_total(x_wins, o_wins, ties);
		cout << "X wins: "  << x_wins << "\n";
		cout << "O wins: " << o_wins << "\n";
		cout << "Ties: " << ties << "\n";

		cout << "Play again? (y/n or q to quit): ";
		cin >> user_input;

	} while(user_input != "n" && user_input != "q");

	cout << "\n=== GAME HISTORY ===\n";
	for(int i = 0; i < all_games.size(); i++) {
		cout << "\nGame " << (i + 1) << " - Winner: ";
		if(all_games[i].get_winner() == "C") {
			cout << "Tie\n";
		}
		else {
			cout << all_games[i].get_winner() << "\n";
		}
		cout << "Final Board:\n";
		all_games[i].display_board();
	}

	cout << "\n=== FINAL RESULTS ===\n";
	int x_wins = 0, o_wins = 0, ties = 0;
	manager.get_winner_total(x_wins, o_wins, ties);
	cout << "X wins: " << x_wins << "\n";
	cout << "O wins: " << o_wins << "\n";
	cout << "Ties: " << ties << "\n";

	cout << "\nThanks for playing!\n";

	return 0;
}