#ifndef EXPENSES_H_
#define EXPENSES_H_

class expenses {
private:
  double foodCost;
  double rentCost;
  double entertainmentCost;
  double tutionCost;
  double savingsCost;
  double miscCost;

public:
  void setFoodCost(double food);
  double getFoodCost();
  void setRent(double rent);
  double getRent();
  void setEntertainmentCost(double entertainment);
  double getEntertainmentCost();
  void setTuitionCost(double tuition);
  double getTutionCost();
  void setSavingsCost(double savings);
  double getSavingsCost();
  void setMiscCost(double misc);
  double getMiscCost();
}

#endif
