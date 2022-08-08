#include "widget.h"

#include <QApplication>

//鼠标移动事件

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
