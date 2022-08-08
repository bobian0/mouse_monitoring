#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    //鼠标按下操作 ，可以区分左键和右键
    void mousePressEvent(QMouseEvent *event);
    //鼠标抬起操作
    void mouseReleaseEvent(QMouseEvent *event);
    //鼠标移动操作
    void mouseMoveEvent(QMouseEvent *event);

    //键盘移动
    void keyPressEvent(QKeyEvent * event);
private:
    Ui::Widget *ui;
    //判断鼠标是否移动
    bool MouseMove;
    QPoint pos;
};
#endif // WIDGET_H
