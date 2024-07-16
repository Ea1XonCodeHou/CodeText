#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTextCharFormat>
#include <QTextCursor>
#include <QTextDocument>
#include <QListWidgetItem>
#include <QMap>
#include <QPixmap>
#include <QIcon>
#include <QGraphicsDropShadowEffect>
/**
 * MainWindow类的构造函数。
 * 初始化主窗口界面，设置模型和网络请求管理器，连接按钮信号和槽函数。
 * @param parent 父窗口指针，默认为nullptr。
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , model(new QStandardItemModel(this))
    , currentPage(0)
    , itemsPerPage(5)
{
    ui->setupUi(this);
    // 为搜索框和搜索按钮添加阴影效果
    QGraphicsDropShadowEffect *shadow1 = new QGraphicsDropShadowEffect();
    shadow1->setBlurRadius(10);
    shadow1->setColor(Qt::black);
    shadow1->setOffset(0);
    ui->searchLineEdit->setGraphicsEffect(shadow1);
    QGraphicsDropShadowEffect *shadow2 = new QGraphicsDropShadowEffect();
    shadow2->setBlurRadius(10);
    shadow2->setColor(Qt::black);
    shadow2->setOffset(0);
    ui->searchButton->setGraphicsEffect(shadow2);
    // 初始化网络请求管理器并连接完成信号至槽函数
    manager =new QNetworkAccessManager(this);
    connect(manager,&QNetworkAccessManager::finished,this, &MainWindow::onNetworkReplyFinished);

    // 连接按钮信号至相应槽函数
    connect(ui->searchButton, &QPushButton::clicked, this, &MainWindow::onSearchButtonClicked);
    connect(ui->prevPageButton, &QPushButton::clicked, this, &MainWindow::onPrevPageButtonClicked);
    connect(ui->nextPageButton, &QPushButton::clicked, this, &MainWindow::onNextPageButtonClicked);

    // 设置新闻表格模型
    ui->newsTableView->setModel(model);
    // 设置表格列宽和行高
    //ui->newsTableView->verticalHeader()->setDefaultSectionSize(150);
    //ui->newsTableView->horizontalHeader()->setDefaultSectionSize(600);
    // 开始爬取新闻数据
    startCrawling();
}

/**
 * MainWindow类的析构函数。
 * 释放内存，删除ui对象。
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * 开始爬取新闻数据。
 * 发送网络请求至指定URL获取新闻页面内容。
 */
void MainWindow::startCrawling(){
    QNetworkRequest request;
    request.setUrl(QUrl("https://finance.eastmoney.com/yaowen.html"));
    manager->get(request);  // 发送请求并获取响应
}

/**
 * 处理网络请求完成事件。
 * 解析响应内容，提取新闻标题，存储并显示新闻数据。
 * @param reply 网络请求的回复对象指针。
 */
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

/**
 * 显示新闻数据。
 * 根据当前页码，更新模型数据，显示对应页的新闻标题。
 * @param page 当前页码。
 */
void MainWindow::displayNews(int page)
{
    model->clear();
    model->setHorizontalHeaderLabels(QStringList() << " ");

    int start = page * itemsPerPage;
    int end = qMin(start + itemsPerPage, filteredNewsData.size());

    for (int i = start; i < end; ++i) {
        QList<QStandardItem*> rowItems;
        for (const QString &text : filteredNewsData[i]) {
            QStandardItem *item = new QStandardItem(text);

            QFont font("等线light", 11);
            font.setLetterSpacing(QFont::PercentageSpacing, 110);
            item->setFont(font);

            if (text.contains("商务部") || text.contains("中国")) {
                item->setForeground(QBrush(Qt::white));
            }

            rowItems.append(item);
        }
        model->appendRow(rowItems);
        ui->newsTableView->setRowHeight(i-start,110);
    }
    ui->newsTableView->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->newsTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->pages->setText(QString("第 %1 页").arg(page + 1));
    currentPage = page;
}


/**
 * 当点击搜索按钮时触发。
 * 获取搜索关键字，过滤新闻数据，并显示过滤后的新闻。
 */
void MainWindow::onSearchButtonClicked()
{
    QString keyword = ui->searchLineEdit->text();
    filterNews(keyword);
}

/**
 * 过滤新闻数据。
 * 根据关键字过滤新闻标题，更新显示的新闻数据。
 * @param keyword 搜索关键字。
 */
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

/**
 * 当点击上一页按钮时触发。
 * 根据当前页码，显示上一页的新闻。
 */
void MainWindow::onPrevPageButtonClicked()
{
    if (currentPage > 0) {
        displayNews(currentPage - 1);
    }
}

/**
 * 当点击下一页按钮时触发。
 * 根据当前页码和数据量，显示下一页的新闻。
 */
void MainWindow::onNextPageButtonClicked()
{
    int maxPage = (filteredNewsData.size() + itemsPerPage - 1) / itemsPerPage - 1;
    if (currentPage < maxPage) {
        displayNews(currentPage + 1);
    }
}
