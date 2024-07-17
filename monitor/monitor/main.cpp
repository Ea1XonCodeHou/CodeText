#include "monitor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    monitor w;
    w.show();
    return a.exec();
}
