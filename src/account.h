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
#include <map>
#include <vector>

class Account {

private:
    double startBalance;
    double incomingSalary;
    const vector<string> months = {"January", "February", "March", "April", "May", "June", "July",
   								"August", "September", "October", "November", "December"};
    map<const string, Expenses*> monthExpenses {{"January", NULL}, {"February", NULL}, {"March", NULL}, {"April", NULL}, {"May", NULL}, {"June", NULL}, {"July", NULL},
    											{"August", NULL}, {"September", NULL}, {"October", NULL}, {"November", NULL}, {"December", NULL}};
    map<const string, Expenses*>::iterator it;
    double savingAccountNumber;
    double checkingAccountNumber;

public:
    Account();
    void printData();
    void writeData(string username);
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
