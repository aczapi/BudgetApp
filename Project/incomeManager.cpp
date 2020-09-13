#include "incomeManager.hpp"
#include <iostream>
#include <string>
#include "helpMethods.hpp"

IncomeManager::IncomeManager(std::string NAME_OF_INCOME_FILE_, int LOGGED_IN_USER_ID_)
    : incomeFile(NAME_OF_INCOME_FILE_), loggedInUserId(LOGGED_IN_USER_ID_) {}

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
};

Income IncomeManager::enterIncomeWithDate(std::string incomeDate) {
    std::string itemName = "";
    float amount = 0.0;

    income.setIncomeId(getIdOfLastIncome());
    income.setUserId(loggedInUserId);
    income.setDate(incomeDate);

    std::cout << "Kind of income: \n";
    itemName = HelpMethods::getLine();
    income.setItem(itemName);
    std::cout << "Enter amount: \n";
    //amount = HelpMethods::
    std::cin >> amount;
    income.setAmount(amount);

    return income;
}

int IncomeManager::getIdOfLastIncome() {
    return incomeFile.getIdOfLastIncome();
}

void IncomeManager::displayBalanceOfCurrentMonth() {}
void IncomeManager::displayBalanceOfPreviousMonth() {}
void IncomeManager::displayBalanceOfSelectedPeriod() {}