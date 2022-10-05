#ifndef ACCOUNTOPERATION_H
#define ACCOUNTOPERATION_H
#include <iostream>

using namespace std;


class AccountOperation
{
    int userId;
    int date;
    string item;
    float amount;

public:
    void setUserId(int userId);
    void setDate(int date);
    void setItem(string item);
    void setAmount(float amount);

    int getUserId();
    int getDate();
    string getItem();
    float getAmount();


};

#endif
