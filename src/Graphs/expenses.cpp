#include "expenses.h"
#include <string>

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts>

Expenses::Expenses() {
    for(int i = 0; i < 12; i++) {
        this->foodCost[i] = 0;
        this->foodBudget[i] = 0;
        this->rentCost[i] = 0;
        this->rentBudget[i] = 0;
        this->entertainmentCost[i] = 0;
        this->entertainmentBudget[i] = 0;
        this->tuitionCost[i] = 0;
        this->tuitionBudget[i] = 0;
        this->savingsCost[i] = 0;
        this->savingsBudget[i] = 0;
        this->miscCost[i] = 0;
        this->miscBudget[i] = 0;
        this->totalCost[i] = 0;
        this->totalBudget[i] = 0;
        this->totalDeficit[i] = 0;
        this->totalExtra[i] = 0;
    }
}

void Expenses::setFoodCost(double food, int month) {
  foodCost[month] = food;
}

double Expenses::getFoodCost(int month) {
  return foodCost[month];
}

QChartView* Expenses::getFoodGraph(){ // annual food spending line graph
  // set foodGraph data
   QLineSeries *foodGraph = new QLineSeries();
   for(int i = 0; i < 12; i++) {
     foodGraph->append(i + 1, getFoodCost(i));
   }

  // make food graph
  QChart *foodChart = new QChart();
  foodChart->legend()->hide();
  foodChart->addSeries(foodGraph);
  foodChart->createDefaultAxes();
  foodChart->setTitle("Food Spending");

  // view food graph
  QChartView *foodView = new QChartView(foodChart);
  foodView->setRenderHint(QPainter::Antialiasing);

  return foodView;
}

void Expenses::setFoodBudget(double food, int month) {
  foodBudget[month] = food;
}

double Expenses::getFoodBudget(int month) {
  return foodBudget[month];
}

void Expenses::setRentCost(double rent, int month) {
  rentCost[month] = rent;
}

double Expenses::getRentCost(int month) {
  return rentCost[month];
}

QChartView* Expenses::getRentGraph() { // annual rent spending line graph
  // set rentGraph data
   QLineSeries *rentGraph = new QLineSeries();
   for(int i = 0; i < 12; i++) {
     rentGraph->append(i + 1, getRentCost(i));
   }

  // make rent graph
  QChart *rentChart = new QChart();
  rentChart->legend()->hide();
  rentChart->addSeries(rentGraph);
  rentChart->createDefaultAxes();
  rentChart->setTitle("Rent Spending");

  // view rent graph
  QChartView *rentView = new QChartView(rentChart);
  rentView->setRenderHint(QPainter::Antialiasing);

  return rentView;
}

void Expenses::setRentBudget(double rent, int month) {
  rentBudget[month] = rent;
}

double Expenses::getRentBudget(int month) {
  return rentBudget[month];
}

void Expenses::setEntertainmentCost(double entertainment, int month) {
  entertainmentCost[month] = entertainment;
}

double Expenses::getEntertainmentCost(int month) {
  return entertainmentCost[month];
}

QChartView* Expenses::getEntertainmentGraph() { // annual entertainment spending line graph
  // set entertainmentGraph data
   QLineSeries *entertainmentGraph = new QLineSeries();
   for(int i = 0; i < 12; i++) {
     entertainmentGraph->append(i + 1, getEntertainmentCost(i));
   }

  // make entertainment graph
  QChart *entertainmentChart = new QChart();
  entertainmentChart->legend()->hide();
  entertainmentChart->addSeries(entertainmentGraph);
  entertainmentChart->createDefaultAxes();
  entertainmentChart->setTitle("Entertainment Spending");

  // view entertainment graph
  QChartView *entertainmentView = new QChartView(entertainmentChart);
  entertainmentView->setRenderHint(QPainter::Antialiasing);

  return entertainmentView;
}

void Expenses::setEntertainmentBudget(double entertainment, int month) {
  entertainmentBudget[month] = entertainment;
}

double Expenses::getEntertainmentBudget(int month) {
  return entertainmentBudget[month];
}

void Expenses::setTuitionCost(double tuition, int month) {
  tuitionCost[month] = tuition;
}

double Expenses::getTuitionCost(int month) {
  return tuitionCost[month];
}

QChartView* Expenses::getTuitionGraph() { // annual tuition spending line graph
  // set tuitionGraph data
   QLineSeries *tuitionGraph = new QLineSeries();
   for(int i = 0; i < 12; i++) {
     tuitionGraph->append(i + 1, getTuitionCost(i));
   }

  // make tuition graph
  QChart *tuitionChart = new QChart();
  tuitionChart->legend()->hide();
  tuitionChart->addSeries(tuitionGraph);
  tuitionChart->createDefaultAxes();
  tuitionChart->setTitle("Tuition Spending");

  // view tuition graph
  QChartView *tuitionView = new QChartView(tuitionChart);
  tuitionView->setRenderHint(QPainter::Antialiasing);

  return tuitionView;
}

void Expenses::setTuitionBudget(double tuition, int month) {
  tuitionBudget[month] = tuition;
}

double Expenses::getTuitionBudget(int month) {
  return tuitionBudget[month];
}

void Expenses::setSavingsCost(double savings, int month) {
  savingsCost[month] = savings;
}

double Expenses::getSavingsCost(int month) {
  return savingsCost[month];
}

QChartView* Expenses::getSavingsGraph() { // annual savings spending line graph
  // set savingsGraph data
  QLineSeries *savingsGraph = new QLineSeries();
  for(int i = 0; i < 12; i++) {
    savingsGraph->append(i + 1, getSavingsCost(i));
  }

  // make savings graph
  QChart *savingsChart = new QChart();
  savingsChart->legend()->hide();
  savingsChart->addSeries(savingsGraph);
  savingsChart->createDefaultAxes();
  savingsChart->setTitle("Savings Spending");

  // view savings graph
  QChartView *savingsView = new QChartView(savingsChart);
  savingsView->setRenderHint(QPainter::Antialiasing);

  return savingsView;
}

void Expenses::setSavingsBudget(double savings, int month) {
  savingsBudget[month] = savings;
}

double Expenses::getSavingsBudget(int month) {
  return savingsBudget[month];
}

void Expenses::setMiscCost(double misc, int month) {
  miscCost[month] = misc;
}

double Expenses::getMiscCost(int month) {
  return miscCost[month];
}

QChartView* Expenses::getMiscGraph() { // annual misc spending line graph
  // set miscGraph data
   QLineSeries *miscGraph = new QLineSeries();
   for(int i = 0; i < 12; i++) {
     miscGraph->append(i + 1, getMiscCost(i));
   }

  // make misc graph
  QChart *miscChart = new QChart();
  miscChart->legend()->hide();
  miscChart->addSeries(miscGraph);
  miscChart->createDefaultAxes();
  miscChart->setTitle("Misc Spending");

  // view misc graph
  QChartView *miscView = new QChartView(miscChart);
  miscView->setRenderHint(QPainter::Antialiasing);

  return miscView;
}

void Expenses::setMiscBudget(double misc, int month) {
  miscBudget[month] = misc;
}

double Expenses::getMiscBudget(int month) {
  return miscBudget[month];
}

void Expenses::projectBudget(){
    for(int i = 0; i < 12; i++){
        totalBudget[i] = foodBudget[i] + rentBudget[i] + entertainmentBudget[i] + tuitionBudget[i] + savingsBudget[i] + miscBudget[i];
    }
}

void Expenses::setExtraDeficit() {
    totalFoodCost = 0;
    totalFoodBudget = 0;
    totalFoodExtra = 0;
    totalFoodDeficit = 0;
    totalRentCost = 0;
    totalRentBudget = 0;
    totalRentExtra = 0;
    totalRentDeficit = 0;
    totalEntertainmentCost = 0;
    totalEntertainmentBudget = 0;
    totalEntertainmentExtra = 0;
    totalEntertainmentDeficit = 0;
    totalTuitionCost = 0;
    totalTuitionBudget = 0;
    totalTuitionExtra = 0;
    totalTuitionDeficit = 0;
    totalSavingsCost = 0;
    totalSavingsBudget = 0;
    totalSavingsExtra = 0;
    totalSavingsDeficit = 0;
    totalMiscCost = 0;
    totalMiscBudget = 0;
    totalMiscExtra = 0;
    totalMiscDeficit = 0;

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

    if(getRentBudget(i) - getRentCost(i) > 0) {
      rentExtra[i] = getRentBudget(i) - getRentCost(i);
      rentDeficit[i] = 0;
    } else if(getRentBudget(i) - getRentCost(i) == 0) {
      rentExtra[i] = 0;
      rentDeficit[i] = 0;
    } else {
      rentExtra[i] = 0;
      rentDeficit[i] = getRentCost(i) - getRentBudget(i);
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
    totalFoodBudget += foodBudget[i];
    totalFoodExtra += foodExtra[i];
    totalFoodDeficit += foodDeficit[i];
    totalRentCost += rentCost[i];
    totalRentBudget += rentBudget[i];
    totalRentExtra += rentExtra[i];
    totalRentDeficit += rentDeficit[i];
    totalEntertainmentCost += entertainmentCost[i];
    totalEntertainmentBudget += entertainmentBudget[i];
    totalEntertainmentExtra += entertainmentExtra[i];
    totalEntertainmentDeficit += entertainmentDeficit[i];
    totalTuitionCost += tuitionCost[i];
    totalTuitionBudget += tuitionBudget[i];
    totalTuitionExtra += tuitionExtra[i];
    totalTuitionDeficit += tuitionDeficit[i];
    totalSavingsCost += savingsCost[i];
    totalSavingsBudget += savingsBudget[i];
    totalSavingsExtra += savingsExtra[i];
    totalSavingsDeficit += savingsDeficit[i];
    totalMiscCost += miscCost[i];
    totalMiscBudget += miscBudget[i];
    totalMiscExtra += miscExtra[i];
    totalMiscDeficit += miscDeficit[i];

    totalCost[i] = foodCost[i] + rentCost[i] + entertainmentCost[i] + tuitionCost[i] + savingsCost[i] + miscCost[i];
    totalDeficit[i] = foodDeficit[i] + rentDeficit[i] + entertainmentDeficit[i] + tuitionDeficit[i] + savingsDeficit[i] + miscDeficit[i];
    totalExtra[i] = foodExtra[i] + rentExtra[i] + entertainmentExtra[i] + tuitionExtra[i] + savingsExtra[i] + miscExtra[i];

    }
    totalAnnualBudget = totalFoodBudget + totalRentBudget + totalEntertainmentBudget + totalTuitionBudget + totalSavingsBudget + totalMiscBudget;
    totalAnnualCost = totalFoodCost + totalRentCost + totalEntertainmentCost + totalTuitionCost + totalSavingsCost + totalMiscCost;
    totalAnnualDeficit = totalFoodDeficit + totalRentDeficit + totalEntertainmentDeficit + totalTuitionDeficit + totalSavingsDeficit + totalMiscDeficit;
    totalAnnualExtra = totalFoodExtra + totalRentExtra + totalEntertainmentExtra + totalTuitionExtra + totalSavingsExtra + totalMiscExtra;
}

QChartView* Expenses::getAnnualCostChart() { // expenses pie chart by year
  QPieSeries *series = new QPieSeries();
  series->append("Food", totalFoodCost);
  series->append("Rent", totalRentCost);
  series->append("Entertainment", totalEntertainmentCost);
  series->append("Tuition", totalTuitionCost);
  series->append("Savings", totalSavingsCost);
  series->append("Misc", totalMiscCost);

  QPieSlice *slice0 = series->slices().at(0);
  slice0->setLabelVisible();
  slice0->setPen(QPen(Qt::darkRed, 2));
  slice0->setBrush(Qt::red);
  QPieSlice *slice1 = series->slices().at(1);
  slice1->setLabelVisible();
  slice1->setPen(QPen(Qt::darkGreen, 2));
  slice1->setBrush(Qt::green);
  QPieSlice *slice2 = series->slices().at(2);
  slice2->setLabelVisible();
  slice2->setPen(QPen(Qt::darkBlue, 2));
  slice2->setBrush(Qt::blue);
  QPieSlice *slice3 = series->slices().at(3);
  slice3->setLabelVisible();
  slice3->setPen(QPen(Qt::darkCyan, 2));
  slice3->setBrush(Qt::cyan);
  QPieSlice *slice4 = series->slices().at(4);
  slice4->setLabelVisible();
  slice4->setPen(QPen(Qt::darkMagenta, 2));
  slice4->setBrush(Qt::magenta);
  QPieSlice *slice5 = series->slices().at(5);
  slice5->setLabelVisible();
  slice5->setPen(QPen(Qt::darkYellow, 2));
  slice5->setBrush(Qt::yellow);

  QChart *chart = new QChart();
  chart->addSeries(series);
  chart->setTitle("Annual Spending");
  chart->legend()->hide();

  QChartView *chartView = new QChartView(chart);
  chartView->setRenderHint(QPainter::Antialiasing);

  return chartView;
}

QChartView* Expenses::getMonthCostChart(int month) { // expenses pie chart by month
  QPieSeries *series = new QPieSeries();
  series->append("Food", foodCost[month]);
  series->append("Rent", rentCost[month]);
  series->append("Entertainment", entertainmentCost[month]);
  series->append("Tuition", tuitionCost[month]);
  series->append("Savings", savingsCost[month]);
  series->append("Misc", miscCost[month]);

  QPieSlice *slice0 = series->slices().at(0);
  slice0->setLabelVisible();
  slice0->setPen(QPen(Qt::darkRed, 2));
  slice0->setBrush(Qt::red);
  QPieSlice *slice1 = series->slices().at(1);
  slice1->setLabelVisible();
  slice1->setPen(QPen(Qt::darkGreen, 2));
  slice1->setBrush(Qt::green);
  QPieSlice *slice2 = series->slices().at(2);
  slice2->setLabelVisible();
  slice2->setPen(QPen(Qt::darkBlue, 2));
  slice2->setBrush(Qt::blue);
  QPieSlice *slice3 = series->slices().at(3);
  slice3->setLabelVisible();
  slice3->setPen(QPen(Qt::darkCyan, 2));
  slice3->setBrush(Qt::cyan);
  QPieSlice *slice4 = series->slices().at(4);
  slice4->setLabelVisible();
  slice4->setPen(QPen(Qt::darkMagenta, 2));
  slice4->setBrush(Qt::magenta);
  QPieSlice *slice5 = series->slices().at(5);
  slice5->setLabelVisible();
  slice5->setPen(QPen(Qt::darkYellow, 2));
  slice5->setBrush(Qt::yellow);

  QChart *chart = new QChart();
  chart->addSeries(series);
  chart->setTitle("Monthly Spending");
  chart->legend()->hide();

  QChartView *chartView = new QChartView(chart);
  chartView->setRenderHint(QPainter::Antialiasing);

  return chartView;
}

QChartView* Expenses::getExtraDeficitGraphYear() { // expenses bar chart by year
  setExtraDeficit();

  QBarSet *set0 = new QBarSet("Under budget spending");
  QBarSet *set1 = new QBarSet("Unused budget");
  QBarSet *set2 = new QBarSet("Over budget spending");

  if(totalAnnualCost > totalAnnualBudget){
      *set0 << totalFoodBudget << totalRentBudget << totalEntertainmentBudget << totalTuitionBudget << totalSavingsBudget << totalMiscBudget;
  }
  else{
      *set0 << totalFoodCost << totalRentCost << totalEntertainmentCost << totalTuitionCost << totalSavingsCost << totalMiscCost;
  }


  *set0 << totalFoodCost << totalRentCost << totalEntertainmentCost << totalTuitionCost << totalSavingsCost << totalMiscCost;
  *set1 << totalFoodExtra << totalRentExtra << totalEntertainmentExtra << totalTuitionExtra << totalSavingsExtra << totalMiscExtra;
  *set2 << totalFoodDeficit << totalRentDeficit << totalEntertainmentDeficit << totalTuitionDeficit << totalSavingsDeficit << totalMiscDeficit;

  set0->setBrush(Qt::gray);
  set1->setBrush(Qt::green);
  set2->setBrush(Qt::red);

  QStackedBarSeries *series = new QStackedBarSeries();
  series->append(set0);
  series->append(set1);
  series->append(set2);

  QChart *chart = new QChart();
  chart->addSeries(series);
  chart->setTitle("Deficit Spending by Year");
  chart->setAnimationOptions(QChart::SeriesAnimations);

  QStringList categories;
  categories << "Food" << "Rent" << "Entertainment" << "Tuition" << "Savings" << "Misc";
  QBarCategoryAxis *axis = new QBarCategoryAxis();
  axis->append(categories);
  chart->createDefaultAxes();
  chart->setAxisX(axis, series);

  chart->legend()->setVisible(true);
  chart->legend()->setAlignment(Qt::AlignBottom);

  QChartView *chartView = new QChartView(chart);
  chartView->setRenderHint(QPainter::Antialiasing);

  return chartView;
}

QChartView* Expenses::getExtraDeficitGraphMonth(int month) { // expenses bar chart by month
  setExtraDeficit();

  QBarSet *set0 = new QBarSet("Under budget spending");
  QBarSet *set1 = new QBarSet("Unused budget");
  QBarSet *set2 = new QBarSet("Over budget spending");

  if(foodCost[month] > foodBudget[month]){
      *set0 << foodBudget[month];
  }
  else{
      *set0 << foodCost[month];
  }

  if(rentCost[month] > rentBudget[month]){
      *set0 << rentBudget[month];
  }
  else{
      *set0 << rentCost[month];
  }

  if(entertainmentCost[month] > entertainmentBudget[month]){
      *set0 << entertainmentBudget[month];
  }
  else{
      *set0 << entertainmentCost[month];
  }

  if(tuitionCost[month] > tuitionBudget[month]){
      *set0 << tuitionBudget[month];
  }
  else{
      *set0 << tuitionCost[month];
  }

  if(savingsCost[month] > savingsBudget[month]){
      *set0 << savingsBudget[month];
  }
  else{
      *set0 << savingsCost[month];
  }

  if(miscCost[month] > miscBudget[month]){
      *set0 << miscBudget[month];
  }
  else{
      *set0 << miscCost[month];
  }


  *set1 << foodExtra[month] << rentExtra[month] << entertainmentExtra[month] << tuitionExtra[month] << savingsExtra[month] << miscExtra[month];
  *set2 << foodDeficit[month] << rentDeficit[month] << entertainmentDeficit[month] << tuitionDeficit[month] << savingsDeficit[month] << miscDeficit[month];

  set0->setBrush(Qt::gray);
  set1->setBrush(Qt::green);
  set2->setBrush(Qt::red);

  QStackedBarSeries *series = new QStackedBarSeries();
  series->append(set0);
  series->append(set1);
  series->append(set2);

  QChart *chart = new QChart();
  chart->addSeries(series);
  chart->setTitle("Deficit Spending in Month");
  chart->setAnimationOptions(QChart::SeriesAnimations);

  QStringList categories;
  categories << "Food" << "Rent" << "Entertainment" << "Tuition" << "Savings" << "Misc";
  QBarCategoryAxis *axis = new QBarCategoryAxis();
  axis->append(categories);
  chart->createDefaultAxes();
  chart->setAxisX(axis, series);

  chart->legend()->setVisible(true);
  chart->legend()->setAlignment(Qt::AlignBottom);

  QChartView *chartView = new QChartView(chart);
  chartView->setRenderHint(QPainter::Antialiasing);

  return chartView;
}

std::string Expenses::financialAdvice() {
    setExtraDeficit();
    std::string concatAdvice = "";

    if (totalFoodDeficit > 0) {
        concatAdvice += "It is recommended to spend no more than 15% on Food.\n";
    }

    if (totalRentDeficit > 0) {
        concatAdvice += "Remember, put 30% of your income towards Rent.\n";
    }

    if (totalEntertainmentDeficit > 0) {
        concatAdvice += "Prioritize your spending! Your Entertainment costs have exceeded 10%.\n";
    }

    if (totalTuitionDeficit > 0) {
        concatAdvice += "Only 20% of your income should be spent on Tuition.\n";
    }

    if (totalSavingsDeficit > 0) {
        concatAdvice += "Your Savings are low, make sure to save at least 5% of your income!\n";
    }

    if (totalMiscDeficit > 0) {
        concatAdvice += "Miscellaneous costs like clothing or transportation shouldn't exceed 20% of your income. Shop smart!\n";
    }

    if (totalAnnualExtra > 0) {
        concatAdvice += "You have some extra money! Add it to Savings!\n";
    }

    if ((totalFoodBudget / totalAnnualBudget) > .17) {
        concatAdvice += "Too much of your budget is in food.\n";
    }

    if ((totalRentBudget / totalAnnualBudget) > .33) {
        concatAdvice += "Too much of your budget is in rent.\n";
    }

    if ((totalEntertainmentBudget / totalAnnualBudget) > .12) {
        concatAdvice += "Too much of your budget is in entertainment.\n";
    }

    if ((totalTuitionBudget / totalAnnualBudget) > .22) {
        concatAdvice += "Too much of your budget is in tuition.\n";
    }

    if ((totalMiscBudget / totalAnnualBudget) > .22) {
        concatAdvice += "Too much of your budget is in miscellaneous expenses.\n";
    }


    if(concatAdvice == ""){
        concatAdvice += "You're doing a good job! Keep it up.";
    }

    return concatAdvice;

    //for overall advice
}

std::string Expenses::financialAdvice(int month) {
    setExtraDeficit();
    std::string concatAdvice = "";
    std::string monthString;

    switch(month) {
        case 0:
            monthString = "January";
            break;
        case 1:
            monthString = "February";
            break;
        case 2:
            monthString = "March";
            break;
        case 3:
            monthString = "April";
            break;
        case 4:
            monthString = "May";
            break;
        case 5:
            monthString = "June";
            break;
        case 6:
            monthString = "July";
            break;
        case 7:
            monthString = "August";
            break;
        case 8:
            monthString = "September";
            break;
        case 9:
            monthString = "October";
            break;
        case 10:
            monthString = "November";
            break;
        case 11:
            monthString = "December";
            break;
    }


    if (foodCost[month]/totalBudget[month] > .17) {
        concatAdvice += "It is recommended to spend no more than 15% on Food in ";
        concatAdvice += monthString;
        concatAdvice += ".\n";
    }

    if (rentCost[month]/totalBudget[month] < .28 || rentCost[month]/totalBudget[month] > .32) {
        concatAdvice += "Remember, put 30% of your income towards Rent in ";
        concatAdvice += monthString;
        concatAdvice += ".\n";
    }

    if (entertainmentCost[month]/totalBudget[month] > .12) {
        concatAdvice += "Prioritize your spending! Your Entertainment costs have exceeded 10% in ";
        concatAdvice += monthString;
        concatAdvice += ".\n";
    }

    if (tuitionCost[month]/totalBudget[month] < .18 || tuitionCost[month]/totalBudget[month] > .24) {
        concatAdvice += "Make sure that 20% of your income to Tuition this month to avoid student loan debt!\n";
    }

    if ((savingsCost[month] / totalBudget[month]) < .04 ) { // is this correct?
        concatAdvice += "Your Savings are low, make sure to save at least 5% of your income this month!\n";
    }

    if (miscCost[month]/totalBudget[month] > .22) {
        concatAdvice += "Miscellaneous costs like clothing or transportation shouldn't exceed 20% of your income!\n";
    }

    if (savingsExtra[month] > 0) {
        concatAdvice += "You have some extra money! Add it to Savings!\n";
    }

    if ((foodBudget[month] / totalBudget[month]) > .17) {
        concatAdvice += "Too much of your budget is in food this month.\n";
    }

    if ((rentBudget[month] / totalBudget[month]) > .33) {
        concatAdvice += "Too much of your budget is in rent this month.\n";
    }

    if ((entertainmentBudget[month] / totalBudget[month]) > .12) {
        concatAdvice += "Too much of your budget is in entertainment this month.\n";
    }

    if ((tuitionBudget[month] / totalBudget[month]) > .22) {
        concatAdvice += "Too much of your budget is in tuition this month.\n";
    }

    if ((miscBudget[month] / totalBudget[month]) > .22) {
        concatAdvice += "Too much of your budget is in miscellaneous expenses this month.\n";
    }

    if(concatAdvice == ""){
        concatAdvice += "You're doing a good job! Keep it up.";
    }

    return concatAdvice;

    //Specific to each month
}
