#pragma once

class Date {
public:
    //class Invalid {};

    Date(int year, int month, int day);
    //~Date();

    Date Today(Date date);

    int getYear() { return year_; };
    int getMonth() { return month_; };
    int getDay() { return day_; };

    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);

    bool isLeapYear(int year);
    bool isDateCorrect();
    bool isBeforeLastDayOfActualMonth(const Date& date, const Date& today);

    void showDate() const;

private:
    int year_;
    int month_;
    int day_;
};
