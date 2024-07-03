#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include "signuptips.h"

namespace Ui {
class signup;
}

class signup : public QDialog
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();

private slots:
    void on_pushButton_clicked();

private:
    Ui::signup *ui;
    signuptips *successtip = new signuptips;
};

#endif // SIGNUP_H
