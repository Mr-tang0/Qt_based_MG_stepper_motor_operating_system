#ifndef WEIGH_H
#define WEIGH_H

#include <QObject>

class weigh : public QObject
{
    Q_OBJECT
public:
    explicit weigh(QObject *parent = nullptr);
    
    void getWeight(int weighAddress);
    void shelling(int weighAddress,bool shell);

    void decode(QString reseiveMessage);

private:
    QByteArray buildData(int weighAddress,QString data,bool optWork);
    QByteArray CRC16(QByteArray data);

signals:
    void weightChange(int weight);

public slots:
};

#endif // WEIGH_H
