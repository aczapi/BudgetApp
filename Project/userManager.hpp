#pragma once

#include <vector>
#include "user.hpp"

class UserManager {
public:
    UserManager();
    void registerUser();
    void userLogIn();
    void changeLoggedInUserPassword();
    void userLogOut();
    bool isUserLoggedIn();
    int getLoggedInUserId();

private:
    int LoggedInUserId;
    std::vector<User> users;
    //UsersFile usersfile;

    User enterDataOfUser();
    int getNewUserId();
    bool doesLoginExist(std::string loginToCheck);
};