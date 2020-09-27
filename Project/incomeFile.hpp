#pragma once
#include <vector>
#include "Markup.h"
#include "income.hpp"

class IncomeFile {
public:
    IncomeFile(std::string IncomeFileName);
    void saveIncomeToFile(Income income);
    std::vector<Income> loadIncomesFromFile(int loggedInUserId);
    int getIdOfLastIncome();

private:
    const std::string INCOME_FILE_NAME_;
    int numberOfIncomes_;
    CMarkup xml_;
};