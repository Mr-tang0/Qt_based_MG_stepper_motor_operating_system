#include "widget.h"
#include "ui_widget.h" 
#include "portui_window.h"
#include "login_window.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("控制");

    Login *myLogin = new Login;
    myLogin->show();

    portUi *portui = new portUi;
    connect(myLogin,&Login::Logined,[=](QString userName){
        portui->show();
        currentUserName = userName;
    });

    connect(portui,&portUi::portConnected,[=](bool connectFlag){
        if(connectFlag)this->show();
        else this->close();
        ui->label->setText(QStringLiteral("当前连接：%1 波特率：%2%3").arg(myPort->portName()).arg(myPort->baudRate()).arg(currentUserName));
    });

    //这里是否考虑将发送和接收放入不同线程
    QThread *mythread = new QThread;
    newworker->moveToThread(mythread);//worker进入子线程，有关于收发的函数均在子线程中执行
    newworker->openReseiveChannal();//开接收

    QString rootPath  = QCoreApplication::applicationDirPath();

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

                saveMotor(i,rootPath+"/log/motor_log.json");

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

        QPushButton *stop = findChild<QPushButton*>("motorStop_"+QString::number(i+1));
        connect(stop,&QPushButton::clicked,[=](){
            myMotorList[i]->stopMove();
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
            myMotorList[i]->detail.motorname = "null";
            refreshUi();
            saveMotor(i,rootPath+"/log/motor_log.json");
        });
    }

    connect(newworker,&Worker::currentWeight,[=](int,double weight){
        ui->weightDisplay->setText(QString::number(weight));
        ui->weightDisplay->setStyleSheet("background-color:white");
        myweigh->currentWeight = weight;
    });
    connect(newworker,&Worker::weighError,[=](int address){
        ui->weightText->append(QStringLiteral("%1称重模块错误").arg(QString::number(address)));
    });

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
    }
    else {
        for (int i = 0;i<myMotorList.length();i++) {
            if(ui->weighAddress->text().toInt()==myMotorList[i]->detail.motorID){
                qDebug()<<"地址不能与电机地址相同";
                for (int i = 0;i<2;i++) {
                    ui->changeWeigh->setStyleSheet("background-color: red");
                    delay(50);
                    ui->changeWeigh->setStyleSheet("background-color: white");
                    delay(50);
                }
                break;
            }
            else if(ui->weighAddress->text().toInt()!=0){
                myweigh->address = ui->weighAddress->text().toInt();
                ui->weighAddress->setEnabled(false);
                ui->changeWeigh->setText("更改地址");
            }
        }

    }
}

void Widget::on_refreshWeigh_clicked()
{
    myweigh->getWeight(myweigh->address);
}

void Widget::on_saveWeight_clicked()
{
    QString rootPath  = QCoreApplication::applicationDirPath();
    saveWeigh(rootPath+"/log/weigh_log.json",false);
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

void Widget::on_clearWeighLog_clicked()
{
    QString rootPath  = QCoreApplication::applicationDirPath();
    saveWeigh(rootPath+"/log/weigh_log.json",true);
    ui->weightText->clear();
}


