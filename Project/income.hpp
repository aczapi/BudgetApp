#pragma once
#include <string>

class Income {
public:
    void setUserId(int userId);
    void setIncomeId(int incomeId);
    void setDate(std::string date);
    void setItem(std::string item);
    void setAmount(float amount);
    void setDateAsInt(int dateAsInt);

    int getUserId() { return userId_; };
    int getIncomeId() { return incomeId_; };
    std::string getDate() { return date_; };
    std::string getItem() { return item_; };
    float getAmount() { return amount_; };
    int getDateAsInt() { return dateAsInt_; };

private:
    int userId_;
    int incomeId_;
    std::string date_;
    std::string item_;
    float amount_;
    int dateAsInt_;
};

bool operator<(Income& firstIncome, Income& secondIncome);