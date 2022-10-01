#include "FileWithUsers.h"

vector <User> FileWithUsers::readUsersFromFile()
{
    CMarkup xml;
    User user;
    vector <User> users;
    bool fileExists = xml.Load( FILE_NAME );

    if (fileExists)
    {
        xml.FindElem();
        xml.IntoElem();
        while ( xml.FindElem("User") )
        {
            xml.IntoElem();
            xml.FindElem( "id" );
            user.setId(atoi( MCD_2PCSZ(xml.GetData())));
            xml.FindElem( "Name" );
            user.setName(xml.GetData());
            xml.FindElem( "Surname" );
            user.setSurname(xml.GetData());
            xml.FindElem( "Login" );
            user.setLogin(xml.GetData());
            xml.FindElem( "Password" );
            user.setPassword(xml.GetData());
            xml.OutOfElem();
            users.push_back(user);
        }
    }
    else
    {
        cout << "Plik nie istnieje." <<endl;
    }
    return users;
}

void FileWithUsers::writeUserToFile(User user)
{
    CMarkup xml;
    bool fileExists = xml.Load( FILE_NAME );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("id", user.getId());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());

    xml.Save(FILE_NAME);
}
