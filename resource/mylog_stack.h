#ifndef MYLOG_STACK_H
#define MYLOG_STACK_H

#include <QWidget>

namespace Ui {
class Mylog_stack;
}

class Mylog_stack : public QWidget
{
    Q_OBJECT

public:
    explicit Mylog_stack(QWidget *parent = nullptr);
    ~Mylog_stack();

private:
    Ui::Mylog_stack *ui;
};

#endif // MYLOG_STACK_H
