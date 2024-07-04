#ifndef SIGNUPTIPS_H
#define SIGNUPTIPS_H

#include <QDialog>

namespace Ui {
class signuptips;
}

class signuptips : public QDialog
{
    Q_OBJECT

public:
    explicit signuptips(QWidget *parent = nullptr);
    ~signuptips();

private:
    Ui::signuptips *ui;
};

#endif // SIGNUPTIPS_H
