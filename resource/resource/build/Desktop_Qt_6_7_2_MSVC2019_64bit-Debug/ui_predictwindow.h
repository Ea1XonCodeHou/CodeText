/********************************************************************************
** Form generated from reading UI file 'predictwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREDICTWINDOW_H
#define UI_PREDICTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PredictWindow
{
public:
    QFormLayout *formLayout;

    void setupUi(QWidget *PredictWindow)
    {
        if (PredictWindow->objectName().isEmpty())
            PredictWindow->setObjectName("PredictWindow");
        PredictWindow->resize(747, 491);
        formLayout = new QFormLayout(PredictWindow);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(PredictWindow);

        QMetaObject::connectSlotsByName(PredictWindow);
    } // setupUi

    void retranslateUi(QWidget *PredictWindow)
    {
        PredictWindow->setWindowTitle(QCoreApplication::translate("PredictWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PredictWindow: public Ui_PredictWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREDICTWINDOW_H
