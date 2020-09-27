#include "incomeFile.hpp"
#include "helpMethods.hpp"

IncomeFile::IncomeFile(std::string incomeFileName)
    : INCOME_FILE_NAME_(incomeFileName) {
    numberOfIncomes_ = 0;
}

void IncomeFile::saveIncomeToFile(Income income) {
    bool fileExists = xml_.Load(INCOME_FILE_NAME_.c_str());

    if (!fileExists) {
        xml_.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml_.AddElem("INCOMES");
    }
    xml_.FindElem();
    xml_.IntoElem();
    xml_.AddElem("INCOME");
    xml_.IntoElem();
    xml_.AddElem("INCOMEID", income.getIncomeId());
    xml_.AddElem("USERID", income.getUserId());
    xml_.AddElem("DATE", income.getDate());
    xml_.AddElem("ITEM", income.getItem());
    xml_.AddElem("AMOUNT", HelpMethods::convertFloatToString(income.getAmount()));
    xml_.Save(INCOME_FILE_NAME_.c_str());
}

std::vector<Income> IncomeFile::loadIncomesFromFile(int loggedInUserId) {
    std::vector<Income> incomes;
    Income income;

    xml_.Load(INCOME_FILE_NAME_.c_str());

    xml_.ResetPos();
    xml_.FindElem();
    xml_.IntoElem();
    while (xml_.FindElem("INCOME")) {
        xml_.IntoElem();

        xml_.FindElem("USERID");
        if (HelpMethods::convertStringToInt(xml_.GetData()) == loggedInUserId) {
            income.setUserId(HelpMethods::convertStringToInt(xml_.GetData()));
            xml_.ResetMainPos();
            xml_.FindElem("INCOMEID");
            income.setIncomeId(HelpMethods::convertStringToInt(xml_.GetData()));
            xml_.FindElem("DATE");
            income.setDate(xml_.GetData());
            xml_.FindElem("ITEM");
            income.setItem(xml_.GetData());
            xml_.FindElem("AMOUNT");
            income.setAmount(HelpMethods::convertStringToFloat(xml_.GetData()));

            incomes.push_back(income);
        }

        xml_.OutOfElem();
    }

    return incomes;
}

int IncomeFile::getIdOfLastIncome() {
    int numberOfIncomes_ = 0;

    bool fileExists = xml_.Load(INCOME_FILE_NAME_.c_str());

    if (!fileExists) {
        return numberOfIncomes_;
    }

    xml_.FindElem();
    xml_.IntoElem();

    while (xml_.FindElem("INCOME")) {
        numberOfIncomes_++;
    }

    return numberOfIncomes_;
}
