#include <iostream>
#include <limits>
#include <string>

using namespace std;

void printHeader() {
    cout << "===================================\n";
    cout << "          UNIT CONVERTER           \n";
    cout << "===================================\n";
    cout << "Choose the unit type:\n";
    cout << "'c' for centimeters\n";
    cout << "'m' for meters\n";
    cout << "'l' for milliliters\n";
    cout << "===================================\n\n";
}

void convertLength(double value, char unit) {
    cout << "\n-----------------------------------\n";
    switch (unit) {
        case 'c':
            cout << value << " cm is equivalent to:\n";
            cout << value * 10 << " mm (millimeters)\n";
            cout << value / 100 << " m (meters)\n";
            break;
        case 'm': 
            cout << value << " m is equivalent to:\n";
            cout << value * 100 << " cm (centimeters)\n";
            cout << value * 1000 << " mm (millimeters)\n";
            break;
        case 'l': 
            cout << value << " ml is equivalent to:\n";
            cout << value * 10 << " cm³ (cubic centimeters)\n";
            cout << value / 1000 << " m³ (cubic meters)\n";
            break;
        default:
            cout << "Invalid unit type. Please use 'c', 'm', or 'l'.\n";
            break;
    }
    cout << "-----------------------------------\n";
}

int main() {
    double value;
    char unit;
    string continueChoice;

    printHeader();

    while (true) {
        cout << "Enter the value to convert: ";
        if (!(cin >> value)) {
            string exitCommand;
            cin.clear(); 
            cin >> exitCommand;
            cout << "Invalid input. Please enter a numeric value.\n";
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            continue;
        }

        cout << "Enter the unit type (c/m/l): ";
        cin >> unit;

        convertLength(value, unit);

        cout << "Do you want to perform another conversion? (yes/no): ";
        cin >> continueChoice;
        
        if (continueChoice == "no") {
            cout << "\nThank you for using the Unit Converter. Goodbye!\n";
            break;
        } else if (continueChoice != "yes") {
            cout << "Invalid choice. Assuming 'yes'.\n";
        }
    }

    return 0;
}

