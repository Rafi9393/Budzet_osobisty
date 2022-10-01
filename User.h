#ifndef USER_H
#define USER_H
#include <iostream>

using namespace std;

class User
{
    int id;
    string name;
    string surname;
    string login;
    string password;

public:

    void setId(int id);
    void setName(string name);
    void setSurname(string surname);
    void setLogin(string login);
    void setPassword(string password);

    int getId();
    string getName();
    string getSurname();
    string getLogin();
    string getPassword();


};

#endif
