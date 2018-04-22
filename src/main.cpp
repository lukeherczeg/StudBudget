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
		User * user = authenticator->getUser(); // Gets the user
		user->getAccount()->setUsername(user->getUsername()); // sets the username for the account of the user
		std::string username = user->getUsername(); // Makes a username for later use with by getting the username
		std::cout << "\nYou're logged in as " << username << "!" << std::endl; // Don't need
		int month;
		string type; // these 2 are just going to be used when you go to the month or go to the expense type

		user->getAccount()->writeData(); // This makes the database initially with 0s


		month = 10;									// These are just for testing!
		type = "MISCBUDGET";
		user->getAccount()->setExpenseType(type); // This is how you make sure you are on the right expense
		user->getAccount()->setMonth(month);	// this is how you set the month you are on
		user->getAccount()->deposit(100);		// this is how you deposit

		month = 9;
		type = "TUITION";
		user->getAccount()->setExpenseType(type); // same
		user->getAccount()->setMonth(month);
		user->getAccount()->deposit(39);	//and these

		cout << "\nYour " << months[month] << " " << type << " is [" <<  user->getAccount()->getExpense() << "]\n";
	}

	return 0;
}
