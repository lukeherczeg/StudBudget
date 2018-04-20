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
   						 "August", "September", "October", "November", "December"};	//vector for months, used for .find

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
	string tempLine;		//line used for getline
	string desiredAmount = to_string(newAmount);	//converts the amount from the input to a string to be inserted
	bool found = false;
	int monthPos = 0;

	for(unsigned int i = 0; i < months.size(); i++){
		if(months[i] == month){	//if input month matches the month in the vector of months
			break;
		}
		monthPos++;	//break and go to the next month
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
	string expense = expenseType + ':';
	ofstream tempWrite;
	readData.open("accountData.txt");
	tempWrite.open("accountDataTemp.txt", ios::app);

	while(getline(readData,tempLine)){		//while there is another line in the text file being red from
			lineContents = split(tempLine, ' ');	//split the line into strings, delimited by spaces

			for(unsigned int i = 0; i < lineContents.size(); i++){	//loops through the line
				if(lineContents[i] == username){	//for finding the correct username
					found = true;
				}
				if(lineContents[i] == month && found){	//for finding the correct line
					foundLine = true;
				}
				if(lineContents[i] == expense && foundLine && found){	//replaces the contents of that line with the correct data
					lineContents[i+1];
					tempLine.replace(tempLine.find(lineContents[i]) + lineContents[i].length() + 1, lineContents[i+1].length(), desiredAmount);
					foundLine = false;	//sets bools back to false for next iteration so correct item is replaced
					found = false;
					break;
				}
		}
		lineContents.clear();
		tempWrite << tempLine << endl;
	}
	tempWrite.close();	//cleanup stuff
	readData.close();
	remove("accountData.txt");
	rename("accountDataTemp.txt","accountData.txt");

}

double Account::getExpense(string username, string month, string expenseType) {
	vector<string> lineContents;		//vector for each line
	string tempLine;					//line used in getline
	bool found = false;					//if username is found
	bool foundLine = false;				//if username and correct month is found
	string expense = expenseType + ':';	//just the name of the expense
	ifstream readData;					//for reading data
	string expenseValueS;				//value to be returned
	double expenseValue;

	readData.open("accountData.txt");

	while (getline(readData, tempLine)) {		//while there is a line in the file
		lineContents = split(tempLine, ' ');	//splits the contents of a line by the spaces between them

		for (unsigned int i = 0; i < lineContents.size(); i++) {	//loops through the line
			if (lineContents[i] == username) {	//checks if correct username is found
				found = true;
			}
			if (lineContents[i] == month && found) {	//checks if correct month is found
				foundLine = true;
			}
			if (lineContents[i] == expense && foundLine && found) {
				expenseValueS = lineContents[i + 1];	//gets the value for that expense
				stringstream convert(expenseValueS);	//converts that value (a string) to a double
				if (!(convert >> expenseValue)) {
					expenseValue = 0;	//if it's not converted, this returns a zero
				}
				return expenseValue;
			}
		}
		lineContents.clear();			//cleanup stuff
	}
	readData.close();
	return expenseValue;
}

double Account::deposit(double expenseAmount, double depositAmount){
	double newExpenseAmount = expenseAmount + depositAmount;
  return newExpenseAmount;
}

double Account::withdraw(double expenseAmount, double withdrawlAmount){
	double updatedExpenses = expenseAmount - withdrawlAmount;
  return updatedExpenses;
}

void Account::transfer(User * user, double transferAmount, string month, string expenseType, string thisUsername){
    int monthPos;
	double amount = this->withdraw(this->getExpense(thisUsername, month, expenseType), transferAmount);
    this->changeExpenseField(thisUsername, month, expenseType, amount); //need to change the actual amount in the expenses

    for(unsigned int i = 0; i < months.size(); i++){
  		if(months[i] == month){	//if input month matches the month in the vector of months
  			break;
  		}
  		monthPos++;	//break and go to the next month
  	}
  	/////////////////////////// Sets the correct type of cost based on the input ///////////////////////////////////

  	if(expenseType == "FOOD"){
  		this->monthExpenses[monthPos]->setFoodCost(amount);
  	}
  	else if(expenseType == "RENT"){
  		this->monthExpenses[monthPos]->setRentCost(amount);
  	}
  	else if(expenseType == "ENTERTAINMENT"){
  		this->monthExpenses[monthPos]->setEntertainmentCost(amount);
  	}
  	else if(expenseType == "TUITION"){
  		this->monthExpenses[monthPos]->setTuitionCost(amount);
  	}
  	else if(expenseType == "SAVINGS"){
  		this->monthExpenses[monthPos]->setSavingsCost(amount);
  	}
  	else if(expenseType == "MISC"){
  		this->monthExpenses[monthPos]->setMiscCost(amount);
  	}
    //outgoing done. TODO incoming needs to be done

}
