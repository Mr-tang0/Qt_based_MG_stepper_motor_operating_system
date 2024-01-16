#include "widget.h"
#include "ui_widget.h"

//静态成员初始化区
QSerialPort *Widget::myPort = new QSerialPort();
Worker *Widget::newworker = new Worker();
weigh* Widget::myweigh = new weigh;
QList<motor*> Widget::myMotorList = {};

//静态成员初始化区

void Widget::initSystem()
{
    QString rootPath  = QCoreApplication::applicationDirPath();
    loadMotorDetails(rootPath+"/motor_log.json");
    loadWeighDetails(rootPath+"/weigh_log.json");
    refreshUi();
    buttonTwinkling("motor_1","yellow",true);


}
void Widget::refreshUi()
{
    for (int i = 0;i<myMotorList.length();i++)
    {
        QPushButton *btn = findChild<QPushButton*>("motor_"+QString::number(i+1));
        btn->setText(myMotorList[i]->detail.motorname);
        btn->setStyleSheet("background-color: white");

        findChild<QLineEdit*>("motorName_"+QString::number(i+1))->setText(myMotorList[i]->detail.motorname);
        findChild<QLineEdit*>("motorID_"+QString::number(i+1))->setText(QString::number(myMotorList[i]->detail.motorID));
        findChild<QLineEdit*>("setSpeed_"+QString::number(i+1))->setText(QString::number(myMotorList[i]->detail.speedControl));
        findChild<QLineEdit*>("maxSpeed_"+QString::number(i+1))->setText(QString::number(myMotorList[i]->detail.maxSpeed));
        findChild<QLineEdit*>("setPositon_"+QString::number(i+1))->setText(QString::number(myMotorList[i]->detail.angleControl));
        findChild<QLineEdit*>("powerControl_"+QString::number(i+1))->setText(QString::number(myMotorList[i]->detail.powerControl));
    }
    findChild<QLineEdit*>("weighAddress")->setText(QString::number(myweigh->address));
}

void Widget::saveMotor(int index,QString filePath)
{

    if(index>=myMotorList.length())
    {
        myMotorList.append(new motor);
    }
    myMotorList[index]->detail.motorname = findChild<QLineEdit*>("motorName_"+QString::number(index+1))->text();
    myMotorList[index]->detail.motorID = findChild<QLineEdit*>("motorID_"+QString::number(index+1))->text().toInt();

    myMotorList[index]->detail.speedControl = findChild<QLineEdit*>("setSpeed_"+QString::number(index+1))->text().toDouble();
    myMotorList[index]->detail.maxSpeed = findChild<QLineEdit*>("maxSpeed_"+QString::number(index+1))->text().toDouble();
    myMotorList[index]->detail.angleControl = findChild<QLineEdit*>("setPositon_"+QString::number(index+1))->text().toDouble();
    myMotorList[index]->detail.powerControl = findChild<QLineEdit*>("powerControl_"+QString::number(index+1))->text().toDouble();
    qDebug()<<findChild<QLineEdit*>("motorName_"+QString::number(index+1))->text();

    saveJson(myMotorList,filePath);
    refreshUi();
}


void Widget::saveWeigh(int index,QString filePath)
{

}

void Widget::buttonTwinkling(QString btnName,QString color,bool flag)//timer的生命周期有问题
{

    QPushButton *btn = new QPushButton;
    btn = findChild<QPushButton*>(btnName);
    if(flag)
    {
        int twinklingFlag = 1;
        connect(twinker,&QTimer::timeout,[=,&twinklingFlag](){

            if(twinklingFlag==1){
                btn->setStyleSheet(QStringLiteral("background-color: %1").arg(color));
                twinklingFlag = 0;
            }
            else
            {
                btn->setStyleSheet("background-color: white");
                twinklingFlag = 1;
            }
        });
        twinker->start(250);
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

void Widget::saveJson(QList<motor*> MotorList,QString filePath)
{
    QFile motorfile(filePath);
    motorfile.open(QIODevice::ReadOnly);
    QByteArray jsonData = motorfile.readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    motorfile.close();

    QJsonObject Object = jsonDoc.object();

    for (int i = 0;i<MotorList.length();i++)
    {
        Object["motorName_"+QString::number(i)] = MotorList[i]->detail.motorname;
        Object["motorID_"+QString::number(i)] = MotorList[i]->detail.motorID;

        Object["powerControl_"+QString::number(i)] = MotorList[i]->detail.powerControl;

        Object["speedControl_"+QString::number(i)] = MotorList[i]->detail.speedControl;
        Object["maxSpeed_"+QString::number(i)] = MotorList[i]->detail.maxSpeed;

        Object["angleControl_"+QString::number(i)] = MotorList[i]->detail.angleControl;
        Object["angleIncrement_"+QString::number(i)] = MotorList[i]->detail.angleIncrement;
    }
    Object["motorNumber"] = MotorList.length();

    jsonDoc.setObject(Object);
    QString temp  = jsonDoc.toJson();
    motorfile.open(QIODevice::WriteOnly);
    motorfile.write(temp.toUtf8());
    motorfile.close();
}

void Widget::loadWeighDetails(QString filePath)
{
    QFile motorfile(filePath);

    try {
        motorfile.open(QIODevice::ReadOnly);
    }
    catch (QFileDevice::FileError) {
        qDebug()<<QStringLiteral("日志文件%1不存在").arg(filePath);
        return;
    }

    QByteArray jsonData = motorfile.readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    QJsonObject jsonObject = jsonDoc.object();
    motorfile.close();

    myweigh->address = jsonObject["address"].toInt();



}


void Widget::loadMotorDetails(QString filePath)
{
    myMotorList.clear();
    QFile motorfile(filePath);

    try {
        motorfile.open(QIODevice::ReadOnly);
    }
    catch (QFileDevice::FileError) {
        qDebug()<<QStringLiteral("日志文件%1不存在").arg(filePath);
        return;
    }

    QByteArray jsonData = motorfile.readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    QJsonObject jsonObject = jsonDoc.object();
    motorfile.close();

    int motorNumber = jsonObject["motorNumber"].toInt();
    for (int i = 0;i<motorNumber;i++)
    {
        myMotorList.append(new motor);
        motorDetails detail =
        {
            jsonObject["motorName_"+QString::number(i)].toString(),//motorname:
            jsonObject["motorID_"+QString::number(i)].toInt(),//motorID:
            jsonObject["powerControl_"+QString::number(i)].toDouble(),//powerControl:
            jsonObject["speedControl_"+QString::number(i)].toDouble(),//speedControl:
            jsonObject["maxSpeed_"+QString::number(i)].toDouble(),//maxSpeed:
            jsonObject["angleControl_"+QString::number(i)].toDouble(),//angleControl:
            jsonObject["angleIncrement_"+QString::number(i)].toDouble()//angleIncrement:
        };
        myMotorList[i]->detail = detail;
    }

}
