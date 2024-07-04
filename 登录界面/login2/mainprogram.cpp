#include "mainprogram.h"
#include "ui_mainprogram.h"

mainprogram::mainprogram(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mainprogram)
{
    ui->setupUi(this);
}

mainprogram::~mainprogram()
{
    delete ui;
}
