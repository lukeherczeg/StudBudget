#ifndef calculations_h
#define calculations_h

//just for test
#include "user.h"
#include "expenses.h"
#include "account.h"
#include <string>
#include <cstdlib>
#include <iostream>

class Calculations {
private:

	double monthlyProfit();
	double transferAmount();
	Account * account;
	Expenses * expenses;

public:

  double calculateProfit();
  void transfer(User);

};

#endif
