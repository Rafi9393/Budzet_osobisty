#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H
#include <iostream>
#include <vector>


#include "Markup.h"
#include "User.h"
#include "XmlFile.h"

using namespace std;

class FileWithUsers :public XmlFile
{
public:
    FileWithUsers(string fileName) : XmlFile(fileName) {};
    vector <User> readUsersFromFile();
    void writeUserToFile(User user);
};

#endif
