#include <iostream>
#include <stdexcept>
#include "func.h"

using std::endl;
using std::cout;
using std::cin;
using std::fixed;
using std::exception;

int main() {
    int choice;
    
    do {
        // Display menu
        cout << "\nHomework 5 Menu\n";
        cout << "1-Get GC Content\n";
        cout << "2-Get DNA Complement\n";
        cout << "3-Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                string dna;
                cout << "Enter DNA string: ";
                cin >> dna;
                try {
                    double gc = get_gc_content(dna);
                    cout << "GC Content: " << gc << endl;
                }
                catch (const exception& e) {
                    cout << e.what() << endl;
					cout << "Please try again.\n";
                }
                break;
            }
            
            case 2: {
                string dna;
                cout << "Enter DNA string: ";
                cin >> dna;
                try {
                    string reverse_complement = get_dna_complement(dna);
                    cout << "Reverse Complement: " << reverse_complement << endl;
                }

                catch (const exception& e) {
                    cout << e.what() << endl;
					cout << "Please try again.\n"; 
                }
                break;
            }
            
            case 3:
                cout << "Exiting...\n";
                break;
                
            default:
                cout << "Invalid choice! Please enter 1, 2, or 3.\n";
                break;
        }
        
    } while (choice != 3);
    
    return 0;
}
