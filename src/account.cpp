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
#include "authenticator.h"


const vector<string> months = {"January", "February", "March", "April", "May", "June", "July",
   						 "August", "September", "October", "November", "December"};

Account::Account(){
	//for(Expenses * ex : this->monthExpenses)
	//	this->monthExpenses.push_back(ex);
	this->checkingAccountNumber = 0;
	this->incomingSalary = 0;
	this->savingAccountNumber = 0;
	this->startBalance = 0;
}

void Account::writeData(string username){ // TODO THIS CAUSES A SEGFAULT. FIX IT! :D
	ofstream writeData;
	writeData.open("accountData.txt", ios_base::app); // Appends new data to the file
	writeData << username << endl;
	for(unsigned int i = 0; i < months.size(); i++){  // Months is the same size as the expenses
		writeData << months[i];
		this->monthExpenses[i] = new Expenses();
		writeData << "FOOD: " 			<<	this->monthExpenses[i]->getFoodCost()
		          << "RENT: " 			<< 	this->monthExpenses[i]->getRentCost()
		          << "ENTERTAINMENT: "  << 	this->monthExpenses[i]->getEntertainmentCost()
		          << "TUITION: " 		<< 	this->monthExpenses[i]->getTuitionCost()
		          << "SAVINGS: "	    << 	this->monthExpenses[i]->getSavingsCost()
		          << "MISC: "			<< 	this->monthExpenses[i]->getMiscCost() << endl;
	}
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
