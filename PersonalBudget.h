#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H
#include <iostream>


#include "AuxiliaryMethods.h"
#include "UserManager.h"

using namespace std;

class PersonalBudget
{
    UserManager userManager;

    char chooseOptionFromMainMenu();
    char chooseOptionFromUserMenu();
    void userRegistration();

public:
   PersonalBudget(string fileName) : userManager(fileName) {};
   void mainApp();
};


#endif
