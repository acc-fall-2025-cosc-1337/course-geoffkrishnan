#include <iostream>
#include <iomanip>
#include <hwexpressions.h>

using std::cout;
using std::cin;
using std::endl;

using std::setprecision;
using std::setw;
using std::fixed;
using std::left;
using std::right;



int main() {
	double meal_amount, tip_rate;
	
	//get and store user input from console
	cout << "Enter meal subtotal before tax (e.g., 15.75): $";
	cin >> meal_amount;
	cout << "\nEnter tip percent(e.g., 20, 14.34): ";
	cin >> tip_rate;

	//calc total
	double sales_tax = get_sales_tax_amount(meal_amount);
	double tip_amount = get_tip_amount(meal_amount, tip_rate);
	double total = meal_amount + sales_tax + tip_amount;

	//format and print receipt to console
	cout << "          Receipt" << endl;		//$ is a character so it doesn't get left aligned with the strings 
	cout << fixed << setprecision(2); 		   //or right aligned with doubles
	cout << left << setw(15) << "Meal amount: " <<  '$' << right << setw(9) << meal_amount << endl;
	cout << left << setw(15) << "Sales tax: "   <<  '$' << right << setw(9) << sales_tax << endl;
	cout << left << setw(15) << "Tip amount: "  <<  '$' << right << setw(9) << tip_amount << endl;
	cout << left << setw(15) << "Total: "       <<  '$' << right << setw(9) << total << endl << endl;

	return 0;
}