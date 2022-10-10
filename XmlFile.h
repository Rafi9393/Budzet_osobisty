#ifndef XMLFILE_H
#define XMLFILE_H
#include <iostream>

#include "AuxiliaryMethods.h"
#include "Income.h"
#include "Expense.h"
#include "Markup.h"
#include "User.h"

using namespace std;

class XmlFile
{


public:
    const string FILE_NAME;
    XmlFile(string FILENAME) : FILE_NAME(FILENAME) {};
};

#endif
