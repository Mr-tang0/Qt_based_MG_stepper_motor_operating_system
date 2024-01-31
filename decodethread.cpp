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
\
    //若来自motor，查询motor配置表，解码motor信息
    if(reseivedMessage.left(2)=="3e")
    {
        // qDebug()<<"orignal"<<reseivedMessage;
        // QString verify = reseivedMessage.mid(8,2);
        // QString temp = reseivedMessage.mid(0,8);
        // QString reseiveVerify = tempMotor->verifySUM(temp).toHex();

        // if(verify!=reseiveVerify) return;//信息错误，退出解码

        //信息无错误：继续进行

        //多圈角度信息
        if(reseivedMessage.mid(2,2)=="92")
        {
            reseivedMessage = reseivedMessage.remove(0,10);//去除指令数据
            // qDebug()<<"remove"<<reseivedMessage;
            //判断数据有误错误略

            //计算距离
            double length = mutiAngleDecode(reseivedMessage);
            mainUiTest::myMotor->detail.currentAngle = length;
            qDebug()<<length;
            emit currentLength(length);

        }
        if(reseivedMessage.left(2)=="9A")
        {

        }
        else {
            emit motorError(false); //motor数据错误
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
    QString usefulMessage = message.mid(0,16);//前十六位为数据

    // QString verify = message.right(2);//后二为验证

    //信息错误:退出解码
    // if(verify!=tempMotor->verifySUM(message))
    // {
    //     return NULL;
    // }
    //信息无错误：继续进行

    //接收数据高位在后，需反转
    QString changeUsefulMessage = "";
    for(int i = 0;i<usefulMessage.length()/2;i++)
    {
        changeUsefulMessage = usefulMessage.mid(i*2,2)+changeUsefulMessage;
    }


    bool ok;

    //转换为10进制
    int angle = changeUsefulMessage.toInt(&ok,16);
    qDebug()<<"length"<<usefulMessage<<angle<<ok;
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
