#ifndef EXPENSE_H
#define EXPENSE_H
#include <iostream>

#include "AccountOperation.h"
using namespace std;


class Expense :public AccountOperation
{
    int expenseId;
public:
    void setExpenseId(int expenseId);
    int getExpenseId();

};

#endif
