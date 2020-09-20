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
                budgetApplication.displayallUsers();
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

    // std::vector<Date> vectorOfDates{};
    // Date date1(2019, 12, 11);
    // vectorOfDates.push_back(date1);
    // Date date2(2020, 1, 1);
    // vectorOfDates.push_back(date2);
    // Date date3(2020, 3, 22);
    // vectorOfDates.push_back(date3);
    // Date date4(2020, 5, 8);
    // vectorOfDates.push_back(date4);
    // Date date5(2020, 10, 30);
    // vectorOfDates.push_back(date5);
    // Date date6(2020, 12, 16);
    // vectorOfDates.push_back(date6);

    // for (int i = 0; i < vectorOfDates.size(); ++i) {
    //     vectorOfDates[i].showDate();
    // }

    // Date firstDate;
    // Date secondDate;
    // std::cout << "First date: ";
    // std::cin >> year >> month >> day;
    // firstDate.setYear(year);
    // firstDate.setMonth(month);
    // firstDate.setDay(day);
    // std::cout << '\n';
    // std::cout << "Second date: ";
    // std::cin >> year >> month >> day;
    // secondDate.setYear(year);
    // secondDate.setMonth(month);
    // secondDate.setDay(day);

    // //User user;

    // for (int i = 0; i < vectorOfDates.size(); ++i) {
    //     if (firstDate.getYear() < vectorOfDates[i].getYear() && vectorOfDates[i].getYear() < secondDate.getYear())
    //         vectorOfDates[i].showDate();
    //     if (firstDate.getYear() == vectorOfDates[i].getYear() && firstDate.getMonth() < vectorOfDates[i].getMonth())
    //         vectorOfDates[i].showDate();
    //     if (firstDate.getYear() == vectorOfDates[i].getYear() && firstDate.getMonth() == vectorOfDates[i].getMonth() && firstDate.getDay() <= vectorOfDates[i].getDay())
    //         vectorOfDates[i].showDate();
    //     if (vectorOfDates[i].getYear() == secondDate.getYear() && vectorOfDates[i].getMonth() < secondDate.getMonth())
    //         vectorOfDates[i].showDate();
    //     if (vectorOfDates[i].getYear() == secondDate.getYear() && vectorOfDates[i].getMonth() == secondDate.getMonth() && vectorOfDates[i].getDay() <= secondDate.getDay())
    //         vectorOfDates[i].showDate();
    // }

    // IncomeManager incomeManager("Income.xml", 1);
    // Income income;
    // IncomeFile IncomeFile("Incomes.xml");

    // incomeManager.addIncome();

    return 0;
}