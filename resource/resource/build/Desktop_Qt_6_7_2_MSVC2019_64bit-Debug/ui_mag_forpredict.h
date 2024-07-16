/********************************************************************************
** Form generated from reading UI file 'mag_forpredict.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAG_FORPREDICT_H
#define UI_MAG_FORPREDICT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mag_forPredict
{
public:
    QFormLayout *formLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *mag_forPredict)
    {
        if (mag_forPredict->objectName().isEmpty())
            mag_forPredict->setObjectName("mag_forPredict");
        mag_forPredict->resize(689, 543);
        formLayout = new QFormLayout(mag_forPredict);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(mag_forPredict);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 687, 541));
        scrollArea->setWidget(scrollAreaWidgetContents);

        formLayout->setWidget(0, QFormLayout::SpanningRole, scrollArea);


        retranslateUi(mag_forPredict);

        QMetaObject::connectSlotsByName(mag_forPredict);
    } // setupUi

    void retranslateUi(QWidget *mag_forPredict)
    {
        mag_forPredict->setWindowTitle(QCoreApplication::translate("mag_forPredict", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mag_forPredict: public Ui_mag_forPredict {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAG_FORPREDICT_H
