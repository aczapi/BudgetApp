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

std::string HelpMethods::convertFloatToString(float numberToConvert) {
    std::ostringstream ss;
    ss << numberToConvert;
    std::string str = ss.str();
    return str;
}

float HelpMethods::getAmount() {
    float amount = 0.0;
    std::string input;
    while (true) {
        getline(std::cin, input);
        for (int i = 0; i < input.length(); ++i) {
            if (input[i] == ',') {
                input[i] = '.';
            }
        }
        std::stringstream myStream(input);
        if (myStream >> amount && amount >= 0.0)
            break;
        std::cout << "It is not an amount. Try again\n";
    }
    return amount;
}