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

std::string HelpMethods::convertIntToString(int numberToConvert) {
    std::ostringstream ss;
    ss << numberToConvert;
    std::string str = ss.str();
    return str;
}
char HelpMethods::getChar() {
    std::string input = "";
    char sign = {0};

    while (true) {
        getline(std::cin, input);

        if (input.length() == 1) {
            sign = input[0];
            break;
        }
        std::cout << "It is not a single sign. Try again.\n";
    }
    return sign;
}

void HelpMethods::doPause() {
    std::cin.ignore();
    std::cout << "Press the Enter key to continue.";
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

char HelpMethods::chooseOptionFromUserMenu() {
    char choice;

    system("clear");
    std::cout << " >>> USER MENU <<<\n";
    std::cout << "---------------------------\n";
    std::cout << "1. Add income.\n";
    std::cout << "2. Add expense.\n";
    std::cout << "3. Display financial balance of the current month.\n";
    std::cout << "4. Display financial balance prom previous month.\n";
    std::cout << "5. Display financial balance from selected period.\n";
    std::cout << "---------------------------\n";
    std::cout << "6. Change password.\n";
    std::cout << "7. Log out.\n";
    std::cout << "---------------------------\n";
    std::cout << "You choose: \n";
    choice = getChar();

    return choice;
}

std::string HelpMethods::getLine() {
    std::string input = "";
    getline(std::cin, input);
    return input;
}

std::string HelpMethods::changeFirstLetterToUpperCaseAndOthersToLowerCase(std::string input) {
    if (!input.empty()) {
        transform(input.begin(), input.end(), input.begin(), ::tolower);
        input[0] = toupper(input[0]);
    }
    return input;
}

float HelpMethods::convertStringToFloat(std::string stringToConvert) {
    float number;
    std::istringstream iss(stringToConvert);
    iss >> number;

    return number;
}