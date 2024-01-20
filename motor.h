#ifndef MOTOR_H
#define MOTOR_H

#include <QObject>
#include"headers.h"

class motor : public QObject
{
    Q_OBJECT
public:
    explicit motor(QObject *parent = nullptr);

    QByteArray buildCmdData(int motorAddress,QString command,int commandDataLen);
    QByteArray buildData(QString command,QString messageData);

    QByteArray verifySUM(QString data);

    void writePram();

    bool motorOpen(bool open);
    void motorPowerMove(bool direction);
    void stopMove();
    void moveToSetPosition();



    motorDetails detail={"",0,0.,0.,0.,0.,0.};
    bool motorOpenFlag = false;


private:
    QJsonObject motorCmdObject;


signals:

public slots:
};

#endif // MOTOR_H
