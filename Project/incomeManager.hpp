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

    void displayIncomesOfCurrentMonth();
    void displayIncomesOfPreviousMonth();
    void displayIncomesOfSelectedPeriod(std::string& startDate, std::string& endDate);
    void loadLoggedInUserIncomes();
    void displayIncome(Income& income);

    std::vector<Income> sort(std::vector<Income>& incomes);
    std::vector<Income> getIncomesFromCurrentMonth(std::vector<Income>& incomesFromCurrentMonth);
    std::vector<Income> getIncomesFromPreviousMonth(std::vector<Income>& incomesFromPreviousMonth);
    std::vector<Income> getIncomesFromSelectedPeriod(std::string& startDate, std::string& endDate, std::vector<Income>& incomesFromSelectedPeriod);
    Income addSelectedIncomes(std::vector<Income>::iterator& itr);
    float getSumOfIncomes();

private:
    std::vector<Income> incomes;
    int loggedInUserId;
    float sumOfIncomes;

    Income enterIncomeWithDate(std::string incomeDate);
    int getIdOfLastIncome();
};