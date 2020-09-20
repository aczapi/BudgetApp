#include "incomeManager.hpp"
#include <iostream>
#include <string>
#include "cmath"
#include "helpMethods.hpp"

IncomeManager::IncomeManager(std::string NAME_OF_INCOME_FILE_, int LOGGED_IN_USER_ID_)
    : incomeFile(NAME_OF_INCOME_FILE_), loggedInUserId(LOGGED_IN_USER_ID_) {
}

void IncomeManager::addIncome() {
    displayAllIncomes();
    // HelpMethods::doPause();

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
    displayAllIncomes();
    //  HelpMethods::doPause();
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

void IncomeManager::displayBalanceOfCurrentMonth() {}
void IncomeManager::displayBalanceOfPreviousMonth() {}
void IncomeManager::displayBalanceOfSelectedPeriod() {}

void IncomeManager::displayAllIncomes() {
    system("clear");
    for (int i = 0; i < incomes.size(); i++) {
        std::cout << incomes[i].getIncomeId() << "\n";
        std::cout << incomes[i].getUserId() << "\n";
        std::cout << incomes[i].getDate() << "\n";
        std::cout << incomes[i].getItem() << "\n";
        std::cout << incomes[i].getAmount() << "\n\n";
    }
    HelpMethods::doPause();
}