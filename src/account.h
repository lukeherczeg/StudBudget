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
	Expenses * expenses;
	string username;
	int month;
	string expenseType;

public:
    Account();
    void setUsername(string username);
    void setMonth(int month);
    void setExpenseType(string expenseType);
    void printData();
    void setCost(double amount);
    void changeExpenseField(double newAmount);
    bool dataExists();
    void writeData();
    void deposit(double depositAmount);
    void withdraw(double withdrawAmount);
    double getExpense();
    //void transfer(User * x, double transferAmount, string month, string expenseType, string thisUsername);
};

#endif /* account_h */
