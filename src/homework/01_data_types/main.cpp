#include <iostream>
#include <data_types.h>
// write namespace using statement for cout
using namespace std;

int main()
{
	int firstResult;
	int secondResult;
	firstResult = multiply_numbers(7, 7);
	secondResult = multiply_numbers(5, 5);
	cout << "7 x 7 = " << firstResult << endl;
	cout << "5 x 5 = " << secondResult << endl;
	return 0;
}
