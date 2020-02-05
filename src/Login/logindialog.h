#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "appdialog.h"


namespace Ui {
class LogInDialog;
}

class LogInDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LogInDialog(QWidget *parent = 0);
    ~LogInDialog();

private slots:
    void on_pushButton_Login_clicked();

private:
    Ui::LogInDialog *ui;
    AppDialog *appDialog;
};

#endif // LOGINDIALOG_H
