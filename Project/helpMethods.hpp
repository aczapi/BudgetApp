#pragma once
#include <iostream>
#include <string>

class HelpMethods {
public:
    static int convertStringToInt(std::string stringToConvert);
    static char getChar();
    static void doPause();
    static char chooseOptionFromMainMenu();
};
