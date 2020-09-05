#include "helpMethods.hpp"
#include <algorithm>
#include <sstream>
#include <string>

int HelpMethods::convertStringToInt(std::string stringToConvert) {
    int number;
    std::istringstream iss(stringToConvert);
    iss >> number;

    return number;
}
char HelpMethods::getChar() {
    std::string entry = "";
    char sign = {0};

    while (true) {
        getline(std::cin, entry);

        if (entry.length() == 1) {
            sign = entry[0];
            break;
        }
        std::cout << "It is not a single sign. Try again.\n";
    }
    return sign;
}

void HelpMethods::doPause() {
    std::cin.ignore();
    std::cout << "\nPress the Enter key to continue.";
    std::cin.get();
}

char HelpMethods::chooseOptionFromMainMenu() {
    char choice;

    system("clear");
    std::cout << "    >>> MAIN MENU  <<<\n";
    std::cout << "---------------------------\n";
    std::cout << "1. Register\n";
    std::cout << "2. Log in\n";
    std::cout << "9. Exit\n";
    std::cout << "---------------------------\n";
    std::cout << "You choose: \n";
    choice = getChar();

    return choice;
}