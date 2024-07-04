/********************************************************************************
** Form generated from reading UI file 'signuptips.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPTIPS_H
#define UI_SIGNUPTIPS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_signuptips
{
public:
    QLabel *label;

    void setupUi(QDialog *signuptips)
    {
        if (signuptips->objectName().isEmpty())
            signuptips->setObjectName("signuptips");
        signuptips->resize(400, 300);
        label = new QLabel(signuptips);
        label->setObjectName("label");
        label->setGeometry(QRect(150, 130, 69, 19));

        retranslateUi(signuptips);

        QMetaObject::connectSlotsByName(signuptips);
    } // setupUi

    void retranslateUi(QDialog *signuptips)
    {
        signuptips->setWindowTitle(QCoreApplication::translate("signuptips", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("signuptips", "\346\263\250\345\206\214\346\210\220\345\212\237\357\274\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class signuptips: public Ui_signuptips {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPTIPS_H
