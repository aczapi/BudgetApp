#include "helpMethods.hpp"
#include <algorithm>
#include <sstream>

int convertStringToInt(std::string stringToConvert) {
    int number;
    std::istringstream iss(stringToConvert);
    iss >> number;

    return number;
}
