#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <windows.h>
#include <iomanip>

using namespace std;


class AuxiliaryMethods
{
public:
    static char readChar();
    static string readLine();
    static string convertIntToString( int number );
    static bool checkFloatAndChangeCommaToDot( string &floatNumber );
    static void setTextColor( unsigned char color );
    static string convertFloatToTwoDigitsPrecisionString(float number);
};

#endif
