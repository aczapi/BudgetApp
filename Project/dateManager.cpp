#include <ctime>

#include "stdio.h"

#include "dateManager.hpp"
#include "helpMethods.hpp"

DateManager::DateManager()
    : START_DATE_("2000-01-01"), SECONDS_PER_DAY_(86400) {
    today_ = getTodayDate();
}

Date DateManager::getTodayDate() {
    Date today;
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);

    today.year_ = now->tm_year + 1900;
    today.month_ = now->tm_mon + 1;
    today.day_ = now->tm_mday;

    return today;
}

int DateManager::getYear(std::string enteredDate) {
    std::string year = "";
    int i = 0;

    while (enteredDate[i] != '-') {
        year += enteredDate[i];
        ++i;
    }
    return date_.year_ = HelpMethods::convertStringToInt(year);
}

int DateManager::getMonth(std::string enteredDate) {
    std::string month = "";

    month = enteredDate.substr(5, 2);
    return date_.month_ = HelpMethods::convertStringToInt(month);
}
int DateManager::getDay(std::string enteredDate) {
    std::string day = "";

    day = enteredDate.substr(8, 2);
    return date_.day_ = HelpMethods::convertStringToInt(day);
}

bool DateManager::isLeapYear() {
    if (((date_.year_ % 4 == 0) && (date_.year_ % 100 != 0)) || (date_.year_ % 400 == 0))
        return true;

    return false;
}

bool DateManager::isDateCorrect() {
    if (date_.year_ < MIN_YEAR)
        return false;

    if (date_.day_ <= 0)
        return false;

    const int firstMonth = 1;
    const int lastMonth = 12;

    if (date_.month_ < firstMonth || date_.month_ > lastMonth)
        return false;

    int daysInMonth = 31;

    switch (date_.month_) {
    case 2:
        daysInMonth = (isLeapYear()) ? 29 : 28;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        daysInMonth = 30;
        break;
    }

    if (daysInMonth < date_.day_)
        return false;

    return true;
}

bool DateManager::isBeforeLastDayOfCurrentMonth(const Date& date, const Date& today) {
    if (date.year_ < today.year_)
        return true;
    if (date.year_ == today.year_ && date.month_ <= today.month_)
        return true;

    return false;
}

std::string DateManager::getWrongDateErrorMessage(WrongDate error) {
    switch (error) {
    case WrongDate::Ok:
        return "Date is correct";
    case WrongDate::WrongFormat:
        return "Date should be in format yyyy-mm-dd";
    case WrongDate::IncorrectDate:
        return "Date is incorrect";
    case WrongDate::NotALeapYear:
        return "It is not a leap year";
    case WrongDate::BeforeLastDayOfCurrentMonth:
        return "Date has to be up to the last day of the current month";
    }
    return {};
}

DateManager::WrongDate DateManager::checkDate(std::string dateToCheck) {
    int lastDayOfFebruaryInLeapYear = 29;
    int secondMonth = 2;

    date_.year_ = getYear(dateToCheck);
    date_.month_ = getMonth(dateToCheck);
    date_.day_ = getDay(dateToCheck);

    if ((date_.day_ == lastDayOfFebruaryInLeapYear) && (date_.month_ == secondMonth) && (!isLeapYear())) {
        return WrongDate::NotALeapYear;
    }
    if (!isDateCorrect()) {
        return WrongDate::IncorrectDate;
    }
    if (!isBeforeLastDayOfCurrentMonth(date_, today_)) {
        return WrongDate::BeforeLastDayOfCurrentMonth;
    }
    return WrongDate::Ok;
}

std::string DateManager::convertDateToString(const Date& date) {
    auto yearString = HelpMethods::convertIntToString(date.year_);
    auto monthString = HelpMethods::convertIntToString(date.month_);
    auto dayString = HelpMethods::convertIntToString(date.day_);

    if (monthString.length() == 1) {
        monthString = '0' + monthString;
    }
    if (dayString.length() == 1) {
        dayString = '0' + dayString;
    }

    auto dateString = yearString + '-' + monthString + '-' + dayString;
    return dateString;
}

std::string DateManager::getDateInCorrectFormat() {
    std::string enteredDate = "";
    DateManager::WrongDate result;

    do {
        std::cout << "\nEnter date in format yyyy-mm-dd: \n";
        enteredDate = HelpMethods::getLine();
        int positionOfFirstDash = 4;
        int positionOfSecondDash = 7;
        int numberOfSignsInCorrectDateFormat = 10;
        char dash = '-';

        if (enteredDate.length() != numberOfSignsInCorrectDateFormat ||
            enteredDate[positionOfFirstDash] != dash ||
            enteredDate[positionOfSecondDash] != dash) {
            result = DateManager::WrongDate::WrongFormat;
            std::cout << DateManager::getWrongDateErrorMessage(result) << '\n';
        } else {
            result = DateManager::checkDate(enteredDate);
            std::cout << DateManager::getWrongDateErrorMessage(result) << '\n';
        }
    } while (result != DateManager::WrongDate::Ok);

    return enteredDate;
}