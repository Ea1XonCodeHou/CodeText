#include "signuptips.h"
#include "ui_signuptips.h"

signuptips::signuptips(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::signuptips)
{
    ui->setupUi(this);
}

signuptips::~signuptips()
{
    delete ui;
}
