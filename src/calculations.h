#ifndef calculations_h
#define calculations_h

//just for test
#include "user.h"
#include <string>
#include <cstdlib>
#include <iostream>

class Calculations {
private:

	double monthlyProfit;
  double transferAmount;

public:

  double calculateProfit();
  void transfer(User);

};

#endif
