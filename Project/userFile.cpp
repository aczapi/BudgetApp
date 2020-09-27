#include "userFile.hpp"
#include "helpMethods.hpp"

UserFile::UserFile(std::string userFileName)
    : USER_FILE_NAME_(userFileName) {}

void UserFile::saveUserToFile(User user) {
    bool fileExists = xml_.Load(USER_FILE_NAME_.c_str());

    if (!fileExists) {
        xml_.SetDoc("<?xml_ version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml_.AddElem("USERS");
    }
    xml_.FindElem();
    xml_.IntoElem();
    xml_.AddElem("USER");
    xml_.IntoElem();
    xml_.AddElem("USERID", user.getUserId());
    xml_.AddElem("NAME", user.getUserName());
    xml_.AddElem("SURNAME", user.getUserSurname());
    xml_.AddElem("LOGIN", user.getUserLogin());
    xml_.AddElem("PASSWORD", user.getUserPassword());
    xml_.Save(USER_FILE_NAME_.c_str());
}

std::vector<User> UserFile::loadAllUsersFromFile() {
    std::vector<User> users;
    User user;

    xml_.Load(USER_FILE_NAME_.c_str());

    xml_.ResetPos();
    xml_.FindElem();
    xml_.IntoElem();
    while (xml_.FindElem("USER")) {
        xml_.IntoElem();
        xml_.FindElem("USERID");
        user.setUserId(HelpMethods::convertStringToInt(xml_.GetData()));
        xml_.FindElem("NAME");
        user.setUserName(xml_.GetData());
        xml_.FindElem("SURNAME");
        user.setUserSurname(xml_.GetData());
        xml_.FindElem("LOGIN");
        user.setUserLogin(xml_.GetData());
        xml_.FindElem("PASSWORD");
        user.setUserPassword(xml_.GetData());
        xml_.OutOfElem();
        users.push_back(user);
    }
    return users;
}
void UserFile::changeUserPasswordAtFile(int loggedInUserId, std::string newPassword) {
    xml_.Load(USER_FILE_NAME_.c_str());

    xml_.ResetPos();
    xml_.FindElem();
    xml_.IntoElem();
    while (xml_.FindElem("USER")) {
        xml_.IntoElem();
        xml_.FindElem("USERID");
        if (HelpMethods::convertStringToInt(xml_.GetData()) == loggedInUserId) {
            xml_.FindElem("PASSWORD");
            xml_.SetData(newPassword);
            break;
        }
        xml_.OutOfElem();
    }
    xml_.Save(USER_FILE_NAME_.c_str());
}
