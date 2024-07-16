#include "Candle.h"
#include "ui_Candle.h"

Candle::Candle(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Candle)
{  setWindowIcon(QIcon(":/new/prefix1/favicon.ico"));

    ui->setupUi(this);
    init();
    auto text = download_kline(code); //下载相应代码股票的k线图

    text_split = match_kline(text); //分割text成K线图格式
    max_date=text_split.size()/11-1;
    init_table();
    update_profittable();
    QPixmap pixmap;
    pixmap.load(":/new/prefix1/setting.PNG");
    // 将背景图片应用为窗口的背景
    this->setAutoFillBackground(true);
    QPalette palette;
    palette.setBrush(QPalette::Window, pixmap);
    this->setPalette(palette);

    ui->pushButton->setStyleSheet("QPushButton {"
                                  "background-color: #87CEEB;"      // 按钮背景色
                                  //"border: 2px solid #8B96A3;"      // 边框样式和颜色
                                  "border-style: outset;"        // 边框样式
                                  "border-width: 4px;"           // 边框宽度
                                  "border-radius: 10px;"         // 圆角半径
                                  "border-color: #8B96A3;"
                                  "color: white;"                   // 文字颜色为白色
                                  "font-size: 26px;"                // 字体大小
                                  "font-weight: bold;"              // 字体加粗
                                  "padding: 10px 15px;"             // 按钮内边距
                                  "font-family: '华文中宋';"         // 字体设置为华文中宋
                                  "}"

                                  "QPushButton:hover {"
                                  "background-color: #4682B4;"      // 鼠标悬停时按钮背景色
                                  //"border: 2px solid #4169E1;"    // 鼠标悬停时边框样式和颜色
                                  "font-family: '华文中宋';"             // 鼠标悬停时字体设置
                                  "font-size: 26px;"                // 鼠标悬停时字体大小
                                  "font-weight: bold;"              // 鼠标悬停时字体加粗
                                  "color: white;"                   // 鼠标悬停时文字颜色为白色
                                  "}");
    ui->pushButton_sellout->setStyleSheet("QPushButton {"
                                          "background-color: 	#B0C4DE;"
                                          "border-style: outset;"        // 边框样式
                                          "border-width: 4px;"           // 边框宽度
                                          "border-radius: 10px;"         // 圆角半径
                                          "border-color: #8B96A3;"       // 边框颜色
                                          "color: white;"
                                          "font-size: 16px;"
                                          "font-weight: bold;"
                                          "padding: 10px 15px;"
                                          "font-family: Arial; font-size: 20pt; font-weight: bold; color: #ffffff;"
                                          "}"
                                          "QPushButton:hover {"
                                          "background-color: #4682B4;"
                                          //"border: 2px solid #4169E1;"
                                          "font-family: Arial; font-size: 20pt; font-weight: bold; color: #ffffff;"
                                          "}");
    ui->pushButton_buyin->setStyleSheet("QPushButton {"
                                        "background-color: 	#B0C4DE;"
                                        "border-style: outset;"        // 边框样式
                                        "border-width: 4px;"           // 边框宽度
                                        "border-radius: 10px;"         // 圆角半径
                                        "border-color: #8B96A3;"       // 边框颜色

                                        "color: white;"
                                        "font-size: 16px;"
                                        "font-weight: bold;"
                                        "padding: 10px 15px;"
                                        "font-family: Arial; font-size: 20pt; font-weight: bold; color: #ffffff;"
                                        "}"
                                        "QPushButton:hover {"
                                        "background-color: #4682B4;"
                                        //"border: 2px solid #4169E1;"
                                        "font-family: Arial; font-size: 20pt; font-weight: bold; color: #ffffff;"
                                        "}");
    ui->pushButton_2->setStyleSheet("QPushButton {"
                                    "background-color: 	#B0C4DE;"
                                    "border-style: outset;"        // 边框样式
                                    "border-width: 4px;"           // 边框宽度
                                    "border-radius: 10px;"         // 圆角半径
                                    "border-color: #8B96A3;"       // 边框颜色
                                    "color: white;"
                                    "font-size: 16px;"
                                    "font-weight: bold;"
                                    "padding: 5px 5px;"
                                    "font-family: Arial; font-size: 20pt; font-weight: bold; color: #ffffff;"
                                    "}"
                                    "QPushButton:hover {"
                                    "background-color: #4682B4;"
                                    //"border: 2px solid #4169E1;"
                                    "font-family: Arial; font-size: 20pt; font-weight: bold; color: #ffffff;"
                                    "}");
    QFont font("宋体",18);
font.setBold(true);
    ui->label->setFont(font);
    ui->label_profit->setFont(font);
    ui->label_4->setFont(font);
    ui->label_5->setFont(font);
    ui->label_6->setFont(font);
    ui->label_7->setFont(font);

    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setStyleSheet("QTableView { alternate-background-color: rgb(217, 225, 240); background: rgb(255, 255, 255); }");
     ui->tableView->verticalHeader()->setHidden(true);
    ui->tableView_profit->verticalHeader()->setHidden(true);
     //ui->tableView_profit->resizeColumnsToContents();
     ui->tableView_profit->horizontalHeader()->setStretchLastSection(true);
}

void Candle::init()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("120.46.221.110");
    db.setPort(3306);
    db.setDatabaseName("模拟交易");//是总的数据库名称
    db.setUserName("admin");
    db.setPassword("123098Qazplm@");
    db.open();
    QSqlQuery query(db);
   int id=QRandomGenerator::global()->bounded(1,2380);
    query.prepare("SELECT * FROM 获取股票 WHERE 编号 =编号");//不能加编号
    query.bindValue("编号", id);
   query.exec();
        query.next();
    code=query.value(0).toString();
    name=query.value(1).toString();
    update_timer=new QTimer();
    connect(update_timer,SIGNAL(timeout()),this,SLOT(update_candle()));
    totalmoney = 100000; // 初始化总资金
    ui->label_totalmoney->setText(QString::number(totalmoney));
    QFont fontTitle("华文隶书", 35);
    fontTitle.setBold(true);
    ui->label_title->setFont(fontTitle);

    QFont font2;
    font2.setBold(true);
    font2.setPointSize(28);
   //ui->label_title->setFont(font);
    ui->label_close->setFont(font2);
    QPalette palette = ui->label_title->palette();
    palette.setColor(QPalette::WindowText, Qt::darkBlue); // 设置文字颜色为红色
    ui->label_title->setPalette(palette);
    ui->label_maxbuyin->setText(QString::number(maxbuyin));
    QVBoxLayout *layout = new QVBoxLayout();
    series = new QCandlestickSeries();
    series->setName("k线图"); //图例的名称
    series->setIncreasingColor(QColor("#ff4c4c")); // 红色
    series->setDecreasingColor(QColor("#2ecc71")); // 绿色
    chart = new QChart();
    chart->addSeries(series);
    series->setBodyWidth(50);
    series->setMaximumColumnWidth(180);
    chart->legend()->setVisible(false); //去掉图例
    chart->setTitle("k线图"); //图表的名称
    QFont titleFont("宋体", 20); // 创建标题字体对象，这里假设使用宋体，大小为15
    titleFont.setBold(true);    // 设置粗体

    chart->setTitleFont(titleFont); // 应用标题字体到图表标题上
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->createDefaultAxes();
    Ax = qobject_cast<QBarCategoryAxis*>(chart->axes(Qt::Horizontal).at(0));
    Ax->setCategories(category); //更改category后必须再更新一遍

    chart->setBackgroundRoundness(10); // 设置图表的边角圆度


    axisY = qobject_cast<QValueAxis *>(chart->axes(Qt::Vertical).at(0));
    axisY->setRange(50, 120);
    series->setBodyWidth(50);
    QChartView *chartview = new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing); //可以防止图像走形
    layout->addWidget(chartview);



    hoverLabel = new QLabel(this); // 初始化用于显示价格信息的标签
    hoverLabel->setStyleSheet("background-color: white; border: 1px solid black; padding: 5px;");
    hoverLabel->setVisible(false); // 初始状态不可见


}

QCandlestickSet *Candle::add_candle(double open, double high, double low, double close,QString date) //返回指针类型
{
    QCandlestickSet *set = new QCandlestickSet();
    set->setOpen(open);
    set->setHigh(high);
    set->setLow(low);
    set->setClose(close);
    connect(set, &QCandlestickSet::hovered, this, [=](bool status) {
        handleCandleHovered(status, open, high, low, close,date);
    }); // 连接悬停事件
    return set;
}

void Candle::handleCandleHovered(bool status, double open, double high, double low, double close,QString date)
{
    if (status) {
        hoverLabel->setText(QString("日期:%5\n开盘价: %1\n收盘价: %2\n最高价: %3\n最低价: %4")
                                .arg(open).arg(close).arg(high).arg(low).arg(date));
        hoverLabel->adjustSize();
        hoverLabel->setVisible(true);
        QFont font("宋体",18);
        hoverLabel->setFont(font);
        QPoint cursorPos = QCursor::pos();
        hoverLabel->move(mapFromGlobal(cursorPos) + QPoint(10, 10)); // 在鼠标位置显示
    } else {
        hoverLabel->setVisible(false);
    }
}

QStringList Candle::match_kline(const QString &text)
{
    QString qreg = "\"klines\":\\[\"(.*?)\"(?:,\"(.*?)\")*";
    QRegularExpression re(qreg);
    auto pos = re.globalMatch(text);
    QString tmp;
    while (pos.hasNext())
    {
        auto match = pos.next();
        tmp.append(match.captured(0));
    }
    tmp = tmp.mid(10);
    auto text_split1 = tmp.split(",");
    return text_split1;
}

void Candle::insert_data_into_candle(int m) //插入第m组的数据
{
    QString date = text_split[11 * m].mid(1); //得到日期;
    ui->label_date->setText(date);
    int index = 11 * m;
    double open = text_split[index + 1].toDouble();
    double close = text_split[index + 2].toDouble();
    double high = text_split[index + 3].toDouble();
    double low = text_split[index + 4].toDouble();
    //滑动窗口使用双端队列更新前8个区间最值
    //更新区间最大值
    while (high > text_split[maxqueue[t_max]*11+3].toDouble() && t_max > h_max) t_max--;
    maxqueue[++t_max] = m;
    if (maxqueue[t_max] - maxqueue[h_max+1]+1 >= 7) h_max++;
    //更新区间最小值
    while (low < text_split[minqueue[t_min]*11+4].toDouble() && t_min > h_min) t_min--;
    minqueue[++t_min] = m;
    if (minqueue[t_min] - minqueue[h_min]+1 >= 7) h_min++;

    axisY->setRange(text_split[minqueue[h_min + 1]*11+4].toDouble(), text_split[maxqueue[h_max + 1]*11+3].toDouble());
    category.append(date);
    auto tmp = add_candle(open, high, low, close,date);
    series->append(tmp);
    series_list.append(tmp);
    if (cur_date >= 6)
    { //删除的时候要把series_list也删除 不然series只会删一次
        category.removeFirst();
        series->remove(series_list.first());
        series_list.removeFirst();
    }
    Ax->setCategories(category); //更改category后必须再更新一遍
}

Candle::~Candle()
{
    delete ui;
}

void Candle::drawarrow(int type)
{
    auto data = download_arrow(type);
    QPixmap t;
    t.loadFromData(data);
    ui->label_arrow->setPixmap(t);
}

void Candle::init_table()
{
    // 创建总收益表格模型并设置表头
    model_profit = new QStandardItemModel(0, 4);
    model_profit->setHeaderData(0, Qt::Horizontal, "总收益", Qt::DisplayRole); // 设置显示文本
    model_profit->setHeaderData(1, Qt::Horizontal, "时间(交易日)", Qt::DisplayRole); // 设置显示文本
    model_profit->setHeaderData(2, Qt::Horizontal, "收益率", Qt::DisplayRole); // 设置显示文本
    model_profit->setHeaderData(3, Qt::Horizontal, "交易次数", Qt::DisplayRole); // 设置显示文本
    ui->tableView_profit->setModel(model_profit);

    // 设置表头字体样式
    QFont headerFont("Arial", 12, QFont::Bold);
    QHeaderView *header_view = ui->tableView_profit->horizontalHeader();
    header_view->setFont(headerFont);

    // 设置表头背景色和文本颜色
    header_view->setStyleSheet("QHeaderView::section {"
                               "background-color: #87CEEB;"   // 设置表头背景色
                               "color: white;"                // 设置表头文本颜色
                               "padding: 1px;"                // 设置内边距
                               "border: 1px solid #8FBC8F;"   // 设置边框样式和颜色
                               "}");

    // 设置表头文本对齐方式
    header_view->setDefaultAlignment(Qt::AlignCenter);  // 设置表头文本居中对齐

    // 创建交易明细表格模型并设置表头
    model = new QStandardItemModel(0, 8);
    model->setHeaderData(0, Qt::Horizontal, "代码", Qt::DisplayRole); // 设置显示文本
    model->setHeaderData(1, Qt::Horizontal, "名称", Qt::DisplayRole); // 设置显示文本
    model->setHeaderData(2, Qt::Horizontal, "成交日期", Qt::DisplayRole); // 设置显示文本
    model->setHeaderData(3, Qt::Horizontal, "交易类型", Qt::DisplayRole); // 设置显示文本
    model->setHeaderData(4, Qt::Horizontal, "成交价格", Qt::DisplayRole); // 设置显示文本
    model->setHeaderData(5, Qt::Horizontal, "成交数量", Qt::DisplayRole); // 设置显示文本
    model->setHeaderData(6, Qt::Horizontal, "成交金额", Qt::DisplayRole); // 设置显示文本
    model->setHeaderData(7, Qt::Horizontal, "成交编号", Qt::DisplayRole); // 设置显示文本
    ui->tableView->setModel(model);

    // 设置表头字体样式
    QHeaderView *header_view_details = ui->tableView->horizontalHeader();
    header_view_details->setFont(headerFont);
    header_view_details->setStyleSheet("QHeaderView::section {"
                                       "background-color: #87CEEB;"   // 设置表头背景色
                                       "color: white;"                // 设置表头文本颜色
        "padding: 1px;"                // 设置内边距
    "border: 1px solid #8FBC8F;"   // 设置边框样式和颜色
"}");
}

void Candle::add_data_to_table(const QString &trade_type) // 修改为const QString &
{
    int row = model->rowCount();
    model->insertRow(row); //插入新行
    double price = text_split[11 * cur_date + 2].toDouble();
    model->setData(model->index(row,0),code);
    model->setData(model->index(row,1),name);
    model->setData(model->index(row, 2), text_split[11 * cur_date].mid(1));
    model->setData(model->index(row, 3), trade_type);
    model->setData(model->index(row, 4), text_split[11 * cur_date + 2]);
    model->setData(model->index(row, 5), ui->lineEdit->text());
    double num = ui->lineEdit->text().toDouble();
    double t = price * num;
    model->setData(model->index(row, 6), QString::number(t));
    model->setData(model->index(row, 7), ++trade_id);
}

QString Candle::download_kline(const QString &code)
{
    QString url = "https://push2his.eastmoney.com/api/qt/stock/kline/get?cb=jQuery35108960623101721146_1720593450084&secid=1.%1&ut=fa5fd1943c7b386f172d6893dbfba10b&fields1=f1%2Cf2%2Cf3%2Cf4%2Cf5%2Cf6&fields2=f51%2Cf52%2Cf53%2Cf54%2Cf55%2Cf56%2Cf57%2Cf58%2Cf59%2Cf60%2Cf61&klt=101&fqt=1&beg=0&end=20500101&smplmt=460&lmt=1000000&_=1720593450085";
    QString url_str = url.arg(code);
    QNetworkAccessManager manager;
    QEventLoop loop;
    QNetworkReply *reply = manager.get(QNetworkRequest(url_str));
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    return reply->readAll();
}

void Candle::on_pushButton_clicked()
{
    if(cur_date!=max_date){
    insert_data_into_candle(cur_date);
    double open = text_split[cur_date * 11 + 1].toDouble(); // cur_date表示第几组
    double close = text_split[cur_date * 11 + 2].toDouble();
    ui->label_close->setText(text_split[cur_date * 11 + 2]); // 默认type=0 上升箭头
    QPalette palette = ui->label_close->palette();
    if (open > close)
    {
        drawarrow(1);
        palette.setColor(QPalette::WindowText, Qt::green);
    }
    else
    {
        drawarrow(0);
        palette.setColor(QPalette::WindowText, Qt::darkRed);
    }
    ui->label_close->setPalette(palette);

    // 更新最大可购买股数
    double currentPrice = close; // 当前收盘价
    int maxbuyin = static_cast<int>(totalmoney / currentPrice); // 根据当前资金和价格计算最大可买入数量
    ui->label_maxbuyin->setText(QString::number(maxbuyin));
   // double currentPrice = text_split[11 * cur_date + 2].toDouble(); // 使用当前收盘价
    double stockValue = totalStocks * currentPrice; // 计算当前持有股票的市值
    double totalAssets = totalmoney + stockValue; // 计算总资产
    double profit = totalAssets - 100000; // 计算总收益
    ui->label_2->setText(QString::number(profit));
    update_profittable();
    cur_date++;}
}


QByteArray Candle::download_arrow(int type)
{
    QString url_uparrow = "data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABEAAAAXCAYAAADtNKTnAAAABHNCSVQICAgIfAhkiAAAAAlwSFlzAAALEgAACxIB0t1+/AAAABZ0RVh0Q3JlYXRpb24gVGltZQAwNy8yMi8yMU6CEBEAAAAcdEVYdFNvZnR3YXJlAEFkb2JlIEZpcmV3b3JrcyBDUzbovLKMAAAAqUlEQVQ4jc2SzQrCQAyEM0uh1+qp7/9yeqq9etnxIEpIk+y2WHAugfx8hGRAUjI9UTiyIuspLYCOuyF2MAO5kGggym8grdW9erEND3n3ZNGCvpA7kL/JSPeD5G7ARxeBjKzATeQQQAue2bLNZnJjvNAna4EbPbmQCBCBUtv36ieQISqstf9p/k0UYFJ3mI7eRAOj7c497KLiYnJdED10bQDSTSww0/+Y7QV3TVJRbIZPgQAAAABJRU5ErkJggg==";
    QString url_downarrow = "data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABEAAAAXCAYAAADtNKTnAAAABHNCSVQICAgIfAhkiAAAAAlwSFlzAAALEgAACxIB0t1+/AAAABZ0RVh0Q3JlYXRpb24gVGltZQAwNy8yMi8yMU6CEBEAAAAcdEVYdFNvZnR3YXJlAEFkb2JlIEZpcmV3b3JrcyBDUzbovLKMAAABI0lEQVQ4jdWUT04CMRSHvxITCjKKm3E1K4RbyHG8gMY7mHgquMVMWHVFXQgZlEFNngsto6UdYcHCL5m8P3399U3bVIkIPuPJ9W7ym8l4qvxcK1Z8CP9EZPX8EvR9Tpom9y5Og/5ROjn+npTzVWPsCO6JK04uezwtLbrqbuO9RQAq/Qpz0HR/xSGiv+NWj8V7iRxCXGRRhG0AdfWA0B9ic0M6ymBRMGtrEgPpKMPmhjKDwaZi1tYMNhVA7feHtIp7UTY3pGnFbG2w9muwzNgKJwboD7fWWs2gk2GtprjJlXLvyfldR6Be3fdDLB/XCkD9fJScUIgyg8TU1gnsiPwl5Hfg2Dkdv2Cf8eARx4Ri+eg98Sc0digi0e/t/UPObrU01YgIn7Vjw2MaoYO6AAAAAElFTkSuQmCC";
    if (type == 1) url_uparrow = url_downarrow;
    QNetworkAccessManager manager;
    QEventLoop loop;
    QNetworkReply *reply = manager.get(QNetworkRequest(url_uparrow));
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    return reply->readAll();
}

void Candle::on_pushButton_buyin_clicked()
{
    double price = text_split[11 * cur_date + 2].toDouble(); // 使用收盘价
    int num = ui->lineEdit->text().toInt();
    auto cost = num * price;
    int maxbuyin = static_cast<int>(totalmoney / price); // 根据当前资金和价格计算最大可买入数量
    if (num <= maxbuyin && totalmoney >= cost && num > 0)
    {
        totalmoney -= cost;
        totalStocks += num; // 更新持有的股票数量
        totalCost += cost; // 更新持有股票的总成本
        maxsellout += num; // 更新可卖出数量
        add_data_to_table("买入");
    }
    ui->label_totalmoney->setText(QString::number(totalmoney));
    ui->label_maxbuyin->setText(QString::number(static_cast<int>(totalmoney / price))); // 重新计算并更新maxbuyin
    ui->label_maxsellout->setText(QString::number(maxsellout));
    double currentPrice = text_split[11 * cur_date + 2].toDouble(); // 使用当前收盘价
    double stockValue = totalStocks * currentPrice; // 计算当前持有股票的市值
    double totalAssets = totalmoney + stockValue; // 计算总资产
    double profit = totalAssets - 100000; // 计算总收益
    ui->label_2->setText(QString::number(profit));
    update_profittable();
}


void Candle::update_profittable()
{
    double currentPrice = text_split[11 * cur_date + 2].toDouble(); // 使用当前收盘价
    double stockValue = totalStocks * currentPrice; // 计算当前持有股票的市值
    double totalAssets = totalmoney + stockValue; // 计算总资产
    double profit = totalAssets - 100000; // 计算总收益
    double profitRate = (profit / 100000) * 100; // 计算收益率

    model_profit->setRowCount(0); // 清空表格
    model_profit->insertRow(0);
    model_profit->setData(model_profit->index(0, 1), QString::number(cur_date));
    model_profit->setData(model_profit->index(0, 0), QString::number(profit));
    model_profit->setData(model_profit->index(0, 2), QString::number(profitRate) + "%");
    model_profit->setData(model_profit->index(0, 3), QString::number(trade_id));
}

void Candle::on_pushButton_sellout_clicked()
{
    int num = ui->lineEdit->text().toInt();
    double price = text_split[11 * cur_date + 2].toDouble(); // 使用收盘价
    auto income = num * price;
    if (num <= maxsellout && num > 0)
    {
        maxsellout -= num;
        totalmoney += income;
        totalStocks -= num; // 更新持有的股票数量
        totalCost -= (totalCost / totalStocks) * num; // 更新持有股票的总成本
        add_data_to_table("卖出");
    }
    double currentPrice = text_split[11 * cur_date + 2].toDouble(); // 使用当前收盘价
    double stockValue = totalStocks * currentPrice; // 计算当前持有股票的市值
    double totalAssets = totalmoney + stockValue; // 计算总资产
    double profit = totalAssets - 100000; // 计算总收益
    ui->label_totalmoney->setText(QString::number(totalmoney));
    ui->label_maxbuyin->setText(QString::number(static_cast<int>(totalmoney / price))); // 重新计算并更新maxbuyin
    ui->label_maxsellout->setText(QString::number(maxsellout));
    ui->label_2->setText(QString::number(profit));
    update_profittable();
}



void Candle::on_pushButton_2_clicked()
{

        if(ui->pushButton_2->text()=="启用自动模式")
        {
            ui->pushButton_2->setText("禁用自动模式");
            ui->pushButton->setStyleSheet("QPushButton {"
                                          "background-color: #4682B4;"      // 鼠标悬停时按钮背景色
                                          //"border: 2px solid #4169E1;"    // 鼠标悬停时边框样式和颜色
                                          "font-family: '华文中宋';"             // 鼠标悬停时字体设置
                                          "font-size: 26px;"                // 鼠标悬停时字体大小
                                          "font-weight: bold;"              // 鼠标悬停时字体加粗
                                          "color: white;"                   // 鼠标悬停时文字颜色为白色
                                          "border-style: outset;"        // 边框样式
                                          "border-width: 4px;"           // 边框宽度
                                          "border-radius: 10px;"         // 圆角半径
                                          "border-color: #8B96A3;"       // 边框颜色
                                          "}"


                                          );
            ui->pushButton->setDisabled(true);
            update_timer->start(1000);
        }
        else {
            ui->pushButton_2->setText("启用自动模式");
            ui->pushButton->setStyleSheet("QPushButton {"
                                          "background-color: #87CEEB;"      // 按钮背景色
                                          //"border: 2px solid #8B96A3;"      // 边框样式和颜色
                                          "border-style: outset;"        // 边框样式
                                          "border-width: 4px;"           // 边框宽度
                                          "border-radius: 10px;"         // 圆角半径
                                          "border-color: #8B96A3;"
                                          "color: white;"                   // 文字颜色为白色
                                          "font-size: 26px;"                // 字体大小
                                          "font-weight: bold;"              // 字体加粗
                                          "padding: 10px 15px;"             // 按钮内边距
                                          "font-family: '华文中宋';"         // 字体设置为华文中宋
                                          "}"

                                          "QPushButton:hover {"
                                          "background-color: #4682B4;"      // 鼠标悬停时按钮背景色
                                          //"border: 2px solid #4169E1;"    // 鼠标悬停时边框样式和颜色
                                          "font-family: '华文中宋';"             // 鼠标悬停时字体设置
                                          "font-size: 26px;"                // 鼠标悬停时字体大小
                                          "font-weight: bold;"              // 鼠标悬停时字体加粗
                                          "color: white;"                   // 鼠标悬停时文字颜色为白色
                                          "}");
            ui->pushButton->setDisabled(false);
            update_timer->stop();
    }
}
void Candle::update_candle()
{
    on_pushButton_clicked();
}
