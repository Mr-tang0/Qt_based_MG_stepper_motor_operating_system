#include "worker.h"
#include "test_window.h"

QTimer *Worker::sendTimer = new QTimer;

Worker::Worker(QObject *parent) : QObject(parent)
{


}

bool Worker::sendMessage(QByteArray message)
{
    QString temp = message.toHex();

    if(temp.left(4)=="3e92" or  temp.left(4)=="0203")
    {
        sendMessageList.append(message);
    }
    else
    {
        sendMessageList.prepend(message);
    }

    return sendFlag;
}

bool Worker::openReseiveChannal()
{
    connect(sendTimer,&QTimer::timeout,[=](){

        if(mainUiTest::myPort->isOpen())
        {
            if(!sendMessageList.isEmpty())
            {
                sendFlag = mainUiTest::myPort->write(sendMessageList.first());
                sendMessageList.removeFirst();
            }
            mainUiTest::myMotor->getLength();
            mainUiTest::myWeigh->getWeight();

            mainUiTest::freshrate++;
        }

        QString temp;
        if(readBuffer.length()<18)return;

        if(readBuffer.left(2)=="3e")
        {
            temp = readBuffer.left(28);
            readBuffer.remove(0,28);
        }
        else {
            temp  = readBuffer.left(18);
            readBuffer.remove(0,18);
        }

        emit ReseiveMassage(temp);

        if(readBuffer.length()>200)
        {
            sendTimer->stop();
            sendTimer->start(20);
        }
        else {
            sendTimer->stop();
            sendTimer->start(10);
        }

    });
    sendTimer->start(10);


    connect(mainUiTest::myPort,&QSerialPort::readyRead,[=]()
    {

        QByteArray reseivedMessage =mainUiTest::myPort->readLine();
        QString temp = reseivedMessage.toHex();
        readBuffer = readBuffer+temp;
    });
    return true;
}

void Worker::delay(int delayTime)
{
    QEventLoop loop;
    QTimer::singleShot(delayTime,&loop,SLOT(quit()));
    loop.exec();

}
