#include "my_thread.h"
#include"widget.h"
my_thread::my_thread()

{}
void my_thread::job()//直接调用主线程的函数会崩溃
{
  //  qDebug()<<"当前线程ID:"<<QThread::currentThreadId();
   // Widget t;
   // t.download_file("f14",3);
}

void my_thread::run()
{
   auto t=new QTimer();
    //connect(t,SIGNAL(timeout()),this,SLOT(job()));//这里不能加my_thread::job
   connect(t,SIGNAL(timeout()),this,SLOT(job()),Qt::DirectConnection);
   t->start(1000);
    exec();
}
