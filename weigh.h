#ifndef WEIGH_H
#define WEIGH_H

#include <QObject>
#include"headers.h"

class weigh : public QObject
{
    Q_OBJECT
public:
    explicit weigh(QObject *parent = nullptr);
    
    void getWeight(int weighAddress);
    void shelling(int weighAddress,bool shell);


    weighDetails detail;

    int address;
    double currentWeight;
    QList<QString> weighLogList;

    QByteArray buildData(int weighAddress,QString data,bool optWork);
    QByteArray CRC16(QByteArray data);

    QJsonObject weighObject;
private:




signals:
    void weightChange(int weight);

public slots:
};

#endif // WEIGH_H
