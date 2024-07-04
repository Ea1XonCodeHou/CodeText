#include "mainprogramwindow.h"
#include "ui_mainprogramwindow.h"

MainprogramWindow::MainprogramWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainprogramWindow)
{
    ui->setupUi(this);
}

MainprogramWindow::~MainprogramWindow()
{
    delete ui;
}
