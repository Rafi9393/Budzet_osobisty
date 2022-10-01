#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <vector>
#include <windows.h>


#include "FileWithUsers.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UserManager
{

    vector <User> users;
    FileWithUsers fileWithUsers;

    User readNewUserData();
    bool isLoginExists(string login);
    int readNewUserId();
//    void printUsers();

public:

    int loggedUserId;
    UserManager(string fileName) :fileWithUsers(fileName)
    {
        users = fileWithUsers.readUsersFromFile();
        loggedUserId = 0;
    }
    bool isUserLoggedIn();
    void userRegistration();


};

#endif
