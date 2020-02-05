#ifndef MAKEACCOUNTDIALOG_H
#define MAKEACCOUNTDIALOG_H

#include <QDialog>
#include "logindialog.h"

namespace Ui {
class MakeAccountDialog;
}

class MakeAccountDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MakeAccountDialog(QWidget *parent = 0);
    ~MakeAccountDialog();

private slots:
    void on_pushButton_accountMade_clicked();

private:
    Ui::MakeAccountDialog *ui;
    LogInDialog *logInDialog;
};

#endif // MAKEACCOUNTDIALOG_H
