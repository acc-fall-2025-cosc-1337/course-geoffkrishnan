#include "tic_tac_toe_3.h"

bool TicTacToe3::check_row_win() {
    if(pegs[0] != " " && pegs[0] == pegs[1] && pegs[1] == pegs[2]) {
        return true;
    }
    if(pegs[3] != " " && pegs[3] == pegs[4] && pegs[4] == pegs[5]) {
        return true;
    }
    if(pegs[6] != " " && pegs[6] == pegs[7] && pegs[7] == pegs[8]) {
        return true;
    }
    return false;
}

bool TicTacToe3::check_column_win() {
    if(pegs[0] != " " && pegs[0] == pegs[3] && pegs[3] == pegs[6]) {
        return true;
    }
    if(pegs[1] != " " && pegs[1] == pegs[4] && pegs[4] == pegs[7]) {
        return true;
    }
    if(pegs[2] != " " && pegs[2] == pegs[5] && pegs[5] == pegs[8]) {
        return true;
    }
    return false;
}

bool TicTacToe3::check_diagonal_win() {
    if(pegs[0] != " " && pegs[0] == pegs[4] && pegs[4] == pegs[8]) {
        return true;
    }
    if(pegs[2] != " " && pegs[2] == pegs[4] && pegs[4] == pegs[6]) {
        return true;
    }
    return false;
}
