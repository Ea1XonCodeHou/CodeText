/********************************************************************************
** Form generated from reading UI file 'mylog_stack.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYLOG_STACK_H
#define UI_MYLOG_STACK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mylog_stack
{
public:
    QFormLayout *formLayout;
    QStackedWidget *mystackedWidget;

    void setupUi(QWidget *Mylog_stack)
    {
        if (Mylog_stack->objectName().isEmpty())
            Mylog_stack->setObjectName("Mylog_stack");
        Mylog_stack->resize(931, 623);
        formLayout = new QFormLayout(Mylog_stack);
        formLayout->setObjectName("formLayout");
        mystackedWidget = new QStackedWidget(Mylog_stack);
        mystackedWidget->setObjectName("mystackedWidget");
        mystackedWidget->setMinimumSize(QSize(100, 0));

        formLayout->setWidget(0, QFormLayout::SpanningRole, mystackedWidget);


        retranslateUi(Mylog_stack);

        QMetaObject::connectSlotsByName(Mylog_stack);
    } // setupUi

    void retranslateUi(QWidget *Mylog_stack)
    {
        Mylog_stack->setWindowTitle(QCoreApplication::translate("Mylog_stack", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mylog_stack: public Ui_Mylog_stack {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYLOG_STACK_H
