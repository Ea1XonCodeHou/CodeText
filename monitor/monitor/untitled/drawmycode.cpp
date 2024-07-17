#include "drawmycode.h"
#include "ui_drawmycode.h"

drawmycode::drawmycode(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::drawmycode)
{
    ui->setupUi(this);
}

drawmycode::~drawmycode()
{
    delete ui;
}
