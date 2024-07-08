#ifndef MY_THREAD_H
#define MY_THREAD_H

#include <QObject>
#include <QDebug>
#include<QThread>
#include<QTimer>
#include<QObject>
class my_thread :public QThread
{
    Q_OBJECT
public:
    explicit my_thread();
    void run();
public slots:
        void job();
};

#endif // MY_THREAD_H
