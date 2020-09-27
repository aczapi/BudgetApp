#include "budgetManager.hpp"
#include "helpMethods.hpp"

BudgetManager::BudgetManager(std::string NAME_OF_INCOMES_FILE_, std::string NAME_OF_EXPENSES_FILE_, int LOGGED_IN_USER_ID_)
    : incomeManager(NAME_OF_INCOMES_FILE_, LOGGED_IN_USER_ID_), expenseManager(NAME_OF_EXPENSES_FILE_, LOGGED_IN_USER_ID_) {
    incomeManager.loadLoggedInUserIncomes();
    expenseManager.loadLoggedInUserExpenses();
}

void BudgetManager::addIncome() {
    incomeManager.addIncome();
}

void BudgetManager::addExpense() {
    expenseManager.addExpense();
}

void BudgetManager::displayBalanceOfCurrentMonth() {
    system("clear");
    float balance = 0.0;
    incomeManager.displayIncomesOfCurrentMonth();
    expenseManager.displayExpensesOfCurrentMonth();
    balance = incomeManager.getSumOfIncomes() - expenseManager.getSumOfExpenses();
    std::cout << "Balance of current month: \n";
    if (balance >= 0) {
        std::cout << "You have saved: " << balance << "\n";
    } else {
        std::cout << "You exceeded the budget by: " << abs(balance) << "\n";
    }
    HelpMethods::doPause();
}
void BudgetManager::displayBalanceOfPreviousMonth() {
    system("clear");
    float balance = 0.0;
    incomeManager.displayIncomesOfPreviousMonth();
    expenseManager.displayExpensesOfPreviousMonth();
    balance = incomeManager.getSumOfIncomes() - expenseManager.getSumOfExpenses();
    std::cout << "Balance of previous month: \n";
    if (balance >= 0) {
        std::cout << "You have saved: " << balance << "\n";
    } else {
        std::cout << "You exceeded the budget by: " << abs(balance) << "\n";
    }
    HelpMethods::doPause();
}
void BudgetManager::displayBalanceOfSelectedPeriod() {
    std::string startDate = "";
    std::string endDate = "";
    float balance = 0.0;

    do {
        std::cout << "Enter start date for selected period.\n";
        startDate = dateManager.getDateInCorrectFormat();
        std::cout << "Enter end date for selected period.\n";
        endDate = dateManager.getDateInCorrectFormat();
    } while (!dateManager.checkIfStartDateIsBeforeEndDate(startDate, endDate));

    system("clear");
    incomeManager.displayIncomesOfSelectedPeriod(startDate, endDate);
    expenseManager.displayExpensesOfSelectedPeriod(startDate, endDate);

    balance = incomeManager.getSumOfIncomes() - expenseManager.getSumOfExpenses();
    std::cout << "Balance of selected period: \n";
    if (balance >= 0) {
        std::cout << "You have saved: " << balance << "\n";
    } else {
        std::cout << "You exceeded the budget by: " << abs(balance) << "\n";
    }
    HelpMethods::doPause();
}