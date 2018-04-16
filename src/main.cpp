#include <iostream>
#include "user.h"
#include "calculations.h"
#include "desiredBudget.h"
#include "account.h"
#include "authenticator.h"
#include "expenses.h"

int main() {
	Authenticator * authenticator = new Authenticator;
	authenticator->authenticate();
	User * user = authenticator->getUser(); // TODO: there is a problem with logging in after signing up

	std::cout << "\nYou're now logged in as " << user->getUsername() << "!"<< std::endl;
	return 0;
}
