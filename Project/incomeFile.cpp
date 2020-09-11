#include "incomeFile.hpp"
#include "helpMethods.hpp"

IncomeFile::IncomeFile(std::string incomeFileName)
    : INCOME_FILE_NAME_(incomeFileName) {}

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
    xml.AddElem("AMOUNT", income.getAmount());
    xml.Save(INCOME_FILE_NAME_.c_str());
}

std::vector<Income> IncomeFile::loadIncomesFromFile() {
    std::vector<Income> incomes;
    Income income;
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
        xml.FindElem("INCOMEID");
        income.setIncomeId(HelpMethods::convertStringToInt(xml.GetData()));
        xml.FindElem("USERID");
        income.setUserId(HelpMethods::convertStringToInt(xml.GetData()));
        xml.FindElem("DATE");
        income.setDate(xml.GetData());
        xml.FindElem("ITEM");
        income.setItem(xml.GetData());
        xml.FindElem("AMOUNT");
        income.setAmount(HelpMethods::convertStringToFloat(xml.GetData()));
        xml.OutOfElem();
        incomes.push_back(income);
    }
    return incomes;
}
