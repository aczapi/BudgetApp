#pragma once
#include <vector>
#include "dateManager.hpp"
#include "income.hpp"
#include "incomeFile.hpp"

class IncomeManager {
public:
    DateManager dateManager;
    Income income;
    IncomeFile incomeFile;

    IncomeManager(std::string NAME_OF_INCOME_FILE_, int LOGGED_IN_USER_ID_);

    void addIncome();

    void displayBalanceOfCurrentMonth();
    void displayBalanceOfPreviousMonth();
    void displayBalanceOfSelectedPeriod();

private:
    std::vector<Income> incomes;
    int loggedInUserId;

    Income enterIncomeWithDate(std::string incomeDate);
    int getIdOfLastIncome();
};