#pragma once
#include <iostream>

class HelpMethods {
public:
    static int convertStringToInt(std::string stringToConvert);
    static float convertStringToFloat(std::string stringToConvert);
    static std::string convertFloatToString(float numberToConvert);
    static std::string convertIntToString(int numberToConvert);
    static char getChar();
    static void doPause();
    static std::string getLine();
    static std::string changeFirstLetterToUpperCaseAndOthersToLowerCase(std::string input);
    static float getAmount();
};
