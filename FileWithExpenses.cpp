#include "FileWithExpenses.h"

int FileWithExpenses::getLastExpenseId()
{
    return lastExpenseId;
}

void FileWithExpenses::writeExpenseToFile(Expense expense)
{
    CMarkup xml;
    bool fileExists = xml.Load( FILE_NAME );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseId", expense.getExpenseId() );
    xml.AddElem("UserId", expense.getUserId() );
    xml.AddElem("Date", expense.getDate() );
    xml.AddElem("Item", expense.getItem() );
    xml.AddElem("Amount", AuxiliaryMethods::convertFloatToTwoDigitsPrecisionString(expense.getAmount()));

    xml.Save(FILE_NAME);
    lastExpenseId++;
}

vector <Expense> FileWithExpenses::readExpensesFromFile(int loggedUserId)
{
    CMarkup xml;
    Expense expense;
    vector <Expense> expenses;
    bool fileExists = xml.Load( FILE_NAME );

    if (fileExists)
    {
        xml.FindElem();
        xml.IntoElem();
        while ( xml.FindElem("Expense") )
        {
            xml.IntoElem();
            xml.FindElem( "ExpenseId" );
            expense.setExpenseId(stoi( MCD_2PCSZ(xml.GetData())));
            lastExpenseId = expense.getExpenseId();
            xml.FindElem( "UserId" );
            int userId = stoi( MCD_2PCSZ(xml.GetData()));
            if (userId == loggedUserId)
            {
                expense.setUserId(userId);
                xml.FindElem( "Date" );
                expense.setDate(stoi( MCD_2PCSZ(xml.GetData())));
                xml.FindElem( "Item" );
                expense.setItem(xml.GetData());
                xml.FindElem( "Amount" );
                expense.setAmount(stof( MCD_2PCSZ(xml.GetData())));
                expenses.push_back(expense);

            }
            xml.OutOfElem();
        }
    }
    else
    {
        cout << "Plik nie istnieje." <<endl;
    }
    return expenses;
}
