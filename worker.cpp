#include "worker.h"
#include "widget.h"
Worker::Worker(QObject *parent) : QObject(parent)
{

}
bool Worker::sendMessage(QByteArray message)
{
    bool sendFlag = Widget::myPort->write(message);
    return sendFlag;
}

bool Worker::openReseiveChannal()
{
    connect(Widget::myPort,&QSerialPort::readyRead,[=]()
    {
        qDebug()<<"something received:";
        QString reseivedMessage =Widget::myPort->readAll();
        decodeMessage(reseivedMessage);
        delay(50);
    });

    return true;
}

//串口接收解码
void Worker::decodeMessage(QString reseivedMessage)
{
    qDebug()<<reseivedMessage;
    //判断来自motor还是weigh
    if(reseivedMessage.left(2)=="3e")
    {
        //若来自motor，查询motor配置表，解码motor信息
    }
    else
    {
        //若来自weigh，查询weigh配置表，解码weigh信息
    }





    //解码完毕，发出信号，通知主线程处理ui、更新motor和weigh的信息
}

void Worker::delay(int delayTime)
{
    QEventLoop loop;
    QTimer::singleShot(delayTime,&loop,SLOT(quit()));
    loop.exec();

}
