#pragma once
#include <iostream>
#include <string>

class HelpMethods {
public:
    static int convertStringToInt(std::string stringToConvert);
    static float convertStringToFloat(std::string stringToConvert);
    static std::string convertIntToString(int numberToConvert);
    static char getChar();
    static void doPause();
    static char chooseOptionFromMainMenu();
    static char chooseOptionFromUserMenu();
    static std::string getLine();
    static std::string changeFirstLetterToUpperCaseAndOthersToLowerCase(std::string input);
};
