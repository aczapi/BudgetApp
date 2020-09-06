#include "budgetApp.hpp"

BudgetApplication::BudgetApplication() {}

void BudgetApplication::userRegister() {
    userManager.userRegister();
}
void BudgetApplication::userLogIn() {
    userManager.userLogIn();
    //  if(uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    // {
    //     adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI,uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    // }
}

void BudgetApplication::displayallUsers() {
    userManager.displayAllUsers();
}

void BudgetApplication::changeLoggedInUserPassword() {
    userManager.changeLoggedInUserPassword();
}

void BudgetApplication::userLogOut() {
    userManager.userLogOut();
    // delete adresatMenedzer;
    // adresatMenedzer = NULL;
}

bool BudgetApplication::isUserLoggedIn() {
    return userManager.isUserLoggedIn();
}

void BudgetApplication::addIncome() {}
void BudgetApplication::addExpense() {}
void BudgetApplication::displayBalanceOfCurrentMonth() {}
void BudgetApplication::displayBalanceOfPreviousMonth() {}
void BudgetApplication::displayBalanceOfSelectedPeriod() {}