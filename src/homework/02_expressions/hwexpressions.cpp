#include "hwexpressions.h"
//Declare a const double tax_rate variable with value 6.75%
const double tax_rate = 0.0675;

//Function get_sales_tax_amount has one double parameter meal_amount, in the function code returns the product of meal_amount and tax_rate.
double get_sales_tax_amount(double meal_amount) {
	if (meal_amount < 0) {
		return -1;
	}
	return meal_amount * tax_rate;
}

//Function get_tip_amount has two double parameters meal_amount and tip_rate and returns the product of meal_amount and tip_rate.
double get_tip_amount(double meal_amount, double tip_rate) {
	if (meal_amount < 0 || tip_rate < 0) {
		return -1;
	}
	return meal_amount * tip_rate;
}

