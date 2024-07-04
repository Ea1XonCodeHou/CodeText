/********************************************************************************
** Form generated from reading UI file 'mainprogram.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPROGRAM_H
#define UI_MAINPROGRAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainprogram
{
public:

    void setupUi(QWidget *mainprogram)
    {
        if (mainprogram->objectName().isEmpty())
            mainprogram->setObjectName("mainprogram");
        mainprogram->resize(717, 480);

        retranslateUi(mainprogram);

        QMetaObject::connectSlotsByName(mainprogram);
    } // setupUi

    void retranslateUi(QWidget *mainprogram)
    {
        mainprogram->setWindowTitle(QCoreApplication::translate("mainprogram", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainprogram: public Ui_mainprogram {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPROGRAM_H
