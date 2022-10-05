#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H
#include <iostream>
#include <vector>

#include "XmlFile.h"
#include "Expense.h"
#include "Markup.h"

using namespace std;


class FileWithExpenses :public XmlFile
{
    int lastExpenseId;
//    void printExpenses(vector <Expense> expenses);
public:
    FileWithExpenses(string nameOfFileWithExpenses) : XmlFile(nameOfFileWithExpenses) {};
    int getLastExpenseId();
    void writeExpenseToFile(Expense expense);
    vector <Expense> readExpensesFromFile(int loggedUserId);

};

#endif
