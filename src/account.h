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

class Account {

private:
    double startBalance;
    double incomingSalary;
    map<const string, Expenses*> users;
    //Expenses expenses;
    double savingAccountNumber;
    double checkingAccountNumber;

public:
    void setStartBalance(double x);
    double getStartBalance();
    void setIncomingSalary(double x);
    double getIncomingSalary();
    void setSavingAccountNumber(double x);
    double getSavingAccountNumber();
    void setCheckingAccountNumber(double x);
    double getCheckingAccountNumber();
    double getAccountNumber();
    double deposit(double x);
    double withdraw(double x);
    //void enterExpenses(Expenses x);
    void transfer(User x);
};

#endif /* account_h */
