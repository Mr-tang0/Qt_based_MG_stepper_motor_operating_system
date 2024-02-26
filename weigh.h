#ifndef WEIGH_H
#define WEIGH_H

#include <QObject>
#include"headers.h"

class weigh : public QObject
{
    Q_OBJECT
public:
    explicit weigh(QObject *parent = nullptr);

    QByteArray CRC16(QByteArray data);
    
    void getWeight();//读质量信息

    void setSensitivity(int Range, int sensitivity);

    void shelling();//去皮操作

    weighDetails detail = {0,0.,0.,0.,0};

private:
    void delay(int delayTime);
    QByteArray buildData(int weighAddress,QString data,bool optWork);
    QByteArray buildData(QString orignalData);
    weighCMD weighcmd;


signals:
    void weightChange(int weight);

public slots:
};

#endif // WEIGH_H
