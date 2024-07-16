#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QRegularExpression>
#include <QStandardItemModel>
#include <QListWidgetItem>
#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onNetworkReplyFinished(QNetworkReply *reply);
    void onSearchButtonClicked();
    void onPrevPageButtonClicked();
    void onNextPageButtonClicked();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *manager;
    QStandardItemModel *model;
    QList<QStringList> newsData;
    QList<QStringList> filteredNewsData;
    int currentPage;
    int itemsPerPage;

    void startCrawling();
    void displayNews(int page);
    void filterNews(const QString &keyword);
    void updateHotWords();
};
#endif // MAINWINDOW_H
