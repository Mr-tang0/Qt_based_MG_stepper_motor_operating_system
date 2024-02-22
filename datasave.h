#ifndef DATASAVE_H
#define DATASAVE_H

#include <QObject>
#include "headers.h"
#include "datasave.h"

class dataSave : public QObject
{
    Q_OBJECT
public:
    explicit dataSave(QObject *parent = nullptr);
    static QLineSeries *tempSeries;
    void runFunc(int sampleRate,bool sampleFlag)
    {
        if(sampleFlag)
        {
            connect(sampleTimer,&QTimer::timeout,[=](){
                getData();
            });
            sampleTimer->start(sampleRate);
        }
        else
        {
            sampleTimer->stop();
        }

    }
    void runFunc(bool sampleFlag)
    {
        if(sampleFlag)
        {
            sampleTimer->start(20);
        }
        else
        {
            sampleTimer->stop();
        }

    }

    bool saveFact(QString filePath);
    bool resetThis();

protected:
    QTimer *sampleTimer = new QTimer;

private:

    void getData();

    QList<QStringList> dataLog;
    QList<double> lengthList,weightList;


signals:
};

#endif // DATASAVE_H
