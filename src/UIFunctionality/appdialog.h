#ifndef APPDIALOG_H
#define APPDIALOG_H

#include <QDialog>
#include "user.h"
#include "account.h"

namespace Ui {
class AppDialog;
}

class AppDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AppDialog(User* &user, QWidget *parent = 0);
    void updateMonthlyAdvice();
    void updateAll();
    void updateBudget();
    void updateBalance();
    ~AppDialog();

private slots:
    void on_pushButton_signOut_clicked();
    void on_comboBox_month_activated(int index);
    void on_pushButton_depositFoodC_clicked();
    void on_pushButton_withdrawFoodC_clicked();
    void on_pushButton_depositRentC_clicked();
    void on_pushButton_withdrawRentC_clicked();
    void on_pushButton_depositEntertainmentC_clicked();
    void on_pushButton_withdrawEntertainmentC_clicked();
    void on_pushButton_depositTuitionC_clicked();
    void on_pushButton_withdrawTuitionC_clicked();
    void on_pushButton_depositSavingsC_clicked();
    void on_pushButton_withdrawSavingsC_clicked();
    void on_pushButton_depositMiscC_clicked();
    void on_pushButton_withdrawMiscC_clicked();
    void on_pushButton_depositFoodB_clicked();
    void on_pushButton_withdrawFoodB_clicked();
    void on_pushButton_depositRentB_clicked();
    void on_pushButton_withdrawRentB_clicked();
    void on_pushButton_depositEntertainmentB_clicked();
    void on_pushButton_withdrawEntertainmentB_clicked();
    void on_pushButton_depositTuitionB_clicked();
    void on_pushButton_withdrawTuitionB_clicked();
    void on_pushButton_depositSavingsB_clicked();
    void on_pushButton_withdrawSavingsB_clicked();
    void on_pushButton_depositMiscB_clicked();
    void on_pushButton_withdrawMiscB_clicked();
    void on_pushButton_makeBudget_clicked();
    void on_pushButton_clearBudget_clicked();
    void on_pushButton_clearBalance_clicked();
    void on_pushButton_makeBalance_clicked();
    void on_tabWidget_currentChanged(int index);
    void on_tabWidget_3_currentChanged(int index);

private:
    User* _user;
    int month;
    QGridLayout *yearGridLayout;
    QGridLayout *gridLayout;
    QGridLayout *monthGridLayout;
    QGridLayout *pieGridLayout;
    Ui::AppDialog *ui;
};

#endif // APPDIALOG_H
