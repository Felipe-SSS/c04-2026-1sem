// Antônio Vinícius Costa Alves Ferreira - 2282
// Felipe Soares dos Santos Silveira - 843
// Kauã de Oliveira Ribeiro - 777
// Lívia Vilela Ribeiro Guimarães - 797
// Luiz Henrique Azevedo de Carvalho - 813
// Vitor Nolasco Ynoguti - 818

#include <iostream>
#include <iomanip>
#include <string>
#include "structs.h"
#include "btree.h"
#include "calc.h"
#include "extra.h"
#include "graphs.h"
#include "plots.h"

using namespace std;

void insert()
{
    cout << "\nFeature in development." << endl;
}

void remove()
{
    cout << "\nFeature in development." << endl;
}

void meaning()
{
    cout << "\nFeature in development." << endl;
}

void synonyms()
{
    cout << "\nFeature in development." << endl;
}

void similarity()
{
    cout << "\nFeature in development." << endl;
}

void listByAlphabet()
{
    cout << "\nFeature in development." << endl;
}

void listBySize()
{
    cout << "\nFeature in development." << endl;
}

// Function responsible for displaying the main menu
int menu() {
    int option;

    while (true) {
        cout << "\n=== MAIN MENU ===\n";
        cout << "1. Insert Word\n";
        cout << "2. Remove Word\n";
        cout << "3. Meaning\n";
        cout << "4. Synonyms\n";
        cout << "5. Calculate Similarity\n";
        cout << "6. List Words by Alphabetic Order\n";
        cout << "7. List Words by Size\n";
        cout << "8. Leave\n";
        cout << "Pick an option: ";
        
        cin >> option;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Try again.\n";
            continue;
        }

        switch (option) {
            case 1:
                return 1;

            case 2:
                return 2;

            case 3:
                return 3;

            case 4:
                return 4;

            case 5:
                return 5;

            case 6:
                return 6;

            case 7:
                return 7;

            case 8:
                return 0;

            default:
                cout << "Invalid option.\n";
        }
    }
}

// Function to display menu again or end process
bool displayMenuAgain() {
    int option;
    
    while (true) {
        cout << "\nDo you wish to pick another option?\n";
        cout << "1. Yes\n";
        cout << "0. No\n\n";

        cin >> option;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Try again.\n";
            continue;
        }
        
        switch (option) {
            case 0:
                cout << "\nEnding process...\n";
                return false;
            case 1:
                cout << "\nReturning to the menu...\n";
                return true;
            default:
                cout << "Invalid option.\n";
        }
    }           
}

int main()
{
    // Variable that represents the option the user picks from the menu
    int option;
    // Variable that determines if the menu should be displayed
    bool displayMenu = true;
    
    // Main loop
    while (true) {
        if (displayMenu) {
            option = menu();
        }
        else {
            break;
        }
        
        // Logic responsible for calling the different functions based on the user's choice
        switch(option) {
            case 0:
                cout << "\nEnding process...\n";
                return 0;

            case 1:
                insert();
                break;
            case 2:
                remove();
                break;
            case 3:
                meaning();
                break;
            case 4:
                synonyms();
                break;
            case 5:
                similarity();
                break;
            case 6:
                listByAlphabet();
                break;
            case 7:
                listBySize();
                break;
        }
        
        // Following the execution of a valid option, as if the user would like to pick another on end the process
        displayMenu = displayMenuAgain();
    }

    return 0;
}