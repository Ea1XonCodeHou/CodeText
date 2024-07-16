#include "client.h"
#include "ui_client.h"
#include <QMovie>

client::client(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::client)
{
    ui->setupUi(this);

    recv_Timer = new QTimer;
    socket = new QTcpSocket;
    connect_to_mysql();
    get_chat_history();

    // 设置推送按钮样式
    ui->pushButton_2->setStyleSheet("QPushButton {"
                                    "background-color: #B0C4DE;"
                                    "border-style: outset;"
                                    "border-width: 4px;"
                                    "border-radius: 5px;"
                                    "border-color: #8B96A3;"
                                    "color: white;"
                                    "font-size: 12px;"
                                    "font-weight: bold;"
                                    "padding: 5px 8px;"
                                    "font-family: 华文中宋; font-size: 10pt; font-weight: bold; color: #ffffff;"
                                    "}"
                                    "QPushButton:hover {"
                                    "background-color: #4682B4;"
                                    "}");

    // 设置背景图片
    QPixmap pixmap(":/new/prefix1/resource/setting.PNG");
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(pixmap.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    this->setPalette(palette);
    this->setAutoFillBackground(true);

    // 设置发送按钮样式
    ui->pushButton->setStyleSheet("QPushButton {"
                                  "background-color: #B0C4DE;"
                                  "border-style: outset;"
                                  "border-width: 4px;"
                                  "border-radius: 5px;"
                                  "border-color: #8B96A3;"
                                  "color: white;"
                                  "font-size: 18px;"
                                  "font-weight: bold;"
                                  "padding: 5px 8px;"
                                  "font-family: Arial; font-size: 10pt; font-weight: bold; color: #ffffff;"
                                  "}"
                                  "QPushButton:hover {"
                                  "background-color: #4682B4;"
                                  "}");

    // 设置标签字体
    QFont font("华文中宋", 14, QFont::Bold);
    ui->label->setFont(font);
    ui->label_2->setFont(font);

    // 设置用户头像
    QPixmap userpic(":/new/prefix1/resource/userpic.png");
    ui->userpicLabel->setPixmap(userpic);

    // 设置动画
    //QMovie *movie = new QMovie(":/new/prefix1/resource/bubble.gif");
    //ui->label_3->setMovie(movie);
    //movie->start();

    // 设置文本框样式
    ui->textEdit->setFont(font);
    ui->textEdit->setStyleSheet("QTextEdit { border: 2px solid gray; border-radius: 10px; }");
}

client::~client()
{
    delete ui;
}

void client::connect_to_mysql()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("120.46.221.110");
    db.setPort(3306);
    db.setDatabaseName("聊天室历史记录");
    db.setUserName("admin");
    db.setPassword("123098Qazplm@");
    db.open();
}

void client::get_chat_history()
{
    QSqlQuery db_cursor(db);
    QString cmd = QString("select * from 聊天室记录");
    db_cursor.exec(cmd);
    while (db_cursor.next()) {
        QString user = db_cursor.value(0).toString();
        QString msg = db_cursor.value(1).toString();
        QString date = db_cursor.value(2).toString();
        insertMessage(user, msg, date);
    }
}

void client::on_pushButton_clicked()
{
    connect_to_server();
}

void client::connect_to_server()
{
    Ip = "127.0.0.1";
    port = "8888";
    socket->connectToHost(QHostAddress(Ip), port.toShort());
    if (socket->state() != QAbstractSocket::ConnectedState)
        QMessageBox::information(this, "提示", "连接失败");
    connect(socket, &QIODevice::readyRead, this, &client::recvmsg);
}

void client::recvmsg()
{
    QString msg = (QString)socket->readAll();
    QStringList text = msg.split('|');
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->textEdit->setTextCursor(cursor);
    QString user = text[1];
    msg = text[0];
    QString date = text[2];
    insertMessage(user, msg, date);
}

void client::on_pushButton_2_clicked()
{
    socket->connectToHost(QHostAddress(Ip), port.toShort());
    if (socket->state() == QAbstractSocket::ConnectedState)
        sendInfo();
    else
        QMessageBox::information(this, "提示", "连接失败");
}

void client::sendInfo()
{
    QString ba;
    ba.append(ui->lineEdit_3->text());
    ba += '|';
    if (ui->lineEdit_4->text().isEmpty())
        ba.append("匿名用户");
    else
        ba.append(ui->lineEdit_4->text());
    ba += '|';
    QDateTime dateTime = QDateTime::currentDateTime();
    QString timestr = dateTime.toString("yyyy-MM-dd hh:mm:ss");
    ba += timestr;
    socket->write(ba.toUtf8().data());
}

void client::insertMessage(const QString &user, const QString &msg, const QString &date)
{
    QString userStyle = "font-weight: bold; color: #333; background-color: #90EE90; padding: 5px;";
    QString dateStyle = "color: #666; font-size: 10pt; background-color: #90EE90; padding: 5px;";
    QString messageStyle = "margin-left: 20px; background-color: #90EE90; padding: 5px;";

    QString formattedMsg;
    if (user == ui->lineEdit_4->text()) { // 用户自己的发言
        formattedMsg = QString("<div style='background-color: #90EE90; padding: 5px; border-radius: 5px;'>"
                               "<div style='%1'>%2</div>" // 用户名
                               "<div style='%3'>%4</div>" // 消息内容
                               "<div style='%5'>%6</div>" // 日期
                               "</div><br>")  // 结尾添加一个空行
                           .arg(userStyle).arg(user)
                           .arg(messageStyle).arg(msg)
                           .arg(dateStyle).arg(date);
    } else {
        userStyle = "font-weight: bold; color: #333; padding: 5px;";
        dateStyle = "color: #666; font-size: 10pt; padding: 5px;";
        messageStyle = "margin-left: 20px; padding: 5px;";
        formattedMsg = QString("<div style='padding: 5px; border-radius: 5px;'>"
                               "<div style='%1'>%2</div>"
                               "<div style='%3'>%4</div>"
                               "<div style='%5'>%6</div>"
                               "</div><br>")
                           .arg(userStyle).arg(user)
                           .arg(messageStyle).arg(msg)
                           .arg(dateStyle).arg(date);
    }
    ui->textEdit->insertHtml(formattedMsg);

    // 确保滚动到底部
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->textEdit->setTextCursor(cursor);
}






