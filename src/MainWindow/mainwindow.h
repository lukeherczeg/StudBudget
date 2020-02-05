#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "makeaccountdialog.h"
#include "logindialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void hideMainWindow();

private slots:
    void on_pushButton_makeAccount_clicked();
    void on_pushButton_login_clicked();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    MakeAccountDialog *makeAccountDialog;
    LogInDialog *logInDialog;
};

#endif // MAINWINDOW_H
