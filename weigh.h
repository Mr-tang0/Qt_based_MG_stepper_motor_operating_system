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

    void shelling(int weighAddress,bool shell);//去皮操作

    weighDetails detail = {0,0.,0.,0.};

private:

    QByteArray buildData(int weighAddress,QString data,bool optWork);



signals:
    void weightChange(int weight);

public slots:
};

#endif // WEIGH_H
