#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
w.showSlot();
    w.show();
    return a.exec();
}
// void Widget::calculateBuySellRatio()
// {
//     QStandardItemModel *model = qobject_cast<QStandardItemModel*>(ui->tableView->model());
//     if (!model) {
//         QMessageBox::warning(this, "错误", "数据模型未设置或无效.");
//         return;
//     }
//     int rowsPerPage = 7;  // 每页显示7条数据
//     int totalRows = 0;
//     int totalPages = 0;
//     // 定义总体统计变量
//     double totalProfitLossRatioSum = 0.0;
//     int totalBuyCount = 0;
//     int totalSellCount = 0;

//     // 查询总行数
//     QSqlQuery countQuery("SELECT COUNT(*) FROM test");
//     if (countQuery.exec() && countQuery.next()) {
//         totalRows = countQuery.value(0).toInt();
//         totalPages = (totalRows + rowsPerPage - 1) / rowsPerPage;
//     } else {
//         QMessageBox::warning(this, "错误", "查询总行数失败或无结果.");
//         return;
//     }

//     for (int currentPage = 0; currentPage < totalPages; ++currentPage) {
//         int startRow = currentPage * rowsPerPage;
//         int endRow = qMin(startRow + rowsPerPage, totalRows);  // 最后一页可能不足一页行数

//         int buyCount = 0;
//         int sellCount = 0;
//         double totalInvestment = 0.0;
//         double totalReturns = 0.0;
//         int totalSharesTraded = 0;
//         int maxShares = INT_MIN;
//         int minShares = INT_MAX;

//         // 计算每页的统计信息
//         for (int i = startRow; i < endRow; ++i) {
//             QModelIndex buySellIndex = model->index(i, 4);
//             QString buySell = model->data(buySellIndex).toString();

//             QModelIndex numIndex = model->index(i, 2);
//             int num = model->data(numIndex).toInt();

//             QModelIndex priceIndex = model->index(i, 3);
//             double price = model->data(priceIndex).toDouble();

//             if (buySell == "买入") {
//                 buyCount++;
//                 totalInvestment += num * price;
//             } else if (buySell == "卖出") {
//                 sellCount++;
//                 totalReturns += num * price;
//             }

//             totalSharesTraded += num;
//             if (num > maxShares) {
//                 maxShares = num;
//             }
//             if (num < minShares) {
//                 minShares = num;
//             }
//         }

//         // 累计总体统计信息
//         totalBuyCount += buyCount;
//         totalSellCount += sellCount;
//         if (totalInvestment > 0.0) {
//             totalProfitLossRatioSum += ((totalReturns - totalInvestment) / totalInvestment) * 100.0;
//         }
//     }


//     QString resultText = QString::asprintf("第 %d 页统计信息:\n"
//                                            "买入交易次数: %d\n卖出交易次数: %d\n"
//                                            "总投入: %.2f\n总回报: %.2f\n"
//                                            "买入交易比例: %.2f%%\n卖出交易比例: %.2f%%\n"
//                                            "总体盈亏比例: %.2f%%\n"
//                                            "平均每次交易股票数量: %.2f\n"
//                                            "最大交易股票数量: %d\n最小交易股票数量: %d\n",
//                                            currentPage + 1,
//                                            buyCount,
//                                            sellCount,
//                                            totalInvestment,
//                                            totalReturns,
//                                            (double)buyCount / (buyCount + sellCount) * 100.0,
//                                            (double)sellCount / (buyCount + sellCount) * 100.0,
//                                            totalProfitLossRatio,
//                                            averageSharesTraded,
//                                            maxShares,
//                                            minShares);

//     QMessageBox::information(this, "提示", resultText);

// }
// ui->textBrowser->clear();
// ui->textBrowser->insertPlainText("根据您的交易历史数据分析：\n");
// ui->textBrowser->insertPlainText(resultText);
// // 格式化输出结果
// QFont font("Arial", 20);
// font.setBold(true);
// font.setItalic(true);
// // 设置字体和文本
// ui->label_2->setFont(font);
// ui->label_2->setText(riskAssessment);
// // 计算总体的平均股票交易量和盈亏比率
// double averageSharesTraded = 0.0;
// double totalProfitLossRatio = 0.0;

// if (totalBuyCount + totalSellCount > 0) {
//     averageSharesTraded = static_cast<double>(totalSharesTraded) / (totalBuyCount + totalSellCount);
// }
// if (totalRows > 0) {
//     totalProfitLossRatio = totalProfitLossRatioSum / totalRows;  // 平均盈亏比率
// }

// // 计算投资建议
// QString investmentAdvice;
// double buyRatio = static_cast<double>(totalBuyCount) / (totalBuyCount + totalSellCount) * 100.0;

// if (totalProfitLossRatio < 0.0 && buyRatio > 50.0) {
//     investmentAdvice = "建议审查您的投资组合并降低风险敞口。";
// } else if (totalProfitLossRatio < 30.0 && buyRatio < 30.0) {
//     investmentAdvice = "可以考虑增加投资敞口以提升收益。";
// } else {
//     investmentAdvice = "建议保持投资组合的平衡。";
// }

// ui->label_3->setText(investmentAdvice);
// ui->textBrowser->setReadOnly(true);

// double maxLoss = 0.0;
// int maxLossRow = -1;
// // 遍历每一行数据
// for (int row = 0; row < model->rowCount(); ++row) {
//     int numShares = model->item(row, 2)->text().toInt();
//     double purchasePrice = model->item(row, 3)->text().toDouble();
//     double currentPrice = model->item(row, 5)->text().toDouble();
//     QString buySell = model->item(row, 4)->text();

//     // 计算亏损（根据买入/卖出的不同应用不同的逻辑）
//     double profitLoss;
//     if (buySell == "买入") {
//         profitLoss = (currentPrice - purchasePrice) * numShares;
//     } else if (buySell == "卖出") {
//         profitLoss = (purchasePrice - currentPrice) * numShares;
//     } else {
//         // 如果买入/卖出字段不是预期的值（买入或卖出），这里可以考虑如何处理，例如跳过或记录错误。
//         continue;
//     }

//     // 比较找出最大亏损的交易
//     if (profitLoss < maxLoss) {
//         maxLoss = profitLoss;
//         maxLossRow = row;
//     }
// }

// // 输出造成最大亏损的交易数据到 QLabel
// if (maxLossRow != -1) {
//     QString stockName = model->item(maxLossRow, 0)->text();
//     QString stockCode = model->item(maxLossRow, 1)->text();
//     double purchasePrice = model->item(maxLossRow, 3)->text().toDouble();
//     QString buySell = model->item(maxLossRow, 4)->text();
//     double currentPrice = model->item(maxLossRow, 5)->text().toDouble();

//     QString outputText = "风险关联交易：\n";
//     outputText += "股票名称：" + stockName + "\n";
//     outputText += "股票代码：" + stockCode + "\n";
//     outputText += "买入/卖出：" + buySell + "\n";
//     outputText += "购买价格：" + QString::number(purchasePrice) + "\n";
//     outputText += "当前价格：" + QString::number(currentPrice) + "\n";
//     outputText += "盈亏：" + QString::number(maxLoss);

//     ui->label->setText(outputText);
// } else {
//     ui->label->setText("未找到任何造成亏损的交易数据。");
// }
// }
