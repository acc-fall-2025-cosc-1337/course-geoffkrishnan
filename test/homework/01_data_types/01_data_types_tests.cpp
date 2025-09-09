#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "data_types.h"
TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify add_numbers function") 
{
	REQUIRE(add_numbers(5, 5) == 10);
	REQUIRE(add_numbers(10, 10) == 20);
}

TEST_CASE("Verify multiply_numbers function")
{
	// Commutative property of multiplication
	REQUIRE(multiply_numbers(153, 22) == 3366);
	REQUIRE(multiply_numbers(22, 153) == 3366);

	// Zero property of multiplication
	REQUIRE(multiply_numbers(0, 753) == 0);
	REQUIRE(multiply_numbers(753, 0) == 0);
	REQUIRE(multiply_numbers(-753, 0) == 0);
	REQUIRE(multiply_numbers(0, -753) == 0);

	// Negative numbers
	REQUIRE(multiply_numbers(-1, -753) == 753);
	REQUIRE(multiply_numbers(-753, -1) == 753);
	REQUIRE(multiply_numbers(-1, 753) == -753);
	REQUIRE(multiply_numbers(753, -1) == -753);

	// Identity property (multiply by 1)
	REQUIRE(multiply_numbers(753, 1) == 753);
	REQUIRE(multiply_numbers(1, 753) == 753);
	REQUIRE(multiply_numbers(-753, 1) == -753);

	// Larger numbers
	REQUIRE(multiply_numbers(100, 200) == 20000);
}