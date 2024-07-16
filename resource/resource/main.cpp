#include "_frame.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    _frame w;
    w.show();
    return a.exec();
}
