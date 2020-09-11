#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Markup.h"
#include "expense.hpp"

class ExpenseFile {
public:
    ExpenseFile(std::string ExpenseFileName);
    void saveExpenseToFile(Expense expense);
    std::vector<Expense> loadExpensesFromFile();

private:
    const std::string EXPENSE_FILE_NAME_;
    CMarkup xml;
};