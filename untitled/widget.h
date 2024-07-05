#ifndef WIDGET_H
#define WIDGET_H
#include <QFile>				// 用于打开文件
#include <QJsonParseError>		// 返回错误信息
#include <QJsonArray>			// Json数据对象
#include <QJsonDocument>		// Json文档对象
#include <QJsonObject>			// 普通Json对象
#include <QDebug>
#include <QWidget>
#include <QDir>
#include <QRegularExpression>
#include <QRandomGenerator>
#include <QUrl>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QFile>
#include<QString>
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    void settable();
    void download_file(QString fn);
    QString text;
};
#endif // WIDGET_H
