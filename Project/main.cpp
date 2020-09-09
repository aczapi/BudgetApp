#include <chrono>
#include <iostream>
#include <vector>
#include "budgetApp.hpp"
#include "date.hpp"
#include "dateManager.hpp"
#include "helpMethods.hpp"
#include "user.hpp"
#include "userManager.hpp"

#include "Markup.h"

int main() {
    BudgetApplication budgetApplication("Users.xml");
    char choice;

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

   
    // //to get data //
    // std::string strFindName = "Aga";
    // xml.ResetPos();
    // xml.FindElem();
    // xml.IntoElem();
    // while (xml.FindElem("User")) {
    //     xml.FindChildElem("Login");
    //     if (xml.GetChildData() == strFindName)
    //         std::cout << strFindName << "\n";
    //     strFindName = xml.GetDoc();

    //     //break;  // found
    // }

    // //INCOMES
    // CMarkup xml;
    // bool fileExists = xml.Load("incomes.xml");

    // if (!fileExists) {
    //     xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    //     xml.AddElem("Incomes");
    // }

    // xml.FindElem();
    // xml.IntoElem();
    // xml.AddElem("IncomeId");
    // xml.IntoElem();
    // xml.AddElem("UserId", "3");
    // xml.AddElem("Date", "2020-08-26");
    // xml.AddElem("Item", "salary");
    // xml.AddElem("Amount", "4000");
    // xml.Save("incomes.xml");

    // //EXPENCES
    // CMarkup xml;
    // bool fileExists = xml.Load("expenses.xml");

    // if (!fileExists) {
    //     xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    //     xml.AddElem("Expenses");
    // }

    // xml.FindElem();
    // xml.IntoElem();
    // xml.AddElem("ExpenseId");
    // xml.IntoElem();
    // xml.AddElem("UserId", "3");
    // xml.AddElem("Date", "2020-01-01");
    // xml.AddElem("Item", "food");
    // xml.AddElem("Amount", "80");
    // xml.Save("expenses.xml");

    //Date date(2000, 1, 1);
    // auto today = date.Today(date);

    // std::cout << "\n";
    // std::string enteredDate = "";

    // std::cout << "Enter date in format yyyy-mm-dd: \n";
    // std::cin >> enteredDate;
    // date.setYear(enteredDate);
    // date.setMonth(enteredDate);
    // date.setDay(enteredDate);

    // std::cout << "Today is: ";
    // today.showDate();

    // auto result = date.checkDates(date, today);
    // std::cout << date.getWrongDateErrorMessage(result) << '\n';
    // date.showDate();

    // std::cout << "\n";

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

    //Date date;
    //DateManager date;
    //auto today = date.getTodayDate();

    // DateManager dateToSet;
    // std::cout << "\n";
    // std::string enteredDate = "";

    // std::cout << "Enter date in format yyyy-mm-dd: \n";
    // std::cin >> enteredDate;
    // // dateToSet.getYear(enteredDate);
    // // dateToSet.getMonth(enteredDate);
    // // dateToSet.getDay(enteredDate);

    // auto result = dateToSet.checkDate(enteredDate);
    // std::cout << dateToSet.getWrongDateErrorMessage(result) << '\n';

    return 0;
}