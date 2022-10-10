#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H
#include <iostream>
#include <vector>



#include "XmlFile.h"

using namespace std;

class FileWithUsers :public XmlFile
{
public:
    FileWithUsers(string fileName) : XmlFile(fileName) {};
    vector <User> readUsersFromFile();
    void writeUserToFile(User user);
    void addUserNewPasswordToFile(User user);
};

#endif
