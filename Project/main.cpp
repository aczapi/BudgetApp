#include <iostream>
#include "helpMethods.hpp"  //refactor later

#include "budgetApp.hpp"

#include "Markup.h"

int main() {
    BudgetApplication budgetApplication("Users.xml", "Incomes.xml", "Expenses.xml");
    char choice;
    IncomeManager incomeManager("Income.xml", 1);
    Income income;
    IncomeFile IncomeFile("Incomes.xml");

    while (true) {
        if (!budgetApplication.isUserLoggedIn()) {
            choice = HelpMethods::chooseOptionFromMainMenu();

            switch (choice) {
            case '1':
                budgetApplication.userRegister();
                break;
            case '2':
                budgetApplication.userLogIn();
                break;
            case '9':
                exit(0);
                break;
            default:
                std::cout << "Not an option.\n";
                HelpMethods::doPause();
                break;
            }
        } else {
            choice = HelpMethods::chooseOptionFromUserMenu();

            switch (choice) {
            case '1':
                budgetApplication.addIncome();

                break;
            case '2':
                budgetApplication.addExpense();
                break;
            case '3':
                budgetApplication.displayBalanceOfCurrentMonth();
                break;
            case '4':
                budgetApplication.displayBalanceOfPreviousMonth();
                break;
            case '5':
                budgetApplication.displayBalanceOfSelectedPeriod();
                break;
            case '6':
                budgetApplication.changeLoggedInUserPassword();
                break;
            case '7':
                budgetApplication.userLogOut();
                break;
            default:
                std::cout << "Not an option.\n";
                HelpMethods::doPause();
                break;
            }
        }
    }

    return 0;
}