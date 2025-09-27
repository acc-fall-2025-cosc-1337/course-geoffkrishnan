#include <iostream>
#include <decisions.h>

using namespace std;

int main() {
	int choice;
	int grade;

	cout << "MAIN MENU" << endl;
	cout << "1-Letter grade using if" << endl;
	cout << "2-Letter grade using switch" << endl;
	cout << "3-Exit" << endl;

	cin >> choice;

	if (choice == 1) {
		cout << "Enter numerical grade: ";
		cin >> grade;

		if (grade >= 0 && grade <= 100) {
			cout << "Letter grade: " << get_letter_grade_using_if(grade) << endl;
		}
		else {
			cout << "Number is out of range" << endl;
		}
	}
	else if (choice == 2) {
		cout << "Enter numerical grade: ";
		cin >> grade;

		if (grade >= 0 && grade <= 100) {
			cout << "Letter grade: " << get_letter_grade_using_switch(grade) << endl;
		}
		else {
			cout << "Number is out of range" << endl;
		}
	}
	else if (choice == 3) {
		cout << "Goodbye!" << endl;
	}

	return 0;
}