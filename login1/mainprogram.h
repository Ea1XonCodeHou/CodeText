#ifndef MAINPROGRAM_H
#define MAINPROGRAM_H

#include <QWidget>

namespace Ui {
class mainprogram;
}

class mainprogram : public QWidget
{
    Q_OBJECT

public:
    explicit mainprogram(QWidget *parent = nullptr);
    ~mainprogram();

private:
    Ui::mainprogram *ui;
};

#endif // MAINPROGRAM_H
