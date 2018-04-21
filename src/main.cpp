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

		user->getAccount()->writeData(username);
		user->getAccount()->changeExpenseField(username, 4, "TUITION", 56.9398475);		//change these parameters to test
		user->getAccount()->changeExpenseField(username, 10, "SAVINGS", 34.69);		//and these
		//user->getAccount()->printData();


		int month;
		string type;
		month = 10;
		type = "SAVINGS";
		cout << "\nYour " << month << " " << type << " are [" <<  user->getAccount()->getExpense(username, month, type) << "]\n";
	}

	return 0;
}
