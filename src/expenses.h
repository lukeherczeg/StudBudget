#ifndef EXPENSES_H_
#define EXPENSES_H_

class Expenses {
private:
  double foodCost;
  double rentCost;
  double entertainmentCost;
  double tuitionCost;
  double savingsCost;
  double miscCost;

public:
  Expenses();
  void setFoodCost(double food);
  double getFoodCost();
  void setRentCost(double rent);
  double getRentCost();
  void setEntertainmentCost(double entertainment);
  double getEntertainmentCost();
  void setTuitionCost(double tuition);
  double getTuitionCost();
  void setSavingsCost(double savings);
  double getSavingsCost();
  void setMiscCost(double misc);
  double getMiscCost();
  double totalExpenses();
};

#endif
