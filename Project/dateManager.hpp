#pragma once

#include <string>
#include <vector>
#include "date.hpp"

static const int MIN_YEAR = 2000;
static const int MAX_YEAR = 2100;
class DateManager {
public:
    DateManager();
    Date getTodayDate();

    enum class WrongDate {
        Ok,
        WrongFormat,
        IncorrectDate,
        NotALeapYear,
        BeforeLastDayOfCurrentMonth
    };
    std::string getWrongDateErrorMessage(WrongDate error);
    WrongDate checkDate(std::string dateToCheck);

    int getYear(std::string enteredDate);
    int getMonth(std::string enteredDate);
    int getDay(std::string enteredDate);

    bool isLeapYear();
    bool isDateCorrect();
    bool isBeforeLastDayOfCurrentMonth(const Date& date, const Date& today);
    std::string convertDateToString(const Date& date);
    int convertDateToLongInt(std::string date);
    std::string getDateInCorrectFormat();

    bool isDateFromCurrentMonth(std::string enteredDate);
    bool isDateFromPreviousMonth(std::string enteredDate);
    bool isDateFromSelectedPeriod(std::string startDate, std::string endDate, std::string enteredDate);
    bool checkIfStartDateIsBeforeEndDate(std::string startDate, std::string endDate);

private:
    Date date_;
    Date today_;
    const std::string START_DATE_;
    const int SECONDS_PER_DAY_;
};