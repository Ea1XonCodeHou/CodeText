#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QTableView>
#include <QSqlTableModel>
#include <QStyledItemDelegate>
#include <QPushButton>
#include <QDebug>
#include <QLabel>
#include <QLineEdit>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class CustomDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    CustomDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) {}

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override
    {
        QStyleOptionViewItem opt = option;
        initStyleOption(&opt, index);

        if (index.column() == 1) { // NameOfStocks column
            opt.font.setBold(true);
            opt.font.setFamily("黑体");
            opt.palette.setColor(QPalette::Text, Qt::red);
        } else if (index.column() == 3) { // ChangeData column
            double changeData = index.data().toDouble();
            if (changeData > 0) {
                opt.palette.setColor(QPalette::Text, Qt::red);
            } else {
                opt.palette.setColor(QPalette::Text, Qt::green);
            }
        } else {
            opt.font.setBold(true);
        }


        QStyledItemDelegate::paint(painter, opt, index);
    }
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void updateData();
    void previousPage();
    void nextPage();
    void searchStock();

private:
    Ui::Widget *ui;
    QSqlDatabase db;
    QSqlTableModel *model;
    QTableView *view;
    QTimer *timer;
    QPushButton *prevButton;
    QPushButton *nextButton;
    QLineEdit *searchBar;
    QLabel *searchLabel;
    QPushButton *searchButton;

    int currentPage;
    int totalPage;
    const int rowsPerPage = 10;

    void connectToDatabase();
    void setupModelAndView();
    void updatePageControls();
    void resetFilter();
};
#endif // WIDGET_H
