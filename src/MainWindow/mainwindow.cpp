#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "authenticator.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::hideMainWindow(){
    this->hide();
}

void MainWindow::on_pushButton_makeAccount_clicked()
{
    makeAccountDialog = new MakeAccountDialog(this);
    makeAccountDialog->show();
}

void MainWindow::on_pushButton_login_clicked()
{
    logInDialog = new LogInDialog(this);
    logInDialog->show();
}

void MainWindow::on_pushButton_clicked() // The delete all users button
{
    Authenticator* authenticator = new Authenticator();
    authenticator->fillMapOfUsers();
    authenticator->clearUsers();
    remove("authData.txt");
    remove("accountData.txt");
    delete authenticator;
}
