#include <string>
#include <iostream>
#include <vector>

using std::string;
using std::vector;

#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

class TicTacToe {
    public:
        bool game_over();
        void start_game(string firstPlayer);
        void mark_board(int position);
        void display_board() const;
        bool is_position_available(int position) const;

        string get_player() const {return player;}
        string get_winner() const {return winner;}

    private:
        void set_next_player();
        void set_winner();
        void clear_board();
        bool check_board_full();
        bool check_column_win();
        bool check_row_win();
        bool check_diagonal_win();

        string player{};
        string winner{};
        vector<string> pegs{9, " "};
};

#endif