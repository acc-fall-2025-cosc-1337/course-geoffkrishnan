#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "hwexpressions.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify get_sales_tax amount function", "hw02") {
	
	//ZOMBIES framework
	// Z - Zero
	REQUIRE(get_sales_tax_amount(0.0) == 0.0);
	
	// O - One/Simple values
	REQUIRE(get_sales_tax_amount(1.0) == Approx(0.0675));
	REQUIRE(get_sales_tax_amount(10.0) == Approx(0.675));

	// M - Many/Multiple amounts
	REQUIRE(get_sales_tax_amount(100.0) == Approx(6.75));
	REQUIRE(get_sales_tax_amount(50.25) == Approx(3.391875));
	REQUIRE(get_sales_tax_amount(999.99) == Approx(67.499325));
	REQUIRE(get_sales_tax_amount(15.75) == Approx(1.063125));
	
	// B - Boundary values
	REQUIRE(get_sales_tax_amount(0.01) == Approx(0.000675));
	REQUIRE(get_sales_tax_amount(9999.99) == Approx(674.999325));
	
	// I - Invalid/Error conditions
	REQUIRE(get_sales_tax_amount(-1.0) == -1.0);
	REQUIRE(get_sales_tax_amount(-10.5) == -1.0);
	REQUIRE(get_sales_tax_amount(-0.01) == -1.0);
	
	// E - Edge cases
	REQUIRE(get_sales_tax_amount(0.001) == Approx(0.0000675));
	REQUIRE(get_sales_tax_amount(1000000.0) == Approx(67500.0));
	
	// S - Simple, straight-forward cases
	REQUIRE(get_sales_tax_amount(8.99) == Approx(0.606825));
	REQUIRE(get_sales_tax_amount(24.75) == Approx(1.670625));
	REQUIRE(get_sales_tax_amount(125.50) == Approx(8.47125));
	REQUIRE(get_sales_tax_amount(0.33) == Approx(0.02227));
	REQUIRE(get_sales_tax_amount(12.34) == Approx(0.83295));
	REQUIRE(get_sales_tax_amount(99.99) == Approx(6.74932));
}

TEST_CASE("Verify get_tip_amount function", "hw02") {
	
	//ZOMBIES framework
	// Z - Zero
	REQUIRE(get_tip_amount(0.0, 0.0) == 0.0);
	REQUIRE(get_tip_amount(10.0, 0.0) == 0.0);
	REQUIRE(get_tip_amount(0.0, 0.15) == 0.0);
	
	// O - One/Simple values
	REQUIRE(get_tip_amount(1.0, 0.15) == Approx(0.15));
	REQUIRE(get_tip_amount(10.0, 0.20) == Approx(2.0));
	
	// M - Many/Multiple amounts
	REQUIRE(get_tip_amount(25.50, 0.18) == Approx(4.59));
	REQUIRE(get_tip_amount(45.75, 0.20) == Approx(9.15));
	REQUIRE(get_tip_amount(100.00, 0.15) == Approx(15.0));
	REQUIRE(get_tip_amount(67.89, 0.22) == Approx(14.9358));
	
	// B - Boundary values
	REQUIRE(get_tip_amount(0.01, 0.15) == Approx(0.0015));
	REQUIRE(get_tip_amount(9999.99, 0.25) == Approx(2499.9975));
	REQUIRE(get_tip_amount(50.0, 0.01) == Approx(0.5));
	REQUIRE(get_tip_amount(50.0, 1.0) == Approx(50.0));
	
	// I - Invalid/Error conditions
	REQUIRE(get_tip_amount(-1.0, 0.15) == -1.0);
	REQUIRE(get_tip_amount(10.0, -0.05) == -1.0);
	REQUIRE(get_tip_amount(-5.0, -0.10) == -1.0);
	REQUIRE(get_tip_amount(-0.01, 0.20) == -1.0);
	REQUIRE(get_tip_amount(25.0, -0.01) == -1.0);
	
	// E - Edge cases
	REQUIRE(get_tip_amount(0.01, 0.15) == Approx(0.0015));
	REQUIRE(get_tip_amount(1000000.0, 0.20) == Approx(200000.0));
	REQUIRE(get_tip_amount(12.50, 0.01) == Approx(0.125));
	
	// S - Simple, straight-forward cases (common tip percentages)
	REQUIRE(get_tip_amount(30.00, 0.15) == Approx(4.5));
	REQUIRE(get_tip_amount(42.75, 0.18) == Approx(7.695));
	REQUIRE(get_tip_amount(85.60, 0.20) == Approx(17.12));
	REQUIRE(get_tip_amount(19.99, 0.25) == Approx(4.9975));
	REQUIRE(get_tip_amount(55.25, 0.22) == Approx(12.155));
}

