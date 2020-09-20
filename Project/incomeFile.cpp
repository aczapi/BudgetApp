#include "incomeFile.hpp"
#include "helpMethods.hpp"

IncomeFile::IncomeFile(std::string incomeFileName)
    : INCOME_FILE_NAME_(incomeFileName) {
    numberOfIncomes = 0;
}

void IncomeFile::saveIncomeToFile(Income income) {
    bool fileExists = xml.Load(INCOME_FILE_NAME_.c_str());

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("INCOMES");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("INCOME");
    xml.IntoElem();
    xml.AddElem("INCOMEID", income.getIncomeId());
    xml.AddElem("USERID", income.getUserId());
    xml.AddElem("DATE", income.getDate());
    xml.AddElem("ITEM", income.getItem());
    xml.AddElem("AMOUNT", HelpMethods::convertFloatToString(income.getAmount()));
    xml.Save(INCOME_FILE_NAME_.c_str());
}

std::vector<Income> IncomeFile::loadIncomesFromFile(int loggedInUserId) {
    std::vector<Income> incomes;
    Income income;
    //numberOfIncomes = 0;
    // bool fileExists = xml.Load(USER_FILE_NAME_.c_str());

    //     if (!fileExists) {
    //         xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    //         xml.AddElem("USERS");
    //     }

    xml.Load(INCOME_FILE_NAME_.c_str());

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("INCOME")) {
        xml.IntoElem();

        xml.FindElem("USERID");
        if (HelpMethods::convertStringToInt(xml.GetData()) == loggedInUserId) {
            income.setUserId(HelpMethods::convertStringToInt(xml.GetData()));
            xml.ResetMainPos();
            xml.FindElem("INCOMEID");
            income.setIncomeId(HelpMethods::convertStringToInt(xml.GetData()));
            xml.FindElem("DATE");
            income.setDate(xml.GetData());
            xml.FindElem("ITEM");
            income.setItem(xml.GetData());
            xml.FindElem("AMOUNT");
            income.setAmount(HelpMethods::convertStringToFloat(xml.GetData()));

            incomes.push_back(income);
        }

        xml.OutOfElem();
    }

    return incomes;
}

int IncomeFile::getIdOfLastIncome() {
    int numberOfIncomes = 0;

    bool fileExists = xml.Load(INCOME_FILE_NAME_.c_str());

    if (!fileExists) {
        return numberOfIncomes;
    }

    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("INCOME")) {
        numberOfIncomes++;
    }

    return numberOfIncomes;
}