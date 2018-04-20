#include <iostream>
#include "user.h"
#include "calculations.h"
#include "desiredBudget.h"
#include "account.h"
#include "authenticator.h"
#include "expenses.h"

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
		user->getAccount()->changeExpenseField(username, "May", "TUITION", 56.9398475);		//change these parameters to test
		user->getAccount()->changeExpenseField(username, "November", "SAVINGS", 34.69);	//and these
		//user->getAccount()->printData();


		string month, type;
		month = "November";
		type = "SAVINGS";
		cout << "\nYour " << month << " " << type << " are [" <<  user->getAccount()->getExpense(username, month, type) << "]\n";
	}

	return 0;
}
