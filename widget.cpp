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

    //这里是否考虑将发送和接收放入不同线程
    QThread *mythread = new QThread;
    newworker->moveToThread(mythread);//worker进入子线程，有关于收发的函数均在子线程中执行
    newworker->openReseiveChannal();//开接收

    QString rootPath  = QCoreApplication::applicationDirPath();
    loadMotorDetails(rootPath+"/motor_log.json");
    initSystem();


    //绑定部件动作
    for (int i = 0;i<4;i++)
    {
        //按钮转到页面
        QPushButton *motorBtn = findChild<QPushButton*>("motor_"+QString::number(i+1));
        connect(motorBtn,&QPushButton::clicked,[=](){
            ui->motorTab->setCurrentIndex(i);
        });

        //设置以及未保存提示
        QPushButton *setBtn = findChild<QPushButton*>("setBtn_"+QString::number(i+1));
        connect(setBtn,&QPushButton::clicked,[=](){
            if(setBtn->text()=="更改设置"){
                setBtn->setText("保存设置");
                setBtn->setStyleSheet("background-color: yellow");
                //开禁止
                findChild<QLineEdit*>("motorName_"+QString::number(i+1))->setEnabled(true);
                findChild<QLineEdit*>("motorID_"+QString::number(i+1))->setEnabled(true);
                findChild<QLineEdit*>("setSpeed_"+QString::number(i+1))->setEnabled(true);
                findChild<QLineEdit*>("maxSpeed_"+QString::number(i+1))->setEnabled(true);
                findChild<QLineEdit*>("setPositon_"+QString::number(i+1))->setEnabled(true);
                findChild<QLineEdit*>("powerControl_"+QString::number(i+1))->setEnabled(true);
            }
            else{
                setBtn->setText("更改设置");
                saveMotor(i,rootPath+"/motor_log.json");
                setBtn->setStyleSheet("background-color: white");
                //关禁止，保存
                findChild<QLineEdit*>("motorName_"+QString::number(i+1))->setEnabled(false);
                findChild<QLineEdit*>("motorID_"+QString::number(i+1))->setEnabled(false);
                findChild<QLineEdit*>("setSpeed_"+QString::number(i+1))->setEnabled(false);
                findChild<QLineEdit*>("maxSpeed_"+QString::number(i+1))->setEnabled(false);
                findChild<QLineEdit*>("setPositon_"+QString::number(i+1))->setEnabled(false);
                findChild<QLineEdit*>("powerControl_"+QString::number(i+1))->setEnabled(false);
            }
        });

        connect(ui->motorTab,&QTabWidget::currentChanged,[=](){
            if(setBtn->text()=="保存设置")
            {
                ui->motorTab->setCurrentIndex(i);
                for (int i = 0;i<2;i++) {
                    setBtn->setStyleSheet("background-color: red");
                    delay(50);
                    setBtn->setStyleSheet("background-color: yellow");
                    delay(50);
                }

            }
        });

        //运动模块
        QPushButton *openMotor = findChild<QPushButton*>("openMotor_"+QString::number(i+1));
        connect(openMotor,&QPushButton::clicked,[=](){
            if(openMotor->text()=="开启电机"){
                if(myMotorList[i]->motorOpen(true)){
                    openMotor->setText("关闭电机");
                    openMotor->setStyleSheet("background-color: yellow");
                }
            }
            else {
                if(!myMotorList[i]->motorOpen(false)){
                    openMotor->setText("开启电机");
                    openMotor->setStyleSheet("background-color: white");
                }
            }
        });

        QPushButton *cwMove = findChild<QPushButton*>("cwMove_"+QString::number(i+1));
        connect(cwMove,&QPushButton::clicked,[=](){
            myMotorList[i]->motorPowerMove(true);
        });

        QPushButton *ccwMove = findChild<QPushButton*>("ccwMove_"+QString::number(i+1));
        connect(ccwMove,&QPushButton::clicked,[=](){
            myMotorList[i]->motorPowerMove(false);
        });

        QPushButton *moveTo = findChild<QPushButton*>("moveTo_"+QString::number(i+1));
        connect(moveTo,&QPushButton::clicked,[=](){
            myMotorList[i]->moveToSetPosition();
        });

        QPushButton *deletebtn = findChild<QPushButton*>("delete_"+QString::number(i+1));
        connect(deletebtn,&QPushButton::clicked,[=](){
            myMotorList.removeOne(myMotorList[i]);
            myMotorList.append(new motor);
            refreshUi();
            saveMotor(i,rootPath+"/motor_log.json");
        });
    }


}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_changeWeigh_clicked()
{
    if(ui->changeWeigh->text()=="更改地址")
    {
        ui->weighAddress->setEnabled(true);
        ui->changeWeigh->setText("确认设置");

        int address = ui->weighAddress->text().toInt();
        for (int i = 0;i<myMotorList.length();i++) {
            if(address==myMotorList[i]->detail.motorID){
                qDebug()<<"地址不能与电机地址相同";
                myweigh->address = myweigh->address;
                break;
            }
            else {
                myweigh->address = address;
            }
        }
    }
    else {
        ui->weighAddress->setEnabled(false);
        ui->changeWeigh->setText("更改地址");
    }
}

void Widget::on_refreshWeigh_clicked()
{
    myweigh->getWeight(myweigh->address);
}

void Widget::on_saveWeight_clicked()
{

}

void Widget::on_weighShelling_clicked()
{
    if(ui->weighShelling->text()=="去皮"){
        myweigh->shelling(myweigh->address,true);
        ui->weighShelling->setText("取消去皮");
    }
    else {
        myweigh->shelling(myweigh->address,false);
        ui->weighShelling->setText("去皮");
    }
}
