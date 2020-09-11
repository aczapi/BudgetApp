#include "expenseFile.hpp"
#include "helpMethods.hpp"

ExpenseFile::ExpenseFile(std::string expenseFileName)
    : EXPENSE_FILE_NAME_(expenseFileName) {}

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
    xml.AddElem("AMOUNT", expense.getAmount());
    xml.Save(EXPENSE_FILE_NAME_.c_str());
}

std::vector<Expense> ExpenseFile::loadExpensesFromFile() {
    std::vector<Expense> expenses;
    Expense expense;
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
        xml.FindElem("EXPENSEID");
        expense.setExpenseId(HelpMethods::convertStringToInt(xml.GetData()));
        xml.FindElem("USERID");
        expense.setUserId(HelpMethods::convertStringToInt(xml.GetData()));
        xml.FindElem("DATE");
        expense.setDate(xml.GetData());
        xml.FindElem("ITEM");
        expense.setItem(xml.GetData());
        xml.FindElem("AMOUNT");
        expense.setAmount(HelpMethods::convertStringToFloat(xml.GetData()));
        xml.OutOfElem();
        expenses.push_back(expense);
    }
    return expenses;
}
