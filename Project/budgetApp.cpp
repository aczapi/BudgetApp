#include "budgetApp.hpp"
#include "helpMethods.hpp"

BudgetApplication::BudgetApplication(std::string USER_FILE_NAME, std::string INCOMES_FILE_NAME, std::string EXPENSES_FILE_NAME)
    : userManager(USER_FILE_NAME), incomesFileName(INCOMES_FILE_NAME), expensesFileName(EXPENSES_FILE_NAME) {}

void BudgetApplication::userRegister() {
    userManager.userRegister();
}
void BudgetApplication::userLogIn() {
    userManager.userLogIn();
    if (userManager.isUserLoggedIn()) {
        budgetManager = std::make_shared<BudgetManager>(incomesFileName, expensesFileName, userManager.getLoggedInUserId());
    }
}

void BudgetApplication::changeLoggedInUserPassword() {
    if (userManager.isUserLoggedIn())
        userManager.changeLoggedInUserPassword();
}

void BudgetApplication::userLogOut() {
    userManager.userLogOut();
}

bool BudgetApplication::isUserLoggedIn() {
    return userManager.isUserLoggedIn();
}

void BudgetApplication::addIncome() {
    if (userManager.isUserLoggedIn()) {
        budgetManager->addIncome();
    } else {
        std::cout << "You are not logged in.\n";
        std::cin.get();
    }
}
void BudgetApplication::addExpense() {
    if (userManager.isUserLoggedIn()) {
        budgetManager->addExpense();
    } else {
        std::cout << "You are not logged in.\n";
        std::cin.get();
    }
}
void BudgetApplication::displayBalanceOfCurrentMonth() {
    if (userManager.isUserLoggedIn()) {
        budgetManager->displayBalanceOfCurrentMonth();
    } else {
        std::cout << "You are not logged in.\n";
        std::cin.get();
    }
}
void BudgetApplication::displayBalanceOfPreviousMonth() {
    if (userManager.isUserLoggedIn()) {
        budgetManager->displayBalanceOfPreviousMonth();
    } else {
        std::cout << "You are not logged in.\n";
        std::cin.get();
    }
}
void BudgetApplication::displayBalanceOfSelectedPeriod() {
    if (userManager.isUserLoggedIn()) {
        budgetManager->displayBalanceOfSelectedPeriod();
    } else {
        std::cout << "You are not logged in.\n";
        std::cin.get();
    }
}