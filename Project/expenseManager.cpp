#include "expenseManager.hpp"
#include <algorithm>
#include <cmath>
#include "helpMethods.hpp"

ExpenseManager::ExpenseManager(std::string NAME_OF_EXPENSE_FILE_, int LOGGED_IN_USER_ID_)
    : expenseFile(NAME_OF_EXPENSE_FILE_), loggedInUserId(LOGGED_IN_USER_ID_) {
}

void ExpenseManager::addExpense() {
    std::string expenseDate = "";
    std::cout << " >>> ADD EXPENSE <<<\n";
    std::cout << "---------------------------\n";

    std::cout << "Add expense with Today's date? Confirm by pressing <y> ";
    auto input = HelpMethods::getChar();
    if (input == 'y' || input == 'Y') {
        expenseDate = dateManager.convertDateToString(dateManager.getTodayDate());
    } else {
        expenseDate = dateManager.getDateInCorrectFormat();
    }

    expense = enterExpenseWithDate(expenseDate);
    expenses.push_back(expense);
    expenseFile.saveExpenseToFile(expense);
}

Expense ExpenseManager::enterExpenseWithDate(std::string expenseDate) {
    std::string itemName = "";
    float amount = 0.0;

    expense.setExpenseId(getIdOfLastExpense() + 1);
    expense.setUserId(loggedInUserId);
    expense.setDate(expenseDate);

    std::cout << "Kind of expense: \n";
    itemName = HelpMethods::getLine();
    expense.setItem(itemName);
    std::cout << "Enter amount: \n";
    amount = HelpMethods::getAmount();

    amount = round(amount * 100) / 100;
    expense.setAmount(amount);

    return expense;
}

int ExpenseManager::getIdOfLastExpense() {
    return expenseFile.getIdOfLastExpense();
}

void ExpenseManager::loadLoggedInUserExpenses() {
    expenses = expenseFile.loadExpensesFromFile(loggedInUserId);
}

std::vector<Expense> ExpenseManager::sort(std::vector<Expense>& expenses) {
    std::sort(expenses.begin(), expenses.end());
    return expenses;
}

void ExpenseManager::displayExpense(Expense& expense) {
    std::cout << "\nExpense's ID:      " << expense.getExpenseId() << "\n";
    std::cout << "Date:             " << expense.getDate() << "\n";
    std::cout << "Kind of income:   " << expense.getItem() << "\n";
    std::cout << "Amount:           " << expense.getAmount() << "\n";
}

float ExpenseManager::getSumOfExpenses() {
    return sumOfExpenses;
}

bool operator<(Expense& firstExpense, Expense& secondExpense) {
    return firstExpense.getDateAsInt() < secondExpense.getDateAsInt();
}

Expense ExpenseManager::addSelectedExpenses(std::vector<Expense>::iterator& itr) {
    expense.setExpenseId(itr->getExpenseId());
    expense.setUserId(itr->getUserId());
    expense.setDate(itr->getDate());
    expense.setItem(itr->getItem());
    expense.setAmount(itr->getAmount());
    expense.setDateAsInt(dateManager.convertDateToLongInt(itr->getDate()));

    return expense;
}

void ExpenseManager::displayExpensesOfCurrentMonth() {
    sumOfExpenses = 0.0;
    std::vector<Expense> expensesFromCurrentMonth;
    expensesFromCurrentMonth = getExpensesFromCurrentMonth(expensesFromCurrentMonth);
    if (!expensesFromCurrentMonth.empty()) {
        std::vector<Expense> sortedExpensesFromCurrentMonth{};
        sortedExpensesFromCurrentMonth = sort(expensesFromCurrentMonth);

        std::vector<Expense>::iterator itr = sortedExpensesFromCurrentMonth.begin();
        std::cout << "EXPENSES: \n";
        while (itr != sortedExpensesFromCurrentMonth.end()) {
            if (dateManager.isDateFromCurrentMonth(itr->getDate())) {
                sumOfExpenses += itr->getAmount();
                displayExpense(*itr);
            }
            itr++;
        }
        std::cout << "\nSum of expenses from current month is: " << sumOfExpenses << "\n\n";
    } else
        std::cout << "There are no expenses in current month\n";
}

std::vector<Expense> ExpenseManager::getExpensesFromCurrentMonth(std::vector<Expense>& expensesFromCurrentMonth) {
    std::vector<Expense>::iterator itr = expenses.begin();
    while (itr != expenses.end()) {
        if (dateManager.isDateFromCurrentMonth(itr->getDate())) {
            expensesFromCurrentMonth.push_back(addSelectedExpenses(itr));
        }
        itr++;
    }
    return expensesFromCurrentMonth;
}

void ExpenseManager::displayExpensesOfPreviousMonth() {
    std::vector<Expense> expensesFromPreviousMonth;
    expensesFromPreviousMonth = getExpensesFromPreviousMonth(expensesFromPreviousMonth);
    if (!expensesFromPreviousMonth.empty()) {
        std::vector<Expense> sortedExpensesFromPreviousMonth{};
        sortedExpensesFromPreviousMonth = sort(expensesFromPreviousMonth);

        sumOfExpenses = 0.0;

        std::vector<Expense>::iterator itr = sortedExpensesFromPreviousMonth.begin();
        std::cout << "EXPENSES: \n";
        while (itr != sortedExpensesFromPreviousMonth.end()) {
            if (dateManager.isDateFromPreviousMonth(itr->getDate())) {
                sumOfExpenses += itr->getAmount();
                displayExpense(*itr);
            }
            itr++;
        }
        std::cout << "\nSum of expenses from previous month is: " << sumOfExpenses << "\n\n";
    } else
        std::cout << "There are no expenses in previous month\n";
}

std::vector<Expense> ExpenseManager::getExpensesFromPreviousMonth(std::vector<Expense>& expensesFromPreviousMonth) {
    std::vector<Expense>::iterator itr = expenses.begin();
    while (itr != expenses.end()) {
        if (dateManager.isDateFromPreviousMonth(itr->getDate())) {
            expensesFromPreviousMonth.push_back(addSelectedExpenses(itr));
        }
        itr++;
    }
    return expensesFromPreviousMonth;
}

void ExpenseManager::displayExpensesOfSelectedPeriod(std::string& startDate, std::string& endDate) {
    sumOfExpenses = 0.0;
    std::vector<Expense> expensesFromSelectedPeriod;
    expensesFromSelectedPeriod = getExpensesFromSelectedPeriod(startDate, endDate, expensesFromSelectedPeriod);

    if (!expensesFromSelectedPeriod.empty()) {
        std::vector<Expense> sortedExpensesFromSelectedPeriod{};
        sortedExpensesFromSelectedPeriod = sort(expensesFromSelectedPeriod);

        std::vector<Expense>::iterator itr = sortedExpensesFromSelectedPeriod.begin();
        std::cout << "EXPENSES: \n";
        while (itr != sortedExpensesFromSelectedPeriod.end()) {
            if (dateManager.isDateFromSelectedPeriod(startDate, endDate, itr->getDate())) {
                sumOfExpenses += itr->getAmount();
                displayExpense(*itr);
            }
            itr++;
        }
        std::cout << "\nSum of expenses from " << startDate << " to " << endDate << " is " << sumOfExpenses << "\n\n";
    } else
        std::cout << "There are no expenses in given time period.\n\n";
}

std::vector<Expense> ExpenseManager::getExpensesFromSelectedPeriod(std::string& startDate, std::string& endDate, std::vector<Expense>& expensesFromSelectedPeriod) {
    std::vector<Expense>::iterator itr = expenses.begin();
    while (itr != expenses.end()) {
        if (dateManager.isDateFromSelectedPeriod(startDate, endDate, itr->getDate())) {
            expensesFromSelectedPeriod.push_back(addSelectedExpenses(itr));
        }
        itr++;
    }
    return expensesFromSelectedPeriod;
}