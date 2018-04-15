/*
 * account.cpp
 *
 *  Created on: Apr 15, 2018
 *      Author: Luke H
 */

/*class Account {

private:
    double startBalance;
    double incomingSalary;
    Expenses expenses; //can't uncomment until Expenses class is created
    double savingAccountNumber;
    double checkingAccountNumber;

public:
    void setStartBalance(double x);
    void setIncomingSalary(double x);
    double getIncomingSalary();
    double getAccountNumber();
    double deposite(double x);
    void enterExpenses(Expenses x);
    void transfer(User x);
};*/
#include "account.h"

void Account::setStartBalance(double startBalance){
  this->startBalance = startBalance;
}

double Account::getStartBalance(){
  return this->startBalance;
}

void Account::setIncomingSalary(double incomingSalary){
  this->incomingSalary = incomingSalary;
}

double Account::getIncomingSalary(){
  return this->incomingSalary;
}

void Account::setSavingAccountNumber(double savingAccountNumber){
  this->savingAccountNumber = savingAccountNumber;
}

double Account::getSavingAccountNumber(){
  return this->savingAccountNumber;
}

void Account::setCheckingAccountNumber(double checkingAccountNumber){
  this->checkingAccountNumber = checkingAccountNumber;
}

double Account::getCheckingAccountNumber(){
  return this->checkingAccountNumber;
}
