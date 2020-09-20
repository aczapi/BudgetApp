#pragma once
#include <vector>
#include "dateManager.hpp"
#include "expense.hpp"
#include "expenseFile.hpp"

class ExpenseManager {
public:
    DateManager dateManager;
    Expense expense;
    ExpenseFile expenseFile;

    ExpenseManager(std::string NAME_OF_EXPENSE_FILE_, int LOGGED_IN_USER_ID_);

    void addExpense();

    void displayBalanceOfCurrentMonth();
    void displayBalanceOfPreviousMonth();
    void displayBalanceOfSelectedPeriod();
    void loadLoggedInUserExpenses();
    void displayAllExpenses();  //delete later

private:
    std::vector<Expense> expenses;
    int loggedInUserId;

    Expense enterExpenseWithDate(std::string expenseDate);
    int getIdOfLastExpense();
};