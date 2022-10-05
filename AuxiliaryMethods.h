#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H
#include <iostream>
#include <sstream>

using namespace std;


class AuxiliaryMethods
{
public:
    static char readChar();
    static string readLine();
    static string convertIntToString(int number);
    static float changeCommaToDot(string floatNumber);
};

#endif
