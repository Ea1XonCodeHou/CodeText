<<<<<<<< HEAD:股票实时显示/untitled.pro
QT       += core network testlib gui sql

========
QT       += core gui
QT       += network
QT       += sql
>>>>>>>> 9af261653293528937eff45e97e1fb1fae6bfc5a:NewMarket7-6/NewMarket7-6.pro
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
