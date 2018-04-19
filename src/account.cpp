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
#include <sstream>
#include <cstdio>
#include <map>
#include <iterator>
#include "expenses.h"
#include "user.h"
#include "account.h"
#include "authenticator.h"


const vector<string> months = {"January", "February", "March", "April", "May", "June", "July",
   						 "August", "September", "October", "November", "December"};

Account::Account(){
	int size = 12;
	this->monthExpenses.reserve(size); // Reserve 12 because there will be 12 months
	for(int i = 0; i < size; i++){
		this->monthExpenses.push_back(NULL);
	}
	this->checkingAccountNumber = 0;
	this->incomingSalary = 0;
	this->savingAccountNumber = 0;
	this->startBalance = 0;
}

bool Account::dataExists(string username){
	ifstream readData;
	string tempLine;
	readData.open("accountData.txt");
	while(readData >> tempLine){
		if(tempLine == username){
			return true;
		}
	}
	return false;
}

void Account::writeData(string username){
	if(!this->dataExists(username)){ // If the given user hasn't already had data logged
		ofstream writeData;
		writeData.open("accountData.txt", ios_base::app); // Appends new data to the file
		writeData << "\n" << username << "\n\n";
		for(unsigned int i = 0; i < months.size(); i++){  // Months is the same size as the expenses
			writeData << months[i];
			for(unsigned int j = 0; j < (9 - months[i].size()); j++){ // 9 is the longest month, September
				writeData << " ";									  // Correctly formats the data.
			}

			this->monthExpenses[i] = new Expenses();	//a new object for expenses is set equal to pointer to each month's expenses
			writeData <<  " "  << "FOOD: " 			<<	this->monthExpenses[i]->getFoodCost()
					  << " | " << "RENT: " 			<< 	this->monthExpenses[i]->getRentCost()
					  << " | " << "ENTERTAINMENT: " << 	this->monthExpenses[i]->getEntertainmentCost()  //For loop causes a new object to be created for
					  << " | " << "TUITION: " 		<< 	this->monthExpenses[i]->getTuitionCost()		//each month, then each expense is printed for that month
					  << " | " << "SAVINGS: "	    << 	this->monthExpenses[i]->getSavingsCost()
					  << " | " << "MISC: "			<< 	this->monthExpenses[i]->getMiscCost() << endl;
		}
		writeData.close();
	}
	else{
		for(unsigned int i = 0; i < months.size(); i++){
			this->monthExpenses[i] = new Expenses();
		}
	}
}

void Account::printData(){
	ifstream readData;
	string tempLine;
	readData.open("accountData.txt");
	while(getline(readData, tempLine)){
		cout << tempLine << endl;
	}
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


// TODO , write a function to both use the data to do ::: line.replace(line.find(deleteline),deleteline.length(),"");
// and change the field by accessing the month's index.


/////////////////// For delimiting a string by spaces on one line ////////////////////////////
template<typename Out>
void split(const string &s, char delim, Out result) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        *(result++) = item;
    }
}

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, back_inserter(elems));
    return elems;
}
/////////////////// For delimiting a string by spaces on one line ////////////////////////////


void Account::changeExpenseField(string username, string month, string expenseType, double newAmount){
	vector<string> lineContents;
	string tempLine;
	string desiredAmount = to_string(newAmount);
	bool found = false;
	int monthPos = 0;

	for(unsigned int i = 0; i < months.size(); i++){
		if(months[i] == month){
			break;
		}
		monthPos++;
	}
	/////////////////////////// Sets the correct type of cost based on the input ///////////////////////////////////

	if(expenseType == "FOOD"){
		this->monthExpenses[monthPos]->setFoodCost(newAmount);
	}
	else if(expenseType == "RENT"){
		this->monthExpenses[monthPos]->setRentCost(newAmount);
	}
	else if(expenseType == "ENTERTAINMENT"){
		this->monthExpenses[monthPos]->setEntertainmentCost(newAmount);
	}
	else if(expenseType == "TUITION"){
		this->monthExpenses[monthPos]->setTuitionCost(newAmount);
	}
	else if(expenseType == "SAVINGS"){
		this->monthExpenses[monthPos]->setSavingsCost(newAmount);
	}
	else if(expenseType == "MISC"){
		this->monthExpenses[monthPos]->setMiscCost(newAmount);
	}


	/////////////////////////// Sets the correct type of cost based on the input ///////////////////////////////////

	bool foundLine = false;
	ifstream readData;
	vector<string> data;
	string expense = expenseType + ':';
	cout << expense;
	ofstream tempWrite;
	readData.open("accountData.txt");
	tempWrite.open("accountDataTemp.txt", ios::app);

	while(getline(readData,tempLine)){
			lineContents = split(tempLine, ' ');

			for(unsigned int i = 0; i < lineContents.size(); i++){
				if(lineContents[i] == username){
					found = true;
				}
				if(lineContents[i] == month && found){
					foundLine = true;
				}
				if(lineContents[i] == expense && foundLine && found){
					lineContents[i+1];
					tempLine.replace(tempLine.find(lineContents[i]) + lineContents[i].length() + 1, lineContents[i+1].length(), desiredAmount);
					foundLine = false;
					found = false;
					break;
				}
		}
		lineContents.clear();
		tempWrite << tempLine << endl;
	}
	tempWrite.close();
	readData.close();
	remove("accountData.txt");
	rename("accountDataTemp.txt","accountData.txt");

}

double Account::deposit(double depositAmount){
	return 0.0; //placeholder - have to include this in calculations and call specific accounts
}

double Account::withdraw(double withdrawlAmount){
	return 0.0; //placeholder - have to include this in calculations and call specific accounts
}



































