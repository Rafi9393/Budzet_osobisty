#include "UserManager.h"


bool UserManager::isUserLoggedIn()
{
    if (loggedUserId > 0)
        return true;
    else
        return false;
}

void UserManager::userRegistration()
{
    User user = readNewUserData();
    users.push_back(user);
    fileWithUsers.writeUserToFile(user);
    cout << "Uzytkownik zostal dodany pomyslnie" << endl;
    system("pause");
}

User UserManager::readNewUserData()
{
    User user;
    string login = "";
    cout << "Podaj imie: ";
    user.setName(AuxiliaryMethods::readLine());
    cout << "Podaj nazwisko: ";
    user.setSurname(AuxiliaryMethods::readLine());
    do
    {
        cout << "Podaj login: ";
        login = AuxiliaryMethods::readLine();
        if(!isLoginExists(login))
            user.setLogin(login);
        else
            cout << "Podany login jest zajety. Sprobuj jeszcze raz." << endl;
    }
    while (isLoginExists(login));

    cout << "Podaj haslo: ";
    user.setPassword(AuxiliaryMethods::readLine());
    user.setId(readNewUserId());
    return user;
}

bool UserManager::isLoginExists(string login)
{
    if (!users.empty())
    {
        for ( size_t i = 0; i < users.size(); i++)
        {
            if ( users[i].getLogin() == login)
                return true;
        }
    }
    return false;
}

int UserManager::readNewUserId()
{
    if (!users.empty())
        return users.back().getId() + 1;
    else
        return 1;

}

//void UserManager::printUsers()
//{
//    for (size_t i = 0; i < users.size(); i++)
//    {
//        cout << users[i].getId() <<". "<< users[i].getName() << endl;
//    }
//}
