#include "userFile.hpp"
#include "helpMethods.hpp"

UserFile::UserFile(std::string userFileName)
    : USER_FILE_NAME_(userFileName) {}

void UserFile::saveUserToFile(User user) {
    bool fileExists = xml.Load(USER_FILE_NAME_.c_str());

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("USERS");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("USER");
    xml.IntoElem();
    xml.AddElem("USERID", user.getUserId());
    xml.AddElem("NAME", user.getUserName());
    xml.AddElem("SURNAME", user.getUserSurname());
    xml.AddElem("LOGIN", user.getUserLogin());
    xml.AddElem("PASSWORD", user.getUserPassword());
    xml.Save(USER_FILE_NAME_.c_str());
}

std::vector<User> UserFile::loadAllUsersFromFile() {
    std::vector<User> users;
    User user;
    // bool fileExists = xml.Load(USER_FILE_NAME_.c_str());

    //     if (!fileExists) {
    //         xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    //         xml.AddElem("USERS");
    //     }

    xml.Load(USER_FILE_NAME_.c_str());

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("USER")) {
        xml.IntoElem();
        xml.FindElem("USERID");
        user.setUserId(HelpMethods::convertStringToInt(xml.GetData()));
        xml.FindElem("NAME");
        user.setUserName(xml.GetData());
        xml.FindElem("SURNAME");
        user.setUserSurname(xml.GetData());
        xml.FindElem("LOGIN");
        user.setUserLogin(xml.GetData());
        xml.FindElem("PASSWORD");
        user.setUserPassword(xml.GetData());
        xml.OutOfElem();
        users.push_back(user);
    }
    return users;
}
void UserFile::changeUserPasswordAtFile(int loggedInUserId, std::string newPassword) {
    xml.Load(USER_FILE_NAME_.c_str());

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("USER")) {
        xml.IntoElem();
        xml.FindElem("USERID");
        if (HelpMethods::convertStringToInt(xml.GetData()) == loggedInUserId) {
            xml.FindElem("PASSWORD");
            xml.SetData(newPassword);
            break;
        }
        xml.OutOfElem();
    }
    xml.Save(USER_FILE_NAME_.c_str());
}
