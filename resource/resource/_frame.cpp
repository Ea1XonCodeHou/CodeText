#include "_frame.h"
#include "ui__frame.h"

#include <QStackedWidget>
#include <QPainterPath>

#include "loginframe.h"
#include "signupframe.h"
#include "ui_loginframe.h"
#include "ui_signupframe.h"


_frame::_frame(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::_frame)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

    loginframe *l1 = new loginframe(this);
    signupframe *l2 = new signupframe(this);
    ui->logORsigFrame->addWidget(l1);
    ui->logORsigFrame->addWidget(l2);
    ui->logORsigFrame->setCurrentIndex(0);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(l1->ui->register_2, &QPushButton::clicked, this, [=](){
        ui->logORsigFrame->setCurrentIndex(1);
    });
    connect(l2->ui->ChangePage, &QPushButton::clicked, this, [=](){
        ui->logORsigFrame->setCurrentIndex(0);
    });
    connect(l1, SIGNAL(this_closed()), this,SLOT(close()) );
}

_frame::~_frame()
{
    delete ui;
}
