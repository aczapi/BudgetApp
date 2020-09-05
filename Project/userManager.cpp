#include "userManager.hpp"
#include <iostream>

#include <algorithm>

void UserManager::registerUser() {
    User user = enterDataOfUser();
    users.push_back(user);

    //save to file

    std::cout << "Account was set up successfully\n";
    system("pause");
}

User UserManager::enterDataOfUser() {
    User user;

    // user.ustawId(pobierzIdNowegoUzytkownika());

    // string login;
    // do
    // {
    //     cout << "Podaj login: ";
    //     cin >> login;
    //     uzytkownik.ustawLogin(login);
    // }
    //  while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    // string haslo;
    // cout << "Podaj haslo: ";
    // cin >> haslo;
    // uzytkownik.ustawHaslo(haslo);

    // return uzytkownik;
}