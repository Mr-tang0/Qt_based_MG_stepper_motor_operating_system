#include "widget.h"
#include "ui_widget.h"

QSerialPort *Widget::myPort = new QSerialPort();
Worker *Widget::newworker = new Worker();


void Widget::buttonTwinkling(QString btnName,bool flag)
{
    QPushButton *btn = new QPushButton;
    btn = findChild<QPushButton*>(btnName);
    if(flag)
    {
        int twinklingFlag = 1;
        connect(twinker,&QTimer::timeout,[=,&twinklingFlag](){

            if(twinklingFlag==1){
                btn->setStyleSheet("background-color: yellow");
                twinklingFlag = 0;
            }
            else
            {
                btn->setStyleSheet("background-color: white");
                twinklingFlag = 1;
            }
        });
        twinker->start(500);
    }
    else
    {
        btn->setStyleSheet("background-color: white");
        twinker->stop();
    }

}

void Widget::delay(int delayTime)
{
    QEventLoop loop;
    QTimer::singleShot(delayTime,&loop,SLOT(quit()));
    loop.exec();
}

void Widget::saveJson(motorDetails &motordetail,QString filePath)
{
    QFile motorfile(filePath);
    motorfile.open(QIODevice::ReadOnly);
    QByteArray jsonData = motorfile.readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    motorfile.close();

    QJsonObject Object = jsonDoc.object();
    Object[motordetail.motorname+" motorname"] = motordetail.motorname;
    Object[motordetail.motorname+" motorID"] = motordetail.motorID;

    Object[motordetail.motorname+" powerControl"] = motordetail.powerControl;

    Object[motordetail.motorname+" speedControl"] = motordetail.speedControl;
    Object[motordetail.motorname+" maxSpeed"] = motordetail.maxSpeed;

    Object[motordetail.motorname+" angleControl"] = motordetail.angleControl;
    Object[motordetail.motorname+" angleIncrement"] = motordetail.angleIncrement;

    jsonDoc.setObject(Object);

    QString temp  = jsonDoc.toJson();
    motorfile.open(QIODevice::WriteOnly);
    motorfile.write(temp.toUtf8());
    motorfile.close();
}

void Widget::loadMotorDetails(QList<motorDetails> &loadmotordetail,QString filePath)
{
    QFile motorfile(filePath);
    motorfile.open(QIODevice::ReadOnly);


    QByteArray jsonData = motorfile.readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    motorfile.close();

    QJsonObject jsonObject = jsonDoc.object();

    foreach(auto item,jsonObject.keys())
    {

    }




}
