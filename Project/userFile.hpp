#pragma once

#include <iostream>
#include <vector>
#include "Markup.h"
#include "user.hpp"

class UserFile {
public:
    UserFile(std::string fileName);
    void saveUserToFile(User user);
    std::vector<User> loadAllUsersFromFile();
    void changeUserPasswordAtFile(int loggedInUserId, std::string newPassword);

    // std::string getFileName();
    // bool isFileEmpty();

private:
    const std::string FILE_NAME_;
    CMarkup xml;
};