#include "FileWithIncomes.h"

int FileWithIncomes::getLastIncomeId()
{
    return lastIncomeId;
}

void FileWithIncomes::writeIncomeToFile(Income income)
{
    CMarkup xml;
    bool fileExists = xml.Load(FILE_NAME);

    if (!fileExists)
    {
        xml.SetDoc( "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n" );
        xml.AddElem( "Incomes" );
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "Income" );
    xml.IntoElem();
    xml.AddElem( "IncomeId", income.getIncomeId());
    xml.AddElem( "UserId", income.getUserId());
    xml.AddElem( "Date", income.getDate());
    xml.AddElem( "Item", income.getItem());
    xml.AddElem( "Amount", AuxiliaryMethods::convertFloatToTwoDigitsPrecisionString(income.getAmount()));

    xml.Save(FILE_NAME);

    lastIncomeId++;
}

vector <Income> FileWithIncomes::readIncomesFromFile(int loggedUserId)
{
    CMarkup xml;
    Income income;
    vector <Income> incomes;
    bool fileExists = xml.Load(FILE_NAME);

    if (fileExists)
    {
        xml.FindElem();
        xml.IntoElem();
        while ( xml.FindElem("Income") )
        {
            xml.IntoElem();
            xml.FindElem("IncomeId");
            income.setIncomeId(stoi(MCD_2PCSZ(xml.GetData())));
            lastIncomeId = income.getIncomeId();
            xml.FindElem("UserId");
            int userId = stoi(MCD_2PCSZ(xml.GetData()) );
            if (userId == loggedUserId)
            {
                income.setUserId(userId);
                xml.FindElem("Date");
                income.setDate(stoi(MCD_2PCSZ(xml.GetData())));
                xml.FindElem("Item");
                income.setItem(xml.GetData());
                xml.FindElem("Amount");
                income.setAmount(stof(MCD_2PCSZ(xml.GetData())));
                incomes.push_back(income);

            }
            xml.OutOfElem();
        }
    }
    else
    {
        cout << "Plik nie istnieje." <<endl;
    }
    return incomes;
}
