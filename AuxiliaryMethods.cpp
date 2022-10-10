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


bool AuxiliaryMethods::checkFloatAndChangeCommaToDot(string &floatNumber)
{
    for (size_t i = 0; i < floatNumber.size(); i++)
    {
        if (floatNumber[i] >= 48 && floatNumber[i] <= 57){}
        else if (floatNumber [i] == '.'){}
        else if (floatNumber[i] == ',')
            floatNumber[i] = '.';
        else
            return false;
    }
    return true;

}

void AuxiliaryMethods::setTextColor(unsigned char color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

string AuxiliaryMethods::convertFloatToTwoDigitsPrecisionString(float number)
{
    stringstream stream;
    stream << fixed << setprecision(2) << number;
    string twoDigitsString = stream.str();
    return twoDigitsString;
}
