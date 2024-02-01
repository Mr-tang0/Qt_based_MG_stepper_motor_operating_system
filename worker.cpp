#include "worker.h"
#include "test_window.h"

weigh *Worker::tempweigh = new weigh;
motor *Worker::tempMotor = new motor;

Worker::Worker(QObject *parent) : QObject(parent)
{

}
//需要添加buffer,否则信息错乱
bool Worker::sendMessage(QByteArray message)
{
    bool sendFlag = mainUiTest::myPort->write(message);
    return sendFlag;
}

bool Worker::openReseiveChannal()
{


    connect(mainUiTest::myPort,&QSerialPort::readyRead,[=]()
    {
        QByteArray reseivedMessage =mainUiTest::myPort->readAll();
        QString temp = reseivedMessage.toHex();

        emit ReseiveMassage(temp);
    });
    return true;
}



void Worker::delay(int delayTime)
{
    QEventLoop loop;
    QTimer::singleShot(delayTime,&loop,SLOT(quit()));
    loop.exec();

}
