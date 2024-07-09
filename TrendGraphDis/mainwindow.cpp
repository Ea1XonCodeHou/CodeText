#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , predictWindow(new PredictWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("智能股市预测");
    // 连接按钮点击信号到槽函数
    connect(ui->predictButton, &QPushButton::clicked, this, &MainWindow::on_predictButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete predictWindow;
}

void MainWindow::on_predictButton_clicked()
{
    // 显示预测界面
    this->close();
    predictWindow->show();
}
