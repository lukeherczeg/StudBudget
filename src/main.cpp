#include <iostream>
#include "user.h"
#include "account.h"
#include "authenticator.h"
#include "expenses.h"

int main() {
  Authenticator * authenticator = new Authenticator;
  User * user = new User();
  user = authenticator->authenticate;
  std::cout << user->getUsername() << "  " << user->getPassword() << std::endl;
  return 0;
}
