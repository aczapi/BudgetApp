#include "userManager.hpp"
#include <iostream>
#include "helpMethods.hpp"

#include <algorithm>

UserManager::UserManager(std::string fileName)
    : userFile(fileName) {
    loggedInUserId = 0;
    users = userFile.loadAllUsersFromFile();
}

std::string UserManager::Password::getErrorMessage(const ErrorCode error) {
    switch (error) {
    case ErrorCode::Ok:
        return "Password set correctly";
    case ErrorCode::PasswordNeedsAtLeastNineCharacters:
        return "Password needs at least nine characters";
    case ErrorCode::PasswordNeedsAtLeastOneNumber:
        return "Password needs at least one number";
    case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
        return "Password needs at least one special character";
    case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
        return "Password needs at least one uppercase letter";
    case ErrorCode::PasswordsDoesNotMatch:
        return "Passwords does not match";
    }
    return {};
}
bool UserManager::Password::doesPasswordsMatch(const std::string& password, const std::string& repeatedPassword) {
    return password == repeatedPassword;
}

UserManager::Password::ErrorCode UserManager::Password::checkPasswordRules(const std::string& password) {
    if (password.length() < MINIMUM_PASSWORD_LENGTH) {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }

    if (std::none_of(password.begin(), password.end(), ::isdigit)) {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }

    if (std::all_of(password.begin(), password.end(), ::isalnum)) {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }

    if (std::none_of(password.begin(), password.end(), ::isupper)) {
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }

    return ErrorCode::Ok;
}

UserManager::Password::ErrorCode UserManager::Password::checkPassword(const std::string& password, const std::string& repeatedPassword) {
    if (!doesPasswordsMatch(password, repeatedPassword)) {
        return ErrorCode::PasswordsDoesNotMatch;
    }

    return checkPasswordRules(password);
}

void UserManager::userRegister() {
    User user = enterDataOfUser();
    users.push_back(user);

    userFile.saveUserToFile(user);

    std::cout << "Account was set up successfully\n";
    HelpMethods::doPause();
}

User UserManager::enterDataOfUser() {
    User user;

    void setUserId(int userId);
    std::string name, surname, login, password;
    user.setUserId(getNewUserId());

    std::cout << "Enter name: ";
    name = HelpMethods::getLine();
    user.setUserName(HelpMethods::changeFirstLetterToUpperCaseAndOthersToLowerCase(name));
    std::cout << "Enter surname: ";
    surname = HelpMethods::getLine();
    user.setUserSurname(HelpMethods::changeFirstLetterToUpperCaseAndOthersToLowerCase(surname));

    do {
        std::cout << "Enter login: ";
        login = HelpMethods::getLine();
        user.setUserLogin(login);
    } while (doesLoginAlreadyExist(user.getUserLogin()) == true);

    password = setAndCheckPassword(user);
    user.setUserPassword(password);
    return user;
}

int UserManager::getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}

bool UserManager::doesLoginAlreadyExist(std::string loginToCheck) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getUserLogin() == loginToCheck) {
            std::cout << "\nLogin already exists. Try another one.\n";
            return true;
        }
    }
    return false;
}

void UserManager::displayAllUsers() {
    system("clear");
    for (int i = 0; i < users.size(); i++) {
        std::cout << users[i].getUserId() << "\n";
        std::cout << users[i].getUserName() << "\n";
        std::cout << users[i].getUserSurname() << "\n";
        std::cout << users[i].getUserLogin() << "\n";
        std::cout << users[i].getUserPassword() << "\n\n";
    }
    HelpMethods::doPause();
}

void UserManager::userLogIn() {
    User user;

    std::string login = "";
    std::cout << "\nEnter login: ";
    login = HelpMethods::getLine();

    std::string password = "";

    for (int i = 0; i < users.size(); i++) {
        if (users[i].getUserLogin() == login) {
            for (int tries = 3; tries > 0; tries--) {
                std::cout << "Enter password. You have " << tries << " tries: ";
                password = HelpMethods::getLine();
                if (users[i].getUserPassword() == password) {
                    std::cout << "\nYou are logged in.\n";
                    HelpMethods::doPause();
                    loggedInUserId = users[i].getUserId();
                    return;
                }
            }
            std::cout << "You have entered password incorrectly 3 times.\n";
            HelpMethods::doPause();
            return;
        }
    }
    std::cout << "There is no user that match entered login.\n";
    HelpMethods::doPause();
}

std::string UserManager::setAndCheckPassword(User& user) {
    std::string password;
    std::string repeatedPassword = "";
    UserManager::Password::ErrorCode result;

    do {
        std::cout << "Set new password: ";
        password = HelpMethods::getLine();
        std::cout << "Repeat password: ";
        repeatedPassword = HelpMethods::getLine();
        result = UserManager::Password::checkPassword(password, repeatedPassword);
        std::cout << UserManager::Password::getErrorMessage(result) << '\n';
        std::cin.get();
    } while (result != UserManager::Password::ErrorCode::Ok);
    return password;
}
void UserManager::changeLoggedInUserPassword() {
    User user;

    std::string password = "";

    for (int i = 0; i < users.size(); i++) {
        if (users[i].getUserId() == loggedInUserId) {
            password = setAndCheckPassword(user);

            user.setUserPassword(password);
            userFile.changeUserPasswordAtFile(loggedInUserId, password);
            std::cout << "Password has been changed.\n";
            HelpMethods::doPause();
        }
        users = userFile.loadAllUsersFromFile();  //refactor
    }
}

void UserManager::userLogOut() {
    loggedInUserId = 0;
}

bool UserManager::isUserLoggedIn() {
    if (loggedInUserId > 0)
        return true;
    else
        return false;
}

int UserManager::getLoggedInUserId() {
    return loggedInUserId;
}
