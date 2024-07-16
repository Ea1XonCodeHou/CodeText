QT       += core gui
QT       += sql
QT       += network
QT       += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    _frame.cpp \
    loginframe.cpp \
    mag_forpredict.cpp \
    main.cpp \
    mainprogram.cpp \
    mainwindow.cpp \
    mylabel.cpp \
    mylog_stack.cpp \
    signupframe.cpp \
    risktest.cpp \
    predictwindow.cpp \
    widget.cpp \
    Mylog.cpp \
    chargein.cpp \
    qrencode/bitstream.c \
    qrencode/mask.c \
    qrencode/mmask.c \
    qrencode/mqrspec.c \
    qrencode/qrencode.c \
    qrencode/qrinput.c \
    qrencode/qrspec.c \
    qrencode/rscode.c \
    qrencode/split.c \
    recharge.cpp \
    tcQrencode.cpp \
    Candle.cpp \
    client.cpp \
    userlog.cpp



HEADERS += \
    ../test/验证码生成/untitled/mylabel.h \
    ../test/验证码生成/untitled/mylabel.h \
    _frame.h \
    global.h \
    loginframe.h \
    mag_forpredict.h \
    mainprogram.h \
    mainwindow.h \
    mylabel.h \
    mylog_stack.h \
    signupframe.h \
    risktest.h \
    predictwindow.h \
    widget.h \
    Mylog.h \
    chargein.h \
    qrencode/bitstream.h \
    qrencode/mask.h \
    qrencode/mmask.h \
    qrencode/mqrspec.h \
    qrencode/qrencode.h \
    qrencode/qrencode_inner.h \
    qrencode/qrinput.h \
    qrencode/qrspec.h \
    qrencode/rscode.h \
    qrencode/split.h \
    recharge.h \
    tcQrencode.h \
    Candle.h \
    client.h \
    userlog.h



FORMS += \
    _frame.ui \
    loginframe.ui \
    mag_forpredict.ui \
    mainprogram.ui \
    mainwindow.ui \
    mylog_stack.ui \
    signupframe.ui \
    risktest.ui \
    predictwindow.ui \
    widget.ui \
    Mylog.ui \
    chargein.ui \
    recharge.ui \
    Candle.ui \
    client.ui



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    bg1.qrc
