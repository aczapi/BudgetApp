#include "expense.hpp"

void Expense::setUserId(int userId) {
    if (userId > 0)
        userId_ = userId;
}
void Expense::setExpenseId(int expenseId) {
    if (expenseId > 0)
        expenseId_ = expenseId;
}
void Expense::setDate(std::string date) {
    date_ = date;
}
void Expense::setItem(std::string item) {
    item_ = item;
}
void Expense::setAmount(float amount) {
    if (amount > 0)
        amount_ = amount;
}