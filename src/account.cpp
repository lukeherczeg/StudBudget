/*
 * account.cpp
 *
 *  Created on: Apr 15, 2018
 *      Author: Luke H
 */
#include <string>
#include <cstdlib>
#include <iostream>
#include "expenses.h"
#include "user.h"
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

double Account::deposit(double depositAmount){
  return 0.0; //placeholder - have to include this in calculations and call specific accounts
}

double Account::withdraw(double withdrawlAmound){
  return 0.0; //placeholder - have to include this in calculations and call specific accounts
}
