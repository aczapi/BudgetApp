#pragma once
#include <string>
#include "date.hpp"

class User {
public:
    void setUserId(int userId);
    void setUserName(std::string name);
    void setUserSurname(std::string surname);
    void setUserLogin(std::string login);
    void setUserPassword(std::string password);

    int getUserId() { return userId_; };
    std::string getUserName() { return name_; };
    std::string getUserSurname() { return surname_; };
    std::string getUserLogin() { return login_; };
    std::string getUserPassword() { return password_; };

private:
    int userId_;
    std::string name_;
    std::string surname_;
    std::string login_;
    std::string password_;
};