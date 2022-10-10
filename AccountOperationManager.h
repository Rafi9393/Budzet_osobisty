#ifndef ACCOUNTOPERATIONMANAGER_H
#define ACCOUNTOPERATIONMANAGER_H
#include <iostream>
#include <vector>
#include <algorithm>

#include "FileWithExpenses.h"
#include "FileWithIncomes.h"
#include "Income.h"
#include "Expense.h"
#include "AuxiliaryMethods.h"
#include "OperationsWithDates.h"

using namespace std;


class AccountOperationsManager
{

    FileWithExpenses fileWithExpenses;
    FileWithIncomes fileWithIncomes;
    const int LOGGED_USER_ID;
    vector <Income> incomes;
    vector <Expense> expenses;

    Income readNewIncomeData();
    Expense readNewExpenseData();
    float readAmount();
    vector <Income> findMonthIncomes(int month);
    vector <Expense> findMonthExpenses(int month);
    vector <Income> findPeriodicIncomes(int beginningDate, int endDate);
    vector <Expense> findPeriodicExpenses(int beginningDate, int endDate);
    void sortIncomesVectorByDate( vector <Income> &incomes);
    void sortExpensesVectorByDate( vector <Expense> &expenses);
    float printIncomesBalance(vector <Income> incomes);
    float printExpensesBalance(vector <Expense> expenses);
    void printColoredBalance(float balance);

public:
    AccountOperationsManager(string nameOffileWithExpenses, string nameOffileWithIncomes, int LOGGEDUSERID)
        : fileWithExpenses(nameOffileWithExpenses), fileWithIncomes(nameOffileWithIncomes), LOGGED_USER_ID(LOGGEDUSERID)
    {
        incomes = fileWithIncomes.readIncomesFromFile(LOGGED_USER_ID);
        expenses = fileWithExpenses.readExpensesFromFile(LOGGED_USER_ID);
    }
    void addIncome();
    void addExpense();
    void currentMonthBalance();
    void lastMonthBalance();
    void periodicMonthBalance();
};

#endif
