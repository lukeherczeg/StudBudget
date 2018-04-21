#include "expenses.h"

Expenses::Expenses(int* f, int* r, int* e, int* t, int* s, int* m, int* fBudget, int* rBudget, int* eBudget, int* tBudget, int* sBudget, int* mBudget) {
    for(int i = 0; i < 12; i++) {
        foodCost[i] = f[i];
        foodBudget[i] = fBudget[i];
        rentCost[i] = r[i];
        rentBudget[i] = rBudget[i];
        entertainmentCost[i] = e[i];
        entertainmentBudget[i] = eBudget[i];
        tuitionCost[i] = t[i];
        tuitionBudget[i] = tBudget[i];
        savingsCost[i] = s[i];
        savingsBudget[i] = sBudget[i];
        miscCost[i] = m[i];
        miscBudget[i] = mBudget[i];
    }
}

void Expenses::setFoodCost(double food, int month) {
  foodCost[month] = food;
  totalCost[month] += food;
}

double Expenses::getFoodCost(int month) {
  return foodCost[month];
}

void Expenses::setFoodBudget(double food, int month) {
  foodBudget[month] = food;
  totalBudget[month] += food;
}

double Expenses::getFoodBudget(int month) {
  return foodBudget[month];
}

void Expenses::setRent(double rent, int month) {
  rentCost[month] = rent;
  totalCost[month] += rent;
}

double Expenses::getRent(int month) {
  return foodCost[month];
}

void Expenses::setRentBudget(double rent, int month) {
  rentBudget[month] = rent;
  totalBudget[month] += rent;
}

double Expenses::getRentBudget(int month) {
  return foodBudget[month];
}

void Expenses::setEntertainmentCost(double entertainment, int month) {
  entertainmentCost[month] = entertainment;
  totalCost[month] += entertainment;
}

double Expenses::getEntertainmentCost(int month) {
  return entertainmentCost[month];
}

void Expenses::setEntertainmentBudget(double entertainment, int month) {
  entertainmentBudget[month] = entertainment;
  totalBudget[month] += entertainment;
}

double Expenses::getEntertainmentBudget(int month) {
  return entertainmentBudget[month];
}

void Expenses::setTuitionCost(double tuition, int month) {
  tuitionCost[month] = tuition;
  totalCost[month] += tuition;
}

double Expenses::getTutionCost(int month) {
  return tuitionCost[month];
}

void Expenses::setTuitionBudget(double tuition, int month) {
  tuitionBudget[month] = tuition;
  totalBudget[month] += tuition;
}

double Expenses::getTutionBudget(int month) {
  return tuitionBudget[month];
}

void Expenses::setSavingsCost(double savings, int month) {
  savingsCost[month] = savings;
  totalCost[month] += savings;
}

double Expenses::getSavingsCost(int month) {
  return savingsCost[month];
}

void Expenses::setSavingsBudget(double savings, int month) {
  savingsBudget[month] = savings;
  totalBudget[month] += savings;
}

double Expenses::getSavingsBudget(int month) {
  return savingsBudget[month];
}

void Expenses::setMiscCost(double misc, int month) {
  miscCost[month] = misc;
  totalCost[month] += misc;
}

double Expenses::getMiscCost(int month) {
  return miscCost[month];
}

void Expenses::setMiscBudget(double misc, int month) {
  miscBudget[month] = misc;
  totalBudget[month] += misc;
}

double Expenses::getMiscBudget(int month) {
  return miscBudget[month];
}

void Expenses::setExtraDeficit() {
  for(int i = 0; i < 12; i++) {
    if(getFoodBudget(i) - getFoodCost(i) > 0) {
      foodExtra[i] = getFoodBudget(i) - getFoodCost(i);
      foodDeficit[i] = 0;
    } else if(getFoodBudget(i) - getFoodCost(i) == 0) {
      foodExtra[i] = 0;
      foodDeficit[i] = 0;
    } else {
      foodExtra[i] = 0;
      foodDeficit[i] = getFoodCost(i) - getFoodBudget(i);
    }

    if(getRentBudget(i) - getRent(i) > 0) {
      rentExtra[i] = getRentBudget(i) - getRent(i);
      rentDeficit[i] = 0;
    } else if(getRentBudget(i) - getRent(i) == 0) {
      rentExtra[i] = 0;
      rentDeficit[i] = 0;
    } else {
      rentExtra[i] = 0;
      rentDeficit[i] = getRent(i) - getRentBudget(i);
    }

    if(getEntertainmentBudget(i) - getEntertainmentCost(i) > 0) {
      entertainmentExtra[i] = getEntertainmentBudget(i) - getEntertainmentCost(i);
      entertainmentDeficit[i] = 0;
    } else if(getEntertainmentBudget(i) - getEntertainmentCost(i) == 0) {
      entertainmentExtra[i] = 0;
      entertainmentDeficit[i] = 0;
    } else {
      entertainmentExtra[i] = 0;
      entertainmentDeficit[i] = getEntertainmentCost(i) - getEntertainmentBudget(i);
    }

    if(getTuitionBudget(i) - getTuitionCost(i) > 0) {
      tuitionExtra[i] = getTuitionBudget(i) - getTuitionCost(i);
      tuitionDeficit[i] = 0;
    } else if(getTuitionBudget(i) - getTuitionCost(i) == 0) {
      tuitionExtra[i] = 0;
      tuitionDeficit[i] = 0;
    } else {
      tuitionExtra[i] = 0;
      tuitionDeficit[i] = getTuitionCost(i) - getTuitionBudget(i);
    }

    if(getSavingsBudget(i) - getSavingsCost(i) > 0) {
      savingsExtra[i] = getSavingsBudget(i) - getSavingsCost(i);
      savingsDeficit[i] = 0;
    } else if(getSavingsBudget(i) - getSavingsCost(i) == 0) {
      savingsExtra[i] = 0;
      savingsDeficit[i] = 0;
    } else {
      savingsExtra[i] = 0;
      savingsDeficit[i] = getSavingsCost(i) - getSavingsBudget(i);
    }

    if(getMiscBudget(i) - getMiscCost(i) > 0) {
      miscExtra[i] = getMiscBudget(i) - getMiscCost(i);
      miscDeficit[i] = 0;
    } else if(getMiscBudget(i) - getMiscCost(i) == 0) {
      miscExtra[i] = 0;
      miscDeficit[i] = 0;
    } else {
      miscExtra[i] = 0;
      miscDeficit[i] = getMiscCost(i) - getMiscBudget(i);
    }

    totalFoodCost += foodCost[i];
    totalFoodExtra += foodExtra[i];
    totalFoodDeficit += foodDeficit[i];
    totalRentCost += rentCost[i];
    totalRentExtra += rentExtra[i];
    totalRentDeficit += rentDeficit[i];
    totalEntertainmentCost += entertainmentCost[i];
    totalEntertainmentExtra += entertainmentExtra[i];
    totalEntertainmentDeficit += entertainmentDeficit[i];
    totalTuitionCost += tuitionCost[i];
    totalTuitionExtra += tuitionExtra[i];
    totalTuitionDeficit += tuitionDeficit[i];
    totalSavingsCost += savingsCost[i];
    totalSavingsExtra += savingsExtra[i];
    totalSavingsDeficit += savingsDeficit[i];
    totalMiscCost += miscCost[i];
    totalMiscExtra += miscExtra[i];
    totalMiscDeficit += miscDeficit[i];
  }
}

void Expenses::financialAdvice() {

}
