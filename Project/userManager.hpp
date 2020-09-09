#pragma once

#include <vector>
#include "user.hpp"
#include "userFile.hpp"

constexpr size_t MINIMUM_PASSWORD_LENGTH = 9;
class UserManager {
public:
    class Password {
    public:
        enum class ErrorCode {
            Ok,
            PasswordNeedsAtLeastNineCharacters,
            PasswordNeedsAtLeastOneNumber,
            PasswordNeedsAtLeastOneSpecialCharacter,
            PasswordNeedsAtLeastOneUppercaseLetter,
            PasswordsDoesNotMatch
        };

        static std::string getErrorMessage(const ErrorCode error);
        static bool doesPasswordsMatch(const std::string& password, const std::string& repeatedPassword);
        static ErrorCode checkPasswordRules(const std::string& password);
        static ErrorCode checkPassword(const std::string& password, const std::string& repeatedPassword);
    };

    UserManager(std::string fileName);
    void userRegister();
    void userLogIn();
    void changeLoggedInUserPassword();
    void userLogOut();
    bool isUserLoggedIn();
    int getLoggedInUserId();
    void displayAllUsers();

private:
    int loggedInUserId;
    std::vector<User> users;
    UserFile userFile;

    User enterDataOfUser();
    int getNewUserId();
    bool doesLoginAlreadyExist(std::string loginToCheck);
    std::string setAndCheckPassword(User& user);
};