/********************************************************************************
** Form generated from reading UI file 'chargein.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARGEIN_H
#define UI_CHARGEIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chargein
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton_4;
    QPushButton *turnback2;

    void setupUi(QWidget *chargein)
    {
        if (chargein->objectName().isEmpty())
            chargein->setObjectName("chargein");
        chargein->resize(686, 580);
        groupBox = new QGroupBox(chargein);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(70, 100, 401, 181));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 60, 93, 28));
        pushButton->setCheckable(true);
        pushButton->setAutoExclusive(true);
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(150, 60, 93, 28));
        pushButton_2->setCheckable(true);
        pushButton_2->setAutoExclusive(true);
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(260, 60, 93, 28));
        pushButton_3->setCheckable(true);
        pushButton_3->setAutoExclusive(true);
        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(150, 130, 93, 28));
        pushButton_5->setCheckable(true);
        pushButton_5->setAutoExclusive(true);
        label = new QLabel(chargein);
        label->setObjectName("label");
        label->setGeometry(QRect(200, 270, 461, 201));
        lineEdit = new QLineEdit(chargein);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(150, 480, 241, 25));
        pushButton_4 = new QPushButton(chargein);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(160, 540, 231, 28));
        turnback2 = new QPushButton(chargein);
        turnback2->setObjectName("turnback2");
        turnback2->setGeometry(QRect(30, 540, 93, 28));

        retranslateUi(chargein);

        QMetaObject::connectSlotsByName(chargein);
    } // setupUi

    void retranslateUi(QWidget *chargein)
    {
        chargein->setWindowTitle(QCoreApplication::translate("chargein", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("chargein", "\345\205\205\345\200\274\351\207\221\351\242\235", nullptr));
        pushButton->setText(QCoreApplication::translate("chargein", "10000", nullptr));
        pushButton_2->setText(QCoreApplication::translate("chargein", "20000", nullptr));
        pushButton_3->setText(QCoreApplication::translate("chargein", "50000", nullptr));
        pushButton_5->setText(QCoreApplication::translate("chargein", "100000", nullptr));
        label->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("chargein", "\350\257\267\350\276\223\345\205\245\344\272\214\347\273\264\347\240\201\345\257\206\351\222\245", nullptr));
        pushButton_4->setText(QCoreApplication::translate("chargein", "\345\205\205\345\200\274", nullptr));
        turnback2->setText(QCoreApplication::translate("chargein", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chargein: public Ui_chargein {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARGEIN_H
