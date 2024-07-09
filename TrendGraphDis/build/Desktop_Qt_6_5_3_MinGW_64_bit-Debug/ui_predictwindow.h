/********************************************************************************
** Form generated from reading UI file 'predictwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREDICTWINDOW_H
#define UI_PREDICTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PredictWindow
{
public:
    QPushButton *returnButton;

    void setupUi(QWidget *PredictWindow)
    {
        if (PredictWindow->objectName().isEmpty())
            PredictWindow->setObjectName("PredictWindow");
        PredictWindow->resize(926, 670);
        returnButton = new QPushButton(PredictWindow);
        returnButton->setObjectName("returnButton");
        returnButton->setGeometry(QRect(90, 540, 211, 81));
        returnButton->setStyleSheet(QString::fromUtf8("font: 700 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(24, 179, 220, 255), stop:1 rgba(255, 255, 255, 255));"));

        retranslateUi(PredictWindow);

        QMetaObject::connectSlotsByName(PredictWindow);
    } // setupUi

    void retranslateUi(QWidget *PredictWindow)
    {
        PredictWindow->setWindowTitle(QCoreApplication::translate("PredictWindow", "Form", nullptr));
        returnButton->setText(QCoreApplication::translate("PredictWindow", "\350\277\224\345\233\236\351\246\226\351\241\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PredictWindow: public Ui_PredictWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREDICTWINDOW_H
