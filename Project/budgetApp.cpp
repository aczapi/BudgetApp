#include "budgetApp.hpp"
#include "helpMethods.hpp"

BudgetApplication::BudgetApplication(std::string USER_FILE_NAME, std::string INCOMES_FILE_NAME, std::string EXPENSES_FILE_NAME)
    : userManager(USER_FILE_NAME), incomesFileName(INCOMES_FILE_NAME), expensesFileName(EXPENSES_FILE_NAME) {}

char BudgetApplication::chooseOptionFromMainMenu() {
    char choice;

    system("clear");
    std::cout << "    >>> MAIN MENU  <<<\n";
    std::cout << "---------------------------\n";
    std::cout << "1. Register\n";
    std::cout << "2. Log in\n";
    std::cout << "9. Exit\n";
    std::cout << "---------------------------\n";
    std::cout << "You choose: \n";
    choice = HelpMethods::getChar();

    return choice;
}

char BudgetApplication::chooseOptionFromUserMenu() {
    char choice;

    std::cin.ignore();
    system("clear");
    std::cout << " >>> USER MENU <<<\n";
    std::cout << "---------------------------\n";
    std::cout << "1. Add income.\n";
    std::cout << "2. Add expense.\n";
    std::cout << "3. Display financial balance of the current month.\n";
    std::cout << "4. Display financial balance prom previous month.\n";
    std::cout << "5. Display financial balance from selected period.\n";
    std::cout << "---------------------------\n";
    std::cout << "6. Change password.\n";
    std::cout << "7. Log out.\n";
    std::cout << "---------------------------\n";
    std::cout << "You choose: \n";
    choice = HelpMethods::getChar();

    return choice;
}
void BudgetApplication::doPause() {
    HelpMethods::doPause();
}

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