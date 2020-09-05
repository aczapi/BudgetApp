#pragma once
#include "userManager.hpp"

class BudgetApplication {
public:
        void userRegister();
    void userLogIn();

private:
    UserManager userManager;
};