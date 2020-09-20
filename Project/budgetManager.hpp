#pragma once
#include "expenseManager.hpp"
#include "incomeManager.hpp"

class BudgetManager {
public:
    void addIncome();
    void addExpense();
    void displayBalanceOfCurrentMonth();
    void displayBalanceOfPreviousMonth();
    void displayBalanceOfSelectedPeriod();

    BudgetManager(std::string NAME_OF_INCOMES_FILE_, std::string NAME_OF_EXPENSES_FILE_, int LOGGED_IN_USER_ID_);

private:
    IncomeManager incomeManager;
    ExpenseManager expenseManager;
    DateManager dateManager;
};