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

    void displayExpensesOfCurrentMonth();
    void displayExpensesOfPreviousMonth();
    void displayExpensesOfSelectedPeriod(std::string startDate, std::string endDate);
    void loadLoggedInUserExpenses();
    std::vector<Expense> sort(std::vector<Expense> expenses);
    void displayExpense(Expense& expense);

    std::vector<Expense> getExpensesFromCurrentMonth(std::vector<Expense>& expensesFromCurrentMonth);
    std::vector<Expense> getExpensesFromPreviousMonth(std::vector<Expense>& expensesFromPreviousMonth);
    std::vector<Expense> getExpensesFromSelectedPeriod(std::string startDate, std::string endDate, std::vector<Expense>& expensesFromSelectedPeriod);
    Expense ExpenseManager::addSelectedExpenses(std::vector<Expense>::iterator itr);
    float getSumOfExpenses();

private:
    std::vector<Expense> expenses;
    int loggedInUserId;

    Expense enterExpenseWithDate(std::string expenseDate);
    int getIdOfLastExpense();
    float sumOfExpenses;
};