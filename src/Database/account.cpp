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
    this->expenses = new Expenses();
    this->username = "";
    this->month = 0;
    this->expenseType = "";
}

Expenses* Account::getExpenseObj(){
    return this->expenses;
}

std::string Account::getFinancialAdvice(int month){
    if(month < 0){
        return this->expenses->financialAdvice();
    }
    else{
        return this->expenses->financialAdvice(month);
    }
}

void Account::setUsername(string username){
    this->username = username;
}

void Account::setMonth(int month){
    this->month = month;
}

void Account::setExpenseType(string expenseType){
    this->expenseType = expenseType;
}

void Account::setProjectedBudget(){
    this->expenses->projectBudget();
}


bool Account::dataExists(){
    ifstream readData;
    string tempLine;
    readData.open("accountData.txt");
    while(readData >> tempLine){
        if(tempLine == this->username){
            return true;
        }
    }
    return false;
}

void Account::writeData(){
    if(!this->dataExists()){ // If the given user hasn't already had data logged
        ofstream writeData;
        writeData.open("accountData.txt", ios_base::app); // Appends new data to the file
        writeData << "\n" << this->username << "\n\n";
        for(unsigned int i = 0; i < months.size(); i++){  // Months is the same size as the expenses
            writeData << months[i];
            for(unsigned int j = 0; j < (9 - months[i].size()); j++){ // 9 is the longest month, September
                writeData << " ";									  // Correctly formats the data.
            }

            writeData <<  " "  << "FOOD: " 					<<	this->expenses->getFoodCost(i)
                      << " | " << "RENT: " 					<< 	this->expenses->getRentCost(i)
                      << " | " << "ENTERTAINMENT: " 		<< 	this->expenses->getEntertainmentCost(i)  //For loop causes a new object to be created for
                      << " | " << "TUITION: " 				<< 	this->expenses->getTuitionCost(i)		//each month, then each expense is printed for that month
                      << " | " << "SAVINGS: "	    		<< 	this->expenses->getSavingsCost(i)
                      << " | " << "MISC: "					<< 	this->expenses->getMiscCost(i)
                      << " | " << "FOODBUDGET: " 			<<	this->expenses->getFoodBudget(i)
                      << " | " << "RENTBUDGET: " 			<< 	this->expenses->getRentBudget(i)
                      << " | " << "ENTERTAINMENTBUDGET: " 	<< 	this->expenses->getEntertainmentBudget(i)
                      << " | " << "TUITIONBUDGET: " 		<< 	this->expenses->getTuitionBudget(i)
                      << " | " << "SAVINGSBUDGET: "	  		<< 	this->expenses->getSavingsBudget(i)
                      << " | " << "MISCBUDGET: "			<< 	this->expenses->getMiscBudget(i) << endl;
        }
        writeData.close();
    }
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

void Account::setCost(double amount){
    if(this->expenseType == "FOOD"){
        this->expenses->setFoodCost(amount, this->month);
    }
    else if(this->expenseType == "RENT"){
        this->expenses->setRentCost(amount, this->month);
    }
    else if(this->expenseType == "ENTERTAINMENT"){
        this->expenses->setEntertainmentCost(amount, this->month);
    }
    else if(this->expenseType == "TUITION"){
        this->expenses->setTuitionCost(amount, this->month);
    }
    else if(this->expenseType == "SAVINGS"){
        this->expenses->setSavingsCost(amount, this->month);
    }
    else if(this->expenseType == "MISC"){
        this->expenses->setMiscCost(amount, this->month);
    }
    else if(this->expenseType == "FOODBUDGET"){
        this->expenses->setFoodBudget(amount, this->month);
    }
    else if(this->expenseType == "RENTBUDGET"){
        this->expenses->setRentBudget(amount, this->month);
    }
    else if(this->expenseType == "ENTERTAINMENTBUDGET"){
        this->expenses->setEntertainmentBudget(amount, this->month);
    }
    else if(this->expenseType == "TUITIONBUDGET"){
        this->expenses->setTuitionBudget(amount, this->month);
    }
    else if(this->expenseType == "SAVINGSBUDGET"){
        this->expenses->setSavingsBudget(amount, this->month);
    }
    else if(this->expenseType == "MISCBUDGET"){
        this->expenses->setMiscBudget(amount, this->month);
    }
}

void Account::changeExpenseField(double newAmount){
    vector<string> lineContents;
    string tempLine;		//line used for getline
    string desiredAmount = to_string(newAmount);	//converts the amount from the input to a string to be inserted
    bool found = false;

    this->setCost(newAmount); // Sets the correct type of cost based on the input

    bool foundLine = false;
    ifstream readData;
    string expense = this->expenseType + ':';
    ofstream tempWrite;
    readData.open("accountData.txt");
    tempWrite.open("accountDataTemp.txt", ios::app);

    while(getline(readData,tempLine)){		//while there is another line in the text file being red from
            lineContents = split(tempLine, ' ');	//split the line into strings, delimited by spaces

            for(unsigned int i = 0; i < lineContents.size(); i++){	//loops through the line
                if(lineContents[i] == this->username){	//for finding the correct username
                    found = true;
                }
                if(lineContents[i] == months[this->month] && found){	//for finding the correct line
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

double Account::getExpense() {
    vector<string> lineContents;		//vector for each line
    string tempLine;					//line used in getline
    bool found = false;					//if username is found
    bool foundLine = false;				//if username and correct month is found
    string expense = this->expenseType + ':';	//just the name of the expense
    ifstream readData;					//for reading data
    string expenseValueS;				//value to be returned
    double expenseValue;

    readData.open("accountData.txt");

    while (getline(readData, tempLine)) {		//while there is a line in the file
        lineContents = split(tempLine, ' ');	//splits the contents of a line by the spaces between them

        for (unsigned int i = 0; i < lineContents.size(); i++) {	//loops through the line
            if (lineContents[i] == this->username) {	//checks if correct username is found
                found = true;
            }
            if (lineContents[i] == months[this->month] && found) {	//checks if correct month is found
                foundLine = true;
            }
            if (lineContents[i] == expense && foundLine && found) {
                expenseValueS = lineContents[i + 1];	//gets the value for that expense
                stringstream convert(expenseValueS);	//converts that value (a string) to a double
                if (!(convert >> expenseValue)) {
                    expenseValue = 0;	//if it's not converted, this returns a zero
                }
                this->setCost(expenseValue);
                return expenseValue;
            }
        }
        lineContents.clear();	//cleanup stuff
    }
    readData.close();

    return expenseValue;
}

void Account::deposit(double depositAmount){
    double updatedExpenses = this->getExpense() + depositAmount;
    changeExpenseField(updatedExpenses);
}

void Account::withdraw(double withdrawAmount){
    double updatedExpenses = this->getExpense() - withdrawAmount;
    changeExpenseField(updatedExpenses);
}
