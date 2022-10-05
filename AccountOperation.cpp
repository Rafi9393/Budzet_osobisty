#include "AccountOperation.h"

void AccountOperation::setUserId(int userId)
{
    this->userId = userId;
}

void AccountOperation::setDate(int date)
{
    this->date = date;
}

void AccountOperation::setItem(string item)
{
    this->item = item;
}

void AccountOperation::setAmount(float amount)
{
    this->amount = amount;
}

int AccountOperation::getUserId()
{
    return userId;
}
int AccountOperation::getDate()
{
    return date;
}

string AccountOperation::getItem()
{
    return item;
}

float AccountOperation::getAmount()
{
    return amount;
}
