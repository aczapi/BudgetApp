#include "expenseFile.hpp"
#include "helpMethods.hpp"

ExpenseFile::ExpenseFile(std::string expenseFileName)
    : EXPENSE_FILE_NAME_(expenseFileName) {
    numberOfExpenses = 0;
}

void ExpenseFile::saveExpenseToFile(Expense expense) {
    bool fileExists = xml.Load(EXPENSE_FILE_NAME_.c_str());

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("EXPENSES");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("EXPENSE");
    xml.IntoElem();
    xml.AddElem("EXPENSEID", expense.getExpenseId());
    xml.AddElem("USERID", expense.getUserId());
    xml.AddElem("DATE", expense.getDate());
    xml.AddElem("ITEM", expense.getItem());
    xml.AddElem("AMOUNT", HelpMethods::convertFloatToString(expense.getAmount()));
    xml.Save(EXPENSE_FILE_NAME_.c_str());
}

std::vector<Expense> ExpenseFile::loadExpensesFromFile(int loggedInUserId) {
    std::vector<Expense> expenses;
    Expense expense;

    //numberOfIncomes = 0;
    // bool fileExists = xml.Load(USER_FILE_NAME_.c_str());

    //     if (!fileExists) {
    //         xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    //         xml.AddElem("USERS");
    //     }

    xml.Load(EXPENSE_FILE_NAME_.c_str());

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("EXPENSE")) {
        xml.IntoElem();

        xml.FindElem("USERID");
        if (HelpMethods::convertStringToInt(xml.GetData()) == loggedInUserId) {
            expense.setUserId(HelpMethods::convertStringToInt(xml.GetData()));
            xml.ResetMainPos();
            xml.FindElem("EXPENSEID");
            expense.setExpenseId(HelpMethods::convertStringToInt(xml.GetData()));
            xml.FindElem("DATE");
            expense.setDate(xml.GetData());
            xml.FindElem("ITEM");
            expense.setItem(xml.GetData());
            xml.FindElem("AMOUNT");
            expense.setAmount(HelpMethods::convertStringToFloat(xml.GetData()));

            expenses.push_back(expense);
        }

        xml.OutOfElem();
    }

    return expenses;
}

int ExpenseFile::getIdOfLastExpense() {
    int numberOfExpenses = 0;

    bool fileExists = xml.Load(EXPENSE_FILE_NAME_.c_str());

    if (!fileExists) {
        return numberOfExpenses;
    }

    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("EXPENSE")) {
        numberOfExpenses++;
    }

    return numberOfExpenses;
}
