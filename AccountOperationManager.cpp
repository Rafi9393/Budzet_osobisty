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
        date = readAndCheckDate();
    }

    income.setDate(OperationsWithDates::convertDateToInt(date));
    cout << "Czego dotyczy przychod?" << endl;
    income.setItem(AuxiliaryMethods::readLine());
    cout << "Jaka jest wysokosc przychodu?" << endl;
    string amount = AuxiliaryMethods::readLine();
    income.setAmount(AuxiliaryMethods::changeCommaToDot(amount));
    income.setIncomeId(fileWithIncomes.getLastIncomeId()+1);
    income.setUserId(LOGGED_USER_ID);

    return income;

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
        date = readAndCheckDate();
    }

    expense.setDate(OperationsWithDates::convertDateToInt(date));
    cout << "Czego dotyczy wydatek?" << endl;
    expense.setItem(AuxiliaryMethods::readLine());
    cout << "Jaka jest wysokosc wydatku?" << endl;
    string amount = AuxiliaryMethods::readLine();
    expense.setAmount(AuxiliaryMethods::changeCommaToDot(amount));
    expense.setExpenseId(fileWithExpenses.getLastExpenseId()+1);
    expense.setUserId(LOGGED_USER_ID);

    return expense;

}

string AccountOperationsManager::readAndCheckDate()
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

//void AccountOperationsManager::printIncomes()
//{
//    for (int i = 0; i < incomes.size(); i++)
//        cout <<incomes[i].getIncomeId() <<". "<<incomes[i].getUserId()<<". "<<incomes[i].getDate()
//             <<" "<<incomes[i].getItem()<<" "<<incomes[i].getAmount()<<endl;
//}

//void AccountOperationsManager::printExpenses()
//{
//    for (int i = 0; i < expenses.size(); i++)
//        cout <<expenses[i].getExpenseId() <<". "<<expenses[i].getUserId()<<". "<<expenses[i].getDate()
//             <<" "<<expenses[i].getItem()<<" "<<expenses[i].getAmount()<<endl;
//}


