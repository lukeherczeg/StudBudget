//  calculations.cpp
//  cop3503_termproject
//  Created by Madeline Farina on 4/13/18 (friday the 13th <3)

#include "calculations.h"
#include "expenses.h"
#include "account.h"
#include "desiredBudget.h"
#include "user.h"
#include <iostream>
#include <string>
#include <fstream>
#include <istream>

using namespace std;

double Calculations::monthlyProfit(){
	double income = this->account->getIncomingSalary();
	double totalExpense = this->expenses->totalExpenses();
	return income - totalExpense;
}

/* unnecessary functions
double Calculations::transferAmount(){
  return 0.0;
}

double Calculations::calculateProfit() {
  return 0.0;
}*/

void Calculations::transfer(User x) {
	//transfers money between user accounts
	
  return;
}
