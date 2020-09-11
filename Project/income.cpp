#include "income.hpp"

void Income::setUserId(int userId) {
    if (userId >= 0)
        userId_ = userId;
}
void Income::setIncomeId(int incomeId) {
    if (incomeId >= 0)
        incomeId_ = incomeId;
}
void Income::setDate(std::string date) {
    date_ = date;
}
void Income::setItem(std::string item) {
    item_ = item;
}
void Income::setAmount(float amount) {
    if (amount > 0)
        amount_ = amount;
}