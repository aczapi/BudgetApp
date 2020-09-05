#pragma once

#include <string>
#include <vector>

class DateManager {
public:
    DateManager();
    Date getTodayDate();

    enum class WrongDate {
        Ok,
        WrongFormat,
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

    //void showDate() const;
    //std::ostream& showDate(std::ostream& out);

    //helpMethods
    int convertStringToInt(std::string stringToConvert);

private:
    Date date_;
    Date today_;
    const std::string START_DATE_;
    const int SECONDS_PER_DAY_;
};