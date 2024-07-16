#include "cilent.h"
#include "ui_cilent.h"

cilent::cilent(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::cilent)
{
    ui->setupUi(this);
}

cilent::~cilent()
{
    delete ui;
}
