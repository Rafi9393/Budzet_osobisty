#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H
#include <iostream>
#include <vector>


#include "XmlFile.h"
#include "Income.h"
#include "Markup.h"

using namespace std;


class FileWithIncomes :public XmlFile
{
    int lastIncomeId;
//    void printIncomes(vector <Income> incomes);
public:
    FileWithIncomes(string nameOfFileWithIncomes) : XmlFile(nameOfFileWithIncomes)
    {
        lastIncomeId = 0;
    }
    int getLastIncomeId();
    void writeIncomeToFile(Income income);
    vector <Income> readIncomesFromFile(int loggedUserId);
};

#endif
