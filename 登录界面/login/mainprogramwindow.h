#ifndef MAINPROGRAMWINDOW_H
#define MAINPROGRAMWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainprogramWindow;
}

class MainprogramWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainprogramWindow(QWidget *parent = nullptr);
    ~MainprogramWindow();

private:
    Ui::MainprogramWindow *ui;
};

#endif // MAINPROGRAMWINDOW_H
