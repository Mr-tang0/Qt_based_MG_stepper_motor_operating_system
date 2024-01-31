#include "worker.h"
#include "test_window.h"

weigh *Worker::tempweigh = new weigh;
motor *Worker::tempMotor = new motor;

Worker::Worker(QObject *parent) : QObject(parent)
{

}
bool Worker::sendMessage(QByteArray message)
{
    bool sendFlag = mainUiTest::myPort->write(message);
    return sendFlag;
}

bool Worker::openReseiveChannal()
{
    connect(mainUiTest::myPort,&QSerialPort::readyRead,[=]()
    {
        QByteArray reseivedMessage =mainUiTest::myPort->readLine();
        QString temp = reseivedMessage.toHex();
        delay(10);
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
