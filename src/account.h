//
//  account.h
//  cop3503_termproject
//
//  Created by Madeline Farina on 3/23/18.
//  Copyright © 2018 Madeline Farina. All rights reserved.
//

#ifndef account_h
#define account_h

#include <string>
#include <cstdlib>
#include <iostream>
#include "expenses.h"
#include "user.h"

class Account {

private:
    double startBalance;
    double incomingSalary;
    //expenses expenses; //can't uncomment until Expenses class is created
    double savingAccountNumber;
    double checkingAccountNumber;

public:
    void setStartBalance(double x);
    void setIncomingSalary(double x);
    double getIncomingSalary();
    double getAccountNumber();
    double deposite(double x);
    //void enterExpenses(Expenses x);
    //void transfer(User x);
};

#endif /* account_h */
