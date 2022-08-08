#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //鼠标未移动
    MouseMove = false;
}


Widget::~Widget()
{
    delete ui;
}

//鼠标按下操作
void Widget::mousePressEvent(QMouseEvent *event)
{
    //用户是否点击左键
    if(event->button() == Qt::LeftButton){

        //获取laber的位置
        QRect rect = ui->label->frameRect();
        //鼠标相对的平移对应的位置
        rect.translate(ui->label->pos());
        //获取鼠标的位置
        QPoint point = event->pos();
        //鼠标是否在标签内
        if(rect.contains(point)){
            MouseMove= true;
            //获取相对位置
            pos = ui->label->pos() - point;
        }
    }

}

//鼠标离开操作
void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        MouseMove = false;
    }
}

//鼠标移动操作
void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if(MouseMove){

        //记录移动的位置
        QPoint newpoint = event->pos()+pos;

        //设置移动的限制
        //获取窗口大小  size(h,w)
        QSize window = size();
        QSize label = ui->label->size();

        //设置位置
        if(newpoint.x()< 0 ){
            newpoint.setX(0);
        }else if(newpoint.x()>(window.width() - label.width())){
            newpoint.setX(window.width() - label.width());
        }

        if(newpoint.y() < 0){
            newpoint.setY(0);
        }else if(newpoint.y() > window.height() - ui->label->height()){
            newpoint.setY(window.height() - ui->label->height());
        }

        //移动
        ui->label->move(newpoint);

    }

}

void Widget::keyPressEvent(QKeyEvent *event)
{
    int x = ui->label->pos().x();
    int y = ui->label->pos().y();
    int winx = this->pos.x();
    int winy = this->pos.y();
    int boxX = ui->label->size().width();
    int boxY = ui->label->size().height();
    qDebug() <<"BoxX = " <<boxX;
    qDebug() <<"BoxX = " <<boxX;
    qDebug() <<"x = " <<x;
    qDebug() <<"y = " <<y;
    qDebug() <<"winx = " <<winx;
    qDebug() <<"winy = " <<winy;
    //保证范围

            if(event->key() == Qt::Key_Up){
                //不足10个像素点就移到边上
                if(y!=winy){
                    if(y+10 > winy){
                        ui->label->move(x,0);
                    }
                    ui->label->move(x,y-10);
                }
            }else if (event->key() == Qt::Key_Down){
                if(y - boxY > winy){
                    if(y-boxY-10 < 0){
                        ui->label->move(x,winy-boxX);
                    }
                    ui->label->move(x,y+10);
                }
            }


        if(event->key() == Qt::Key_Left){
            if(x- 10< 0){
                ui->label->move(0,y);
            }
            ui->label->move(x-10,y);
        }else if(event->key() == Qt::Key_Right){
            if(x+10 > winx){
                ui->label->move(winx,y);
            }
            ui->label->move(x+10,y);
        }


}

