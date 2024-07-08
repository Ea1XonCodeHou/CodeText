#ifndef THREAD_H
#define THREAD_H
#include<QThread>
#include <QObject>
class thread:public QThread
{
    Q_OBJECT
public:
   thread(QObject * parent = 0);
public:
   run();
};

#endif // THREAD_H
