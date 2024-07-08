#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTextCharFormat>
#include <QTextCursor>
#include <QTextDocument>
#include <QListWidgetItem>
#include <QMap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , model(new QStandardItemModel(this))
    , currentPage(0)
    , itemsPerPage(5)
{
    ui->setupUi(this);

    manager =new QNetworkAccessManager(this);
    connect(manager,&QNetworkAccessManager::finished,this, &MainWindow::onNetworkReplyFinished);

    connect(ui->searchButton, &QPushButton::clicked, this, &MainWindow::onSearchButtonClicked);
    connect(ui->prevPageButton, &QPushButton::clicked, this, &MainWindow::onPrevPageButtonClicked);
    connect(ui->nextPageButton, &QPushButton::clicked, this, &MainWindow::onNextPageButtonClicked);

    ui->newsTableView->setModel(model);

    ui->newsTableView->verticalHeader()->setDefaultSectionSize(150);
    ui->newsTableView->horizontalHeader()->setDefaultSectionSize(600);
    startCrawling();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startCrawling(){
    QNetworkRequest request;
    request.setUrl(QUrl("https://finance.eastmoney.com/yaowen.html"));
    manager->get(request);  // 发送请求并获取响应
}

void MainWindow::onNetworkReplyFinished(QNetworkReply *reply){
    if (reply) {
        QByteArray content = reply->readAll();
        QRegularExpression re("<p class=\"info\" title=\"([^\"]+)\">");
        QRegularExpressionMatchIterator it = re.globalMatch(content);
        newsData.clear();
        while (it.hasNext()) {
            QRegularExpressionMatch match = it.next();
            QString title = match.captured(1);
            newsData.append(QStringList() << title);
        }
        reply->deleteLater();
        filteredNewsData = newsData;  // 初始化时显示所有新闻
        displayNews(0);
    }
}

void MainWindow::displayNews(int page)
{
    model->clear();
    model->setHorizontalHeaderLabels(QStringList() << "今日股市热闻");

    int start = page * itemsPerPage;
    int end = qMin(start + itemsPerPage, filteredNewsData.size());

    for (int i = start; i < end; ++i) {
        QList<QStandardItem*> rowItems;
        for (const QString &text : filteredNewsData[i]) {
            rowItems.append(new QStandardItem(text));
        }
        model->appendRow(rowItems);

        ui->newsTableView->setRowHeight(i-start,100);
    }
    ui->newsTableView->setColumnWidth(0, 600);
    currentPage = page;
}

void MainWindow::onSearchButtonClicked()
{
    QString keyword = ui->searchLineEdit->text();
    filterNews(keyword);
}

void MainWindow::filterNews(const QString &keyword)
{
    filteredNewsData.clear();
    for (const QStringList &news : newsData) {
        if (news[0].contains(keyword, Qt::CaseInsensitive)) {
            filteredNewsData.append(news);
        }
    }

    displayNews(0);
}

void MainWindow::onPrevPageButtonClicked()
{
    if (currentPage > 0) {
        displayNews(currentPage - 1);
    }
}

void MainWindow::onNextPageButtonClicked()
{
    int maxPage = (filteredNewsData.size() + itemsPerPage - 1) / itemsPerPage - 1;
    if (currentPage < maxPage) {
        displayNews(currentPage + 1);
    }
}

