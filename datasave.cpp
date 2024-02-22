#include "datasave.h"
#include "test_window.h"

QLineSeries *dataSave::tempSeries = new QLineSeries();

dataSave::dataSave(QObject *parent)
    : QObject{parent}
{

}
bool dataSave::saveFact(QString filePath)
{
    for (int i = 0; i < lengthList.length(); i++)
    {
        QStringList temp = {QString::number(lengthList[i]),QString::number(weightList[i])};
        dataLog<<temp;
    }

    QFile labelFile(filePath);
    if(!labelFile.open(QIODevice::Append|QIODevice::Text))
    {
        return false;
    }
    else {
        QTextStream out(&labelFile);

        for (int i = 0;i<dataLog.length();i++)
        {
            for (int j = 0;j<dataLog[i].length();j++)
            {
                out<<dataLog[i][j].toUtf8().toStdString().c_str();
                out<<",";
            }
            out<<"\n";
        }
        labelFile.close();
    }
    return true;

}
void dataSave::getData()
{
    double weigh =  mainUiTest::myWeigh->detail.currentWeight;
    double length =  mainUiTest::myMotor->detail.currentAngle;

    lengthList.append(length);
    weightList.append(weigh);

    QPointF data = QPointF(weigh,length);
    *tempSeries<<data;

    mainUiTest::freshrate++;
}
bool dataSave::resetThis()
{
    dataLog.clear();

    lengthList.clear();
    weightList.clear();
}
