#include <iostream>
#include "tic_tac_toe.h"

using std::cout;
using std::cin;
using std::string;

int main() {
	TicTacToe tic_tac_toe;
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

		cout << "Play again? (y/n or q to quit): ";
		cin >> user_input;

	} while(user_input != "n" && user_input != "q");

	cout << "Thanks for playing!\n";

	return 0;
}