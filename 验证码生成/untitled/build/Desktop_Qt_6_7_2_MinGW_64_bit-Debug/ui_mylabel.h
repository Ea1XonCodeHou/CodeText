/********************************************************************************
** Form generated from reading UI file 'mylabel.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYLABEL_H
#define UI_MYLABEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mylabel
{
public:

    void setupUi(QWidget *mylabel)
    {
        if (mylabel->objectName().isEmpty())
            mylabel->setObjectName("mylabel");
        mylabel->resize(400, 300);

        retranslateUi(mylabel);

        QMetaObject::connectSlotsByName(mylabel);
    } // setupUi

    void retranslateUi(QWidget *mylabel)
    {
        mylabel->setWindowTitle(QCoreApplication::translate("mylabel", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mylabel: public Ui_mylabel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYLABEL_H
