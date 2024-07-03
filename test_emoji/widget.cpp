#include "widget.h"
#include "ui_widget.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    char32_t  t[] = {0x1F601,0x0};	//加上0x00是为了防止表情后面跟随乱码

    for(char32_t i = 0x1F601 ; i <=  0x1F64F ; ++i)
    {
        t[0] = i ;
        ui->textBrowser->insertPlainText(QString::fromUcs4(t));
    }
}

Widget::~Widget()
{
    delete ui;
}
