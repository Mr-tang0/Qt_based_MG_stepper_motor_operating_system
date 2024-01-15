#include "widget.h"
#include "ui_widget.h"

//静态成员初始化区
QSerialPort *Widget::myPort = new QSerialPort();
Worker *Widget::newworker = new Worker();

QList<motor*> Widget::myMotorList = {};

//静态成员初始化区

void Widget::initSystem()
{
    QString rootPath  = QCoreApplication::applicationDirPath();
    loadMotorDetails(rootPath+"/motor_log.json");
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

        QList<QString> lineEditList = {"motorName_","motorID_","setSpeed_","maxSpeed_","setPositon_"};
        QList<QLineEdit> EditList;

        for (int j = 0;j<lineEditList.length();j++)
        {
            EditList.append(*findChild<QLineEdit*>(lineEditList[j]+QString::number(1)));
            QLineEdit *lineEdit = findChild<QLineEdit*>(lineEditList[j]+QString::number(1));
            lineEdit->setText(myMotorList[i]->detail.motorname);

        }



    }

}
void Widget::buttonTwinkling(QString btnName,QString color,bool flag)
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

void Widget::loadMotorDetails(QString filePath)
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

    int motorNumber = jsonObject["motorNumber"].toInt();
    for (int i = 0;i<motorNumber;i++)
    {
        myMotorList.append(new motor);
        motorDetails detail =
        {
            jsonObject["motorName_"+QString::number(i)].toString(),//motorname:
            jsonObject["motorID_"+QString::number(i)].toInt(),//motorID:
            jsonObject["powerControl_"+QString::number(i)].toInt(),//powerControl:
            jsonObject["speedControl_"+QString::number(i)].toInt(),//speedControl:
            jsonObject["maxSpeed_"+QString::number(i)].toInt(),//maxSpeed:
            jsonObject["angleControl_"+QString::number(i)].toInt(),//angleControl:
            jsonObject["angleIncrement_"+QString::number(i)].toInt()//angleIncrement:
        };
        myMotorList[i]->detail = detail;
    }

}
