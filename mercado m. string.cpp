#include <iostream>
#include <cstring> // Include the C string library

using namespace std;

// Function to convert a string to lowercase
void strlwr_custom(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to convert a string to uppercase
void strupr_custom(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

// Function to reverse a string
void strrev_custom(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        swap(str[i], str[n - i - 1]);
    }
}

int main() {
    char str1[100], str2[100], str3[200]; // Allocate space for the strings

    // Ask the user to input the strings
    cout << "Enter the first string (str1): ";
    cin.getline(str1, 100); // Input first string
    cout << "Enter the second string (str2): ";
    cin.getline(str2, 100); // Input second string

    // 1. STRLEN
    cout << "Length of str1: " << strlen(str1) << endl;
    cout << "Length of str2: " << strlen(str2) << endl;

    // 2. STRCPY
    strcpy(str3, str1); // Copy str1 to str3
    cout << "After copying, str3: " << str3 << endl;

    // 3. STRCAT
    strcat(str3, str2); // Concatenate str2 to str3
    cout << "After concatenation, str3: " << str3 << endl;

    // 4. STRCMP
    int result = strcmp(str1, str2); // Compare str1 and str2
    if (result < 0) {
        cout << "str1 is less than str2" << endl;
    } else if (result > 0) {
        cout << "str1 is greater than str2" << endl;
    } else {
        cout << "str1 is equal to str2" << endl;
    }

    // 5. STRLWR
    strlwr_custom(str3); // Convert str3 to lowercase
    cout << "str3 in lowercase: " << str3 << endl;

    // 6. STRUPR
    strupr_custom(str3); // Convert str3 to uppercase
    cout << "str3 in uppercase: " << str3 << endl;

    // 7. STRREV
    strrev_custom(str3); // Reverse str3
    cout << "Reversed str3: " << str3 << endl;

    return 0;
}
