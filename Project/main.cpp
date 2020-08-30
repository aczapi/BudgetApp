#include <iostream>
#include "date.hpp"

#include "Markup.h"

int main() {
    //Date date(2000, 12, 30);

    // CMarkup xml;
    // bool fileExists = xml.Load("users.xml");

    // if (!fileExists) {
    //     xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    //     xml.AddElem("Users");
    // }

    // std::string name = "";
    // std::cin >> name;
    // int userId = 0;
    // std::cin >> userId;
    // std::string surname = "";
    // std::cin >> surname;
    // std::string login = "";
    // std::cin >> login;
    // std::string password = "";
    // std::cin >> password;

    // xml.FindElem();
    // xml.IntoElem();
    // xml.AddElem("User");
    // xml.IntoElem();
    // xml.AddElem("UserId", userId);
    // xml.AddElem("Name", name);
    // xml.AddElem("Surname", surname);
    // xml.AddElem("Login", login);
    // xml.AddElem("Password", password);
    // xml.Save("users.xml");

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

    //INCOMES
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

    //EXPENCES
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
    // xml.AddElem("Date", "2020-08-26");
    // xml.AddElem("Item", "food");
    // xml.AddElem("Amount", "80");
    // xml.Save("expenses.xml");

    std::cout
        << "Hi there!\n";
    Date date(2000, 1, 1);
    auto today = date.Today(date);

    std::cout << "\n";
    int year = 2000;
    int month = 1;
    int day = 1;

    std::cout << "Podaj datę w formacie rrrr-mm--dd: \n";
    std::cin >> year >> month >> day;
    date.setYear(year);
    date.setMonth(month);
    date.setDay(day);

    if (!date.isDateCorrect() || !date.isBeforeLastDayOfActualMonth(date, today))
        std::cout << "Wrong date! Date should be in format yyyy-mm-dd and has to be up to the last day of the current month\n";
    else {
        std::cout << "date correct\n";
        date.showDate();
    }

    today.showDate();

    return 0;
}