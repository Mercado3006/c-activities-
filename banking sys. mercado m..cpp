#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <ctime>
#include <iomanip>

using namespace std;

// Structure for storing transaction details
struct Transaction {
    char type[20];        // "DEPOSIT" or "WITHDRAW"
    double amount;
    double balance;       // Balance after transaction
    char date[30];       // Date and time of transaction
    char description[100]; // Transaction description
};

class Bank {
private:
    char name[50];
    long long accountNum;
    char type[20];
    double balance;
    char password[20];
    Transaction history[100];  // Array to store last 100 transactions
    int transCount;           // Counter for transactions

    void addTransaction(const char* type, double amount, const char* desc) {
        if(transCount < 100) {
            // Get current date and time
            time_t now = time(0);
            strftime(history[transCount].date, 30, "%Y-%m-%d %H:%M:%S", localtime(&now));
            
            strcpy(history[transCount].type, type);
            history[transCount].amount = amount;
            history[transCount].balance = balance;
            strcpy(history[transCount].description, desc);
            
            transCount++;
        }
    }

public:
    Bank() {
        balance = 0;
        transCount = 0;
    }

    void createAccount() {
        cout << "\nEnter Your Full Name: ";
        cin.ignore();
        cin.getline(name, 50);
        
        cout << "Enter Account Type (Savings/Current): ";
        cin >> type;
        
        cout << "Enter Password: ";
        cin >> password;
        
        cout << "Enter Initial Deposit Amount: $";
        cin >> balance;
        
        // Generate random account number
        accountNum = rand() % 900000000 + 100000000;
        
        // Record initial deposit in transaction history
        if(balance > 0) {
            addTransaction("DEPOSIT", balance, "Initial deposit");
        }
        
        cout << "\nAccount Created Successfully!";
        cout << "\nYour Account Number is: " << accountNum;
    }

    bool login(long long accNum, char pass[]) {
        if(accountNum == accNum && strcmp(password, pass) == 0)
            return true;
        return false;
    }

    void deposit() {
        double amount;
        char desc[100];
        
        cout << "\nEnter Amount to Deposit: $";
        cin >> amount;
        
        cout << "Enter Description: ";
        cin.ignore();
        cin.getline(desc, 100);
        
        if(amount > 0) {
            balance += amount;
            addTransaction("DEPOSIT", amount, desc);
            cout << "\nDeposit Successful";
            cout << "\nNew Balance: $" << fixed << setprecision(2) << balance;
        } else {
            cout << "\nInvalid Amount";
        }
    }

    void withdraw() {
        double amount;
        char desc[100];
        
        cout << "\nEnter Amount to Withdraw: $";
        cin >> amount;
        
        cout << "Enter Description: ";
        cin.ignore();
        cin.getline(desc, 100);
        
        if(amount > 0 && amount <= balance) {
            balance -= amount;
            addTransaction("WITHDRAW", amount, desc);
            cout << "\nWithdrawal Successful";
            cout << "\nRemaining Balance: $" << fixed << setprecision(2) << balance;
        } else {
            cout << "\nInvalid Amount or Insufficient Balance";
        }
    }

    void checkBalance() {
        cout << "\nAccount Holder: " << name;
        cout << "\nAccount Number: " << accountNum;
        cout << "\nAccount Type: " << type;
        cout << "\nCurrent Balance: $" << fixed << setprecision(2) << balance;
    }

    void showTransactionHistory() {
        cout << "\n^^^^^ Transaction History ^^^^^\n";
        cout << setfill('=') << setw(80) << "=" << setfill(' ') << endl;
        cout << left << setw(25) << "Date/Time" 
             << setw(10) << "Type"
             << right << setw(15) << "Amount"
             << setw(15) << "Balance"
             << "   Description" << endl;
        cout << setfill('=') << setw(80) << "=" << setfill(' ') << endl;

        for(int i = transCount - 1; i >= 0; i--) {
            cout << left << setw(25) << history[i].date 
                 << setw(10) << history[i].type
                 << right << setw(15) << fixed << setprecision(2) << history[i].amount
                 << setw(15) << history[i].balance
                 << "   " << history[i].description << endl;
        }
        cout << setfill('=') << setw(80) << "=" << setfill(' ') << endl;
    }

    long long getAccountNum() {
        return accountNum;
    }
};

int main() {
    Bank accounts[100];  // Array to store accounts
    int numAccounts = 0;
    int choice;
    bool loggedIn = false;
    int currentAccount = -1;
    
    // Seed random number generator
    srand(time(0));

    while(1) {
        if(!loggedIn) {
            cout << "\n^^^^^ BANK MANAGEMENT SYSTEM ^^^^^";
            cout << "\n1. Create New Account";
            cout << "\n2. Login to Account";
            cout << "\n3. Exit";
            cout << "\nEnter your choice: ";
            cin >> choice;

            switch(choice) {
                case 1: {
                    if(numAccounts < 100) {
                        accounts[numAccounts].createAccount();
                        numAccounts++;
                    } else {
                        cout << "\nMaximum account limit reached!";
                    }
                    break;
                }
                case 2: {
                    long long accNum;
                    char pass[20];
                    cout << "\nEnter Account Number: ";
                    cin >> accNum;
                    cout << "Enter Password: ";
                    cin >> pass;
                    
                    for(int i = 0; i < numAccounts; i++) {
                        if(accounts[i].login(accNum, pass)) {
                            loggedIn = true;
                            currentAccount = i;
                            cout << "\nLogin Successful!";
                            break;
                        }
                    }
                    if(!loggedIn) {
                        cout << "\nInvalid Account Number or Password!";
                    }
                    break;
                }
                case 3: {
                    cout << "\nThank you for using our banking system!\n";
                    return 0;
                }
                default: {
                    cout << "\nInvalid Choice!";
                }
            }
        } else {
            cout << "\n^^^^^ ACCOUNT MENU ^^^^^";
            cout << "\n1. Deposit";
            cout << "\n2. Withdraw";
            cout << "\n3. Check Balance";
            cout << "\n4. Transaction History";
            cout << "\n5. Logout";
            cout << "\nEnter your choice: ";
            cin >> choice;

            switch(choice) {
                case 1: {
                    accounts[currentAccount].deposit();
                    break;
                }
                case 2: {
                    accounts[currentAccount].withdraw();
                    break;
                }
                case 3: {
                    accounts[currentAccount].checkBalance();
                    break;
                }
                case 4: {
                    accounts[currentAccount].showTransactionHistory();
                    break;
                }
                case 5: {
                    loggedIn = false;
                    currentAccount = -1;
                    cout << "\nLogout Successful!";
                    break;
                }
                default: {
                    cout << "\nInvalid Choice!";
                }
            }
        }
    }
    return 0;
}
