#include "decodethread.h"
#include "test_window.h"

decodeThread::decodeThread(QObject *parent) : QObject(parent)
{

}

//串口接收解码
//判断来自motor还是weigh
//解码完毕后，发出信号，通知主线程处理ui、更新motor和weigh的信息
void decodeThread::decodeMessage(QString reseivedMessage)
{
    //若来自motor，查询motor配置表，解码motor信息
    if(reseivedMessage.left(2)=="3e")
    {
        qDebug()<<reseivedMessage;
        QString verify = reseivedMessage.mid(8,2);
        reseivedMessage = reseivedMessage.remove(reseivedMessage.length()-2,2);
        int len = reseivedMessage.length()/2;
        for (int i = 0;i<len;i++) {
            reseivedMessage.insert(2*i+i," ");
        }
        QString reseiveVerify = tempMotor->verifySUM(reseivedMessage).toHex();

        //判断数据完整
        if(verify==reseiveVerify)
        {
            //进入解码
            reseivedMessage.remove(0,2);
            if(reseivedMessage.left(2)=="92")//多圈角度信息
            {
                double length = mutiAngleDecode(reseivedMessage);
                mainUiTest::myMotor->detail.currentAngle = length;
                emit currentLength(length);
            }
            else if (reseivedMessage.left(2)=="9A") //电机状态信息
            {

            }

        }
        else {
            emit motorError(-1); //motor数据错误
        }
    }

    //若来自weigh，解码weigh信息
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
            if (reseivedMessage.mid(2,2)=="03") {
                double weight = decodeCurrentWeight(reseivedMessage);
                mainUiTest::myWeigh->detail.currentWeight = weight;
                emit currentWeight(weight);
            }
        }
        else {
            emit weighError(address);//weigh数据错误
        }
    }
}



void decodeThread::delay(int delayTime)
{
    QEventLoop loop;
    QTimer::singleShot(delayTime,&loop,SLOT(quit()));
    loop.exec();

}

double decodeThread::mutiAngleDecode(QString message)
{
    QString usefulMessage = message.mid(8,16);
    QString verify = message.right(2);
    if(verify!=tempMotor->verifySUM(message))
    {
        return -1;
    }

    QString changeUsefulMessage = "";//接收数据高位在后，需反转
    for(int i = 0;i<usefulMessage.length()/2;i++)
    {
        changeUsefulMessage = usefulMessage.mid(i*2,2)+" "+changeUsefulMessage;
    }
    bool ok;
    int angle = changeUsefulMessage.toInt(&ok,16);

    double pitch = mainUiTest::myMotor->detail.pitch;

    double length = pitch*angle/36000.;

    return length;
}

double decodeThread::decodeCurrentWeight(QString message)
{
    QString weightString = message.mid(6,8);
    weightString = weightString.right(4)+weightString.left(4);
    bool ok;
    double weight = weightString.toInt(&ok,16)/100.00;
    return weight;
}
