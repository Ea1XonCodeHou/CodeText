#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
#include <QRegularExpression>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
QStringList MainWindow::download_file(QString fn, int totalPages) {
    QString base_url = "https://30.push2.eastmoney.com/api/qt/clist/get?cb=jQuery112402453391037201289_1720082624724&pn=%1&pz=20&po=1&np=1&ut=bd1d9ddb04089700cf9c27f6f7426281&fltt=2&invt=2&dect=1&wbp2u=|0|0|0|web&fid=f3&fs=m:1+t:2,m:1+t:23&fields=f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f12,f13,f14,f15,f16,f17,f18,f20,f21,f23,f24,f25,f22,f11,f62,f128,f136,f115,f152&_=1720082624725";
    QNetworkAccessManager manager;
    QStringList allData;

    for (int page = 1; page <= totalPages; ++page) {
        QString url_str = base_url.arg(page);
        QNetworkReply *reply = manager.get(QNetworkRequest(QUrl(url_str)));
        QEventLoop loop;
        QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
        loop.exec();

        auto text = reply->readAll();
        QString qreg = '\"' + fn + "\":\"(.*?)\"";
        QString qregdouble = '\"' + fn + "\":(\\d+\\.\\d+)";
        if (fn != "f12" && fn != "f14") qreg = qregdouble;

        QRegularExpression re(qreg);
        auto pos = re.globalMatch(text);
        while (pos.hasNext()) {
            auto match = pos.next();
            auto tmp = match.captured(0).mid(fn.size() + 3);
            if (fn == "f12" || fn == "f14") tmp = tmp.mid(1, tmp.size() - 2);
            allData.append(tmp);
        }

        reply->deleteLater();
    }

    return allData;
}

void MainWindow::fetchDataAndDisplay() {
    QStringList result = download_file("f12", 20); // 读取20页的数据
    for (const QString &data : result) {
        qDebug() << data;
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}
