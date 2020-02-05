#include "logindialog.h"
#include "ui_logindialog.h"
#include "authenticator.h"
#include "sha256.h"


#include <QMessageBox>

LogInDialog::LogInDialog(QWidget *parent) : QDialog(parent),
    ui(new Ui::LogInDialog)
{
    ui->setupUi(this);
}

LogInDialog::~LogInDialog()
{
    delete ui;
}

void LogInDialog::on_pushButton_Login_clicked()
{
    bool finished = false;
    Authenticator* authenticator = new Authenticator();
    authenticator->fillMapOfUsers();

    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    std::string usernameStr = username.toUtf8().constData();
    std::string passwordStr = password.toUtf8().constData();

    sha256 * algorithm = new sha256;
    std::string hashPassword = algorithm->doSha256(passwordStr);
    delete algorithm;

    authenticator->logIn(usernameStr, hashPassword, finished);
    User* user = authenticator->getUser();

       if(finished) {
           appDialog = new AppDialog(user, this);
           appDialog->show();
           hide();
           this->parentWidget()->hide(); //MAKES THE MAINWINDOW HIDE
       }
       else {
           QMessageBox::warning(this,"Login", "Username or password is not correct");
       }
}
