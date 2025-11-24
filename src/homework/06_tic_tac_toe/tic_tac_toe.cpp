//cpp
#include "tic_tac_toe.h"
#include <cmath>

using std::cout;

bool TicTacToe::game_over() {
    if(check_row_win() || check_column_win() || check_diagonal_win()) {
        set_winner();
        return true;
    }
    else if(check_board_full()) {
        winner = "C";
        return true;
    }
    else {
        return false;
    }
}

void TicTacToe::start_game(std::string first_player) {
    player = first_player;
    clear_board();
}

void TicTacToe::mark_board(int position) {
    pegs[position - 1] = player;
    set_next_player();
}

void TicTacToe::display_board() const {
    int size = static_cast<int>(sqrt(pegs.size()));
    for(int i = 0; i < static_cast<int>(pegs.size()); i += size) {
        for(int j = 0; j < size; j++) {
            cout << pegs[i + j];
            if(j < size - 1) cout << "|";
        }
        cout << "\n";
    }
}

bool TicTacToe::is_position_available(int position) const {
    return pegs[position - 1] == " ";
}

void TicTacToe::set_next_player() {
    if(player == "X") {
        player = "O";
    }
    else {
        player = "X";
    }
}

bool TicTacToe::check_board_full() {
    auto full = true;

    for(auto &peg: pegs) {
        if(peg == " ") {
            full = false;
            break;
        }
    }

    return full;
}

void TicTacToe::clear_board() {
    for(auto &peg: pegs) {
        peg = " ";
    }
}


void TicTacToe::set_winner() {
    if (player == "X") {
        winner = "O";
    }
    else {
        winner = "X";
    }
}