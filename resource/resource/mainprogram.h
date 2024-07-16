#ifndef MAINPROGRAM_H
#define MAINPROGRAM_H

#include <QWidget>

namespace Ui {
class mainprogram;
}

class mainprogram : public QWidget
{
    Q_OBJECT

public:
    explicit mainprogram(QWidget *parent = nullptr);
    ~mainprogram();
    Ui::mainprogram *ui;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

private:
    bool m_dragging = false;
    QPoint m_dragStartPos;
};

#endif // MAINPROGRAM_H
