#include "expenseFile.hpp"
#include "helpMethods.hpp"

ExpenseFile::ExpenseFile(std::string expenseFileName)
    : EXPENSE_FILE_NAME_(expenseFileName) {
    numberOfExpenses_ = 0;
}

void ExpenseFile::saveExpenseToFile(Expense expense) {
    bool fileExists = xml_.Load(EXPENSE_FILE_NAME_.c_str());

    if (!fileExists) {
        xml_.SetDoc("<?xml_ version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml_.AddElem("EXPENSES");
    }
    xml_.FindElem();
    xml_.IntoElem();
    xml_.AddElem("EXPENSE");
    xml_.IntoElem();
    xml_.AddElem("EXPENSEID", expense.getExpenseId());
    xml_.AddElem("USERID", expense.getUserId());
    xml_.AddElem("DATE", expense.getDate());
    xml_.AddElem("ITEM", expense.getItem());
    xml_.AddElem("AMOUNT", HelpMethods::convertFloatToString(expense.getAmount()));
    xml_.Save(EXPENSE_FILE_NAME_.c_str());
}

std::vector<Expense> ExpenseFile::loadExpensesFromFile(int loggedInUserId) {
    std::vector<Expense> expenses;
    Expense expense;

    xml_.Load(EXPENSE_FILE_NAME_.c_str());

    xml_.ResetPos();
    xml_.FindElem();
    xml_.IntoElem();
    while (xml_.FindElem("EXPENSE")) {
        xml_.IntoElem();

        xml_.FindElem("USERID");
        if (HelpMethods::convertStringToInt(xml_.GetData()) == loggedInUserId) {
            expense.setUserId(HelpMethods::convertStringToInt(xml_.GetData()));
            xml_.ResetMainPos();
            xml_.FindElem("EXPENSEID");
            expense.setExpenseId(HelpMethods::convertStringToInt(xml_.GetData()));
            xml_.FindElem("DATE");
            expense.setDate(xml_.GetData());
            xml_.FindElem("ITEM");
            expense.setItem(xml_.GetData());
            xml_.FindElem("AMOUNT");
            expense.setAmount(HelpMethods::convertStringToFloat(xml_.GetData()));

            expenses.push_back(expense);
        }

        xml_.OutOfElem();
    }

    return expenses;
}

int ExpenseFile::getIdOfLastExpense() {
    int numberOfExpenses_ = 0;

    bool fileExists = xml_.Load(EXPENSE_FILE_NAME_.c_str());

    if (!fileExists) {
        return numberOfExpenses_;
    }

    xml_.FindElem();
    xml_.IntoElem();

    while (xml_.FindElem("EXPENSE")) {
        numberOfExpenses_++;
    }

    return numberOfExpenses_;
}
