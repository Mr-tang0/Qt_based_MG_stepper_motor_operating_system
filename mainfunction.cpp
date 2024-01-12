#include "widget.h"
#include "ui_widget.h"

QSerialPort *Widget::myPort = new QSerialPort();
Worker *Widget::newworker = new Worker();




void Widget::delay(int delayTime)
{
    QEventLoop loop;
    QTimer::singleShot(delayTime,&loop,SLOT(quit()));
    loop.exec();
}
