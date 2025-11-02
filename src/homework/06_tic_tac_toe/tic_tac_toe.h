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

        string get_player() const {return player;}

    private:
        void set_next_player();
        bool check_board_full();
        void clear_board();

        string player{};
        vector<string> pegs{9, " "};
};

#endif