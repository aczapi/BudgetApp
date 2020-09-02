#pragma once

#include <string>
#include <vector>

class Date {
public:
    enum class WrongDate {
        Ok,
        WrongFormat,
        NotALeapYear,
        BeforeLastDayOfCurrentMonth
    };
    std::string getWrongDateErrorMessage(WrongDate error);
    WrongDate checkDates(Date& date, Date& today);

    Date();
    Date(int year, int month, int day);

    Date Today(Date date);

    int getYear() { return year_; };
    int getMonth() { return month_; };
    int getDay() { return day_; };

    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);

    bool isLeapYear(int year);
    bool isDateCorrect();
    bool isBeforeLastDayOfCurrentMonth(const Date& date, const Date& today);

    void showDate() const;

private:
    int year_;
    int month_;
    int day_;
};
