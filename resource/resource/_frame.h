#ifndef _FRAME_H
#define _FRAME_H

#include <QWidget>

namespace Ui {
class _frame;
}

class _frame : public QWidget
{
    Q_OBJECT

public:
    Ui::_frame *ui;
    explicit _frame(QWidget *parent = nullptr);
    ~_frame();

private:
};

#endif // _FRAME_H
