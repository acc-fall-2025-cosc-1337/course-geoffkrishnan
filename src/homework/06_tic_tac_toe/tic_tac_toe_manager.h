#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

#include <string>
#include <iostream>
#include <vector>
#include "tic_tac_toe.h"

using std::string;
using std::vector;

class TicTacToeManager{
    public:
        void get_winner_total(int& x, int& o, int& t);
        void save_game(TicTacToe b);

    private:
        vector<TicTacToe> games;
        int x_win = 0;
        int o_win = 0;
        int ties = 0;

        void update_winner_count(string winner);
};

#endif