#include "date.hpp"
#include <ctime>

#include "stdio.h"

#include <iostream>

Date::Date(){};

Date::Date(int year, int month, int day)
    : year_(year), month_(month), day_(day) {
}

void Date::setYear(int year) {
    year_ = year;
}
void Date::setMonth(int month) {
    month_ = month;
}
void Date::setDay(int day) {
    day_ = day;
}

//today as a default??

Date Date::Today(Date today) {
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    today.setYear(now->tm_year + 1900);
    today.setMonth(now->tm_mon + 1);
    today.setDay(now->tm_mday);

    return today;
}

bool Date::isLeapYear(int year) {
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        return true;

    return false;
}

bool Date::isDateCorrect() {
    static const int minYear = 2000;
    static const int maxYear = 2100;

    if (year_ < minYear || year_ > maxYear)
        return false;

    if (day_ <= 0)
        return false;

    const int firstMonth = 1;
    const int lastMonth = 12;

    if (month_ < firstMonth || month_ > lastMonth)
        return false;

    int daysInMonth = 31;

    switch (month_) {
    case 2:
        daysInMonth = (isLeapYear(year_)) ? 29 : 28;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        daysInMonth = 30;
        break;
    }

    if (daysInMonth < day_)
        return false;

    return true;
}

bool Date::isBeforeLastDayOfCurrentMonth(const Date& date, const Date& today) {
    if (date.year_ < today.year_)
        return true;
    if (date.year_ == today.year_ && date.month_ <= today.month_)
        return true;

    return false;
}

void Date::showDate() const {
    if (month_ < 10 && day_ > 9)
        std::cout << year_ << "-0" << month_ << "-" << day_ << '\n';
    if (month_ > 9 && day_ < 10)
        std::cout << year_ << "-" << month_ << "-0" << day_ << '\n';
    if (month_ < 10 && day_ < 10)
        std::cout << year_ << "-0" << month_ << "-0" << day_ << '\n';
    if (month_ > 9 && day_ > 9)
        std::cout << year_ << "-" << month_ << "-" << day_ << '\n';
}

std::string Date::getWrongDateErrorMessage(WrongDate error) {
    switch (error) {
    case WrongDate::Ok:
        return "OK";
    case WrongDate::WrongFormat:
        return "Date should be in format yyyy-mm-dd";
    case WrongDate::NotALeapYear:
        return "It is not a leap year";
    case WrongDate::BeforeLastDayOfCurrentMonth:
        return "Date has to be up to the last day of the current month";
    }
    return {};
}

Date::WrongDate Date::checkDates(Date& date, Date& today) {
    int lastDayOfFebruaryInLeapYear = 29;
    int secondMonth = 2;

    if ((date.getDay() == lastDayOfFebruaryInLeapYear) && (date.getMonth() == secondMonth) && (!date.isLeapYear(date.getYear()))) {
        return WrongDate::NotALeapYear;
    }
    if (!date.isDateCorrect()) {
        return WrongDate::WrongFormat;
    }
    if (!date.isBeforeLastDayOfCurrentMonth(date, today)) {
        return WrongDate::BeforeLastDayOfCurrentMonth;
    }
    return WrongDate::Ok;
}
