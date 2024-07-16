/********************************************************************************
** Form generated from reading UI file 'global.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GLOBAL_H
#define UI_GLOBAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_global
{
public:

    void setupUi(QWidget *global)
    {
        if (global->objectName().isEmpty())
            global->setObjectName("global");
        global->resize(400, 300);

        retranslateUi(global);

        QMetaObject::connectSlotsByName(global);
    } // setupUi

    void retranslateUi(QWidget *global)
    {
        global->setWindowTitle(QCoreApplication::translate("global", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class global: public Ui_global {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GLOBAL_H
