#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "expenses.h"
#include "user.h"
#include "authenticator.h"
#include <map>
#include <vector>

class Account {

private:
    Expenses * expenses;
    string username;
    int month;
    string expenseType;

public:
    Account();
    Expenses* getExpenseObj();
    std::string getFinancialAdvice(int month);
    void setProjectedBudget();
    void setUsername(string username);
    void setMonth(int month);
    void setExpenseType(string expenseType);
    void setCost(double amount);
    void changeExpenseField(double newAmount);
    bool dataExists();
    void writeData();
    void deposit(double depositAmount);
    void withdraw(double withdrawAmount);
    double getExpense();
};


#endif // ACCOUNT_H
