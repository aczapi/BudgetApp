#pragma once

#include <vector>
#include "Markup.h"
#include "user.hpp"

class UserFile {
public:
    UserFile(std::string userFileName);
    void saveUserToFile(User user);
    std::vector<User> loadAllUsersFromFile();
    void changeUserPasswordAtFile(int loggedInUserId, std::string newPassword);

private:
    const std::string USER_FILE_NAME_;
    CMarkup xml_;
};