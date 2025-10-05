#include <iostream>
#include "repetition.h"
using std::cout;
using std::cin;
using std::endl;



int main() {
    int choice;
    int number;
    
    do 
    {
        // Display menu
        cout << "\nHomework 4 Menu\n";
        cout << "1-Factorial\n";
        cout << "2-Sum odd numbers\n";
        cout << "3-Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) 
        {
            case 1:
                // Get and validate input for factorial
                cout << "Enter a number (must be > 0 and < 10): ";
                cin >> number;
                
                while (number <= 0 || number >= 10) 
                {
                    cout << "Invalid input! Number must be greater than 0 and less than 10.\n";
                    cout << "Enter a number: ";
                    cin >> number;
                }
                
                cout << "Factorial of " << number << " is: " << get_factorial(number) << endl;
                break;
                
            case 2:
                // Get and validate input for sum of odd numbers
                cout << "Enter a number (must be > 0 and < 100): ";
                cin >> number;
                
                while (number <= 0 || number >= 100) 
                {
                    cout << "Invalid input! Number must be greater than 0 and less than 100.\n";
                    cout << "Enter a number: ";
                    cin >> number;
                }
                
                cout << "Sum of odd numbers from 1 to " << number << " is: " << sum_odd_numbers(number) << endl;
                break;
                
            case 3:
                cout << "Exiting program. Goodbye!\n";
                break;
                
            default:
                cout << "Invalid choice! Please select 1, 2, or 3.\n";
                break;
        }
        
    } while (choice != 3);  
    
    return 0;
}