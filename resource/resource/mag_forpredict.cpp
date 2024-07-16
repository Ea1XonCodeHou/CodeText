#include "mag_forpredict.h"
#include "ui_mag_forpredict.h"

#include "predictwindow.h"

#include <QWheelEvent>

mag_forPredict::mag_forPredict(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mag_forPredict)
{
    ui->setupUi(this);
    PredictWindow *pred = new PredictWindow;
    ui->scrollArea->setWidget(pred);

}
void mag_forPredict::wheelEvent(QWheelEvent *event) {
    if (event->angleDelta().y() > 0) { // 向上滚动
        emit void wheelup();
    } else { // 向下滚动
        emit void wheeldown();
    }
}
mag_forPredict::~mag_forPredict()
{
    delete ui;
}
