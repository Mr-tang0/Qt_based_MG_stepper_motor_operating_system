#include "worker.h"
#include "test_window.h"

weigh *Worker::tempweigh = new weigh;
motor *Worker::tempMotor = new motor;
QTimer *Worker::sendTimer = new QTimer;

Worker::Worker(QObject *parent) : QObject(parent)
{

}

//需要添加buffer,否则信息错乱

bool Worker::sendMessage(QByteArray message)
{
    // sendMessageList.append(message);

    if(message.toHex().mid(2,2)=="92" or message.toHex().mid(0,1)=="0")
    {
        sendMessageList.append(message);
    }
    else {
        sendMessageList.prepend(message);
    }
    return true;
}



bool Worker::openReseiveChannal()
{
    connect(sendTimer,&QTimer::timeout,[=](){
        if(!sendMessageList.isEmpty())
        {
            sendFlag = mainUiTest::myPort->write(sendMessageList.first());
            sendMessageList.removeFirst();
        }
    });

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
