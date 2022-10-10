#ifndef OPERATIONSWITHDATES_H
#define OPERATIONSWITHDATES_H
#include <iostream>
#include <time.h>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>

#include "AuxiliaryMethods.h"

using namespace std;


class OperationsWithDates
{
    static bool isDateHasCorrectSeparators(string date);
    static vector <int> convertStringDateToIntVector(string date);
    static bool isLeapYear(int year);
    static bool isYearCorrect(int year);
    static bool isMonthCorrect(int month, int year);
    static bool isDayCorrect(int year, int month, int day);
    static string addZeroTodate(string date);
public:
    static string getCurrentDate();
    static bool isDateCorrect(string date);
    static int convertDateToInt(string date);
    static int convertSplitIntDateToMergedInt(int year, int month, int day);
    static int convertStringDateToIntYear(string date);
    static int convertStringDateToIntMonth(string date);
    static int convertStringDateToIntDay(string date);
    static int howManyDaysHasAMOnth(int year, int month);
    static string convertMergedIntDateToString(int date);
    static string readAndCheckDate();
};

#endif
