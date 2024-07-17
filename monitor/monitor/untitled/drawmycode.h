#ifndef DRAWMYCODE_H
#define DRAWMYCODE_H

#include <QWidget>

namespace Ui {
class drawmycode;
}

class drawmycode : public QWidget
{
    Q_OBJECT

public:
    explicit drawmycode(QWidget *parent = nullptr);
    ~drawmycode();

private:
    Ui::drawmycode *ui;
};

#endif // DRAWMYCODE_H
