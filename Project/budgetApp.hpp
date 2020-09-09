#pragma once
#include "userManager.hpp"

class BudgetApplication {
public:
    BudgetApplication(std ::string userFileName);
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
};