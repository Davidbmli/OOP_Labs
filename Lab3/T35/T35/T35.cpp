#include <iostream>
#include <string>
using namespace std;

class Bank {
private:
    string username;
    string password;
    double balance;
    static int userCount;
    bool isLoggedIn;

public:
    Bank(string user, string pass) : username(user), password(pass), balance(0.0), isLoggedIn(false) {
        userCount++;
    }

    ~Bank() {
        userCount--;
    }

    bool login(string user, string pass) {
        if (user == username && pass == password) {
            isLoggedIn = true;
            cout << "Login successful!" << endl;
            return true;
        }
        else {
            cout << "Invalid credentials." << endl;
            return false;
        }
    }

    void deposit(double amount) {
        if (!isLoggedIn) {
            cout << "Please log in first." << endl;
            return;
        }
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. Amount: $" << amount << endl;
        }
        else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (!isLoggedIn) {
            cout << "Please log in first." << endl;
            return;
        }
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. Amount: $" << amount << endl;
        }
        else {
            cout << "Insufficient balance or invalid amount." << endl;
        }
    }

    void displayBalance() const {
        if (!isLoggedIn) {
            cout << "Please log in first." << endl;
            return;
        }
        cout << "Current balance: $" << balance << endl;
    }

    static int getUserCount() {
        return userCount;
    }
};

int Bank::userCount = 0;

int main() {
    Bank user1("bujor_david", "password123");

    string inputUser, inputPass;
    cout << "Enter username: ";
    cin >> inputUser;
    cout << "Enter password: ";
    cin >> inputPass;

    if (user1.login(inputUser, inputPass)) {
        int choice;
        do {
            cout << "\n1. Deposit\n2. Withdraw\n3. Display Balance\n4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                double depositAmount;
                cout << "Enter deposit amount: ";
                cin >> depositAmount;
                user1.deposit(depositAmount);
                break;
            case 2:
                double withdrawAmount;
                cout << "Enter withdrawal amount: ";
                cin >> withdrawAmount;
                user1.withdraw(withdrawAmount);
                break;
            case 3:
                user1.displayBalance();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
            }
        } while (choice != 4);
    }

    cout << "\nTotal active users: " << Bank::getUserCount() << endl;
    return 0;
}
