#include "tic_tac_toe_4.h"

bool TicTacToe4::check_row_win() {
    // Check all 4 rows for 4 in a row
    for(int row = 0; row < 4; row++) {
        int start_index = row * 4;
        if(pegs[start_index] != " " &&
           pegs[start_index] == pegs[start_index + 1] &&
           pegs[start_index + 1] == pegs[start_index + 2] &&
           pegs[start_index + 2] == pegs[start_index + 3]) {
            return true;
        }
    }
    return false;
}

bool TicTacToe4::check_column_win() {
    // Check all 4 columns for 4 in a row
    for(int col = 0; col < 4; col++) {
        if(pegs[col] != " " &&
           pegs[col] == pegs[col + 4] &&
           pegs[col + 4] == pegs[col + 8] &&
           pegs[col + 8] == pegs[col + 12]) {
            return true;
        }
    }
    return false;
}

bool TicTacToe4::check_diagonal_win() {
    // Check main diagonal: 0, 5, 10, 15
    if(pegs[0] != " " &&
       pegs[0] == pegs[5] &&
       pegs[5] == pegs[10] &&
       pegs[10] == pegs[15]) {
        return true;
    }

    // Check anti-diagonal: 3, 6, 9, 12
    if(pegs[3] != " " &&
       pegs[3] == pegs[6] &&
       pegs[6] == pegs[9] &&
       pegs[9] == pegs[12]) {
        return true;
    }

    return false;
}
