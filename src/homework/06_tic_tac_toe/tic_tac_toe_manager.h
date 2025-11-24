#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include "tic_tac_toe.h"

using std::string;
using std::vector;
using std::unique_ptr;

class TicTacToeManager{
    public:
        void get_winner_total(int& x, int& o, int& t);
        void save_game(unique_ptr<TicTacToe>& game);
        void display_games() const;

    private:
        vector<unique_ptr<TicTacToe>> games;
        int x_win = 0;
        int o_win = 0;
        int ties = 0;

        void update_winner_count(string winner);
};

#endif