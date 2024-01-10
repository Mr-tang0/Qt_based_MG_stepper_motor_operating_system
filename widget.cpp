#include "widget.h"
#include "ui_widget.h"



Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    findAvailablePort();
    connectSerialPort(9600,"COM1");

    weigh *myWeigh = new weigh;
    myWeigh->getWeight("a");
}

Widget::~Widget()
{
    delete ui;
}
