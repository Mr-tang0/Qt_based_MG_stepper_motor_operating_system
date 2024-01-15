#include "widget.h"
#include "ui_widget.h" 
#include "portui.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("mainWindow");
    portUi *portui = new portUi;
    portui->show();
    connect(portui,&portUi::connected,[=](bool connectFlag){
        if(connectFlag)
        this->show();
        else this->close();
        ui->label->setText(QStringLiteral("当前连接：%1 波特率：%2").arg(myPort->portName()).arg(myPort->baudRate()));
    });

    initSystem();



//    QThread *mythread = new QThread;
//    newworker->moveToThread(mythread);//worker进入子线程，有关于收发的函数均在子线程中执行
//    newworker->openReseiveChannal();//开接收

//    myMotorList.append(new motor);
//    qDebug()<<myMotorList.first();


//    motor *myMotor = new motor;
//    myMotor->buildData("power_control","500");



}

Widget::~Widget()
{
    delete ui;
}


