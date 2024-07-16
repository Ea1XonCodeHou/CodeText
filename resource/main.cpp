#include "_frame.h"
#include "global.h"
#include "BuySell.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    _frame w;
    //test
    //Current_User_Name = "gandi";
    //Widget w;


    w.show();
    return a.exec();
}
