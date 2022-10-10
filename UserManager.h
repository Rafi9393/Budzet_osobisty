#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <vector>
#include <windows.h>


#include "FileWithUsers.h"
#include "AuxiliaryMethods.h"
#include "User.h"

using namespace std;

class UserManager
{
    int loggedUserId;
    vector <User> users;
    FileWithUsers fileWithUsers;

    User readNewUserData();
    bool isLoginExists(string login);
    int readNewUserId();

public:
    UserManager(string fileName) :fileWithUsers(fileName)
    {
        users = fileWithUsers.readUsersFromFile();
        loggedUserId = 0;
    }
    void setLoggedUserId(int id);
    int getLoggedUserId();
    bool isUserLoggedIn();
    void userRegistration();
    int userLogin();
    void userLogout();
    void changeLoggedUserPassword();
};

#endif
