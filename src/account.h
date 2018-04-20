//
//  account.h
//  cop3503_termproject
//
//  Created by Madeline Farina on 3/23/18.
//  Copyright © 2018 Madeline Farina. All rights reserved.
//

#ifndef account_h
#define account_h

#include "expenses.h"
#include "user.h"
#include "authenticator.h"
#include <map>
#include <vector>

class Account {

private:
	vector<Expenses*> monthExpenses;
	vector<Expenses*>::iterator it;
    double startBalance;
    double incomingSalary;
    double savingAccountNumber;
    double checkingAccountNumber;

public:
    Account();
    void printData();
    void changeExpenseField(string username, string month, string expenseType, double newAmount);
    bool dataExists(string username);
    void writeData(string username);
    void setStartBalance(double balance);
    double getStartBalance();
    void setIncomingSalary(double salary);
    double getIncomingSalary();
    void setSavingAccountNumber(double number);
    double getSavingAccountNumber();
    void setCheckingAccountNumber(double number);
    double getCheckingAccountNumber();
    double getAccountNumber();
    double deposit(double expenseAmount, double depositAmount);
    double withdraw(double expenseAmount, double withdrawlAmount);
	  double getExpense(string username, string month, string expenseType);
    //void enterExpenses(Expenses x);
    void transfer(User * x, double transferAmount, string month, string expenseType, string thisUsername);
};

#endif /* account_h */
