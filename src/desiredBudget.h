#ifndef DESIREDBUDGET_H_
#define DESIREDBUDGET_H_
class desiredBudget {
private:
  double foodBudget;
  double rentBudget;
  double entertainmentBudget;
  double tutionBudget;
  double savingsBudget;
  double miscBudget;

public:
  void setFoodBudget(double food);
  double getFoodBudget();
  void setRent(double rent);
  double getRent();
  void setEntertainmentBudget(double entertainment);
   double getEntertainmentBudget();
   void setTuitionBudget(double tuition);
   double getTutionBudget();
   void setSavingsBudget(double savings);
   double getSavingsBudget();
   void setMiscBudget(double misc);
   double getMiscBudget();
}

#ENDIF
