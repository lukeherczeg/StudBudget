/*
 * account.cpp
 *
 *  Created on: Apr 15, 2018
 *      Author: Luke H
 */
#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <istream>
#include <map>
#include <iterator>
#include "expenses.h"
#include "user.h"
#include "account.h"


void Account::writeData(string username){
	ofstream writeData;
	writeData.open ("accountData.txt", ios_base::app); // Appends new data to the file
	writeData << username << endl;
	for(string month: this->months){
		writeData << month;
		this->it = this->monthExpenses.find(month);
		if(it->first == month){
			for(this->it = this->monthExpenses.begin(); this->it != this->monthExpenses.end(); this->it++){
				writeData << "FOOD: " << this->it->second->getFoodCost() << "RENT: "
				<< this->it->second->getRentCost() << "ENTERTAINMENT: " << this->it->second->getEntertainmentCost() << "TUITION: "
				<< this->it->second->getTuitionCost() << "SAVINGS: " << this->it->second->getSavingsCost() << "MISC: "
				<< this->it->second->getMiscCost();
			}
		}
	}
	cout << "Account created! You can now log in." << endl;
	writeData.close();

}

void Account::printData(){
	ifstream readData;
	string tempLine;
	readData.open("accountData.txt");
	while(getline(readData, tempLine))
		cout << tempLine << endl;
	readData.close();
}

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
