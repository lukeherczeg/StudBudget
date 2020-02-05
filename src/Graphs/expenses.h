#ifndef EXPENSES_H
#define EXPENSES_H

#include <QMainWindow>
#include <string>

#include <QtCharts>

using namespace QtCharts;

class Expenses {

public:
    Expenses();
    void setFoodCost(double food, int month);
    double getFoodCost(int month);
    void setFoodBudget(double food, int month);
    double getFoodBudget(int month);
    void setRentCost(double rent, int month);
    double getRentCost(int month);
    void setRentBudget(double rent, int month);
    double getRentBudget(int month);
    void setEntertainmentCost(double entertainment, int month);
    double getEntertainmentCost(int month);
    void setEntertainmentBudget(double entertainment, int month);
    double getEntertainmentBudget(int month);
    void setTuitionCost(double tuition, int month);
    double getTuitionCost(int month);
    void setTuitionBudget(double tuition, int month);
    double getTuitionBudget(int month);
    void setSavingsCost(double savings, int month);
    double getSavingsCost(int month);
    void setSavingsBudget(double savings, int month);
    double getSavingsBudget(int month);
    void setMiscCost(double misc, int month);
    double getMiscCost(int month);
    void setMiscBudget(double misc, int month);
    double getMiscBudget(int month);
    void setExtraDeficit();
    void projectBudget();
    QChartView* getRentGraph();
    QChartView* getEntertainmentGraph();
    QChartView* getTuitionGraph();
    QChartView* getSavingsGraph();
    QChartView* getMiscGraph();
    QChartView* getFoodGraph();
    QChartView* getAnnualCostChart();
    QChartView* getMonthCostChart(int month);
    QChartView* getExtraDeficitGraphYear();
    QChartView* getExtraDeficitGraphMonth(int month);
    std::string financialAdvice();
    std::string financialAdvice(int month);

private:
    double foodCost[12];
    double foodBudget[12];
    double foodExtra[12];
    double foodDeficit[12];
    double rentCost[12];
    double rentBudget[12];
    double rentExtra[12];
    double rentDeficit[12];
    double entertainmentCost[12];
    double entertainmentBudget[12];
    double entertainmentExtra[12];
    double entertainmentDeficit[12];
    double tuitionCost[12];
    double tuitionBudget[12];
    double tuitionExtra[12];
    double tuitionDeficit[12];
    double savingsCost[12];
    double savingsBudget[12];
    double savingsExtra[12];
    double savingsDeficit[12];
    double miscCost[12];
    double miscBudget[12];
    double miscExtra[12];
    double miscDeficit[12];
    double totalCost[12];
    double totalBudget[12];
    double totalExtra[12];
    double totalDeficit[12];
    double totalFoodCost;
    double totalFoodBudget;
    double totalFoodExtra;
    double totalFoodDeficit;
    double totalRentCost;
    double totalRentBudget;
    double totalRentExtra;
    double totalRentDeficit;
    double totalEntertainmentCost;
    double totalEntertainmentBudget;
    double totalEntertainmentExtra;
    double totalEntertainmentDeficit;
    double totalTuitionCost;
    double totalTuitionBudget;
    double totalTuitionExtra;
    double totalTuitionDeficit;
    double totalSavingsCost;
    double totalSavingsBudget;
    double totalSavingsExtra;
    double totalSavingsDeficit;
    double totalMiscCost;
    double totalMiscBudget;
    double totalMiscExtra;
    double totalMiscDeficit;
    double totalAnnualCost;
    double totalAnnualBudget;
    double totalAnnualDeficit;
    double totalAnnualExtra;
};

#endif // EXPENSES_H
