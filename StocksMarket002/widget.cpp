#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , currentPage(0)
{
    ui->setupUi(this);

    // 创建搜索栏和搜索按钮
    searchBar = new QLineEdit(this);
    searchButton = new QPushButton("Search", this);
    searchLabel = new QLabel("Search by Stock ID:", this);

    // 创建QTableView对象
    view = new QTableView(this);

    view->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    view->setMinimumSize(400, 300); // 设置表格最小尺寸为800x600

    // 创建分页按钮
    prevButton = new QPushButton("Previous Page", this);
    nextButton = new QPushButton("Next Page", this);


    // 设置布局
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    QHBoxLayout *searchLayout = new QHBoxLayout();

    searchLayout->addWidget(searchLabel);
    searchLayout->addWidget(searchBar);
    searchLayout->addWidget(searchButton);

    buttonLayout->addWidget(prevButton);
    buttonLayout->addWidget(nextButton);

    mainLayout->addLayout(searchLayout);
    mainLayout->addWidget(view);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);

    // 连接数据库并设置模型和视图
    connectToDatabase();
    setupModelAndView();

    // 创建QTimer对象并连接信号槽
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Widget::updateData);
    timer->start(30000);  // 每30秒刷新一次

    // 连接分页按钮的信号槽
    connect(prevButton, &QPushButton::clicked, this, &Widget::previousPage);
    connect(nextButton, &QPushButton::clicked, this, &Widget::nextPage);

    //连接搜索按钮的信号槽
    connect(searchButton, &QPushButton::clicked, this, &Widget::searchStock);
}

Widget::~Widget()
{
    if (db.isOpen()) {
        db.close();
    }
    delete ui;
}

void Widget::connectToDatabase()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setPort(3306);  // MySQL的默认端口是3306
    db.setDatabaseName("stocksinformtion");  // 替换为你的数据库名
    db.setUserName("root");  // 替换为你的用户名
    db.setPassword("Hyc20040825");  // 替换为你的密码

    if (!db.open()) {
        QMessageBox::critical(this, "Database Connection", "Failed to connect to the database: " + db.lastError().text());
    } else {
        QMessageBox::information(this, "Database Connection", "Successfully connected to the database!");
    }
}

void Widget::setupModelAndView()
{
    if (db.isOpen()) {
        model = new QSqlTableModel(this, db);
        model->setTable("BasicStocks");
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        model->select();

        // 设置表头数据
        model->setHeaderData(0, Qt::Horizontal, tr("股票代码"));
        model->setHeaderData(1, Qt::Horizontal, tr("股票名称"));
        model->setHeaderData(2, Qt::Horizontal, tr("现价价格/单支"));
        model->setHeaderData(3, Qt::Horizontal, tr("今日涨跌额"));
        model->setHeaderData(4, Qt::Horizontal, tr("今日涨跌幅"));

        // 计算总页数
        totalPage = (model->rowCount() + rowsPerPage - 1) / rowsPerPage;

        // 将模型设置到视图
        view->setModel(model);
        view->resizeColumnsToContents();

        // 应用自定义委托
        CustomDelegate *delegate = new CustomDelegate(this);
        view->setItemDelegate(delegate);

        updatePageControls();
    } else {
        QMessageBox::critical(this, "Database Error", "Database is not open.");
    }
}

void Widget::updateData()
{
    if (db.isOpen()) {
        model->select();  // 重新查询数据库以更新数据
        totalPage = (model->rowCount() + rowsPerPage - 1) / rowsPerPage; // 重新计算总页数
        updatePageControls();
    } else {
        QMessageBox::critical(this, "Database Error", "Database is not open.");
    }
}

void Widget::previousPage()
{
    if (currentPage > 0) {
        --currentPage;
        updatePageControls();
    }
}

void Widget::nextPage()
{
    if (currentPage < totalPage - 1) {
        ++currentPage;
        updatePageControls();
    }
}

void Widget::updatePageControls()
{
    model->setFilter(QString("1 LIMIT %1 OFFSET %2").arg(rowsPerPage).arg(currentPage * rowsPerPage));
    model->select();

    prevButton->setEnabled(currentPage > 0);
    nextButton->setEnabled(currentPage < totalPage - 1);
}
void Widget::searchStock()
{
    QString stockId = searchBar->text();
    if (!stockId.isEmpty()) {
        model->setFilter(QString("id_BasicStocks = '%1'").arg(stockId));
        model->select();
    } else {
        resetFilter();
    }
}

void Widget::resetFilter()
{
    model->setFilter("");
    model->select();
}
