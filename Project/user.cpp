#include "user.hpp"

void User::setUserId(int userId) {
    if (userId >= 0)
        userId_ = userId;
}
void User::setUserName(std::string name) {
    name_ = name;
}
void User::setUserSurname(std::string surname) {
    surname_ = surname;
}
void User::setUserLogin(std::string login) {
    login_ = login;
}
void User::setUserPassword(std::string password) {
    password_ = password;
}
