#include <iostream>
#include "user.h"
#include "account.h"
#include "authenticator.h"
#include "expenses.h"

int main() {
	Authenticator * authenticator = new Authenticator;
	User * user;
	authenticator->authenticate();
	user = authenticator->getUser();
	std::cout << user->getUsername() << "," << user->getPassword() << std::endl;
	return 0;
}
