#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <windows.h>
using namespace std;

class BankAccount {
private:
    static int AccountNumber;
public:
    string ownerName;
    int accountNumber;
    double balance;

    BankAccount(string name, double initialBalance) {
        ownerName = name;
        accountNumber = GetAccountNumber();
        balance = initialBalance;
    }

    void Deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Положено " << amount << " $ на рахунок" << endl;
        }
        else {
            cout << "Недоступна сума депозиту." << endl;
        }
    }

    void Withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            cout << "Вилучено " << amount << "$ з рахунку" << endl;
        }
        else {
            cout << "Недостатньо коштів або недоступна сума зняття" << endl;
        }
    }

    double GetBalance() {
        return balance;
    }

    void DisplayInfo() {
        cout << "Ім'я власника: " << ownerName << endl;
        cout << "Номер акаунта: " << accountNumber << endl;
        cout << "Баланс: " << balance << endl;
    }

    static int GetAccountNumber() {
        return ++AccountNumber;
    }
};

int BankAccount::AccountNumber = 100000;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    BankAccount account1("Тарас Шевченко", 1000.0);
    BankAccount account2("Володимир Кравченко", 500.0);

    account1.Deposit(500.0);
    account2.Withdraw(200.0);

    account1.DisplayInfo();
    account2.DisplayInfo();

}