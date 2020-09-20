#include "expenseManager.hpp"

#include <cmath>
#include <iostream>
#include <string>
#include "expenseManager.hpp"
#include "helpMethods.hpp"

ExpenseManager::ExpenseManager(std::string NAME_OF_EXPENSE_FILE_, int LOGGED_IN_USER_ID_)
    : expenseFile(NAME_OF_EXPENSE_FILE_), loggedInUserId(LOGGED_IN_USER_ID_) {
}

void ExpenseManager::addExpense() {
    displayAllExpenses();
    // HelpMethods::doPause();

    std::string expenseDate = "";
    std::cout << " >>> ADD EXPENSE <<<\n";
    std::cout << "---------------------------\n";

    std::cout << "Add expense with Today's date? Confirm by pressing <y> ";
    auto input = HelpMethods::getChar();
    if (input == 'y' || input == 'Y') {
        expenseDate = dateManager.convertDateToString(dateManager.getTodayDate());
    } else {
        expenseDate = dateManager.getDateInCorrectFormat();
    }

    expense = enterExpenseWithDate(expenseDate);
    expenses.push_back(expense);
    expenseFile.saveExpenseToFile(expense);
}

Expense ExpenseManager::enterExpenseWithDate(std::string expenseDate) {
    std::string itemName = "";
    float amount = 0.0;

    expense.setExpenseId(getIdOfLastExpense() + 1);
    expense.setUserId(loggedInUserId);
    expense.setDate(expenseDate);

    std::cout << "Kind of expense: \n";
    itemName = HelpMethods::getLine();
    expense.setItem(itemName);
    std::cout << "Enter amount: \n";
    amount = HelpMethods::getAmount();

    amount = round(amount * 100) / 100;
    expense.setAmount(amount);

    return expense;
}

int ExpenseManager::getIdOfLastExpense() {
    return expenseFile.getIdOfLastExpense();
}

void ExpenseManager::loadLoggedInUserExpenses() {
    expenses = expenseFile.loadExpensesFromFile(loggedInUserId);
}

void ExpenseManager::displayBalanceOfCurrentMonth() {}
void ExpenseManager::displayBalanceOfPreviousMonth() {}
void ExpenseManager::displayBalanceOfSelectedPeriod() {}

void ExpenseManager::displayAllExpenses() {
    system("clear");
    for (int i = 0; i < expenses.size(); i++) {
        std::cout << expenses[i].getExpenseId() << "\n";
        std::cout << expenses[i].getUserId() << "\n";
        std::cout << expenses[i].getDate() << "\n";
        std::cout << expenses[i].getItem() << "\n";
        std::cout << expenses[i].getAmount() << "\n\n";
    }
    HelpMethods::doPause();
}