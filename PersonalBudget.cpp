#include "PersonalBudget.h"

void PersonalBudget::userRegistration()
{
    userManager.userRegistration();
}

void PersonalBudget::userLogin()
{
    userManager.userLogin();
    if( userManager.isUserLoggedIn() )
    {
        accountOperationsManager = new AccountOperationsManager(NAME_OF_THE_FILE_WITH_EXPENSES, NAME_OF_THE_FILE_WITH_INCOMES, userManager.getLoggedUserId());
    }
}

void PersonalBudget::userLogout()
{
    userManager.userLogout();
    delete accountOperationsManager;
    accountOperationsManager = NULL;
}

void PersonalBudget::addIncome()
{
    accountOperationsManager -> addIncome();
}

void PersonalBudget::addExpense()
{
    accountOperationsManager -> addExpense();
}

char PersonalBudget::chooseOptionFromMainMenu()
{
    char option;
    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    option = AuxiliaryMethods::readChar();
    return option;
}

char PersonalBudget::chooseOptionFromUserMenu()
{
    char option;
    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego meisiaca" << endl;
    cout << "4. Bilans z poprzedniego meisiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    option = AuxiliaryMethods::readChar();
    return option;
}

void PersonalBudget::mainApp()
{
    while (true)
    {
        if (!userManager.isUserLoggedIn())
        {
            switch (chooseOptionFromMainMenu())
            {
            case '1':
                userRegistration();
                break;
            case '2':
                userLogin();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            switch (chooseOptionFromUserMenu())
            {
            case '1':
                addIncome();
                break;
            case '2':
                addExpense();
                break;
            case '3':
                accountOperationsManager->currentMonthBalance();
                break;
            case '4':
                accountOperationsManager->lastMonthBalance();
                break;
            case '5':
                accountOperationsManager->periodicMonthBalance();
                break;
            case '6':
                userManager.changeLoggedUserPassword();
                break;
            case '7':
                userLogout();
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }
}
