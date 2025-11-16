#include "repetition.h"

/*
factorial definition
for  n ∈ ℕ₀
n! = {
1                   if n = 0
1 * 2 * 3 * ... * n if n >= 1
}
*/


int get_factorial(int num) {
    int result = 1;

    for (int i = num; i > 0; i--) {
       result *= i; 
    }

    return result;
}

int sum_odd_numbers(int num) {
    int curr_odd = 1, result = 0;

    while (curr_odd <= num) {
        result += curr_odd;
        //next odd num
        curr_odd += 2;
    }

    return result;
}

