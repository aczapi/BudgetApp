#pragma once
#include <string>
#include <vector>
#include "Markup.h"
#include "income.hpp"

class IncomeFile {
public:
    IncomeFile(std::string IncomeFileName);
    void saveIncomeToFile(Income income);
    std::vector<Income> loadIncomesFromFile();

private:
    const std::string INCOME_FILE_NAME_;
    CMarkup xml;
};