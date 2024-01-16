#include "worker.h"
#include "widget.h"

weigh *Worker::tempweigh = new weigh;
motor *Worker::tempMotor = new motor;

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
        QByteArray reseivedMessage =Widget::myPort->readLine();
        QString temp = reseivedMessage.toHex();
        decodeMessage(temp);
        delay(50);
    });

    return true;
}

//串口接收解码
//判断来自motor还是weigh
//解码完毕后，发出信号，通知主线程处理ui、更新motor和weigh的信息
void Worker::decodeMessage(QString reseivedMessage)
{
    //若来自motor，查询motor配置表，解码motor信息
    if(reseivedMessage.left(2)=="3e")
    {
        QString verify = reseivedMessage.right(2);
        reseivedMessage = reseivedMessage.remove(reseivedMessage.length()-2,2);
        int len = reseivedMessage.length()/2;
        for (int i = 0;i<len;i++) {
            reseivedMessage.insert(2*i+i," ");
        }
        QString reseiveVerify = tempMotor->verifySUM(reseivedMessage).toHex();

        //判断数据完整
        if(verify==reseiveVerify)
        {

        }
        else {
            emit motorError(0); //motor数据错误
        }
    }

    //若来自weigh，查询weigh配置表，解码weigh信息
    else
    {
        QString verify = reseivedMessage.right(4);

        reseivedMessage = reseivedMessage.remove(reseivedMessage.length()-4,4);

        QByteArray temp = QByteArray::fromHex(reseivedMessage.toStdString().c_str());

        QString reseiveVerify = tempweigh->CRC16(temp).toHex();

        //判断数据完整无误
        int address = reseivedMessage.left(2).toInt();
        if(verify==reseiveVerify)
        {
            //没必要查表，表内只有一个值
            if (reseivedMessage.mid(2,2)=="03") {
                QString weightString = reseivedMessage.mid(6,8);
                weightString = weightString.right(4)+weightString.left(4);
                bool ok;
                double weight = weightString.toInt(&ok,16)/100.00;
                qDebug()<<weight<<address;
                emit currentWeight(address, weight);

            }
        }
        else {
            emit weighError(address);//weigh数据错误
        }
    }   
}



void Worker::delay(int delayTime)
{
    QEventLoop loop;
    QTimer::singleShot(delayTime,&loop,SLOT(quit()));
    loop.exec();

}
