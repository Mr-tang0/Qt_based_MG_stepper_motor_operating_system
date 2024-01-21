#ifndef MOTOR_H
#define MOTOR_H

#include <QObject>
#include"headers.h"

class motor : public QObject
{
    Q_OBJECT
public:
    explicit motor(QObject *parent = nullptr);

    QByteArray buildCmdData(QString command);

    QByteArray buildData(QString command,QString messageData);

    QByteArray verifySUM(QString data);


    bool open();
    bool close();
    bool stop();

    void speedMove();
    void angleMove();

    bool writeParam();

    bool readState1();
    bool readState2();
    bool readState3();
    bool clearError();

    motorDetails detail={"",0,0.,0.,0.,0.,0.,0.,0.};
    bool motorOpenFlag = false;


private:
    QJsonObject motorCmdObject;//这是用json文件的读参数方法

    motorCMD motorcmd;
    motorDATA motordata;
    motorParam motorparam;


signals:

public slots:
};

#endif // MOTOR_H
