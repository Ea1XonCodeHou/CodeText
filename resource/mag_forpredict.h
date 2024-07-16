#ifndef MAG_FORPREDICT_H
#define MAG_FORPREDICT_H


#include "predictwindow.h"
#include "qobjectdefs.h"
#include <QWidget>

namespace Ui {
class mag_forPredict;
}

class mag_forPredict : public QWidget
{
    Q_OBJECT

public:
    explicit mag_forPredict(QWidget *parent = nullptr);
    ~mag_forPredict();

signals:
    void wheelup();
    void wheeldown();

protected:
    virtual void wheelEvent(QWheelEvent *event) override;

private:
    Ui::mag_forPredict *ui;
};

#endif // MAG_FORPREDICT_H
