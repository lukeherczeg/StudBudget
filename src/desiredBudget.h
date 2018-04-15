#ifndef DESIREDBUDGET_H_
#define DESIREDBUDGET_H_

class DesiredBudget {
private:
  double foodBudget;
  double rentBudget;
  double entertainmentBudget;
  double tuitionBudget;
  double savingsBudget;
  double miscBudget;

public:
  void setFoodBudget(double food);
  double getFoodBudget();
  void setRentBudget(double rent);
  double getRentBudget();
  void setEntertainmentBudget(double entertainment);
   double getEntertainmentBudget();
   void setTuitionBudget(double tuition);
   double getTuitionBudget();
   void setSavingsBudget(double savings);
   double getSavingsBudget();
   void setMiscBudget(double misc);
   double getMiscBudget();
};

#endif
