#ifndef ACCOUNTOPERATIONMANAGER_H
#define ACCOUNTOPERATIONMANAGER_H
#include <iostream>
#include <vector>

#include "FileWithExpenses.h"
#include "FileWithIncomes.h"
#include "Income.h"
#include "Expense.h"
#include "AuxiliaryMethods.h"
#include "OperationsWithDates.h"

using namespace std;


class AccountOperationsManager
{
    const int LOGGED_USER_ID;

    FileWithIncomes fileWithIncomes;
    FileWithExpenses fileWithExpenses;
    vector <AccountOperation> AccountOperations;
    vector <Income> incomes;
    vector <Expense> expenses;

    Income readNewIncomeData();
    Expense readNewExpenseData();
    string readAndCheckDate();
//    void printExpenses();
    //    void printIncomes();

public:
    AccountOperationsManager(string nameOffileWithExpenses, string nameOffileWithIncomes, int LOGGEDUSERID)
        : fileWithExpenses(nameOffileWithExpenses), fileWithIncomes(nameOffileWithIncomes), LOGGED_USER_ID(LOGGEDUSERID)
    {
        incomes = fileWithIncomes.readIncomesFromFile(LOGGED_USER_ID);
        expenses = fileWithExpenses.readExpensesFromFile(LOGGED_USER_ID);
    }

    void addIncome();
    void addExpense();

};

#endif
