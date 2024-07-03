#include "signup.h"
#include "ui_signup.h"

signup::signup(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::signup)
{
    ui->setupUi(this);
}

signup::~signup()
{
    delete ui;
}

void signup::on_pushButton_clicked()
{
    successtip ->show();
}

