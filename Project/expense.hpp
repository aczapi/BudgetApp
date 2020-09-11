#pragma once
#include <string>
#include <vector>
#include "date.hpp"

class Expense {
public:
    void setUserId(int userId);
    void setExpenseId(int expenseId);
    void setDate(std::string date);
    void setItem(std::string item);
    void setAmount(float amount);

    int getUserId() { return userId_; };
    int getExpenseId() { return expenseId_; };
    std::string getDate() { return date_; };
    std::string getItem() { return item_; };
    float getAmount() { return amount_; };

private:
    int userId_;
    int expenseId_;
    std::string date_;
    std::string item_;
    float amount_;
};