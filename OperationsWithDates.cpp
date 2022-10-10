#include "OperationsWithDates.h"

string OperationsWithDates::getCurrentDate()
{
    time_t t = time(nullptr);
    struct tm *timeInfo = localtime(&t);
    ostringstream oss;
    oss << put_time(timeInfo, "%Y-%m-%d");
    string str = oss.str();
    return str;
}

bool OperationsWithDates::isDateCorrect(string date)
{
    if (isDateHasCorrectSeparators(date))
    {
        vector <int> separatedIntDate = convertStringDateToIntVector(date);
        if (isYearCorrect(separatedIntDate[0]))
            if(isMonthCorrect(separatedIntDate[1], separatedIntDate[0]))
                if(isDayCorrect(separatedIntDate[0], separatedIntDate[1], separatedIntDate[2]))
                    return true;
    }
    return false;
}

bool OperationsWithDates::isYearCorrect(int year)
{
    return (year >= 2000) && (year <= convertStringDateToIntYear(getCurrentDate())) ? true : false;
}

bool OperationsWithDates::isMonthCorrect(int month, int year)
{
    if (year == convertStringDateToIntYear(getCurrentDate()))
    {
        if (month <= convertStringDateToIntMonth(getCurrentDate()))
            return true;
        return false;
    }

    if ((month >= 1) && (month <= 12))
        return true;
    return false;

}

bool OperationsWithDates::isDayCorrect(int year, int month, int day)
{
    int checkedMonth = howManyDaysHasAMOnth(year, month);
    if ((day >= 1) && (day <= checkedMonth) )
        return true;
    return false;
}

int OperationsWithDates::howManyDaysHasAMOnth(int year, int month)
{
    switch (month)
    {
    case 1:
        return 31;
        break;
    case 2:
        if(isLeapYear(year))
            return 29;
        else
            return 28;
        break;
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
        break;
    default:
        return 30;
        break;
    }
}

bool OperationsWithDates::isLeapYear(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? true : false;
}

vector <int> OperationsWithDates::convertStringDateToIntVector(string date)
{
    vector <int> intDate;
    intDate.push_back(convertStringDateToIntYear(date));
    intDate.push_back(convertStringDateToIntMonth(date));
    intDate.push_back(convertStringDateToIntDay(date));
    return intDate;
}

int OperationsWithDates::convertStringDateToIntDay(string date)
{
    string day = "";
    for (int i = 8; i <= 9; i++)
    {
        day += date[i];
    }
    return stoi(day);
}

int OperationsWithDates::convertStringDateToIntMonth(string date)
{
    string month = "";
    for (int i = 5; i <= 6; i++)
    {
        month += date[i];
    }
    return stoi(month);
}

int OperationsWithDates::convertStringDateToIntYear(string date)
{
    string year = "";
    for (int i = 0; i <= 3; i++)
    {
        year += date[i];
    }
    return stoi(year);
}

bool OperationsWithDates::isDateHasCorrectSeparators(string date)
{
    return ( (date[4] == '-') && (date[7] == '-') ) ? true : false;
}

int OperationsWithDates::convertDateToInt(string date)
{
    string day = "", month = "";
    string dateWithoutSeparators = "";
    dateWithoutSeparators += AuxiliaryMethods::convertIntToString(convertStringDateToIntYear(date));
    month = AuxiliaryMethods::convertIntToString(convertStringDateToIntMonth(date));
    if (month.size() == 1)
        dateWithoutSeparators += "0" + month;
    else
        dateWithoutSeparators += month;

    day = AuxiliaryMethods::convertIntToString(convertStringDateToIntDay(date));
    if (day.size() == 1)
        dateWithoutSeparators += "0" + day;
    else
        dateWithoutSeparators += day;

    return stoi(dateWithoutSeparators);
}

int OperationsWithDates::convertSplitIntDateToMergedInt(int year, int month, int day)
{
    string stringYear = "", stringDay = "", stringMonth = "";
    stringYear = to_string(year);
    stringMonth = addZeroTodate(to_string(month));
    stringDay = addZeroTodate(to_string(day));
    string dateToConvert = stringYear + stringMonth + stringDay;
    return stoi(dateToConvert);
}

string OperationsWithDates::addZeroTodate(string date)
{
    if (date.size() == 1)
        date = "0" + date;
    return date;
}

string OperationsWithDates::convertMergedIntDateToString(int date)
{
    string stringDate = to_string(date);
    string convertedDate = "";
    for (size_t i = 0; i < stringDate.size(); i++)
    {
        if ( i == 3 || i == 5)
        {
            convertedDate += stringDate[i];
            convertedDate += "-";
        }
        else
        {
            convertedDate += stringDate[i];
        }
    }
    return convertedDate;
}

string OperationsWithDates::readAndCheckDate()
{
    string date = "";
    do
    {
        date = AuxiliaryMethods::readLine();
        if (!OperationsWithDates::isDateCorrect(date))
            cout << "Podana data jest nieprawidlowa. Podaj poprawna date (RRRR-MM-DD)." << endl;
    }
    while(!OperationsWithDates::isDateCorrect(date));
    return date;
}
