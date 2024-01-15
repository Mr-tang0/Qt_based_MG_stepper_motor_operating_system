#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include"headers.h"

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);

    bool sendMessage(QByteArray message);
    bool openReseiveChannal();


private:
    void decodeMessage(QString reseivedMessage);
    void delay(int delayTime);

signals:
    void currentPosition(int motorID,double positon);
    void currentSpeed(int motorID,double speed);
    void currentVoltage(int motorID,double voltage);
    void currentCurrent(int motorID,double current);
    void currentTemperature(int motorID,double temperature);

    void currentWeight(int weighID, double weight);

public slots:
};

#endif // WORKER_H
