#ifndef WEIGH_H
#define WEIGH_H

#include <QObject>

class weigh : public QObject
{
    Q_OBJECT
public:
    explicit weigh(QObject *parent = nullptr);
    
    int getWeight(QString serialData);
    QByteArray buildData(int weighAddress,QString data,bool optWork);
    QByteArray CRC16(QByteArray data);


signals:
    void weightChange(int weight);

public slots:
};

#endif // WEIGH_H
