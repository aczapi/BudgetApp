#include "incomeManager.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include "cmath"
#include "helpMethods.hpp"

IncomeManager::IncomeManager(std::string NAME_OF_INCOME_FILE_, int LOGGED_IN_USER_ID_)
    : incomeFile(NAME_OF_INCOME_FILE_), loggedInUserId(LOGGED_IN_USER_ID_) {
}

void IncomeManager::addIncome() {
    std::string incomeDate = "";
    std::cout << " >>> ADD INCOME <<<\n";
    std::cout << "---------------------------\n";

    std::cout << "Add income with Today's date? Confirm by pressing <y> ";
    auto input = HelpMethods::getChar();
    if (input == 'y' || input == 'Y') {
        incomeDate = dateManager.convertDateToString(dateManager.getTodayDate());
    } else {
        incomeDate = dateManager.getDateInCorrectFormat();
    }

    income = enterIncomeWithDate(incomeDate);
    incomes.push_back(income);
    incomeFile.saveIncomeToFile(income);
}

Income IncomeManager::enterIncomeWithDate(std::string incomeDate) {
    std::string itemName = "";
    float amount = 0.0;

    income.setIncomeId(getIdOfLastIncome() + 1);
    income.setUserId(loggedInUserId);
    income.setDate(incomeDate);

    std::cout << "Kind of income: \n";
    itemName = HelpMethods::getLine();
    income.setItem(itemName);
    std::cout << "Enter amount: \n";

    amount = HelpMethods::getAmount();

    amount = round(amount * 100) / 100;
    income.setAmount(amount);

    return income;
}

int IncomeManager::getIdOfLastIncome() {
    return incomeFile.getIdOfLastIncome();
}

void IncomeManager::loadLoggedInUserIncomes() {
    incomes = incomeFile.loadIncomesFromFile(loggedInUserId);
}

std::vector<Income> IncomeManager::sort(std::vector<Income> incomes) {
    std::sort(incomes.begin(), incomes.end());
    return incomes;
}

void IncomeManager::displayIncome(Income& income) {
    std::cout << "\nIncome's ID:      " << income.getIncomeId() << "\n";
    std::cout << "Date:             " << income.getDate() << "\n";
    std::cout << "Kind of income:   " << income.getItem() << "\n";
    std::cout << "Amount:           " << income.getAmount() << "\n";
}

float IncomeManager::getSumOfIncomes() {
    return sumOfIncomes;
}

bool operator<(Income& firstIncome, Income& secondIncome) {
    return firstIncome.getDateAsInt() < secondIncome.getDateAsInt();
}

void IncomeManager::displayIncomesOfCurrentMonth() {
    sumOfIncomes = 0.0;
    std::vector<Income> incomesFromCurrentMonth{};
    incomesFromCurrentMonth = getIncomesFromCurrentMonth(incomesFromCurrentMonth);

    if (!incomesFromCurrentMonth.empty()) {
        std::vector<Income> sortedIncomesFromCurrentMonth{};
        sortedIncomesFromCurrentMonth = sort(incomesFromCurrentMonth);

        std::vector<Income>::iterator itr = sortedIncomesFromCurrentMonth.begin();
        std::cout << "INCOMES: \n";
        while (itr != sortedIncomesFromCurrentMonth.end()) {
            if (dateManager.isDateFromCurrentMonth(itr->getDate())) {
                sumOfIncomes += itr->getAmount();
                displayIncome(*itr);
            }
            itr++;
        }
        std::cout << "\nSum of incomes from current month is: " << sumOfIncomes << "\n\n";

    } else
        std::cout << "There are no incomes in current month.\n";
}

Income IncomeManager::addSelectedIncomes(std::vector<Income>::iterator itr) {
    income.setIncomeId(itr->getIncomeId());
    income.setUserId(itr->getUserId());
    income.setDate(itr->getDate());
    income.setItem(itr->getItem());
    income.setAmount(itr->getAmount());
    income.setDateAsInt(dateManager.convertDateToLongInt(itr->getDate()));

    return income;
}

std::vector<Income> IncomeManager::getIncomesFromCurrentMonth(std::vector<Income>& incomesFromCurrentMonth) {
    std::vector<Income>::iterator itr = incomes.begin();
    while (itr != incomes.end()) {
        if (dateManager.isDateFromCurrentMonth(itr->getDate())) {
            incomesFromCurrentMonth.push_back(addSelectedIncomes(itr));
        }
        itr++;
    }
    return incomesFromCurrentMonth;
}

void IncomeManager::displayIncomesOfPreviousMonth() {
    sumOfIncomes = 0.0;
    std::vector<Income> incomesFromPreviousMonth{};
    incomesFromPreviousMonth = getIncomesFromPreviousMonth(incomesFromPreviousMonth);

    if (!incomesFromPreviousMonth.empty()) {
        std::vector<Income> sortedIncomesFromPreviousMonth{};
        sortedIncomesFromPreviousMonth = sort(incomesFromPreviousMonth);

        std::vector<Income>::iterator itr = sortedIncomesFromPreviousMonth.begin();
        std::cout << "INCOMES: \n";
        while (itr != sortedIncomesFromPreviousMonth.end()) {
            if (dateManager.isDateFromPreviousMonth(itr->getDate())) {
                sumOfIncomes += itr->getAmount();
                displayIncome(*itr);
            }
            itr++;
        }
        std::cout << "\nSum of incomes from previous month is: " << sumOfIncomes << "\n\n";
    } else
        std::cout << "There are no incomes in previous month.\n";
}

std::vector<Income> IncomeManager::getIncomesFromPreviousMonth(std::vector<Income>& incomesFromPreviousMonth) {
    std::vector<Income>::iterator itr = incomes.begin();
    while (itr != incomes.end()) {
        if (dateManager.isDateFromPreviousMonth(itr->getDate())) {
            incomesFromPreviousMonth.push_back(addSelectedIncomes(itr));
        }
        itr++;
    }
    return incomesFromPreviousMonth;
}

void IncomeManager::displayIncomesOfSelectedPeriod(std::string startDate, std::string endDate) {
    sumOfIncomes = 0.0;
    std::vector<Income> incomesFromSelectedPeriod{};
    incomesFromSelectedPeriod = getIncomesFromSelectedPeriod(startDate, endDate, incomesFromSelectedPeriod);

    if (!incomesFromSelectedPeriod.empty()) {
        std::vector<Income> sortedIncomesFromSelectedPeriod{};
        sortedIncomesFromSelectedPeriod = sort(incomesFromSelectedPeriod);
        std::vector<Income>::iterator itr = sortedIncomesFromSelectedPeriod.begin();
        std::cout << "INCOMES: \n";
        while (itr != sortedIncomesFromSelectedPeriod.end()) {
            if (dateManager.isDateFromSelectedPeriod(startDate, endDate, itr->getDate())) {
                sumOfIncomes += itr->getAmount();
                displayIncome(*itr);
            }
            itr++;
        }
        std::cout << "\nSum of incomes from " << startDate << " to " << endDate << " is " << sumOfIncomes << "\n\n";
    } else
        std::cout << "There are no incomes in given time period.\n";
}

std::vector<Income> IncomeManager::getIncomesFromSelectedPeriod(std::string startDate, std::string endDate, std::vector<Income>& incomesFromSelectedPeriod) {
    std::vector<Income>::iterator itr = incomes.begin();
    while (itr != incomes.end()) {
        if (dateManager.isDateFromSelectedPeriod(startDate, endDate, itr->getDate())) {
            incomesFromSelectedPeriod.push_back(addSelectedIncomes(itr));
        }
        itr++;
    }
    return incomesFromSelectedPeriod;
}
