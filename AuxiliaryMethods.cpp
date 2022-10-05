#include "AuxiliaryMethods.h"


char AuxiliaryMethods::readChar()
{
    string input = "";
    char character  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}

string AuxiliaryMethods::readLine()
{
    string input = "";
    getline(cin, input);
    return input;
}

string AuxiliaryMethods::convertIntToString(int number)
{
    stringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}


float AuxiliaryMethods::changeCommaToDot(string floatNumber)
{
    for (int i = 0; i < floatNumber.size(); i++)
    {
        if ( floatNumber[i] == ',')
            floatNumber[i] = '.';
    }
    return stof(floatNumber);
}
