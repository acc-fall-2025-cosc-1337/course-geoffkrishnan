#include "tic_tac_toe_manager.h"

using std::cout;

void TicTacToeManager::get_winner_total(int& x, int& o, int& t) {
    x = x_win;
    o = o_win;
    t = ties;
}

void TicTacToeManager::save_game(unique_ptr<TicTacToe>& game) {
    update_winner_count(game->get_winner());
    games.push_back(std::move(game));
}

void TicTacToeManager::display_games() const {
    cout << "\n=== GAME HISTORY ===\n";
    for(int i = 0; i < static_cast<int>(games.size()); i++) {
        cout << "\nGame " << (i + 1) << " - Winner: ";
        if(games[i]->get_winner() == "C") {
            cout << "Tie\n";
        }
        else {
            cout << games[i]->get_winner() << "\n";
        }
        cout << "Final Board:\n";
        games[i]->display_board();
    }
}

void TicTacToeManager::update_winner_count(string winner) {
    if (winner == "X") {
        x_win++;
    }
    else if (winner == "O") {
        o_win++;
    }
    else {
        ties++;
    }
}