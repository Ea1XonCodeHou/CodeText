#ifndef RISKTEST_H
#define RISKTEST_H

#include <QWidget>
#include <QSqlDatabase>
#include <QMap>
#include <QStandardItemModel>
#include <QLabel>
#include <QNetworkAccessManager>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QUrl>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QString>
#include <QStringList>
#include <QColor>
#include <QTextBrowser>
#include <QTableView>
#include <QStandardItemModel>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMap>
#include <QFont>
#include <QFontDatabase>
#include <QObject>
#include <QPixmap>
#include <QPalette>
#include <QStyledItemDelegate>

QT_BEGIN_NAMESPACE
namespace Ui {
class risktest;
}
QT_END_NAMESPACE

class risktest : public QWidget
{
    Q_OBJECT

public:

    risktest(QWidget *parent = nullptr);
    ~risktest();
    void linkSlot();
    void showSlot();
    void calculateBuySellRatio();
    QMap<QString, QString> download_file(QString fn);
    void fetchDataForStockAsync(const QString &stockCode, QStandardItemModel *model, int row);
    void fetchDataForStockAsyncModel(QString &stockCode, QStandardItemModel model, int row);
    void fetchDataForCurrentPage();
    void updateTableViewWithoutOffset();

private slots:

    void on_pushButton_clicked();

public slots:

    void nextPage();
    void previousPage();
    void firstPage();
    void lastPage();

private:

    Ui::risktest *ui;
    QSqlDatabase db;
    QStandardItemModel *model;


    int currentPage;  // 当前页数
    int rowsPerPage;  // 每页显示的行数
    int totalRows;    // 总行数
    int totalPages;   // 总页数

    void updateTableView();
};
#endif // RISKTEST_H
