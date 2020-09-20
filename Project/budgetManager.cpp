#include "budgetManager.hpp"

BudgetManager::BudgetManager(std::string NAME_OF_INCOMES_FILE_, std::string NAME_OF_EXPENSES_FILE_, int LOGGED_IN_USER_ID_)
    : incomeManager(NAME_OF_INCOMES_FILE_, LOGGED_IN_USER_ID_), expenseManager(NAME_OF_EXPENSES_FILE_, LOGGED_IN_USER_ID_) {
    incomeManager.loadLoggedInUserIncomes();
    expenseManager.loadLoggedInUserExpenses();
}

void BudgetManager::addIncome() {
    incomeManager.addIncome();
}

void BudgetManager::addExpense() {
    expenseManager.addExpense();
}