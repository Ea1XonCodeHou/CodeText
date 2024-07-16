#include "mylog_stack.h"
#include "ui_Mylog.h"
#include "ui_chargein.h"
#include "ui_mylog_stack.h"
#include "Mylog.h"
#include "recharge.h"
#include "chargein.h"
#include "ui_recharge.h"

Mylog_stack::Mylog_stack(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Mylog_stack)
{
    ui->setupUi(this);
    Mylog *p1 = new Mylog();
    recharge *p2 = new recharge();
    chargein *p3 = new chargein();
    ui->mystackedWidget->addWidget(p1);
    ui->mystackedWidget->addWidget(p2);
    ui->mystackedWidget->addWidget(p3);
    ui->mystackedWidget->setCurrentIndex(0);

    connect(p2->ui->turnback, &QPushButton::clicked, this, [=](){
        ui->mystackedWidget->setCurrentIndex(0);
    });
    connect(p3->ui->turnback2, &QPushButton::clicked, this, [=](){
        ui->mystackedWidget->setCurrentIndex(0);
    });
    connect(p1->ui->setuserinfo, &QPushButton::clicked, this, [=](){
        ui->mystackedWidget->setCurrentIndex(1);
    });
    connect(p1->ui->chargein, &QPushButton::clicked, this, [=](){
        ui->mystackedWidget->setCurrentIndex(2);
    });
}

Mylog_stack::~Mylog_stack()
{
    delete ui;
}
