#include <iostream>
#include "user.h"
#include "calculations.h"
#include "desiredBudget.h"
#include "account.h"
#include "authenticator.h"
#include "expenses.h"

int main() {
	Authenticator * authenticator = new Authenticator;
	authenticator->fillMapOfUsers();
	authenticator->printUserObjects();
	authenticator->authenticate();

	if(authenticator->getUser() != NULL){ // Used so the exit function doesn't cause an overflow.

		User * user = authenticator->getUser();
		std::string username = user->getUsername();
		std::cout << "\nYou're logged in as " << username << "!" << std::endl;


		//user->getAccount()->writeData(username); // TODO fix the segfault on this function!
		user->getAccount()->printData();
	}

	return 0;
}
