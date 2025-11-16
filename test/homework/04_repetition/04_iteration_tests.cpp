#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "repetition.h"

TEST_CASE("Test get_factorial", "hw04") {
	REQUIRE(get_factorial(5) == 120);
	REQUIRE(get_factorial(1) == 1);
	REQUIRE(get_factorial(9) == 362880);
}

TEST_CASE("Test get_sum_odd_numbers", "hw04") {
	REQUIRE(sum_odd_numbers(9) == 25);
	REQUIRE(sum_odd_numbers(1) == 1);
	REQUIRE(sum_odd_numbers(5) == 9);
	REQUIRE(sum_odd_numbers(8) == 16);
}