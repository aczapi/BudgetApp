#pragma once
#include <memory>
#include "budgetManager.hpp"
#include "userManager.hpp"

class BudgetApplication {
public:
    BudgetApplication(std ::string USER_FILE_NAME, std::string INCOMES_FILE_NAME, std::string EXPENSES_FILE_NAME);
    ~BudgetApplication(){};
    void userRegister();
    void userLogIn();
    void displayallUsers();

    void changeLoggedInUserPassword();
    void userLogOut();
    bool isUserLoggedIn();
    void addIncome();
    void addExpense();
    void displayBalanceOfCurrentMonth();
    void displayBalanceOfPreviousMonth();
    void displayBalanceOfSelectedPeriod();

private:
    UserManager userManager;
    const std::string incomesFileName;
    const std::string expensesFileName;
    std::shared_ptr<BudgetManager> budgetManager;
};