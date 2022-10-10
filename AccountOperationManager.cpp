#include "AccountOperationManager.h"

void AccountOperationsManager::addIncome()
{
    Income income = readNewIncomeData();
    incomes.push_back(income);
    fileWithIncomes.writeIncomeToFile(income);
    cout << "Przychod zostal zapisany." << endl;
    system("pause");
}

void AccountOperationsManager::addExpense()
{
    Expense expense = readNewExpenseData();
    expenses.push_back(expense);
    fileWithExpenses.writeExpenseToFile(expense);
    cout << "Wydatek zostal zapisany." << endl;
    system("pause");
}

void AccountOperationsManager::currentMonthBalance()
{
    system("cls");
    int acctualMonth = OperationsWithDates::convertStringDateToIntMonth(OperationsWithDates::getCurrentDate());
    vector <Income> currentMonthIncomes = findMonthIncomes(acctualMonth);
    sortIncomesVectorByDate(currentMonthIncomes);
    vector <Expense> currentMonthExpenses = findMonthExpenses(acctualMonth);
    sortExpensesVectorByDate(currentMonthExpenses);

    cout << "Bilans wydatkow za biezacy miesiac:" << endl;
    float incomesSum = 0, expensesSum = 0;
    if (currentMonthIncomes.empty())
        cout << endl << "Brak przychodow w biezacym miesiacu. " << endl;
    else
        incomesSum = printIncomesBalance(currentMonthIncomes);

    if (currentMonthExpenses.empty())
        cout << endl << "Brak wydatkow w biezacym miesiacu. " << endl;
    else
        expensesSum = printExpensesBalance(currentMonthExpenses);

    cout << endl << "Suma przychodow za biezacy miesiac to: ";
    printColoredBalance(incomesSum);
    cout << "Suma wydatkow za biezacy miesiac to: ";
    if ( expensesSum == 0)
        printColoredBalance(expensesSum);
    else
        printColoredBalance(expensesSum*(-1));

    float balance = incomesSum - expensesSum;

    cout << "Balans w biezacym miesiacu to: ";
    printColoredBalance(balance);
    cout << endl;
    system("pause");
}

void AccountOperationsManager::lastMonthBalance()
{
    system("cls");
    int lastMonth = OperationsWithDates::convertStringDateToIntMonth(OperationsWithDates::getCurrentDate()) - 1;
    vector <Income> lastMonthIncomes = findMonthIncomes(lastMonth);
    sortIncomesVectorByDate(lastMonthIncomes);
    vector <Expense> lastMonthExpenses = findMonthExpenses(lastMonth);
    sortExpensesVectorByDate(lastMonthExpenses);
    cout << "Bilans wydatkow za poprzedni miesiac:" << endl;

    float incomesSum = 0, expensesSum = 0;
    if (lastMonthIncomes.empty())
        cout << endl << "Brak przychodow w poprzednim miesiacu. " << endl;
    else
        incomesSum = printIncomesBalance(lastMonthIncomes);

    if (lastMonthExpenses.empty())
        cout << endl << "Brak wydatkow w poprzednim miesiacu. " << endl;
    else
        expensesSum = printExpensesBalance(lastMonthExpenses);

    cout << endl << "Suma przychodow za poprzedni miesiac to: ";
    printColoredBalance(incomesSum);
    cout << "Suma wydatkow za poprzedni miesiac to: ";
    if ( expensesSum == 0)
        printColoredBalance(expensesSum);
    else
        printColoredBalance(expensesSum*(-1));

    float balance = incomesSum - expensesSum;

    cout << "Balans w poprzednim miesiacu to: ";
    printColoredBalance(balance);
    cout << endl;
    system("pause");
}

void AccountOperationsManager::periodicMonthBalance()
{
    cout << "Podaj, od jakiej daty chcesz wyswietlic balans(RRRR-MM-DD): ";
    string stringBeginningDate = OperationsWithDates::readAndCheckDate();
    cout << "Podaj, do jakiej daty chcesz wyswietlic balans(RRRR-MM-DD): ";
    string stringEndDate = OperationsWithDates::readAndCheckDate();

    int beginningDate = OperationsWithDates::convertDateToInt(stringBeginningDate);
    int endDate = OperationsWithDates::convertDateToInt(stringEndDate);

    vector <Income> foundIncomes = findPeriodicIncomes(beginningDate, endDate);
    sortIncomesVectorByDate(foundIncomes);
    vector <Expense> foundExpenses = findPeriodicExpenses(beginningDate, endDate);
    sortExpensesVectorByDate(foundExpenses);

    system("cls");
    cout << "Bilans wydatkow okres od: " << stringBeginningDate <<" do " << stringEndDate << ": " << endl;
    float incomesSum = 0, expensesSum = 0;
    if (foundIncomes.empty())
        cout << endl << "Brak przychodow w danym okresie. " << endl;
    else
        incomesSum = printIncomesBalance(foundIncomes);

    if (foundExpenses.empty())
        cout << endl << "Brak wydatkow w danym okresie. " << endl;
    else
        expensesSum = printExpensesBalance(foundExpenses);

    cout << endl << "Suma przychodow za dany okres to: ";
    printColoredBalance(incomesSum);
    cout << "Suma wydatkow za dany okres to: ";
    if ( expensesSum == 0)
        printColoredBalance(expensesSum);
    else
        printColoredBalance(expensesSum*(-1));

    float balance = incomesSum - expensesSum;

    cout << "Balans w danym okresie to: ";
    printColoredBalance(balance);
    cout << endl;
    system("pause");

}

vector <Expense> AccountOperationsManager::findPeriodicExpenses(int beginningDate, int endDate)
{
    vector <Expense> foundExpenses;
    for (size_t i = 0; i < expenses.size(); i++)
        if ( (expenses[i].getDate() >= beginningDate) && (expenses[i].getDate() <= endDate))
            foundExpenses.push_back(expenses[i]);

    return foundExpenses;
}

vector <Income> AccountOperationsManager::findPeriodicIncomes(int beginningDate, int endDate)
{
    vector <Income> foundIncomes;
    for (size_t i = 0; i < incomes.size(); i++)
        if ( (incomes[i].getDate() >= beginningDate) && (incomes[i].getDate() <= endDate))
            foundIncomes.push_back(incomes[i]);

    return foundIncomes;
}

vector <Expense> AccountOperationsManager::findMonthExpenses(int month)
{
    vector <Expense> foundExpenses;
    int actualYear = OperationsWithDates::convertStringDateToIntYear(OperationsWithDates::getCurrentDate());
    int lastDayOfMonth = OperationsWithDates::howManyDaysHasAMOnth(actualYear, month);
    int firstDayOfMonth = 1;
    int beginningDate = OperationsWithDates::convertSplitIntDateToMergedInt(actualYear, month, firstDayOfMonth);
    int endDate = OperationsWithDates::convertSplitIntDateToMergedInt(actualYear, month, lastDayOfMonth);

    for (size_t i = 0; i < expenses.size(); i++)
        if ( (expenses[i].getDate() >= beginningDate) && (expenses[i].getDate() <= endDate))
            foundExpenses.push_back(expenses[i]);

    return foundExpenses;
}

vector <Income> AccountOperationsManager::findMonthIncomes(int month)
{
    vector <Income> foundIncomes;
    int actualYear = OperationsWithDates::convertStringDateToIntYear(OperationsWithDates::getCurrentDate());
    int lastDayOfMonth = OperationsWithDates::howManyDaysHasAMOnth(actualYear,month);
    int firstDayOfMonth = 1;
    int beginningDate = OperationsWithDates::convertSplitIntDateToMergedInt(actualYear, month, firstDayOfMonth);
    int endDate = OperationsWithDates::convertSplitIntDateToMergedInt(actualYear, month, lastDayOfMonth);

    for (size_t i = 0; i < incomes.size(); i++)
        if ( (incomes[i].getDate() >= beginningDate) && (incomes[i].getDate() <= endDate))
            foundIncomes.push_back(incomes[i]);

    return foundIncomes;

}

Income AccountOperationsManager::readNewIncomeData()
{
    Income income;
    string date;
    cout << "Czy przychod dotyczy dnia dzisiejszego? [t/n]" <<endl;
    char confirmation = AuxiliaryMethods::readChar();

    if (confirmation == 't')
    {
        date = OperationsWithDates::getCurrentDate();
    }
    else
    {
        cout << "Podaj date ktorej dotyczy wprowadzany przychod (RRRR-MM-DD)." << endl;
        date = OperationsWithDates::readAndCheckDate();
    }

    income.setDate(OperationsWithDates::convertDateToInt(date));
    cout << "Czego dotyczy przychod?" << endl;
    income.setItem(AuxiliaryMethods::readLine());
    cout << "Jaka jest wysokosc przychodu?" << endl;
    income.setAmount(readAmount());
    income.setIncomeId(fileWithIncomes.getLastIncomeId() +1);
    income.setUserId(LOGGED_USER_ID);

    return income;

}

float AccountOperationsManager::readAmount()
{
    string amount = "";
    do
    {
        amount = AuxiliaryMethods::readLine();
        if (AuxiliaryMethods::checkFloatAndChangeCommaToDot(amount))
        {
            return stof(amount);
        }

        else
            cout << "Podana wartosc nie jest poprawna liczba. Sprobuj ponownie." << endl;
    }while (!AuxiliaryMethods::checkFloatAndChangeCommaToDot(amount));
    return 0;
}

Expense AccountOperationsManager::readNewExpenseData()
{
    Expense expense;
    string date;
    cout << "Czy wydatek dotyczy dnia dzisiejszego? [t/n]" <<endl;
    char confirmation = AuxiliaryMethods::readChar();

    if (confirmation == 't')
    {
        date = OperationsWithDates::getCurrentDate();
    }
    else
    {
        cout << "Podaj date ktorej dotyczy wprowadzany wydatek (RRRR-MM-DD)." << endl;
        date = OperationsWithDates::readAndCheckDate();
    }

    expense.setDate(OperationsWithDates::convertDateToInt(date));
    cout << "Czego dotyczy wydatek?" << endl;
    expense.setItem(AuxiliaryMethods::readLine());
    cout << "Jaka jest wysokosc wydatku?" << endl;
    expense.setAmount(readAmount());
    expense.setExpenseId(fileWithExpenses.getLastExpenseId()+1);
    expense.setUserId(LOGGED_USER_ID);

    return expense;

}

float AccountOperationsManager::printIncomesBalance(vector <Income> incomes)
{
    float incomesSum = 0;
    cout << endl <<" Przychody:" << endl;
    for (size_t i = 0; i < incomes.size(); i++)
    {
        cout << (i+1) << ", " << OperationsWithDates::convertMergedIntDateToString(incomes[i].getDate()) <<
             ", " <<incomes[i].getItem() << ", +" << incomes[i].getAmount() <<" zl" << endl;
        incomesSum += incomes[i].getAmount();
    }
    return incomesSum;
}

float AccountOperationsManager::printExpensesBalance(vector <Expense> expenses)
{
    float expensesSum = 0;
    cout << endl <<" Wydatki:" << endl;
    for (size_t i = 0; i < expenses.size(); i++)
    {
        cout << (i+1) << ", " << OperationsWithDates::convertMergedIntDateToString(expenses[i].getDate()) <<
             ", " <<expenses[i].getItem() << ", -" << expenses[i].getAmount() <<" zl" << endl;
        expensesSum += expenses[i].getAmount();
    }
    return expensesSum;
}

void AccountOperationsManager::printColoredBalance(float balance)
{
    if (balance < 0)
    {
        AuxiliaryMethods::setTextColor(0x0C);
        cout << balance << " zl" <<endl;
        AuxiliaryMethods::setTextColor(0x07);
    }
    else if (balance > 0)
    {
        AuxiliaryMethods::setTextColor(0xA);
        cout << "+" << balance << " zl" <<endl;
        AuxiliaryMethods::setTextColor(0x07);
    }
    else
    {
        cout << balance << " zl" <<endl;
    }
}

void AccountOperationsManager::sortIncomesVectorByDate( vector <Income> &incomes)
{
    sort( incomes.begin(), incomes.end(), [](Income & l, Income & r)
    {
        return l.getDate() < r.getDate();
    });
}

void AccountOperationsManager::sortExpensesVectorByDate( vector <Expense> &expenses)
{
    sort( expenses.begin(), expenses.end(), [](Expense & l, Expense & r)
    {
        return l.getDate() < r.getDate();
    });
}

