#include "widget.h"
#include "ui_widget.h" 


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    findAvailablePort();
    connectSerialPort(9600,"COM1");

    QThread *mythread = new QThread;
    newworker->moveToThread(mythread);//worker进入子线程，有关于收发的函数均在子线程中执行
    newworker->openReseiveChannal();//开接收

    weigh *myWeigh = new weigh;

    for (int i = 0;i<100;i++)
    {
        myWeigh->getWeight(1);
        delay(100);
    }


}

Widget::~Widget()
{
    delete ui;
}
