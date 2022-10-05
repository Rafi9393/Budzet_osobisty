#ifndef INCOME_H
#define INCOME_H
#include <iostream>

#include "AccountOperation.h"

using namespace std;


class Income :public AccountOperation
{
    int incomeId;
public:
    void setIncomeId(int incomeId);
    int getIncomeId();
};

#endif
