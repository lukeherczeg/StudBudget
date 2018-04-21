#include <iostream>
#include "user.h"
#include "account.h"
#include "authenticator.h"
#include "expenses.h"

const vector<string> months = {"January", "February", "March", "April", "May", "June", "July",
   						 "August", "September", "October", "November", "December"};	//vector for months, used for .find


int main() {
	Authenticator * authenticator = new Authenticator();

	authenticator->fillMapOfUsers(); // Just for observing users and their memory, don't need for final product.
	authenticator->printUserObjects();
	authenticator->authenticate();

	if(authenticator->getUser() != NULL){ // Used so the exit function doesn't cause an overflow.
		User * user = authenticator->getUser();
		std::string username = user->getUsername();
		std::cout << "\nYou're logged in as " << username << "!" << std::endl;
		user->getAccount()->setUsername(username);
		int month;
		string type;

		user->getAccount()->writeData();


		month = 10;
		type = "MISCBUDGET";
		user->getAccount()->setExpenseType(type);
		user->getAccount()->setMonth(month);
		user->getAccount()->deposit(100);		//change these parameters to test

		month = 9;
		type = "TUITION";
		user->getAccount()->setExpenseType(type);
		user->getAccount()->setMonth(month);
		user->getAccount()->deposit(39);	//and these

		cout << "\nYour " << months[month] << " " << type << " is [" <<  user->getAccount()->getExpense() << "]\n";
	}

	return 0;
}
