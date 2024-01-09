#include <iostream>
#include <vector>

using namespace std;

class Expense {
public:
    Expense(double amount, string description, string date) {
        this->amount = amount;
        this->description = description;
        this->date = date;
    }

    double getAmount() const { return amount; }
    string getDescription() const { return description; }
    string getDate() const { return date; }

private:
    double amount;
    string description;
    string date;
};

class ExpenseTracker {
public:
    ExpenseTracker() {}

    void addExpense(Expense expense) {
        expenses.push_back(expense);
    }

    void removeLastExpense() {
        if (!expenses.empty()) {
            expenses.pop_back();
        }
    }

    double getTotalExpense() const {
        double total = 0;
        for (const Expense& expense : expenses) {
            total += expense.getAmount();
        }
        return total;
    }

private:
    vector<Expense> expenses;
};

int main() {
    ExpenseTracker expenseTracker;

    expenseTracker.addExpense(Expense(100, "Їжа", "2024-01-09"));
    expenseTracker.addExpense(Expense(200, "Транспорт", "2024-01-10"));

    cout << "Загальна сума витрат: " << expenseTracker.getTotalExpense() << endl;

}