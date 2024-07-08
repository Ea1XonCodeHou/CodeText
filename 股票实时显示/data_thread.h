#ifndef DATA_THREAD_H
#define DATA_THREAD_H
#include<QThread>
class data_thread:public QThread
{
    Q_OBJECT
public:
    explicit data_thread(QObject *parent = nullptr);

protected:
    void run();
    QStringList download_file(QString fn);
public slots:

};

#endif // DATA_THREAD_H
