#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H
#include <iostream>


#include "AuxiliaryMethods.h"
#include "UserManager.h"
#include "AccountOperationManager.h"

using namespace std;

class PersonalBudget
{
    UserManager userManager;
    AccountOperationsManager *accountOperationsManager;
    const string NAME_OF_THE_FILE_WITH_INCOMES;
    const string NAME_OF_THE_FILE_WITH_EXPENSES;

    char chooseOptionFromMainMenu();
    char chooseOptionFromUserMenu();
    void userRegistration();
    void userLogin();
    void userLogout();
    void addIncome();
    void addExpense();

public:
   PersonalBudget(string fileName, string nameOfTheFileWithIncomes, string nameOfTheFileWithExpenses)
   : userManager(fileName), NAME_OF_THE_FILE_WITH_INCOMES(nameOfTheFileWithIncomes), NAME_OF_THE_FILE_WITH_EXPENSES(nameOfTheFileWithExpenses)  {};
   ~PersonalBudget()
   {
       delete accountOperationsManager;
       accountOperationsManager = NULL;
   }

   void mainApp();
};


#endif
