#include "mainprogram.h"
#include "ui_mainprogram.h"
#include "widget.h"
#include "mainwindow.h"
#include "risktest.h"
#include "mag_forpredict.h"
#include "mylog_stack.h"
#include "client.h"

#include <QGraphicsDropShadowEffect>
#include <QSystemTrayIcon>
#include <QMouseEvent>


mainprogram::mainprogram(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mainprogram)
{
    ui->setupUi(this);
    //样式设置

    //设置阴影
    QGraphicsDropShadowEffect *shadow1 = new QGraphicsDropShadowEffect();//阴影边框效果
    shadow1->setBlurRadius(10);//设置阴影四角的弧度
    shadow1->setColor(Qt::black);//设置阴影颜色
    shadow1->setOffset(0);//设置阴影距离  0就看不到边框阴影
    ui->stackedWidget->setGraphicsEffect(shadow1);//将阴影事件放到指定控件上

    //信号处理

    connect(ui->CloseButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->MiniButton, SIGNAL(clicked()), this, SLOT(showMinimized()));
    connect(ui->MaxButton, &QPushButton::clicked, this, [=](){
        if (this->isMaximized())
        {
            this->showNormal();
        }
        else
        {
            this->showMaximized();
        }
    });
    MainWindow *p1 = new MainWindow(this);
    Widget *p2 = new Widget(this);
    mag_forPredict *p3 = new mag_forPredict(this);
    risktest *p4 = new risktest(this);
    Mylog_stack *p5 = new Mylog_stack();
    client *p6 = new client();
    ui->stackedWidget->addWidget(p1);
    ui->stackedWidget->addWidget(p2);
    ui->stackedWidget->addWidget(p3);
    ui->stackedWidget->addWidget(p4);
    ui->stackedWidget->addWidget(p5);
    ui->stackedWidget->addWidget(p6);
}

mainprogram::~mainprogram()
{
    delete ui;
}


void mainprogram::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_dragging = true;
        m_dragStartPos = event->pos();
    }
}

void mainprogram::mouseMoveEvent(QMouseEvent *event)
{
    if (m_dragging) {
        move(event->globalPos() - m_dragStartPos);
    }
}

void mainprogram::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_dragging = false;
    }
}

void mainprogram::wheelEvent(QWheelEvent *event)
{
    if (event->modifiers() & Qt::ControlModifier) {
        int delta = event->angleDelta().y();
        if (delta > 0) {
            resize(width() * 1.1, height() * 1.1);
        } else if (delta < 0) {
            resize(width() * 0.9, height() * 0.9);
        }
    }
}
