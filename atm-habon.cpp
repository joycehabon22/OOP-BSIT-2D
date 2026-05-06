#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Account {
public:
    int id;
    string name;
    string pin;
    double balance;

    void display() {
        cout << "\nAccount Name: " << name;
        cout << "\nBalance: " << balance << endl;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposit successful!\n";
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!\n";
        } else {
            balance -= amount;
            cout << "Withdrawal successful!\n";
        }
    }

    void changePin(string newPin) {
        pin = newPin;
        cout << "PIN changed successfully!\n";
    }
};

// Save account to file
void saveAccount(Account acc) {
    ofstream file("account.txt");
    file << acc.id << endl;
    file << acc.name << endl;
    file << acc.pin << endl;
    file << acc.balance << endl;
    file.close();
}

// Load account from file
Account loadAccount() {
    Account acc;
    ifstream file("account.txt");
    file >> acc.id;
    file.ignore();
    getline(file, acc.name);
    file >> acc.pin;
    file >> acc.balance;
    file.close();
    return acc;
}

int main() {
    Account acc = loadAccount();

    string inputName, inputPin;
    cout << "Enter Account Name: ";
    getline(cin, inputName);
    cout << "Enter PIN: ";
    cin >> inputPin;

    if (inputName != acc.name || inputPin != acc.pin) {
        cout << "Login failed!\n";
        return 0;
    }

    int choice;
    do {
        cout << "\n--- ATM MENU ---\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Change PIN\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            acc.display();
        } 
        else if (choice == 2) {
            double amount;
            cout << "Enter amount: ";
            cin >> amount;
            acc.deposit(amount);
        } 
        else if (choice == 3) {
            double amount;
            cout << "Enter amount: ";
            cin >> amount;
            acc.withdraw(amount);
        } 
        else if (choice == 4) {
            string newPin;
            cout << "Enter new PIN: ";
            cin >> newPin;
            acc.changePin(newPin);
        }

        saveAccount(acc);

    } while (choice != 5);

    cout << "Thank you for using ATM!\n";
    return 0;
}