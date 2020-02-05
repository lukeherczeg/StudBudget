#include "appdialog.h"
#include "ui_appdialog.h"
#include <QMessageBox>
#include <QtCharts>
#include <QWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>

using namespace QtCharts;

AppDialog::AppDialog(User* &user, QWidget *parent) :
    QDialog(parent),
    _user(user),
    ui(new Ui::AppDialog)
{
    ui->setupUi(this);

    ui->comboBox_month->insertItem(0, "January");
    ui->comboBox_month->insertItem(1, "February");
    ui->comboBox_month->insertItem(2, "March");
    ui->comboBox_month->insertItem(3, "April");
    ui->comboBox_month->insertItem(4, "May");
    ui->comboBox_month->insertItem(5, "June");
    ui->comboBox_month->insertItem(6, "July");
    ui->comboBox_month->insertItem(7, "August");
    ui->comboBox_month->insertItem(8, "September");
    ui->comboBox_month->insertItem(9, "October");
    ui->comboBox_month->insertItem(10, "November");
    ui->comboBox_month->insertItem(11,"December");

    string username = user->getUsername();
    QString userQStr = QString::fromUtf8((username + '!').c_str()); // To make the system greet the user
    ui->label_getUsername->setText(userQStr);

    user->getAccount()->setUsername(username);
    user->getAccount()->writeData();

    this->updateAll();
    Expenses *expenses = user->getAccount()->getExpenseObj();

    QChartView *foodChart = expenses->getFoodGraph();
    QChartView *rentChart = expenses->getRentGraph();
    QChartView *entertainmentChart = expenses->getEntertainmentGraph();
    QChartView *savingsChart = expenses->getSavingsGraph();
    QChartView *tuitionChart = expenses->getTuitionGraph();
    QChartView *miscChart = expenses->getMiscGraph();
    QChartView *stackedChart = expenses->getExtraDeficitGraphYear();
    QChartView *yearPieChart = expenses->getAnnualCostChart();

    monthGridLayout = new QGridLayout(ui->groupBox_monthlyGraphs);
    pieGridLayout = new QGridLayout(ui->groupBox_monthlyGraphs_2);

    yearGridLayout = new QGridLayout(ui->groupBox_yearlyGraphs);
    gridLayout = new QGridLayout(ui->groupBox_graphs);

    ui->groupBox_graphs->setLayout(gridLayout);
    ui->groupBox_yearlyGraphs->setLayout(yearGridLayout);
    ui->groupBox_monthlyGraphs->setLayout(monthGridLayout);
    ui->groupBox_monthlyGraphs_2->setLayout(pieGridLayout);

    QChartView *monthStackedChart = expenses->getExtraDeficitGraphMonth(this->month);
    QChartView *pieChart = expenses->getMonthCostChart(this->month);

    monthGridLayout->addWidget(monthStackedChart, 0, 0, 1, 1);
    pieGridLayout->addWidget(pieChart, 0, 0, 1, 1);

    gridLayout->addWidget(foodChart, 0, 0, 1, 1);
    gridLayout->addWidget(rentChart, 0, 1, 1, 1);
    gridLayout->addWidget(entertainmentChart, 1, 1, 1, 1);
    gridLayout->addWidget(savingsChart, 1, 0, 1, 1);
    gridLayout->addWidget(tuitionChart, 0, 2, 1, 1);
    gridLayout->addWidget(miscChart, 1, 2, 1, 1);
    yearGridLayout->addWidget(stackedChart, 0, 0, 1, 1);
    yearGridLayout->addWidget(yearPieChart, 0, 1, 1, 1);


    std::string finAdvice = this->_user->getAccount()->getFinancialAdvice(this->month);
    QString finAdviceQStr = QString::fromUtf8(finAdvice.c_str());

    ui->label_financialAdvice->clear();
    ui->label_financialAdvice->setText(finAdviceQStr);
    ui->label_financialAdvice->show();

    this->updateBalance();
    this->updateBudget();
    user->getAccount()->setProjectedBudget();

    this->updateMonthlyAdvice();
}

AppDialog::~AppDialog()
{
    delete ui;
}

void AppDialog::on_pushButton_signOut_clicked()
{
    hide();
    this->parentWidget()->parentWidget()->show();
    delete this;
}

void AppDialog::updateAll(){
    for (int i = 0; i < 12; i++) {
        this->month = i;
        updateBudget();
        updateBalance();
    }
    this->month = 0;
}

void AppDialog::updateMonthlyAdvice(){
    std::string finAdvice = this->_user->getAccount()->getFinancialAdvice(this->month);
    QString finAdviceQStr = QString::fromUtf8(finAdvice.c_str());

    ui->label_financialAdvice->clear();
    ui->label_financialAdvice->setText(finAdviceQStr);
    ui->label_financialAdvice->show();
}


void AppDialog::updateBudget(){
    this->_user->getAccount()->setMonth(this->month);

    this->_user->getAccount()->setExpenseType("FOODBUDGET");
    double foodBudget = this->_user->getAccount()->getExpense();
    ui->label_foodBudget_3->setText(QString::number(foodBudget));
    ui->label_foodBudget_3->repaint();

    this->_user->getAccount()->setExpenseType("RENTBUDGET");
    double rentBudget = this->_user->getAccount()->getExpense();
    ui->label_rentBudget_3->setText(QString::number(rentBudget));
    ui->label_rentBudget_3->repaint();

    this->_user->getAccount()->setExpenseType("ENTERTAINMENTBUDGET");
    double entertainmentBudget = this->_user->getAccount()->getExpense();
    ui->label_entertainmentBudget_3->setText(QString::number(entertainmentBudget));
    ui->label_entertainmentBudget_3->repaint();

    this->_user->getAccount()->setExpenseType("TUITIONBUDGET");
    double tuitionBudget = this->_user->getAccount()->getExpense();
    ui->label_tuitionBudget_3->setText(QString::number(tuitionBudget));
    ui->label_tuitionBudget_3->repaint();

    this->_user->getAccount()->setExpenseType("SAVINGSBUDGET");
    double savingsBudget = this->_user->getAccount()->getExpense();
    ui->label_savingsBudget_3->setText(QString::number(savingsBudget));
    ui->label_savingsBudget_3->repaint();

    this->_user->getAccount()->setExpenseType("MISCBUDGET");
    double miscBudget = this->_user->getAccount()->getExpense();
    ui->label_miscBudget_3->setText(QString::number(miscBudget));
    ui->label_miscBudget_3->repaint();
}

void AppDialog::updateBalance(){
    this->_user->getAccount()->setMonth(this->month);

    this->_user->getAccount()->setExpenseType("FOOD");
    double foodCost = this->_user->getAccount()->getExpense();
    ui->label_foodCost->setText(QString::number(foodCost));
    ui->label_foodCost->repaint();

    this->_user->getAccount()->setExpenseType("RENT");
    double rentCost = this->_user->getAccount()->getExpense();
    ui->label_rentCost->setText(QString::number(rentCost));
    ui->label_rentCost->repaint();

    this->_user->getAccount()->setExpenseType("ENTERTAINMENT");
    double entertainmentCost = this->_user->getAccount()->getExpense();
    ui->label_entertainmentCost->setText(QString::number(entertainmentCost));
    ui->label_entertainmentCost->repaint();

    this->_user->getAccount()->setExpenseType("TUITION");
    double tuitionCost = this->_user->getAccount()->getExpense();
    ui->label_tuitionCost->setText(QString::number(tuitionCost));
    ui->label_tuitionCost->repaint();

    this->_user->getAccount()->setExpenseType("SAVINGS");
    double savingsCost = this->_user->getAccount()->getExpense();
    ui->label_savingsCost->setText(QString::number(savingsCost));
    ui->label_savingsCost->repaint();

    this->_user->getAccount()->setExpenseType("MISC");
    double miscCost = this->_user->getAccount()->getExpense();
    ui->label_miscCost->setText(QString::number(miscCost));
    ui->label_miscCost->repaint();
}

void AppDialog::on_comboBox_month_activated(int index)
{
    this->month = index;
    this->_user->getAccount()->setMonth(this->month);
    Expenses *expenses = this->_user->getAccount()->getExpenseObj();

    ui->lineEdit_foodCostChanged->clear();
    ui->lineEdit_rentCostChanged->clear();
    ui->lineEdit_entertainmentCostChanged->clear();
    ui->lineEdit_tuitionCostChanged->clear();
    ui->lineEdit_savingsCostChanged->clear();
    ui->lineEdit_miscCostChanged->clear();
    ui->lineEdit_foodBudgetChanged_3->clear();
    ui->lineEdit_rentBudgetChanged_3->clear();
    ui->lineEdit_entertainmentBudgetChanged_3->clear();
    ui->lineEdit_tuitionBudgetChanged_3->clear();
    ui->lineEdit_savingsBudgetChanged_3->clear();
    ui->lineEdit_miscBudgetChanged_3->clear();

    this->updateBalance();
    this->updateBudget();
    this->updateMonthlyAdvice();

    QChartView *monthStackedChart = expenses->getExtraDeficitGraphMonth(this->month);
    QChartView *pieChart = expenses->getMonthCostChart(this->month);

    monthGridLayout->addWidget(monthStackedChart, 0, 0, 1, 1);
    pieGridLayout->addWidget(pieChart, 0, 0, 1, 1);
}

void AppDialog::on_pushButton_depositFoodC_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString depositAmt = ui->lineEdit_foodCostChanged->text();
    double depositAmtDouble = depositAmt.toDouble();
    this->_user->getAccount()->setExpenseType("FOOD");
    this->_user->getAccount()->deposit(depositAmtDouble);

    this->updateBalance();
    this->updateMonthlyAdvice();
}

void AppDialog::on_pushButton_withdrawFoodC_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString withdrawAmt = ui->lineEdit_foodCostChanged->text();
    double withdrawAmtDouble = withdrawAmt.toDouble();
    this->_user->getAccount()->setExpenseType("FOOD");

    if (this->_user->getAccount()->getExpense() - withdrawAmtDouble < 0) {
        QMessageBox::warning(this, "Below Zero", "Withdrawing this amount will result in negative spending.\n If you have obtained more money, add it to your budget. Please try again.");
    }
    else {
        this->_user->getAccount()->withdraw(withdrawAmtDouble);
    }
    this->updateBalance();
    this->updateMonthlyAdvice();
}

void AppDialog::on_pushButton_depositRentC_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString depositAmt = ui->lineEdit_rentCostChanged->text();
    double depositAmtDouble = depositAmt.toDouble();
    this->_user->getAccount()->setExpenseType("RENT");
    this->_user->getAccount()->deposit(depositAmtDouble);

    this->updateBalance();
    this->updateMonthlyAdvice();
}

void AppDialog::on_pushButton_withdrawRentC_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString withdrawAmt = ui->lineEdit_rentCostChanged->text();
    double withdrawAmtDouble = withdrawAmt.toDouble();
    this->_user->getAccount()->setExpenseType("RENT");
    if (this->_user->getAccount()->getExpense() - withdrawAmtDouble < 0) {
        QMessageBox::warning(this, "Below Zero", "Withdrawing this amount will result in negative spending.\n If you have obtained more money, add it to your budget. Please try again.");
    }
    else {
        this->_user->getAccount()->withdraw(withdrawAmtDouble);
    }
    this->updateBalance();
    this->updateMonthlyAdvice();
}

void AppDialog::on_pushButton_depositEntertainmentC_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString depositAmt = ui->lineEdit_entertainmentCostChanged->text();
    double depositAmtDouble = depositAmt.toDouble();
    this->_user->getAccount()->setExpenseType("ENTERTAINMENT");
    this->_user->getAccount()->deposit(depositAmtDouble);

    this->updateBalance();
    this->updateMonthlyAdvice();
}

void AppDialog::on_pushButton_withdrawEntertainmentC_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString withdrawAmt = ui->lineEdit_entertainmentCostChanged->text();
    double withdrawAmtDouble = withdrawAmt.toDouble();
    this->_user->getAccount()->setExpenseType("ENTERTAINMENT");
    if (this->_user->getAccount()->getExpense() - withdrawAmtDouble < 0) {
        QMessageBox::warning(this, "Below Zero", "Withdrawing this amount will result in negative spending.\n If you have obtained more money, add it to your budget. Please try again.");
    }
    else {
        this->_user->getAccount()->withdraw(withdrawAmtDouble);
    }
    this->updateBalance();
    this->updateMonthlyAdvice();
}

void AppDialog::on_pushButton_depositTuitionC_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString depositAmt = ui->lineEdit_tuitionCostChanged->text();
    double depositAmtDouble = depositAmt.toDouble();
    this->_user->getAccount()->setExpenseType("TUITION");
    this->_user->getAccount()->deposit(depositAmtDouble);

    this->updateBalance();
    this->updateMonthlyAdvice();
}

void AppDialog::on_pushButton_withdrawTuitionC_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString withdrawAmt = ui->lineEdit_tuitionCostChanged->text();
    double withdrawAmtDouble = withdrawAmt.toDouble();
    this->_user->getAccount()->setExpenseType("TUITION");
    if (this->_user->getAccount()->getExpense() - withdrawAmtDouble < 0) {
        QMessageBox::warning(this, "Below Zero", "Withdrawing this amount will result in negative spending.\n If you have obtained more money, add it to your budget. Please try again.");
    }
    else {
        this->_user->getAccount()->withdraw(withdrawAmtDouble);
    }
    this->updateBalance();
    this->updateMonthlyAdvice();
}

void AppDialog::on_pushButton_depositSavingsC_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString depositAmt = ui->lineEdit_savingsCostChanged->text();
    double depositAmtDouble = depositAmt.toDouble();
    this->_user->getAccount()->setExpenseType("SAVINGS");
    this->_user->getAccount()->deposit(depositAmtDouble);

    this->updateBalance();
    this->updateMonthlyAdvice();
}

void AppDialog::on_pushButton_withdrawSavingsC_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString withdrawAmt = ui->lineEdit_savingsCostChanged->text();
    double withdrawAmtDouble = withdrawAmt.toDouble();
    this->_user->getAccount()->setExpenseType("SAVINGS");
    if (this->_user->getAccount()->getExpense() - withdrawAmtDouble < 0) {
        QMessageBox::warning(this, "Below Zero", "Withdrawing this amount will result in negative spending.\n If you have obtained more money, add it to your budget. Please try again.");
    }
    else {
        this->_user->getAccount()->withdraw(withdrawAmtDouble);
    }
    this->updateBalance();
    this->updateMonthlyAdvice();
}

void AppDialog::on_pushButton_depositMiscC_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString depositAmt = ui->lineEdit_miscCostChanged->text();
    double depositAmtDouble = depositAmt.toDouble();
    this->_user->getAccount()->setExpenseType("MISC");
    this->_user->getAccount()->deposit(depositAmtDouble);

    this->updateBalance();
    this->updateMonthlyAdvice();
}

void AppDialog::on_pushButton_withdrawMiscC_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString withdrawAmt = ui->lineEdit_miscCostChanged->text();
    double withdrawAmtDouble = withdrawAmt.toDouble();
    this->_user->getAccount()->setExpenseType("MISC");
    if (this->_user->getAccount()->getExpense() - withdrawAmtDouble < 0) {
        QMessageBox::warning(this, "Below Zero", "Withdrawing this amount will result in negative spending.\n If you have obtained more money, add it to your budget. Please try again.");
    }
    else {
        this->_user->getAccount()->withdraw(withdrawAmtDouble);
    }
    this->updateBalance();
    this->updateMonthlyAdvice();
}

void AppDialog::on_pushButton_depositFoodB_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString depositAmt = ui->lineEdit_foodBudgetChanged_3->text();
    double depositAmtDouble = depositAmt.toDouble();
    this->_user->getAccount()->setExpenseType("FOODBUDGET");
    this->_user->getAccount()->deposit(depositAmtDouble);

    this->updateBudget();
    this->updateMonthlyAdvice();
}

void AppDialog::on_pushButton_withdrawFoodB_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString withdrawAmt = ui->lineEdit_foodBudgetChanged_3->text();
    double withdrawAmtDouble = withdrawAmt.toDouble();
    this->_user->getAccount()->setExpenseType("FOODBUDGET");

    if (this->_user->getAccount()->getExpense() - withdrawAmtDouble < 0) {
        QMessageBox::warning(this, "Below Zero", "Withdrawing this amount will result in a negative budget. Please try again.");
    }
    else {
        this->_user->getAccount()->withdraw(withdrawAmtDouble);
    }
    this->updateBudget();
    this->updateMonthlyAdvice();
}

void AppDialog::on_pushButton_depositRentB_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString depositAmt = ui->lineEdit_rentBudgetChanged_3->text();
    double depositAmtDouble = depositAmt.toDouble();
    this->_user->getAccount()->setExpenseType("RENTBUDGET");
    this->_user->getAccount()->deposit(depositAmtDouble);

    this->updateBudget();
    this->updateMonthlyAdvice();
}

void AppDialog::on_pushButton_withdrawRentB_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString withdrawAmt = ui->lineEdit_rentBudgetChanged_3->text();
    double withdrawAmtDouble = withdrawAmt.toDouble();
    this->_user->getAccount()->setExpenseType("RENTBUDGET");

    if (this->_user->getAccount()->getExpense() - withdrawAmtDouble < 0) {
        QMessageBox::warning(this, "Below Zero", "Withdrawing this amount will result in a negative budget. Please try again.");
    }
    else {
        this->_user->getAccount()->withdraw(withdrawAmtDouble);
    }
    this->updateBudget();
    this->updateMonthlyAdvice();
}

void AppDialog::on_pushButton_depositEntertainmentB_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString depositAmt = ui->lineEdit_entertainmentBudgetChanged_3->text();
    double depositAmtDouble = depositAmt.toDouble();
    this->_user->getAccount()->setExpenseType("ENTERTAINMENTBUDGET");
    this->_user->getAccount()->deposit(depositAmtDouble);

    this->updateBudget();
    this->updateMonthlyAdvice();
}

void AppDialog::on_pushButton_withdrawEntertainmentB_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString withdrawAmt = ui->lineEdit_entertainmentBudgetChanged_3->text();
    double withdrawAmtDouble = withdrawAmt.toDouble();
    this->_user->getAccount()->setExpenseType("ENTERTAINMENTBUDGET");

    if (this->_user->getAccount()->getExpense() - withdrawAmtDouble < 0) {
        QMessageBox::warning(this, "Below Zero", "Withdrawing this amount will result in a negative budget. Please try again.");
    }
    else {
        this->_user->getAccount()->withdraw(withdrawAmtDouble);
    }
    this->updateBudget();
    this->updateMonthlyAdvice();
}

void AppDialog::on_pushButton_depositTuitionB_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString depositAmt = ui->lineEdit_tuitionBudgetChanged_3->text();
    double depositAmtDouble = depositAmt.toDouble();
    this->_user->getAccount()->setExpenseType("TUITIONBUDGET");
    this->_user->getAccount()->deposit(depositAmtDouble);

    this->updateBudget();
    this->updateMonthlyAdvice();
}

void AppDialog::on_pushButton_withdrawTuitionB_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString withdrawAmt = ui->lineEdit_tuitionBudgetChanged_3->text();
    double withdrawAmtDouble = withdrawAmt.toDouble();
    this->_user->getAccount()->setExpenseType("TUITIONBUDGET");


    if (this->_user->getAccount()->getExpense() - withdrawAmtDouble < 0) {
        QMessageBox::warning(this, "Below Zero", "Withdrawing this amount will result in a negative budget. Please try again.");
    }
    else {
        this->_user->getAccount()->withdraw(withdrawAmtDouble);
    }
    this->updateBudget();
    this->updateMonthlyAdvice();
}

void AppDialog::on_pushButton_depositSavingsB_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString depositAmt = ui->lineEdit_savingsBudgetChanged_3->text();
    double depositAmtDouble = depositAmt.toDouble();
    this->_user->getAccount()->setExpenseType("SAVINGSBUDGET");
    this->_user->getAccount()->deposit(depositAmtDouble);

    this->updateBudget();
    this->updateMonthlyAdvice();
}

void AppDialog::on_pushButton_withdrawSavingsB_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString withdrawAmt = ui->lineEdit_savingsBudgetChanged_3->text();
    double withdrawAmtDouble = withdrawAmt.toDouble();
    this->_user->getAccount()->setExpenseType("SAVINGSBUDGET");


    if (this->_user->getAccount()->getExpense() - withdrawAmtDouble < 0) {
        QMessageBox::warning(this, "Below Zero", "Withdrawing this amount will result in a negative budget. Please try again.");
    }
    else {
        this->_user->getAccount()->withdraw(withdrawAmtDouble);
    }
    this->updateBudget();
    this->updateMonthlyAdvice();
}

void AppDialog::on_pushButton_depositMiscB_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString depositAmt = ui->lineEdit_miscBudgetChanged_3->text();
    double depositAmtDouble = depositAmt.toDouble();
    this->_user->getAccount()->setExpenseType("MISCBUDGET");
    this->_user->getAccount()->deposit(depositAmtDouble);

    this->updateBudget();
    this->updateMonthlyAdvice();
}

void AppDialog::on_pushButton_withdrawMiscB_clicked()
{
    this->_user->getAccount()->setMonth(this->month);

    QString withdrawAmt = ui->lineEdit_miscBudgetChanged_3->text();
    double withdrawAmtDouble = withdrawAmt.toDouble();
    this->_user->getAccount()->setExpenseType("MISCBUDGET");


    if (this->_user->getAccount()->getExpense() - withdrawAmtDouble < 0) {
        QMessageBox::warning(this, "Below Zero", "Withdrawing this amount will result in a negative budget. Please try again.");
    }
    else {
        this->_user->getAccount()->withdraw(withdrawAmtDouble);
    }
    this->updateBudget();
    this->updateMonthlyAdvice();
}

void AppDialog::on_pushButton_makeBudget_clicked()
{
    QString totalAmt = ui->lineEdit_makeBudget->text();
    double totalAmtDouble = totalAmt.toDouble(); // Take in a total budget
    totalAmtDouble /= 12; // Split it into 12 months

    double foodAmt          = .15 * totalAmtDouble; // Make the proper percentages
    double rentAmt          = .30 * totalAmtDouble;
    double entertainmentAmt = .10 * totalAmtDouble;
    double tuitionAmt       = .20 * totalAmtDouble;
    double savingsAmt       = .05 * totalAmtDouble;
    double miscAmt          = .20 * totalAmtDouble;

    for(int i = 0; i < 12; i++){
        this->_user->getAccount()->setMonth(i);

        this->_user->getAccount()->setExpenseType("FOODBUDGET");
        this->_user->getAccount()->changeExpenseField(0);
        this->_user->getAccount()->setExpenseType("RENTBUDGET");
        this->_user->getAccount()->changeExpenseField(0);
        this->_user->getAccount()->setExpenseType("ENTERTAINMENTBUDGET");
        this->_user->getAccount()->changeExpenseField(0);
        this->_user->getAccount()->setExpenseType("TUITIONBUDGET");
        this->_user->getAccount()->changeExpenseField(0);
        this->_user->getAccount()->setExpenseType("SAVINGSBUDGET");
        this->_user->getAccount()->changeExpenseField(0);
        this->_user->getAccount()->setExpenseType("MISCBUDGET");
        this->_user->getAccount()->changeExpenseField(0);
    }

    for(int i = 0; i < 12; i++){
        this->_user->getAccount()->setMonth(i);

        this->_user->getAccount()->setExpenseType("FOODBUDGET");
        this->_user->getAccount()->deposit(foodAmt);
        this->_user->getAccount()->setExpenseType("RENTBUDGET");
        this->_user->getAccount()->deposit(rentAmt);
        this->_user->getAccount()->setExpenseType("ENTERTAINMENTBUDGET");
        this->_user->getAccount()->deposit(entertainmentAmt);
        this->_user->getAccount()->setExpenseType("TUITIONBUDGET");
        this->_user->getAccount()->deposit(tuitionAmt);
        this->_user->getAccount()->setExpenseType("SAVINGSBUDGET");
        this->_user->getAccount()->deposit(savingsAmt);
        this->_user->getAccount()->setExpenseType("MISCBUDGET");
        this->_user->getAccount()->deposit(miscAmt);
    }
    this->_user->getAccount()->setProjectedBudget();
    this->updateBalance();
    this->updateBudget();
    this->updateMonthlyAdvice();
}

void AppDialog::on_pushButton_clearBudget_clicked()
{
    for(int i = 0; i < 12; i++){
        this->_user->getAccount()->setMonth(i);

        this->_user->getAccount()->setExpenseType("FOODBUDGET");
        this->_user->getAccount()->changeExpenseField(0);
        this->_user->getAccount()->setExpenseType("RENTBUDGET");
        this->_user->getAccount()->changeExpenseField(0);
        this->_user->getAccount()->setExpenseType("ENTERTAINMENTBUDGET");
        this->_user->getAccount()->changeExpenseField(0);
        this->_user->getAccount()->setExpenseType("TUITIONBUDGET");
        this->_user->getAccount()->changeExpenseField(0);
        this->_user->getAccount()->setExpenseType("SAVINGSBUDGET");
        this->_user->getAccount()->changeExpenseField(0);
        this->_user->getAccount()->setExpenseType("MISCBUDGET");
        this->_user->getAccount()->changeExpenseField(0);
    }
    this->_user->getAccount()->setProjectedBudget();
    this->updateBalance();
    this->updateBudget();
    this->updateMonthlyAdvice();
}

void AppDialog::on_pushButton_clearBalance_clicked()
{
    for(int i = 0; i < 12; i++){
        this->_user->getAccount()->setMonth(i);

        this->_user->getAccount()->setExpenseType("FOOD");
        this->_user->getAccount()->changeExpenseField(0);
        this->_user->getAccount()->setExpenseType("RENT");
        this->_user->getAccount()->changeExpenseField(0);
        this->_user->getAccount()->setExpenseType("ENTERTAINMENT");
        this->_user->getAccount()->changeExpenseField(0);
        this->_user->getAccount()->setExpenseType("TUITION");
        this->_user->getAccount()->changeExpenseField(0);
        this->_user->getAccount()->setExpenseType("SAVINGS");
        this->_user->getAccount()->changeExpenseField(0);
        this->_user->getAccount()->setExpenseType("MISC");
        this->_user->getAccount()->changeExpenseField(0);
    }
    this->updateBalance();
    this->updateBudget();
    this->updateMonthlyAdvice();
}

void AppDialog::on_pushButton_makeBalance_clicked()
{
    double value;
    for(int i = 0; i < 12; i++){
        this->_user->getAccount()->setMonth(i);

        this->_user->getAccount()->setExpenseType("FOODBUDGET");
        value = this->_user->getAccount()->getExpense();
        this->_user->getAccount()->setExpenseType("FOOD");
        this->_user->getAccount()->changeExpenseField(value);

        this->_user->getAccount()->setExpenseType("RENTBUDGET");
        value = this->_user->getAccount()->getExpense();
        this->_user->getAccount()->setExpenseType("RENT");
        this->_user->getAccount()->changeExpenseField(value);

        this->_user->getAccount()->setExpenseType("ENTERTAINMENTBUDGET");
        value = this->_user->getAccount()->getExpense();
        this->_user->getAccount()->setExpenseType("ENTERTAINMENT");
        this->_user->getAccount()->changeExpenseField(value);

        this->_user->getAccount()->setExpenseType("TUITIONBUDGET");
        value = this->_user->getAccount()->getExpense();
        this->_user->getAccount()->setExpenseType("TUITION");
        this->_user->getAccount()->changeExpenseField(value);

        this->_user->getAccount()->setExpenseType("SAVINGSBUDGET");
        value = this->_user->getAccount()->getExpense();
        this->_user->getAccount()->setExpenseType("SAVINGS");
        this->_user->getAccount()->changeExpenseField(value);

        this->_user->getAccount()->setExpenseType("MISCBUDGET");
        value = this->_user->getAccount()->getExpense();
        this->_user->getAccount()->setExpenseType("MISC");
        this->_user->getAccount()->changeExpenseField(value);
    }
    this->updateBalance();
    this->updateBudget();
    this->updateMonthlyAdvice();
}

void AppDialog::on_tabWidget_currentChanged(int index)
{
    if (index == 1) {
        Expenses *expenses = this->_user->getAccount()->getExpenseObj();

        QChartView *foodChart = expenses->getFoodGraph();
        QChartView *rentChart = expenses->getRentGraph();
        QChartView *entertainmentChart = expenses->getEntertainmentGraph();
        QChartView *savingsChart = expenses->getSavingsGraph();
        QChartView *tuitionChart = expenses->getTuitionGraph();
        QChartView *miscChart = expenses->getMiscGraph();
        QChartView *stackedChart = expenses->getExtraDeficitGraphYear();
        QChartView *yearPieChart = expenses->getAnnualCostChart();

        gridLayout->addWidget(foodChart, 0, 0, 1, 1);
        gridLayout->addWidget(rentChart, 0, 1, 1, 1);
        gridLayout->addWidget(entertainmentChart, 1, 1, 1, 1);
        gridLayout->addWidget(savingsChart, 1, 0, 1, 1);
        gridLayout->addWidget(tuitionChart, 0, 2, 1, 1);
        gridLayout->addWidget(miscChart, 1, 2, 1, 1);
        yearGridLayout->addWidget(stackedChart, 0, 0, 1, 1);
        yearGridLayout->addWidget(yearPieChart, 0, 1, 1, 1);

        std::string yearlyFinAdvice = this->_user->getAccount()->getFinancialAdvice(-1); // -1 is to make it do year cost instead of monthly
        QString yearlyFinAdviceQStr = QString::fromUtf8(yearlyFinAdvice.c_str());

        ui->label_yearAdvice->setText(yearlyFinAdviceQStr);
        ui->label_yearAdvice->show();
    }
}

void AppDialog::on_tabWidget_3_currentChanged(int index)
{
    if (index == 1) {
        Expenses *expenses = this->_user->getAccount()->getExpenseObj();

        this->updateBalance();
        this->updateBudget();
        this->updateMonthlyAdvice();

        QChartView *monthStackedChart = expenses->getExtraDeficitGraphMonth(this->month);
        QChartView *pieChart = expenses->getMonthCostChart(this->month);

        monthGridLayout->addWidget(monthStackedChart, 0, 0, 1, 1);
        pieGridLayout->addWidget(pieChart, 0, 0, 1, 1);
    }

}
