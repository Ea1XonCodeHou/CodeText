#include "predictwindow.h"
#include "ui_predictwindow.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QPainter>
#include <QPen>
#include <QPixmap>
#include <QIcon>
#include <QStyle>
#include <QMouseEvent>
#include <QToolTip>


PredictWindow::PredictWindow(QWidget *parent):
    QWidget(parent),
    ui(new Ui::PredictWindow),
    networkManager(new QNetworkAccessManager(this))
{


    ui->setupUi(this);

    connect(networkManager, &QNetworkAccessManager::finished, this, &PredictWindow::onNetworkReply);
    fetchStockData();
    setMouseTracking(true);

}

PredictWindow::~PredictWindow()
{
    delete ui;
}


void PredictWindow::fetchStockData()
{
    QNetworkRequest request(QUrl("https://q.stock.sohu.com/hisHq?code=zs_000001&stat=1&order=D&period=d&callback=historySearchHandler&rt=jsonp&0.06329827237401364"));
    networkManager->get(request);
}

void PredictWindow::onNetworkReply(QNetworkReply* reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        parseJsonResponse(responseData);
    } else {
        qDebug() << "Error:" << reply->errorString();
    }
    reply->deleteLater();
}

void PredictWindow::parseJsonResponse(const QByteArray& responseData)
{
    QString dataString = QString::fromUtf8(responseData);
    int startIndex = dataString.indexOf('[');
    int endIndex = dataString.lastIndexOf(']');
    if (startIndex == -1 || endIndex == -1) {
        qDebug() << "Invalid JSONP format";
        return;
    }

    QString jsonString = dataString.mid(startIndex, endIndex - startIndex + 1);
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonString.toUtf8());

    if (jsonDoc.isArray()) {
        QJsonArray jsonArray = jsonDoc.array();
        if (!jsonArray.isEmpty() && jsonArray.first().isObject()) {
            QJsonObject jsonObject = jsonArray.first().toObject();
            if (jsonObject.contains("hq")) {
                QJsonArray hqArray = jsonObject["hq"].toArray();
                int count = 0;
                for (const QJsonValue& value : hqArray) {
                    if (count >= 120) break;
                    QJsonArray dataArray = value.toArray();
                    if (dataArray.size() >= 6) { // 确保包含所有需要的数据
                        StockData data;
                        data.date = dataArray[0].toString();
                        data.open = dataArray[1].toString().toDouble();
                        data.close = dataArray[2].toString().toDouble();
                        data.high = dataArray[5].toString().toDouble(); // 添加最高价
                        data.low = dataArray[4].toString().toDouble();  // 添加最低价
                        data.changeAmount = dataArray[3].toString().toDouble();
                        data.changePercentage = dataArray[4].toString().remove('%').toDouble();
                        stockDataList.prepend(data);
                        count++;
                    }
                }
            }
        }
    }
}



double PredictWindow::linearRegression(const QVector<double>& x, const QVector<double>& y)
{
    int n = x.size();
    if (n == 0) return 0;

    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    for (int i = 0; i < n; ++i) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    double slope = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double intercept = (sumY - slope * sumX) / n;

    // Predict the next value (x = n)
    return slope * n + intercept;
}

void PredictWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    if (stockDataList.isEmpty()) {
        return;
    }

    // Define margins and spacing
    int margin = 50;
    int extraMargin = 60; // Extra space at the top and bottom
    int rectWidth = (width() - 2 * margin) / stockDataList.size();
    int chartHeight = height() - 2 * margin - 2 * extraMargin;

    // Find the min and max values for scaling
    double minPrice = stockDataList[0].open;
    double maxPrice = stockDataList[0].open;
    int minIndex = 0;
    int maxIndex = 0;

    for (int i = 0; i < stockDataList.size(); ++i) {
        const auto& data = stockDataList[i];
        if (data.open < minPrice) {
            minPrice = data.open;
            minIndex = i;
        }
        if (data.close < minPrice) {
            minPrice = data.close;
            minIndex = i;
        }
        if (data.open > maxPrice) {
            maxPrice = data.open;
            maxIndex = i;
        }
        if (data.close > maxPrice) {
            maxPrice = data.close;
            maxIndex = i;
        }
    }

    // Draw the K-line chart and lines

    QColor customRed(255, 48, 48);
    QColor PGreen(50, 205, 50);

    QColor upLine(255, 99, 71);
    QColor downLine(72, 209, 204);

    QPen openPen(upLine, 2); // Thicker pen for open price line
    QPen closePen(downLine, 2); // Thicker pen for close price line

    QVector<QRect> rectList;
    QVector<QPointF> openPoints;
    QVector<QPointF> closePoints;

    for (int i = 0; i < stockDataList.size(); ++i) {
        const auto& data = stockDataList[i];
        int x = margin + i * rectWidth;
        int openY = margin + extraMargin + chartHeight * (1 - (data.open - minPrice) / (maxPrice - minPrice));
        int closeY = margin + extraMargin + chartHeight * (1 - (data.close - minPrice) / (maxPrice - minPrice));

        QRect rect(x, qMin(openY, closeY), rectWidth, qAbs(openY - closeY));
        rectList.append(rect);

        if (data.changePercentage > 0) {
            painter.setBrush(customRed);
        } else {
            painter.setBrush(PGreen);
        }
        painter.drawRect(rect);

        openPoints.append(QPointF(x + rectWidth / 2, openY));
        closePoints.append(QPointF(x + rectWidth / 2, closeY));
    }

    // Draw open price line
    painter.setPen(closePen);
    painter.drawPolyline(openPoints.data(), openPoints.size());

    // Draw close price line
    painter.setPen(openPen);
    painter.drawPolyline(closePoints.data(), closePoints.size());

    // Draw axes
    painter.setPen(Qt::black);
    painter.drawLine(margin, margin + extraMargin, margin, height() - margin - extraMargin); // Y axis
    painter.drawLine(margin, height() - margin, width() - margin, height() - margin); // X axis


    // Draw Y axis labels
    painter.setPen(Qt::black);
    int numYLabels = 10;
    for (int i = 0; i <= numYLabels; ++i) {
        double value = minPrice + i * (maxPrice - minPrice) / numYLabels;
        int y = margin + extraMargin + chartHeight * (1 - (value - minPrice) / (maxPrice - minPrice));

        // Draw tick marks
        painter.drawLine(margin - 5, y, margin, y);

        // Draw text labels
        QFont font("Arial", 8);
        painter.setFont(font);
        painter.drawText(5, y + 5, QString::number(value, 'f', 2));
    }

    // Draw Y axis arrow
    painter.drawLine(margin, margin, margin, height() - margin); // Y axis line
    painter.drawLine(margin, margin, margin - 5, margin + 5);    // Y axis arrow
    painter.drawLine(margin, margin, margin + 5, margin + 5);    // Y axis arrow

    // Draw Y axis label
    QString yAxisLabel = "市值/元";
    painter.drawText(margin - 30, margin - 10, yAxisLabel);

    // Draw X axis labels
    painter.setPen(Qt::black);
    int labelInterval = stockDataList.size() / 5; // Show labels at intervals to avoid clutter
    for (int i = 0; i < stockDataList.size(); ++i) {
        if (i % labelInterval == 0) {
            const auto& data = stockDataList[i];
            int x = margin + i * rectWidth + rectWidth / 2;

            // Draw tick marks
            painter.drawLine(x, height() - margin, x, height() - margin + 5);

            // Draw text labels
            QFont font("Arial", 8);
            painter.setFont(font);
            painter.drawText(x - rectWidth / 2, height() - margin + 20, data.date);
        }
    }

    // Draw X axis arrow
    int maxX = margin + stockDataList.size() * rectWidth;
    painter.drawLine(margin, height() - margin, maxX, height() - margin); // X axis line
    painter.drawLine(maxX, height() - margin, maxX - 5, height() - margin - 5); // X axis arrow
    painter.drawLine(maxX, height() - margin, maxX - 5, height() - margin + 5); // X axis arrow

    // Draw X axis label
    QString xAxisLabel = "日期";
    painter.drawText(maxX + 10, height() - margin + 10, xAxisLabel);

    // Draw labels for the minimum and maximum values
    painter.setPen(Qt::black);
    int minY = margin + extraMargin + chartHeight * (1 - (minPrice - minPrice) / (maxPrice - minPrice));
    int maxY = margin + extraMargin + chartHeight * (1 - (maxPrice - minPrice) / (maxPrice - minPrice));

    // Draw a text box for min and max values
    QRect textBox(width() - 250, 50, 200, 50);
    QFont font("华文中宋", 12);
    painter.setFont(font);
    painter.setPen(Qt::black);
    painter.setBrush(Qt::white);
    painter.drawRect(textBox);
    painter.drawText(textBox.adjusted(5, 5, 0, 0), Qt::AlignLeft | Qt::AlignTop,
                     QString("本阶段最低市值: %1\n本阶段最高市值: %2").arg(minPrice).arg(maxPrice));

    // Draw arrows from text box to min and max points
    QPen arrowPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    painter.setPen(arrowPen);

    // Arrow to min point
    painter.drawLine(textBox.left() + 10, textBox.bottom(), margin + minIndex * rectWidth + rectWidth / 2, minY);
    painter.drawLine(margin + minIndex * rectWidth + rectWidth / 2 - 5, minY - 5, margin + minIndex * rectWidth + rectWidth / 2, minY);
    painter.drawLine(margin + minIndex * rectWidth + rectWidth / 2 + 5, minY - 5, margin + minIndex * rectWidth + rectWidth / 2, minY);

    // Arrow to max point
    painter.drawLine(textBox.left() + 10, textBox.bottom(), margin + maxIndex * rectWidth + rectWidth / 2, maxY);
    painter.drawLine(margin + maxIndex * rectWidth + rectWidth / 2 - 5, maxY - 5, margin + maxIndex * rectWidth + rectWidth / 2, maxY);
    painter.drawLine(margin + maxIndex * rectWidth + rectWidth / 2 + 5, maxY - 5, margin + maxIndex * rectWidth + rectWidth / 2, maxY);

    // Linear regression for the last 5 days
    if (stockDataList.size() >= 5) {
        int n = 5;
        double sumX = 0, sumYOpen = 0, sumYClose = 0, sumXYOpen = 0, sumXYClose = 0, sumX2 = 0;
        for (int i = 0; i < n; ++i) {
            sumX += i;
            sumYOpen += stockDataList[stockDataList.size() - n + i].open;
            sumYClose += stockDataList[stockDataList.size() - n + i].close;
            sumXYOpen += i * stockDataList[stockDataList.size() - n + i].open;
            sumXYClose += i * stockDataList[stockDataList.size() - n + i].close;
            sumX2 += i * i;
        }

        double slopeOpen = (n * sumXYOpen - sumX * sumYOpen) / (n * sumX2 - sumX * sumX);
        double interceptOpen = (sumYOpen - slopeOpen * sumX) / n;
        double slopeClose = (n * sumXYClose - sumX * sumYClose) / (n * sumX2 - sumX * sumX);
        double interceptClose = (sumYClose - slopeClose * sumX) / n;

        double predictedOpen = slopeOpen * n + interceptOpen;
        double predictedClose = slopeClose * n + interceptClose;
        double changePercent = ((predictedClose - stockDataList.last().close) / stockDataList.last().close) * 100.0;

        int predictedX = margin + stockDataList.size() * rectWidth;
        int predictedOpenY = margin + extraMargin + chartHeight * (1 - (predictedOpen - minPrice) / (maxPrice - minPrice));
        int predictedCloseY = margin + extraMargin + chartHeight * (1 - (predictedClose - minPrice) / (maxPrice - minPrice));

        // Draw prediction rectangle
        QRect predictionRect(predictedX, qMin(predictedOpenY, predictedCloseY), rectWidth, qAbs(predictedOpenY - predictedCloseY));
        painter.setBrush(Qt::gray);
        painter.drawRect(predictionRect);

        // Draw prediction lines
        painter.setPen(QPen(Qt::magenta, 3, Qt::DashLine));
        painter.drawLine(predictedX, predictedOpenY, predictedX + rectWidth, predictedOpenY);
        painter.drawLine(predictedX, predictedCloseY, predictedX + rectWidth, predictedCloseY);

        // Draw prediction text
        QFont font = painter.font();
        font.setBold(true);
        painter.setFont(font);
        painter.setPen(Qt::black);
        painter.drawText(predictedX - 110, predictedOpenY-150, QString("预测开盘: %1").arg(predictedOpen, 0, 'f', 2));
        painter.drawText(predictedX - 110, predictedCloseY-150, QString("预测收盘: %1").arg(predictedClose, 0, 'f', 2));
        painter.drawText(predictedX - 110, predictedCloseY - 100, QString("预测明日变化: %1%").arg(changePercent, 0, 'f', 2));
    }
    this->rectList=rectList;
}

void PredictWindow::mouseMoveEvent(QMouseEvent *event)
{
    QPoint cursorPos = event->pos();
    for (int i = 0; i < rectList.size(); ++i) {
        if (rectList[i].contains(cursorPos)) {
            const StockData& data = stockDataList[i];

            // 构建提示文字
            QString tooltipText = QString("<span style='font-family:\"华文中宋\"; font-weight:bold;'>日期:</span> %1<br/>"
                                          "<span style='font-family:\"华文中宋\"; font-weight:bold;'>开盘价:</span> %2<br/>"
                                          "<span style='font-family:\"华文中宋\"; font-weight:bold;'>收盘价:</span> %3<br/>"
                                          "<span style='font-family:\"华文中宋\"; font-weight:bold;'>涨跌幅:</span> %4%")
                                      .arg(data.date)
                                      .arg(data.open)
                                      .arg(data.close)
                                      .arg(data.changePercentage);

            // 显示提示文字
            QToolTip::showText(event->globalPos(), tooltipText, this);
            break;
        }
    }
}
