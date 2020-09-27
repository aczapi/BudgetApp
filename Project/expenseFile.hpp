#pragma once
#include <vector>
#include "Markup.h"
#include "expense.hpp"

class ExpenseFile {
public:
    ExpenseFile(std::string ExpenseFileName);
    void saveExpenseToFile(Expense expense);
    std::vector<Expense> loadExpensesFromFile(int loggedInUserId);
    int getIdOfLastExpense();

private:
    const std::string EXPENSE_FILE_NAME_;
    int numberOfExpenses_;
    CMarkup xml_;
};